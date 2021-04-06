//Celestial Default Program
//Version 0.1 Beta
//Written by Kevin George

//Headers
#include "Keyboard.h"
#include "Mouse.h"

void setup()
{
//Pin Programming
int responseDelay = 10;
int encoderPin1 = 2;
int encoderPin2 = 3;
int buttonPin = 4;
int selection = 1;
int direction;
long LastValue = 0;
pinMode(encoderPin1, INPUT);
pinMode(encoderPin2, INPUT);
pinMode(buttonPin, INPUT);
digitalWrite(encoderPin1, HIGH);
digitalWrite(encoderPin2, HIGH);
//Beginning
Mouse.begin();
Keyboard.begin();
Serial.begin(9600);

Serial.println("Starting...");
Serial.println("");
Serial.println("");
//Zoom 
void zoom(int dir){

if (dir == '+'){
keyboard.press(KEY_LEFT_CTRL);
Mouse.move(0, 0, 1);
Keyboard.releaseAll();
Serial.println("Zoom: +");
}

if (dir == '-'){
keyboard.press(KEY_LEFT_CTRL);
Mouse.move(0, 0, -1);
Keyboard.releaseAll();  
Serial.println("Zoom: -");
}
//Scroll
void scroll(int dir){

if (dir == '+'){
Mouse.move(0, 0, 1);
Serial.println("Scroll: +");
}

if (dir == '-'){
Mouse.move(0, 0, -1);
Serial.println("Scroll: -");
}

}

}
//Program Selection
void Program(int select, int dir){

switch (select){
    case 1:
        zoom(dir);
        Serial.write("Changed to Zoom");
    break;
    case 2:
        scroll(dir);
        Serial.write("Changed to Scroll");
    break;  
    default:
        select = 1;
        Serial.write("Cycled");
    break;
}

}

}
void loop()
{
//Button Definition
if (digitalRead(ButtonPin) == HIGH){
    selection = selection + 1;
}



Program(selection, direction);

}