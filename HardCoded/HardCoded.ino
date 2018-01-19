
#include <ESP8266WiFi.h>

const char* ssid = "WIFI_NAME_NETWORK";
const char* password = "MY_PASSWORD";


const int led = D4;



void setup(void){
  long init = millis();
  pinMode(led, OUTPUT);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  // Aguarda até estar ligado
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Ligado a ");
  Serial.println(ssid);
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
  Serial.print("Tempo a ligar ");
  Serial.print(millis() - init  );
  Serial.println(" milisegundos");
}

void loop(void){
   if (WiFi.status() == WL_CONNECTED) {
    digitalWrite(led, HIGH);
   }else{
    digitalWrite(led, LOW);
   }
}
