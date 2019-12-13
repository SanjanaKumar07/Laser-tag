int LED=5;
int button=9;
void setup() { 
  pinMode (LED,OUTPUT);
  pinMode (button,INPUT_PULLUP);
 
  // put your setup code here, to run once:

}

void loop() {

if(digitalRead(button))
{
digitalWrite(LED,LOW);
}
else 
{
  digitalWrite(LED,HIGH);
}



  // put your main code here, to run repeatedly:

}
