#include<SPI.h>
#include<WiFi.h>
char ssid[] ="Anushamg"; 
char password[] = "12345678";
long sensorValue = 0;
WiFiClient client;
WiFiServer server(80);
void setup()
{
Serial.begin(9600); 
pinMode(RED_LED, OUTPUT);   
Serial.print("Attempting to connect to Network named: ");
Serial.println(ssid);
WiFi.begin(ssid, password);
while ( WiFi.status() != WL_CONNECTED)
{
  Serial.print(".");
  delay(300);
}
Serial.println("\nYou're connected to the network");
Serial.println("Waiting for an ip address");
while (WiFi.localIP() == INADDR_NONE)
{ 
Serial.print(".");
delay(300);
}
PrintWifiStatus();
Serial.println("Starting webserver on port 80");
server.begin();  
Serial.println("Webserver started!");
}
void loop()
{
client = server.available();
if(client)
{
Serial.println("new client");
boolean currentLineBlank=true;
while(client.connected())
{
if(client.available())
{
  char c=client.read();Serial.write(c);
if(c='\n' && currentLineBlank)
{
SendResponseServer();
break;
}
if(c='\n')
{
currentLineBlank=true;
}
else if(c!='\r')
{
currentLineBlank=false;
}
}
}
delay(1);
client.stop();
Serial.println("client disconnected");
}
}
void SendResponseServer()
{ 
client.println("HTTP/1.1 200 OK"); 
client.println("Content-Type:text/html");
client.println("Connection: close"); 
client.println("Refresh: 1"); 
client.println();
client.println("<!DOCTYPE HTML>");
client.println("<html>");
client.println("<head><title>WiFi Web Server</title></head><body align=center>");
client.println("<h1 align=center><font color=\"red\">Welcome to SensorServer</font></h1>");
sensorValue = analogRead(A0);
client.print("Potentiometer"); 
client.print(" is ");
client.println("<mark>");
client.println( "<h1>");
client.println("<mark>");
client.println(sensorValue);
client.println("</marked>");
client.print("</h1>");
client.println("<br />");
client.println("</html>");
}
void PrintWifiStatus() {
Serial.print("Network Name: ");
Serial.println(WiFi.SSID());
IPAddress ip = WiFi.localIP(); 
Serial.print("IP Address: "); 
Serial.println(ip);
}
