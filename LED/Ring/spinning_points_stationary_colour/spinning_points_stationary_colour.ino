#include <FastLED.h>

#define NUMPIXELS 24
#define DATA_PIN 9
int pos = 0;
int points = 3;

CRGB leds[NUMPIXELS];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUMPIXELS);
}

void loop() {
  updatepos();
  for (int i = pos; i < pos + NUMPIXELS; i+=NUMPIXELS/points) {
    if (i >= 24) {
      leds[i-24] = CHSV((i*255)/NUMPIXELS, 255, 150);  
    } else {
      leds[i] = CHSV((i*255)/NUMPIXELS, 255, 150);
    }
  }
  fade_raw(leds, NUMPIXELS, 120);
  FastLED.show();
  delay(100);
}

void updatepos() {
  pos ++;
  if (pos >= 24){
    pos = 0;
  }
}