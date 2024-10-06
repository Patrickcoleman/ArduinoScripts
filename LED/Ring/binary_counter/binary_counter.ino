#include <FastLED.h>

#define NUMPIXELS 24  // Number of pixels in the ring
#define DATA_PIN 9    // Pin to which the LED ring is connected
bool lit[24];

// Define the LED array
CRGB leds[NUMPIXELS];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUMPIXELS); // Initialize the LED array
  for (int i = 0; i < 24; i++) {
    lit[i] = false;
  }
}

void loop() {
  for (int i = 0; i < 24; i++) {
    lit[i] = !lit[i];
    if (lit[i]){
      break;
    }
  }

  for (int i = 0; i < NUMPIXELS; i++) {
    if (lit[i]) {
      leds[i] = CHSV(140, 150, 40);
    } else {
      leds[i] = CHSV(100, 0, 0);
    } 
  }
  FastLED.show();  // Update the LED strip
  delay(100);       // Pause for a moment
}