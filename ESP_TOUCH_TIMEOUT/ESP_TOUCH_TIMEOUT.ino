#include <ESP8266WiFi.h>

bool timeout = true;
void setup(){
  WiFi.mode(WIFI_STA);
  if(WiFi.SSID() != NULL){
    WiFi.begin(WiFi.SSID().c_str(), WiFi.psk().c_str());
    long start = millis();
    while(millis() - start < 30000){
      if(WiFi.status() == WL_CONNECTED){
        timeout = false;
        break;
      }
       delay(500);
    }
  }
  if(timeout){
    timeout  = true;
    WiFi.beginSmartConfig();
    long start = millis();
    while(millis() - start < 30000){
      if(WiFi.status() == WL_CONNECTED){
        timeout = false;
        break;
      }
        delay(500);
    }
  }
 if(timeout){
  while(1)ESP.restart();
   delay(500);
  }
}

void loop(void){
  
}
