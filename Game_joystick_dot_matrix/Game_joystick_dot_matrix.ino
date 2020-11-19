#include "LedControl.h"

LedControl lc=LedControl(10,12,11,1);

unsigned long delaytime1=500;
unsigned long delaytime2=50;

const int SW_pin = 2; 
const int X_pin = 0; 
const int Y_pin = 1; 

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  
  lc.shutdown(0,false);
  lc.setIntensity(0,8);
  lc.clearDisplay(0);
}

void loop() { 
  if (analogRead(X_pin)>100 && analogRead(Y_pin)>100) {
    lc.clearDisplay(0);
    lc.setLed(0,0,0,1);
    lc.setLed(0,7,7,1);
    lc.setLed(0,0,7,1);
    delay(1000);
    lc.clearDisplay(0);
    lc.setLed(0,7,0,1);
    delay(1000);
  } else if (analogRead(X_pin)<100 || analogRead(Y_pin)<100) {
    lc.clearDisplay(0);
    lc.setRow(0,0,B11111111);
    delay(100);
    lc.setColumn(0,7,B11111111);
  }
}
