//Code pulled from https://arduinogetstarted.com/tutorials/arduino-ultrasonic-sensor
//Code pulled from Strandtest.ino example

#include <Adafruit_NeoPixel.h>


int Trigger = 12; //defining pins for interface
int Echo = 9;
int led = 6; // pinout for led data pin
int led_count = 36;
int intensity = 5;
float duration, distance; //defining variable for calculations

Adafruit_NeoPixel strip(led_count, led, NEO_GRB + NEO_KHZ800); //sets up strip

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //for us to view values
  pinMode(Trigger, OUTPUT); //defining the Trigger pin to be an output
  pinMode(Echo, INPUT); //defining the Echo pin to be an input

  strip.begin();
  strip.show();
  strip.setBrightness(intensity);
  uint32_t color = strip.Color(255,0,255); //purple
  for(int c=0; c<strip.numPixels(); c++) {
        strip.setPixelColor(c, color); // Set pixel 'c' to value 'color'
  }
  strip.show();
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);


  duration = pulseIn(Echo, HIGH);
  distance = 0.017 * duration; //This calculated the distance in cm

  intensity = (1/distance)*255;
  strip.setBrightness(intensity);
  strip.show();
  Serial.print("distance: "); //prints out the distance to the serial monitor
  Serial.print(distance);
  Serial.println(" cm");

  delay(500); //wait for 500 milliseconds
}
