#include <FastLED.h>

#define NUMPIXELS 24  // Number of pixels in the ring
#define DATA_PIN 9    // Pin to which the LED ring is connected
int pos = 0;
int speed = 1;
int stepsBeforeIncrease = 400;
int currentStep = 0;

// Define the LED array
CRGB leds[NUMPIXELS];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUMPIXELS);
}

void loop() {
  updatepos();
  updatespeed();
  for (int i = 0; i < NUMPIXELS; i++) {
    if (i == pos) {
      leds[i] = CHSV(220, 255, 100); // Set pixel color based on hue
    } else {
      leds[i] = CHSV(140, 255, 25);
    } 
  }

  FastLED.show();
  delay(30);
}

void updatespeed() {
  currentStep ++;
  if (currentStep == stepsBeforeIncrease) {
    speed ++;
    currentStep = 0;
  }
}

void updatepos() {
  pos += speed;
  while (pos >= 24) {
   pos -= 24; 
  }
}
