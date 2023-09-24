#define BLYNK_TEMPLATE_ID "TMPL3yGpYCOXY"
#define BLYNK_TEMPLATE_NAME "pill box"
#define BLYNK_AUTH_TOKEN "cy10kc129EAGdI9x1ZWR_Ya3qz7Xny-N"

// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp8266.h>



// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "wifi";
char pass[] = "123456789";

BlynkTimer timer;
char auth[] = BLYNK_AUTH_TOKEN;



void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  delay(10);
}
void loop()
{

  Blynk.run();

  String data, data2, data3, data4;
  while (Serial.available()) {
    data = Serial.readStringUntil('\n');
    String t1 = data;
    //Serial.println("moist =   "  );
    Serial.print(t1);
    t1.trim();

    if (t1 == "1")
    {
      Serial.println("helllo");
      Blynk.virtualWrite(V0, "Morning tablet");
      Blynk.logEvent("pill_box", "Morning tablet");

    }

    if (t1 == "2")
    {
      Serial.println("helllo2");
         Blynk.virtualWrite(V0, "night tablet");
      Blynk.logEvent("pill_box", "night tablet");
    }
  }
