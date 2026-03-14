
#define BLYNK_TEMPLATE_ID "XXXX" //your blynk tem id
#define BLYNK_TEMPLATE_NAME "Notification"  
#define BLYNK_AUTH_TOKEN "YYYY" // your auth token

#define BLYNK_PRINT Serial

#ifdef ESP32
#include <WiFi.h>
#include <WiFiClient.h>
//==========================================================
char ssid[] = "XXXXX";        // type your wifi name
char pass[] = "YYYYY";  // type your wifi password
String Message="SOS Alert!";
//==========================================================

#include <BlynkSimpleEsp32.h>
#define Push_Button 35
#define wifi_led 33
#endif

#ifdef ESP8266
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define Push_Button D1
#define wifi_led D4
#endif

char auth[] = BLYNK_AUTH_TOKEN;

unsigned long old = 0;
unsigned long current = 0;
int interval = 10;
int interval2 = 0;


void setup() {
  Serial.begin(115200);
  Serial.println("\nPlease wait for Blynk Server connection");
  pinMode(wifi_led, OUTPUT);
  pinMode(Push_Button, INPUT);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);
  wifi_testing();
  Blynk.begin(auth, ssid, pass);
   Blynk.logEvent("notification", Message);
}

void loop() {
  Blynk.run();
  wifi_testing();
  current = millis();
  interval2 = (current - old) / 1000;
  if ((digitalRead(Push_Button) == LOW) & (interval2 >= 3)) {
    Serial.println("Blynk notification Sent to Mobile");
    Blynk.logEvent("notification", Message);
    while (digitalRead(Push_Button) == LOW)
    delay(10);
    current = millis();
    old = millis();
    interval2 = 0;


    
     if ((digitalRead(Push_Button) == HIGH )) {
    Serial.println("Blynk notification Sent to Mobile");
    Blynk.logEvent("notification", Message);
    while (digitalRead(Push_Button) == LOW)
    delay(10);
  }
}

void wifi_testing() {
  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    Serial.print(".");
    digitalWrite(wifi_led, LOW);
    delay(250);
    digitalWrite(wifi_led, HIGH);
    current = millis();
    if ((current - old) / 1000 > interval)
      ESP.restart();
  }
}
