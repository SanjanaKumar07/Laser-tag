#include <IRremote.h>
#include <LiquidCrystal.h>
IRsend irsend;
int recvPin = 10;
int button = 9;
IRrecv irrecv(recvPin);
decode_results results;
int health=5;

void setup() 
{
  
  // put your setup code here, to run once:
 pinMode(button,INPUT_PULLUP);
 Serial.begin(9600);
 irrecv.enableIRIn(); // Start the receiver
pinMode(LED_BUILTIN,OUTPUT);
pinMode(10,INPUT);
pinMode(6,OUTPUT);
 }

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(button)==0)
{
  irsend.sendNEC(0xBBBB, 32);
  Serial.println("sent");
  digitalWrite(6,HIGH);
}
else {
  digitalWrite(6,LOW);
  
if(irrecv.decode(&results))
{
  Serial.println(results.value,HEX);
    irrecv.resume();
  digitalWrite(LED_BUILTIN,HIGH);
  //delay(500);
  health--;
  Serial.print(health);
}
  digitalWrite(LED_BUILTIN,LOW);

}
if(health==0)
 {
  Serial.print("Game over");
  delay(500);
  exit(0);
 }
}
