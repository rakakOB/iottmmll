#include<SPI.h>
#include<WiFi.h>
IPAddress ip(192, 168, 1, 122);
char ssid[] ="";
char password[] ="12345678";
unsigned char data=0;
WiFiServer server(9999);
void setup() {
Serial.begin(9600);
Serial.print("Attempting to connect to Network named:");
Serial.println(ssid);
WiFi.config(ip);
WiFi.begin(ssid,password);
while (WiFi.status() != WL_CONNECTED) { 
Serial.print(".");
delay(300);
}
Serial.println("\nYou're connected to thenetwork");
Serial.println("Waiting for an ip address");
while (WiFi.localIP() == INADDR_NONE) {
Serial.print(".");
delay(300);
}
Serial.println("\nIP Address obtained");
printWifiStatus();
server.begin();
}
void loop()
{
WiFiClient client = server.available();
if(client==true)
{
server.print("HELLO\n");
delay(500);
}
}
void printWifiStatus() {
Serial.print("SSID: ");
Serial.println(WiFi.SSID());
IPAddress IP = WiFi.localIP();
Serial.print("IP Address: ");
Serial.println(IP);
}
