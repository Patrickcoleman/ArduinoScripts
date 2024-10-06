#include <FastLED.h>

#define NUMPIXELS 24  // Number of pixels in the ring
#define DATA_PIN 9    // Pin to which the LED ring is connected
int litpixel = 0;
int timedelay = 150;
int delaycounter = 1;
bool desc = true;

// Define the LED array
CRGB leds[NUMPIXELS];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUMPIXELS); // Initialize the LED array
}

void loop() {
  move_litpixel();
  update_delay();
  for (int i = 0; i < NUMPIXELS; i++) {
    // Calculate the hue for each pixel
    if (i == litpixel) {
      leds[i] = CHSV(timedelay/2, 255, 150); // Set pixel color based on hue
    } else {
      leds[i] = CHSV(160, 255, 30);
    } 
  }
  FastLED.show();  // Update the LED strip
  delay(timedelay);       // Pause for a moment
}

void move_litpixel(){
  litpixel += 1;
  if (litpixel > 23) {
    litpixel = 0;
  }
}

void update_delay(){
  delaycounter -= 1;
  if (delaycounter <= 0){
    if (desc) {
      timedelay -= 1;
    } else {
      timedelay += 1;
    }
    if (timedelay <= 2 or timedelay > 150){
      desc = !desc;
    }
    delaycounter = 100/timedelay;
  }
}