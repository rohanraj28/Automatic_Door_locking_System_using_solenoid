#include<Keypad.h>

char*password = "3690";
int LED_pin = 3;
int lock = 5;
int position = 0;
int position1 = 0;

const byte ROWS = 4; // 4 rows
const byte COLS = 4; // 4 columns 

char keys[ROWS][COLS]
{
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
}; 

byte rowPins[ROWS] = { 13, 12, 11, 10 }; //connection of rows pins to the arduino 
byte colPins[COLS] = { 9, 8, 7, 6 };

Keypad keypad = Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);




void setup() {
  // put your setup code here, to run once:
pinMode(lock,OUTPUT);
door_close();
pinMode(LED_pin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
char key = keypad.getKey();

if(key != NO_KEY){


if (key == password[position]){
  position++;
  
  
}
if (key != password[position1]){
  position1++;
}
if (position == 4){
  position = 0;
  position1 = 0;
  door_open();
}

if (position1 == 4){
  position1 = 0;
  position=0;
  
  wrong();
}

}
}

void door_open(){
  digitalWrite(lock,LOW);
  digitalWrite(LED_pin,HIGH);
  delay(700);
  digitalWrite(LED_pin,LOW);
  
  delay(3000);
  digitalWrite(lock,HIGH);
}

void door_close(){
  digitalWrite(lock,HIGH);
}
void wrong(){
  digitalWrite(lock,HIGH);
  digitalWrite(LED_pin,HIGH);
  delay(400);
  digitalWrite(LED_pin,LOW);
  delay(200);
  //delay(600);
  digitalWrite(LED_pin,HIGH);
  delay(400);
  digitalWrite(LED_pin,LOW);
  delay(200);
  digitalWrite(LED_pin,HIGH);
  delay(400);
  digitalWrite(LED_pin,LOW);
  delay(200);
  digitalWrite(LED_pin,HIGH);
  delay(400);
  digitalWrite(LED_pin,LOW);
}