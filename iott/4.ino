#include<SPI.h>
#include<WiFi.h>

char ssid[]="";
char password[]="";
IPAddress ip;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("Attempting to connect to the network:");
  Serial.println(ssid);
  WiFi.begin(ssid,password);
  while(WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(300);
  }
  Serial.println("\nYou are connected to the network:");
  while(WiFi.localIP()==INADDR_NONE){
    Serial.print(".");
    delay(300);
  }
  ip=WiFi.localIP();
  Serial.print("Dynamic IP address:");
  Serial.println(ip);
}

void loop() {
  // put your main code here, to run repeatedly: 
  
}
