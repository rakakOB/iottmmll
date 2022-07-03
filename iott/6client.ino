#include <SPI.h>
#include <WiFi.h>
char ssid[]="";
char password[]= "123456789";
uint16_t port =9999; // port number of the server
IPAddress server(192,168,1,122); 
WiFiClient client;
void setup()
{
Serial.begin(9600);
WiFi.begin(ssid,password);
while(WiFi.status()!=WL_CONNECTED)
{
Serial.println("Waiting for Wi-Fi Connection");
Serial.print(".");
delay(300);
}
Serial.println("WiFi Connected");
Serial.println("Attempting to connect to Server");
while(!client.connect(server,port));
Serial.println("Connected to Server");
}
void loop()
{
if(client.available())
{
char c=client.read();
Serial.print(c);
}
}
