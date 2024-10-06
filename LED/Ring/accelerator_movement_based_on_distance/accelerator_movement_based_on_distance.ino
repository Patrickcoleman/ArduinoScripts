#include <FastLED.h>

#define NUMPIXELS 24  // Number of pixels in the ring
#define DATA_PIN 9    // Pin to which the LED ring is connected
int largeposition = 0;
int ringsize = 24000;

double speedbase = 0;
int maxspeedbase = 8;
bool asc = true;

int speedupcounter = 0;
int speedupcountermax = 100;

// Define the LED array
CRGB leds[NUMPIXELS];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUMPIXELS); // Initialize the LED array
}

void loop() {
  move();
  changespeed();
  int pos = calculatepos();
  for (int i = 0; i < NUMPIXELS; i++) {
    if (i == pos) {
      leds[i] = CHSV(70-70*(speedbase/maxspeedbase), 255, 75); // Set pixel color based on hue
    } else {
      leds[i] = CHSV(160, 100, 0);
    } 
  }
  FastLED.show();  // Update the LED strip
  delay(1);       // Pause for a moment
}

void changespeed(){
  speedupcounter += 1;
  if (speedupcounter >= speedupcountermax) {
    if (asc) {
      speedbase += 0.2;
    } else {
      speedbase -= 0.2;
    }
    if (speedbase >= maxspeedbase || speedbase <= -maxspeedbase){
      asc = !asc;
    }
    speedupcounter = 0;
  }

}

void move() {
  largeposition += (speedbase*speedbase*speedbase);
  if (largeposition >= ringsize) {
    largeposition -= ringsize;
  } else if (largeposition < 0){
    largeposition += ringsize;
  }
}

int calculatepos() {
  int pos = (largeposition+500)/1000;
  if (pos == 24){
    pos = 0;
  }
  return pos;
}