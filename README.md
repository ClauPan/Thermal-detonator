# Thermal Detonator

********** 
GENERAL DESCRIPTION

 The idea of this project is to replicate the looks of a detonator by using an Arduino microcontroller board. To this we connect a micro switch, DFPlayer Mini module (to witch the speaker is connected) and LEDs such that when the switch is pressed, the LEDs will light up in a specific order as well as the speaker will be emitting a particular sound, both of this signifying the start of an arming sequence for a detonator. We will also connect to the Arduino microcontroller a vibration/ movement sensor module SW-420, so that when the detonator is thrown and it hits an object, the previous sequence will change, meaning the LED’s will all be on at the same time and the speaker will emit an explosion sound.
********** 
COMPONENTS

Arduino Pro Mini

Vibration Sensor Module SW-420	

DFPlayer Mini

Speaker

Red LED

Yellow LEDs

100 Ohm Resistor

1k Ohm Resistor

Microswitch

Switch

9V Battery

********** 
SOFTWARE DESIGN

-Development environments used: ArduinoIDE

-Used libraries: 

  SoftwareSerial.h / https://docs.arduino.cc/learn/built-in-libraries/software-serial

  DFRobotDFPlayerMini.h / https://github.com/DFRobot/DFRobotDFPlayerMini

********** 
RESOURCES

-SW-420 Vibration Sensor Module / https://components101.com/sensors/sw-420-vibration-sensor-module
-Arduino Pro Mini / https://docs.arduino.cc/retired/boards/arduino-pro-mini
-Arduino Pro Mini / https://cdn.sparkfun.com/datasheets/Dev/Arduino/Boards/ProMini16MHzv1.pdf
-DFR0299 DFPlayer Mini / https://wiki.dfrobot.com/DFPlayer_Mini_SKU_DFR0299


