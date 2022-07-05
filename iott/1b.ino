void setup() {
  // put your setup code here, to run once:
  pinMode(RED_LED,OUTPUT);
  pinMode(PUSH1,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly: 
  int SW1 = digitalRead(PUSH1);
  if(SW1==LOW){
    digitalWrite(RED_LED,HIGH);
  }
  else{
    digitalWrite(RED_LED,LOW);
  }
}
