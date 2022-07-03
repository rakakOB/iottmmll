#include<SPI.h>
#include<WiFi.h>
char ssid[]="WATER";
char password[]="12345678";
IPAddress ip,subnet,gateway;
void setup(){
  Serial.begin(9600);
  Serial.print("attempting to connect to network named:");
  Serial.println(ssid);
  WiFi.begin(ssid,password);
  while(WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(300); 
  }
  Serial.println("\n You are connected to the network:");
  while(WiFi.localIP()==INADDR_NONE){
    Serial.print(".");
    delay(300);
  }
  ip = WiFi.localIP();
  Serial.print("IP Address:");
  Serial.println(ip);
  subnet = WiFi.subnetMask();
  Serial.print("Subnet mask address:");
  Serial.println(subnet);
  gateway=WiFi.gatewayIP();
  Serial.print("Gateway IP is:");
  Serial.println(gateway);
}

void loop() {
  // put your main code here, to run repeatedly: 
  
}
