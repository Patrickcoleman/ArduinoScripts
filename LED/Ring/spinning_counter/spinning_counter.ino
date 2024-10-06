#include <FastLED.h>

#define NUMPIXELS 24  // Number of pixels in the ring
#define DATA_PIN 9    // Pin to which the LED ring is connected
int unlocked = 0;
int pos = 0;
// int colour = 0;

CRGB leds[NUMPIXELS];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUMPIXELS); // Initialize the LED array
}

void loop() {
  pos += 1;
  if (pos > unlocked) {
    pos = 0;
    unlocked += 1;
    // colour += 10;
  }

  if (unlocked >= 24) {
    unlocked = 0;
    pos = 0;
  }
  for (int i = 0; i < NUMPIXELS; i++) {
    if (i <= pos) {
      leds[i] = CHSV(220, 255, 50);
    } else if (i <= unlocked) {
      leds[i] = CHSV(200, 255, 30);
    } else {
      leds[i] = CHSV(140, 255, 10);
    } 
  }
  FastLED.show();
  delay(100);
}