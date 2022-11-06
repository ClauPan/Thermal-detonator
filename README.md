# Thermal Detonator

********** 
GENERAL DESCRIPTION:

 The idea of this project is to replicate the looks of a detonator by using an Arduino microcontroller board. To this we connect a micro switch, DFPlayer Mini module (to witch the speaker is connected) and LEDs such that when the switch is pressed, the LEDs will light up in a specific order as well as the speaker will be emitting a particular sound, both of this signifying the start of an arming sequence for a detonator. We will also connect to the Arduino microcontroller a vibration/ movement sensor module SW-420, so that when the detonator is thrown and it hits an object, the previous sequence will change, meaning the LED’s will all be on at the same time and the speaker will emit an explosion sound.
********** 
--------------------------------------------- 
SOFTWARE DESIGN

-Development environments used: ArduinoIDE

-Used libraries: 

  SoftwareSerial.h / https://docs.arduino.cc/learn/built-in-libraries/software-serial

  DFRobotDFPlayerMini.h / https://github.com/DFRobot/DFRobotDFPlayerMini
