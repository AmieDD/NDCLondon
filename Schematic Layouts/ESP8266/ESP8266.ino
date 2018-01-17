//www.amiedd.com
//Arduino Uno, Unity connection with ESP8266

#include <SoftwareSerial.h>

#define ESP8266_TX    3
#define ESP8266_RX    4
#define ESP8266_BAUD    9600

SoftwareSerial esp8266(ESP8266_TX, ESP8266_RX); // SoftwareSerial(RX, TX)

void setup()
{
  Serial.begin(ESP8266_BAUD);
  esp8266.begin(ESP8266_BAUD);
}

void loop()
{
  while(Serial.available() > 0)
    esp8266.write(Serial.read());

  while(esp8266.available() > 0)
    Serial.write(esp8266.read());
}