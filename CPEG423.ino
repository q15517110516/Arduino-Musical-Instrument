#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include "Volume3.h"
const byte numRows= 4; //number of rows on the keypad
const byte numCols= 4; //number of columns on the keypad
byte a[8] = {31,31,31,31,31,31,31,31};
byte b[8] = {0,0,0,0,0,0,0,0};


//keymap defines the key pressed according to the row and columns just as appears on the keypad
char keymap[numRows][numCols]={
  {'0', '1', '2', '3'},
  {'4', '5', '6', '7'},
  {'8', '9', 'A', 'B'},
  {'C', 'D', 'E', 'F'}
};

byte rowPins[numRows] = {9,8,7,6}; //Rows 0 to 3
byte colPins[numCols]= {5,4,3,2}; //Columns 0 to 3
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);
LiquidCrystal_I2C lcd(0x21, 16, 2);
void setup(){
  lcd.begin();
  lcd.createChar(1,a);
  lcd.createChar(2,b);
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Volume: ");
  lcd.setCursor(0,1);
  lcd.print("Pitch:  ");
  pinMode(10,OUTPUT);
  Serial.begin(9600);
}
int freq;
int _vol;
void loop()
{
  char keypressed = myKeypad.getKey();
  if (keypressed != NO_KEY)
  {
    if(keypressed == '0'){
      clearP();
      writeP(1);
      freq = 256;
    }
    else if(keypressed == '1'){
      clearP();
      writeP(2);
      freq = 288;
    }
    else if(keypressed == '2'){
      clearP();
      writeP(3);
      freq = 320;
    }
    else if(keypressed == '3'){
      clearP();
      writeP(4);
      freq = 341;
    }
    else if(keypressed == '4'){
      clearP();
      writeP(5);
      freq = 385;
    }
    else if(keypressed == '5'){
      clearP();
      writeP(6);
      freq = 427;
    }
    else if(keypressed == '6'){
      clearP();
      writeP(7);
      freq = 480;
    }
    else if(keypressed == '7'){
      clearP();
      writeP(8);
      freq = 512;
    }
    else if(keypressed == '8'){
      clearV();
      writeV(1);
      _vol = 0;
    }
    else if(keypressed == '9'){
      clearV();
      writeV(2);
      _vol = 100;
    }
    else if(keypressed == 'A'){
      clearV();
      writeV(3);
      _vol = 200;
    }
    else if(keypressed == 'B'){
      clearV();
      writeV(4);
      _vol = 300;
    }
    else if(keypressed == 'C'){
      clearV();
      writeV(5);
      _vol = 400;
    }
    else if(keypressed == 'D'){
      clearV();
      writeV(6);
      _vol = 500;
    }
    else if(keypressed == 'E'){
      clearV();
      writeV(7);
      _vol = 600;
    }
    else if(keypressed == 'F'){
      clearV();
      writeV(8);
      _vol = 700;
    }
    vol.tone(10,freq,_vol);
  }
}

void clearV(){
  for(int i=8;i<16;i++){
    lcd.setCursor(i,0);
    lcd.write(2);
  }
}

void clearP(){
  for(int i=8;i<16;i++){
    lcd.setCursor(i,1);
    lcd.write(2);
  }
}

void writeP(int i){
  for(int j=0;j<i;j++){
    lcd.setCursor(8+j,1);
    lcd.write(1);
  }
}

void writeV(int i){
  for(int j=0;j<i;j++){
    lcd.setCursor(8+j,0);
    lcd.write(1);
  }
}

