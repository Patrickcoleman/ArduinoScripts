#include <FastLED.h>

#define NUMPIXELS 24
#define DATA_PIN 9
int pos = 0;
int points = 2;
int startingcolour = 0;

CRGB leds[NUMPIXELS];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUMPIXELS);
}

void loop() {
  updatepos();
  fade_raw(leds, NUMPIXELS, 50);
  startingcolour ++;
  int point = 0;
  for (int i = pos; i < pos + NUMPIXELS; i+=NUMPIXELS/points) {
    if (i >= 24) {
      leds[i-24] = CHSV(startingcolour + point*255/points, 255, 75);  
    } else {
      leds[i] = CHSV(startingcolour + point*255/points, 255, 75);
    }
    point ++;
  }
  FastLED.show();
  delay(100);
}

void updatepos() {
  pos ++;
  if (pos >= 24){
    pos = 0;
  }
}