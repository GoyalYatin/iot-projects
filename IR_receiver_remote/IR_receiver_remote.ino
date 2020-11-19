#include <IRremote.h> //include the library
#define Button_1 0xFF30CF
#define Button_1_alt 0x9716BE3F
#define Button_2 0xFF18E7
#define Button_2_alt 0x3D9AE3F7
#define Button_3 0xFF7A85
#define Button_3_alt 0x6182021B
#define Button_4 0xFF10EF
#define Button_4_alt 0x8C22657B
#define Button_5 0xFF38C7
#define Button_5_alt 0x488F3CBB
#define Button_6 0xFF5AA5
#define Button_6_alt 0x449E79F
#define Button_OFF 0xFFA25D
#define Button_OFF_alt 0xE318261B
const int RED = 11;
const int GREEN = 10;
const int YELLOW = 9;
int receiver = 13; //initialize pin 13 as recevier pin.
uint32_t Previous; 
IRrecv irrecv(receiver); //create a new instance of receiver
decode_results results;


void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); //start the receiver
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  digitalWrite(RED, HIGH); 
  digitalWrite(GREEN, HIGH); 
  digitalWrite(YELLOW, HIGH); 
}
void loop() {
  if (irrecv.decode(&results)) { //if we have received an IR signal
    if (results.value==0xFFFFFFFF) { 
      results.value=Previous;
    }
    switch(results.value) {
      case Button_1_alt :
      case Button_1 : 
        digitalWrite(RED, HIGH); 
        digitalWrite(GREEN, LOW); 
        digitalWrite(YELLOW, LOW); 
        break;
      case Button_2_alt :
      case Button_2 : 
        digitalWrite(RED, LOW);
        digitalWrite(GREEN, HIGH); 
        digitalWrite(YELLOW, LOW);  
        break;
      case Button_3_alt :
      case Button_3 : 
        digitalWrite(RED, LOW);
        digitalWrite(GREEN, LOW); 
        digitalWrite(YELLOW, HIGH);  
        break;
      case Button_4_alt :
      case Button_4 : 
        digitalWrite(RED, HIGH);
        digitalWrite(GREEN, HIGH); 
        digitalWrite(YELLOW, HIGH);  
        break;
      case Button_5_alt :
      case Button_5 : 
        wave1();
        break;
      case Button_6_alt :
      case Button_6 : 
        wave2();
        break;
      case Button_OFF_alt :
      case Button_OFF : 
        digitalWrite(RED, LOW);
        digitalWrite(GREEN, LOW); 
        digitalWrite(YELLOW, LOW);  
        break;
    } 
    
  Serial.println (results.value, HEX); //display HEX results 
  irrecv.resume(); //next value
 }
 Previous=results.value;
 if (results.value == Button_5 || results.value == Button_5_alt) {
  wave1();
 } else if (results.value == Button_6 || results.value == Button_6_alt) {
  wave2();
 }
} 

void wave1() {
  digitalWrite(RED, HIGH);
  delay(200);
  digitalWrite(GREEN, HIGH); 
  delay(200);
  digitalWrite(YELLOW, HIGH); 
   
  delay(500);

  digitalWrite(RED, LOW);  
  delay(200);
  digitalWrite(GREEN, LOW); 
  delay(200);
  digitalWrite(YELLOW, LOW);
  
  delay(500);
}

void wave2() {
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW); 
  digitalWrite(YELLOW, LOW); 
   
  delay(200);

  digitalWrite(RED, LOW);
  digitalWrite(GREEN, HIGH); 
  digitalWrite(YELLOW, LOW); 
   
  delay(200);

  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW); 
  digitalWrite(YELLOW, HIGH); 
   
  delay(200);
}
