#include <IRremote.h>
#include <LiquidCrystal.h>
IRsend irsend;
int recvPin = 10;
int button = 9;
IRrecv irrecv(recvPin);
decode_results results;
int health=20;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 6, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int amo = 50;

void setup() 
{
  
  // put your setup code here, to run once:
 pinMode(button,INPUT_PULLUP);
 Serial.begin(9600);
 irrecv.enableIRIn(); // Start the receiver
pinMode(LED_BUILTIN,OUTPUT);
pinMode(10,INPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
 lcd.begin(16, 2);
  
 }

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(button)==0)
{
  irsend.sendNEC(0xBBBBBBBB, 32);
   irrecv.enableIRIn(); // Start the receiver
  Serial.println("sent");
  digitalWrite(6,HIGH);
  amo--;
  lcd.setCursor(0,0);
  lcd.print("AMO = ");
  lcd.print(amo);
}
else {
  digitalWrite(6,LOW);
  
if(irrecv.decode(&results==2863311530))
{
  Serial.println(results.value,HEX);
    irrecv.resume();
  digitalWrite(LED_BUILTIN,HIGH);
  //delay(500);
  health--;
  lcd.setCursor(0,1);
  lcd.print("HEALTH =");
  lcd.print(health );
  if(health==9)
  {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("9");
  }
}
  digitalWrite(LED_BUILTIN,LOW);

}
if(health==0)
 {
  lcd.print("Game over");
  delay(500);
  digitalWrite(7,HIGH);
  exit(0);
 }
}
