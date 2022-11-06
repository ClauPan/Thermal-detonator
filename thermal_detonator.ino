/*
 Name:    StarWars_ThermalDetonator.ino
 Created: 21/05/2022 
 Author:  KrytClaw

*/

#include "Arduino.h"

#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

#define BUTTON 2//detonator button
#define LEDRED  5//armed LED
#define LEDLEFT 6 // yellow LED
#define LEDMIDDLE 7 // yello LED
#define LEDRIGHT 8 //yellow LED
#define SENSOR 9 //sensor input
#define TX 10 //TX pin on DFPlayer module
#define RX 11 //RX pin on DFPlayer module

const int time = 2124;//the delay between sequence change
int sequenceNumber = 0;

SoftwareSerial softwareSerial(TX, RX);

DFRobotDFPlayerMini player; // declaration of player

//Run one LED sequence
void Sequence(bool Left, bool Middle, bool Right){
  if (digitalRead(BUTTON) == LOW)//if true (button is pressed) run LED sequence
  {
    if (Left)
    {
      digitalWrite(LEDLEFT, HIGH);
    }
    else
    {
      digitalWrite(LEDLEFT, LOW);
    }

    if (Middle)
    {
      digitalWrite(LEDMIDDLE, HIGH);
    }
    else
    {
      digitalWrite(LEDMIDDLE, LOW);
    }

    if (Right)
    {
      digitalWrite(LEDRIGHT, HIGH);
    }
    else
    {
      digitalWrite(LEDRIGHT, LOW);
    }
  }
}

long TP_init(){
long measurement=pulseIn (SENSOR, HIGH); //wait for the pin to get HIGH and returns measurement
return measurement;
}

void setup()
{
  Serial.begin(9600);
  pinMode(SENSOR, INPUT);
  softwareSerial.begin(9600);

  pinMode(LEDRED, OUTPUT);
  pinMode(LEDLEFT, OUTPUT);
  pinMode(LEDMIDDLE, OUTPUT);
  pinMode(LEDRIGHT, OUTPUT);

  digitalWrite(LEDRED, LOW);
  digitalWrite(LEDLEFT, LOW);
  digitalWrite(LEDMIDDLE, LOW);
  digitalWrite(LEDRIGHT, LOW);
    
  //now set pins to input
  pinMode(BUTTON, INPUT_PULLUP);
  

  // start the player
  player.begin(softwareSerial);

  
}

void loop(){
  // Start communication with DFPlayer Mini

    // Set volume to a value between (0 to 30)
    player.volume(30);

  if (digitalRead(BUTTON) == LOW ){
      player.play(1); // play the arming sequence
      digitalWrite(LEDRED, HIGH);//switch armed LED (red) on
  }
  
  if (digitalRead(BUTTON) == LOW && sequenceNumber == 0)
  {
    long measurement =pulseIn (SENSOR, HIGH); //get measurement from teh sensor
    Serial.println(measurement);
    if (measurement > 1000)
    { // measurement checks
      player.stop();
      player.play(2); //playing detonating sequence
      sequenceNumber = 0;
      digitalWrite(LEDRED, HIGH);
      digitalWrite(LEDRIGHT, HIGH);
      digitalWrite(LEDMIDDLE, HIGH);
      digitalWrite(LEDLEFT, HIGH);
      while(digitalRead(BUTTON)==LOW){ // give a chance to turn off the toy
        delay(10000);
        player.stop();
        digitalWrite(LEDRED, LOW);
        digitalWrite(LEDRIGHT, LOW);
        digitalWrite(LEDMIDDLE, LOW);
        digitalWrite(LEDLEFT, LOW);
      }
    }
    else
    { // measuremnt does not check
      delay(time);
      Sequence(false, true, true); // continu with arming sequence
      sequenceNumber++;
    }
  }

  if (digitalRead(BUTTON) == LOW && sequenceNumber == 1) 
  {
    long measurement =pulseIn (SENSOR, HIGH);
    Serial.println(measurement);
    if(measurement > 1000){
      player.stop();
      player.play(2);
      sequenceNumber = 0;
      digitalWrite(LEDRED, HIGH);
      digitalWrite(LEDRIGHT, HIGH);
      digitalWrite(LEDMIDDLE, HIGH);
      digitalWrite(LEDLEFT, HIGH);
      while(digitalRead(BUTTON)==LOW){
        delay(10000);
        player.stop();
        digitalWrite(LEDRED, LOW);
        digitalWrite(LEDRIGHT, LOW);
        digitalWrite(LEDMIDDLE, LOW);
        digitalWrite(LEDLEFT, LOW);
      }
    }else{
    Sequence(true, false, true);
    delay(time);
    sequenceNumber++;
  }
  }

  if (digitalRead(BUTTON) == LOW && sequenceNumber == 2){
    long measurement =pulseIn (SENSOR, HIGH);
    Serial.println(measurement);
    if(measurement > 1000){
      player.stop();
      player.play(2);
      sequenceNumber = 0;
      digitalWrite(LEDRED, HIGH);
      digitalWrite(LEDRIGHT, HIGH);
      digitalWrite(LEDMIDDLE, HIGH);
      digitalWrite(LEDLEFT, HIGH);
      while(digitalRead(BUTTON)==LOW){
        delay(10000);
        player.stop();
        digitalWrite(LEDRED, LOW);
        digitalWrite(LEDRIGHT, LOW);
        digitalWrite(LEDMIDDLE, LOW);
        digitalWrite(LEDLEFT, LOW);
      }
    }else{
    Sequence(true, true, true);
    delay(time);
    sequenceNumber++;
  }
  }

  if (digitalRead(BUTTON) == LOW && sequenceNumber == 3)
  {
    long measurement =pulseIn (SENSOR, HIGH);
    Serial.println(measurement);
    if(measurement > 1000){
      player.stop();
      player.play(2);
      sequenceNumber = 0;
      digitalWrite(LEDRED, HIGH);
      digitalWrite(LEDRIGHT, HIGH);
      digitalWrite(LEDMIDDLE, HIGH);
      digitalWrite(LEDLEFT, HIGH);
      while(digitalRead(BUTTON)==LOW){
        delay(10000);
        player.stop();
        digitalWrite(LEDRED, LOW);
        digitalWrite(LEDRIGHT, LOW);
        digitalWrite(LEDMIDDLE, LOW);
        digitalWrite(LEDLEFT, LOW);
      }
    }else{
    Sequence(true, false, true);
    delay(time);
    sequenceNumber++;
  }
  }

  if (digitalRead(BUTTON) == LOW && sequenceNumber == 4)
  {
    long measurement =pulseIn (SENSOR, HIGH);
    Serial.println(measurement);
    if(measurement > 1000){
      player.stop();
      player.play(2);
      sequenceNumber = 0;
      digitalWrite(LEDRED, HIGH);
      digitalWrite(LEDRIGHT, HIGH);
      digitalWrite(LEDMIDDLE, HIGH);
      digitalWrite(LEDLEFT, HIGH);
      while(digitalRead(BUTTON)==LOW){
        delay(10000);
        player.stop();
        digitalWrite(LEDRED, LOW);
        digitalWrite(LEDRIGHT, LOW);
        digitalWrite(LEDMIDDLE, LOW);
        digitalWrite(LEDLEFT, LOW);
      }
    }else{
    Sequence(true, false, false);
    delay(time);
    sequenceNumber++;
  }
  }
  if (digitalRead(BUTTON) == LOW && sequenceNumber == 5)
  {
    long measurement =pulseIn (SENSOR, HIGH);
    Serial.println(measurement);
    if(measurement > 1000){
      player.stop();
      player.play(2);
      sequenceNumber = 0;
      digitalWrite(LEDRED, HIGH);
      digitalWrite(LEDRIGHT, HIGH);
      digitalWrite(LEDMIDDLE, HIGH);
      digitalWrite(LEDLEFT, HIGH);
      while(digitalRead(BUTTON)==LOW){
        delay(10000);
        player.stop();
        digitalWrite(LEDRED, LOW);
        digitalWrite(LEDRIGHT, LOW);
        digitalWrite(LEDMIDDLE, LOW);
        digitalWrite(LEDLEFT, LOW);
      }
    }else{
    Sequence(false, true, false);
    delay(time);
    sequenceNumber++;
  }
  }

  if (digitalRead(BUTTON) == LOW && sequenceNumber == 6)
  {
    long measurement =pulseIn (SENSOR, HIGH);
    Serial.println(measurement);
    if(measurement > 1000){
      player.stop();
      player.play(2);
      sequenceNumber = 0;
      digitalWrite(LEDRED, HIGH);
      digitalWrite(LEDRIGHT, HIGH);
      digitalWrite(LEDMIDDLE, HIGH);
      digitalWrite(LEDLEFT, HIGH);
      while(digitalRead(BUTTON)==LOW){
        delay(10000);
        player.stop();
        digitalWrite(LEDRED, LOW);
        digitalWrite(LEDRIGHT, LOW);
        digitalWrite(LEDMIDDLE, LOW);
        digitalWrite(LEDLEFT, LOW);
      }
    }else{
    Sequence(false, false, true);
    delay(time);
    sequenceNumber++;
  }
  }

  if (digitalRead(BUTTON) == LOW && sequenceNumber == 7)
  {
    long measurement =pulseIn (SENSOR, HIGH);
    Serial.println(measurement);
    if(measurement > 1000){
      player.stop();
      player.play(2);
      sequenceNumber = 0;
      digitalWrite(LEDRED, HIGH);
      digitalWrite(LEDRIGHT, HIGH);
      digitalWrite(LEDMIDDLE, HIGH);
      digitalWrite(LEDLEFT, HIGH);
      while(digitalRead(BUTTON)==LOW){
        delay(10000);
        player.stop();
        digitalWrite(LEDRED, LOW);
        digitalWrite(LEDRIGHT, LOW);
        digitalWrite(LEDMIDDLE, LOW);
        digitalWrite(LEDLEFT, LOW);
      }
    }else{
    Sequence(true, false, false);
    delay(time);
    sequenceNumber++;
  }
  }

  if (digitalRead(BUTTON) == LOW && sequenceNumber == 8)
  {
    long measurement =pulseIn (SENSOR, HIGH);
    Serial.println(measurement);
    if(measurement > 1000){
      player.stop();
      player.play(2);
      sequenceNumber = 0;
      digitalWrite(LEDRED, HIGH);
      digitalWrite(LEDRIGHT, HIGH);
      digitalWrite(LEDMIDDLE, HIGH);
      digitalWrite(LEDLEFT, HIGH);
      while(digitalRead(BUTTON)==LOW){
        delay(10000);
        player.stop();
        digitalWrite(LEDRED, LOW);
        digitalWrite(LEDRIGHT, LOW);
        digitalWrite(LEDMIDDLE, LOW);
        digitalWrite(LEDLEFT, LOW);
      }
    }else{
    Sequence(true, false, true);
    delay(time);
    sequenceNumber++;
  }
  }

  if (digitalRead(BUTTON) == LOW && sequenceNumber == 9)
  {
    long measurement =pulseIn (SENSOR, HIGH);
    Serial.println(measurement);
    if(measurement > 1000){
      player.stop();
      player.play(2);
      sequenceNumber = 0;
      digitalWrite(LEDRED, HIGH);
      digitalWrite(LEDRIGHT, HIGH);
      digitalWrite(LEDMIDDLE, HIGH);
      digitalWrite(LEDLEFT, HIGH);
      while(digitalRead(BUTTON)==LOW){
        delay(10000);
        player.stop();
        digitalWrite(LEDRED, LOW);
        digitalWrite(LEDRIGHT, LOW);
        digitalWrite(LEDMIDDLE, LOW);
        digitalWrite(LEDLEFT, LOW);
      }
    }else{
    Sequence(false, true, true);
    delay(time);
    sequenceNumber++;
  }
  }

  if (digitalRead(BUTTON) == LOW && sequenceNumber == 10)
  {
    long measurement =pulseIn (SENSOR, HIGH);
    Serial.println(measurement);
    if(measurement > 1000){
      player.stop();
      player.play(2);
      sequenceNumber = 0;
      digitalWrite(LEDRED, HIGH);
      digitalWrite(LEDRIGHT, HIGH);
      digitalWrite(LEDMIDDLE, HIGH);
      digitalWrite(LEDLEFT, HIGH);
      while(digitalRead(BUTTON)==LOW){
        delay(10000);
        player.stop();
        digitalWrite(LEDRED, LOW);
        digitalWrite(LEDRIGHT, LOW);
        digitalWrite(LEDMIDDLE, LOW);
        digitalWrite(LEDLEFT, LOW);
      }
    }else{
    Sequence(true, false, false);
    delay(time);
    sequenceNumber++;
  }
  }
  
  if (digitalRead(BUTTON) == LOW && sequenceNumber == 11){
    long measurement =pulseIn (SENSOR, HIGH);
    Serial.println(measurement);
    if(measurement > 1000){
      player.stop();
      player.play(2);
      sequenceNumber = 0;
      digitalWrite(LEDRED, HIGH);
      digitalWrite(LEDRIGHT, HIGH);
      digitalWrite(LEDMIDDLE, HIGH);
      digitalWrite(LEDLEFT, HIGH);
      while(digitalRead(BUTTON)==LOW){
        delay(10000);
        player.stop();
        digitalWrite(LEDRED, LOW);
        digitalWrite(LEDRIGHT, LOW);
        digitalWrite(LEDMIDDLE, LOW);
        digitalWrite(LEDLEFT, LOW);
      }
    }else{
    Sequence(true, true, false);
    delay(time);
    sequenceNumber = 0;
    }
  }

   if (digitalRead(BUTTON) == HIGH) // toy is turned off
  {
    sequenceNumber = 0;
    player.stop();
    digitalWrite(LEDRED, LOW);
    digitalWrite(LEDRIGHT, LOW);
    digitalWrite(LEDMIDDLE, LOW);
    digitalWrite(LEDLEFT, LOW);
  }   
  
}
