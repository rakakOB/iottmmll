#include<SPI.h>
#include<WiFi.h>

char ssid[] = "";
char password[]="";
IPAddress ip(198,168,1,12);
int keyIndex=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.print("Attempting to connect to network named:");
  Serial.println(ssid);
  WiFi.begin(ssid,password);
  WiFi.config(ip);
  while(WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(300);
  }
  Serial.println("\nYou are connected to the network:");
  ip=WiFi.localIP();
  Serial.print("Static i0p address:");
  Serial.println(ip);

}

void loop() {
  // put your main code here, to run repeatedly: 
  
}
