/*
 * Arduino projekt för EEDat. 
 */
#include <SoftwareSerial.h>
#include "WiFiEsp.h"
SoftwareSerial Serial1(6, 7);

char ssid[] = ""; //SSID
char pass[] = ""; //The password

int status = WL_IDLE_STATUS;

void setup()
{
  // put your setup code here, to run once:

  Serial.begin(115200);

  Serial1.begin(9600);

  WiFi.init(&Serial1);

  if (WiFi.status() == WL_NO_SHIELD)
  {
    Serial.println("WiFi shield not present");

    while (true)
      ;

    while (status != WL_CONNECTED)
    {
      Serial.print("Attempting to connect to SSID: ");
      Serial.println(ssid);

      status = WiFi.begin(ssid, pass);

      Serial.println("You're connected to the network");
    }

    void loop()
    {
      // put your main code here, to run repeatedly:
    }
