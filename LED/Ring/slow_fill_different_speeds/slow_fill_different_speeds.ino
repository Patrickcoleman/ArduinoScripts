#include <FastLED.h>

#define NUMPIXELS 24
#define DATA_PIN 9 
float multis[4] = {1.1, 1.2, 1.3, 1.4};
const int streams = sizeof(multis)/sizeof(multis[0]);
float tracks[24][streams];

int basetime = 100;
int time = 0;

CRGB leds[NUMPIXELS];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUMPIXELS);
  for (int i = 0; i < 24; i++) {
    for (int j = 0; j < streams; j++){
      if (i==0){
        tracks[i][j] = basetime;
      } else {
        tracks[i][j] = tracks[i-1][j] * multis[j];
      }
    }
  }
}

void loop() {
  time += 10;
  for (int j = 0; j < 24; j++){
    if (tracks[j][3] <= time){
      leds[j] = CHSV(200, 150, 50);
    } else if (tracks[j][2] <= time){
      leds[j] = CHSV(150, 150, 50);
    } else if (tracks[j][1] <= time){
      leds[j] = CHSV(100, 150, 50);
    } else if (tracks[j][0] <= time){
      leds[j] = CHSV(50, 150, 50);
    } else {
      leds[j] = CHSV(0, 150, 50);
    }
  }
  FastLED.show();
  delay(10);
}

