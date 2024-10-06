#include <FastLED.h>

#define NUMPIXELS 24  // Number of pixels in the ring
#define DATA_PIN 9    // Pin to which the LED ring is connected
int fox = 0;
int foxmove = 0;
bool foxmoving = true;
int rabbit = 12;
int rabbitmove = 0;

// Define the LED array
CRGB leds[NUMPIXELS];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUMPIXELS); // Initialize the LED array
  randomSeed(analogRead(0));
}

void loop() {
  if (foxmoving){
    movefox();
  }
  foxmoving = !foxmoving;
  moverabbit();
  for (int i = 0; i < NUMPIXELS; i++) {
    // Calculate the hue for each pixel
    if (i == fox) {
      leds[i] = CHSV(30, 255, 100); // Set pixel color based on hue
    } else if (i == rabbit) {
      leds[i] = CHSV(0, 0, 50);
    } else {
      leds[i] = CHSV(100, 255, 30);
    } 
  }
  FastLED.show();  // Update the LED strip
  delay(100);       // Pause for a moment
}

void movefox() {
  if (foxmove == 0){
    if (random(4) == 1){
      foxmove = random(-10, 11);
    }
  } else if(foxmove > 0){
    fox -= 1;
    foxmove -= 1;
  } else {
    fox += 1;
    foxmove += 1;
  }

  if (fox < 0) {
    fox = 23;
  } else if (fox > 23) {
    fox = 0;
  }
}

void moverabbit(){
  if (fox == rabbit - 3 || fox == rabbit + 21){
    rabbitmove = -5;
  } else if (fox == rabbit + 3 || fox == rabbit -21) {
    rabbitmove = 5;
  }


  if (rabbitmove > 0) {
    rabbit -= 1;
    rabbitmove -= 1;
  } else if (rabbitmove < 0){
    rabbit += 1;
    rabbitmove += 1;
  }

  if (rabbit < 0) {
    rabbit = 23;
  } else if (rabbit > 23) {
    rabbit = 0;
  }
}

