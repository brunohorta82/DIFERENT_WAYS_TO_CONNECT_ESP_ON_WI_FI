#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>         //https://github.com/tzapu/WiFiManager

const int led = D4;

void setup() {
   long init = millis();
  pinMode(led, OUTPUT);
    Serial.begin(115200);
    WiFiManager wifiManager;
    wifiManager.autoConnect("OMEUESP");
    Serial.println("LIGADO :)");
    Serial.print("Tempo a ligar ");
    Serial.print(millis() - init  );
    Serial.println(" milisegundos");
}

void loop() {
   if (WiFi.status() == WL_CONNECTED) {
      digitalWrite(led, HIGH);
   }else{
      digitalWrite(led, LOW);
   }
    
}
