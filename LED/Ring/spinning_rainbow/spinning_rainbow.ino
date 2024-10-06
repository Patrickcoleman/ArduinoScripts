#include <FastLED.h>

#define NUMPIXELS 24  // Number of pixels in the ring
#define DATA_PIN 9    // Pin to which the LED ring is connected

// Define the LED array
CRGB leds[NUMPIXELS];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUMPIXELS); // Initialize the LED array
}

void loop() {
  for (long firstPixelHue = 0; firstPixelHue < 256; firstPixelHue += 1) {
    for (int i = 0; i < NUMPIXELS; i++) {
      // Calculate the hue for each pixel
      int pixelHue = firstPixelHue + (i * 256L / NUMPIXELS);
      leds[i] = CHSV(pixelHue, 255, 100); // Set pixel color based on hue
    }
    FastLED.show();  // Update the LED strip
    delay(1);       // Pause for a moment
  }
}

