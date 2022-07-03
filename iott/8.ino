#include <SPI.h>
#include <WiFi.h>
char ssid[] = "Anushamg"; 
char password[] ="12345678"; 
int keyIndex = 0; 
WiFiServer server(80);
void setup() 
{
Serial.begin(115200); 
pinMode(RED_LED,OUTPUT); 
Serial.print("Attempting to connect to Network named: ");
Serial.println(ssid);
WiFi.begin(ssid,password);
while(WiFi.status()!= WL_CONNECTED) 
{
Serial.print(".");
delay(300);
}
Serial.println("\nYou're connected to the network");
Serial.println("Waiting for an ip address");
while (WiFi.localIP()==INADDR_NONE) {
Serial.print("."); 
delay(300);}
Serial.println("\nIP Address obtained");
printWifiStatus();
Serial.println("Starting webserver on port 80");
server.begin(); 
Serial.println("Webserver started!");
}
void loop() 
{
int i = 0;
WiFiClient client = server.available(); 
if (client) { 
Serial.println("new client"); 
char buffer[150] = {0}; 
while(client.connected()) 
{
if(client.available()) 
{
char c = client.read(); 
Serial.write(c); 
if (c == '\n') 
{
if (strlen(buffer)==0) 
{
client.println("HTTP/1.1 200 OK");
client.println("Content-type:text/html");
client.println();
client.println("<html><head><title>Energia CC3200 WiFi Web Server</title></head><body align=center>");
client.println("<h1 align=center><font color=\"red\">Welcome to the CC3200 WiFi WebServer</font></h1>");
client.print("RED LED <button onclick=\"location.href='/H'\">HIGH</button>");
client.println(" <button onclick=\"location.href='/L'\">LOW</button><br>");
client.println();
break; 
}
else { 
memset(buffer, 0, 150);
i = 0;
}
}
else if(c != '\r') 
{
  buffer[i++] = c; // add it to the end of the currentLine
}
if(endsWith(buffer,"GET /H")) 
{
digitalWrite(RED_LED,HIGH); // GET /H turns the LED on
}
if(endsWith(buffer,"GET /L")) 
{
digitalWrite(RED_LED,LOW); // GET /L turns the LED off
}
}
}

client.stop();
Serial.println("client disconnected");
}
}
boolean endsWith(char*inString, char*compString) 
{
int compLength = strlen(compString);
int strLength = strlen(inString);
int i;
for (i=0;i<compLength;i++) {
char a = inString[(strLength-1)-i];
char b = compString[(compLength-1)- i];
if (a!=b) 
{
return false;
}
}
return true;
}
void printWifiStatus() 
{
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
  Serial.print("To see this page in action, open a browser to http://");
  Serial.println(ip);
}
