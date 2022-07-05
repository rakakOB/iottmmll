void setup() {
  // put your setup code here, to run once:
  pinMode(RED_LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly: 
  int value;
  for(value=0;value<256;value+=10){
    analogWrite(RED_LED,value);
    delay(300);
  }
}
