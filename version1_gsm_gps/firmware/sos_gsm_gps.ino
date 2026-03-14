// ==== Minimal SOS: SIM800L + GPS + Collision Switch (ESP32) ====

#include <TinyGPS++.h>
#include <HardwareSerial.h>

// ====== Pins (ESP32) ======
#define GPS_RX       16
#define GPS_TX       17
#define SIM800L_RX    4
#define SIM800L_TX    5
#define SWITCH_PIN   27   // YL-99 OUT (active HIGH on impact)



// ====== Timings ======
const unsigned long DEBOUNCE_MS  = 50UL;
//const unsigned long CALL_TIME_MS = 5000UL;  // ring ~5 s before hangup

// ====== Globals ======
TinyGPSPlus gps;
HardwareSerial gpsSerial(2);
HardwareSerial sim800l(1);

// Debounce state
bool lastSwitchStable = false;
unsigned long lastSwitchChangeMs = 0;

// GPS cache (last valid)
float lastLatitude  = 0.0f;
float lastLongitude = 0.0f;

// ====== Helpers ======
inline bool readCollisionRaw() {         // YL-99 HIGH on impact
  return digitalRead(SWITCH_PIN) == HIGH;
}

bool debounce(bool raw, bool &stable, unsigned long &ts) {
  unsigned long now = millis();
  if (raw != stable) {
    if (now - ts >= DEBOUNCE_MS) {
      stable = raw;
      ts = now;
      return true; // stable change occurred (edge)
    }
  } else {
    ts = now;
  }
  return false;
}

void readGPS() {
  while (gpsSerial.available() > 0) {
    gps.encode(gpsSerial.read());
  }
}

void sendATCommand(const String& command, int waitMs) {
  sim800l.println(command);
  delay(waitMs);
  while (sim800l.available()) {
    Serial.println(sim800l.readString());
  }
}

// ======CALL and SMS=======
void placeCallAndSendSMS(float latitude, float longitude) {
  String gmapLink = "https://maps.google.com/?q=" + String(latitude, 6) + "," + String(longitude, 6);
  String message  = "SOS Alert! Location: " + gmapLink;

  sendATCommand("AT+CMGF=1", 1000);
  sendATCommand("ATD+91xxxxxxxxx;", 10000); // Call
  delay(2000);
  sendATCommand("ATH", 1000);               // Hangup
  sendATCommand("AT+CMGS=\"+91xxxxxxxx\"", 1000); // SMS
  sim800l.print(message);
  sim800l.write(26); // CTRL+Z
  delay(3000);
}

// ====== Setup ======
void setup() {
  Serial.begin(115200);

  gpsSerial.begin(9600, SERIAL_8N1, GPS_RX, GPS_TX);
  sim800l.begin(9600, SERIAL_8N1, SIM800L_RX, SIM800L_TX);

  pinMode(SWITCH_PIN, INPUT);

  lastSwitchStable     = readCollisionRaw();
  lastSwitchChangeMs   = millis();

  Serial.println("SOS device ready.");
}

// ====== Loop ======
void loop() {
  // Keep GPS fresh
  readGPS();
  if (gps.location.isValid()) {
    lastLatitude  = gps.location.lat();
    lastLongitude = gps.location.lng();
  }
  bool swRaw = readCollisionRaw();
  bool changed = debounce(swRaw, lastSwitchStable, lastSwitchChangeMs);
  bool collision = lastSwitchStable;
  }

  delay(5);
}
