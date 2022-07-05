void setup() {
  // put your setup code here, to run once:
pinMode(RED_LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly: 
  digitalWrite(RED_LED,HIGH);
  delay(100);
  digitalWrite(RED_LED,LOW);
  delay(100);
}
