#include <Keyboard.h>
#include <KeyboardLayout.h>
#include <Keyboard_da_DK.h>
#include <Keyboard_de_DE.h>
#include <Keyboard_es_ES.h>
#include <Keyboard_fr_FR.h>
#include <Keyboard_hu_HU.h>
#include <Keyboard_it_IT.h>
#include <Keyboard_pt_PT.h>
#include <Keyboard_sv_SE.h>


const int buzzer = 8;
const int sensor0Pin = A0; // Analog pin for first flex sensor
const int sensor1Pin = A1; // Analog pin for second flex sensor
const int sensor2Pin = A2; // Analog pin for third flex sensor
const int threshold0 = 60; // Threshold value for flex sensor 0 readings
const int threshold1 = 70; // Threshold value for flex sensor 1 readings
const int threshold2 = 320; // Threshold value for flex sensor 2 readings

bool numericalMode = false; // Flag to indicate numerical mode

void setup() {
  Keyboard.begin(); // Initialize Keyboard library
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600); // Enable serial communication for debugging (optional)
}

void loop() {
  int sensor0Value = analogRead(sensor0Pin);
  int sensor1Value = analogRead(sensor1Pin);
  int sensor2Value = analogRead(sensor2Pin);

  Serial.print("Sensor 0: ");
  Serial.print(sensor0Value);
  Serial.print(" | Sensor 1: ");
  Serial.print(sensor1Value);
  Serial.print(" | Sensor 2: ");
  Serial.println(sensor2Value);

    // Phrase mode actions (unchanged)
    if (sensor2Value <= threshold2) {
    tone(buzzer, 5000); // Send 1KHz sound signal...
    delay(100);
    Keyboard.print("python lessons");
    noTone(buzzer);  

    } 
    else if (sensor0Value < threshold0) {
    tone(buzzer, 5000); // Send 1KHz sound signal...
    delay(100);
    Keyboard.print("youtube.com");
    noTone(buzzer); 
    } 
    else if (sensor1Value < threshold1) {
    tone(buzzer, 5000); // Send 1KHz sound signal...
    delay(100);
    Keyboard.press(KEY_RETURN);
    delay(50);  // Hold for a brief time
    Keyboard.releaseAll();
    noTone(buzzer);
    }

  delay(1000); // Delay to prevent rapid keystrokes
}
