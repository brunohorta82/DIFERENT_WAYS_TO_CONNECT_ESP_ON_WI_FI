
#include <ESP8266WiFi.h>
const int led = D4;
void setup(void){
  
  long init = millis();
  pinMode(led, OUTPUT);
  Serial.begin(115200);
  // Aguarda até estar ligado
  WiFi.mode(WIFI_STA);
  Serial.println("A Aguardar Configuração");
  WiFi.beginSmartConfig();
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    Serial.println(WiFi.smartConfigDone());
  }
 
 
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
