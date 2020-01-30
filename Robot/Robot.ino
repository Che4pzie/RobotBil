/*
 * Arduino projekt för EEDat. 
 */
  pinMode(STATUS_LED, OUTPUT);
}

/**
* Denna funktion används för att blink status_led som definertats i config.h
* Modifiera ej denna funktion
*/
void blinkStatusLed(int del)
{
  digitalWrite(STATUS_LED, HIGH);
  delay(del);
  digitalWrite(STATUS_LED, LOW);
  delay(del);
}

/**
* Denna funktion används för att ansluta till wifi.
*/
void connectToWiFi()
{

  WiFi.init(&Serial1);

  if (WiFi.status() == WL_NO_SHIELD)
  {
    Serial.println("WiFi shield not present");
    while (true)
      ;
  }

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(SSID_NAME);
    WiFi.begin(SSID_NAME, SSID_PASSWORD);
  }

  Serial.println("You're connected to the network");
}
