#include <FastLED.h>

#define LED_PIN 2
#define NUM_LEDS 125
#define LAYER_SIZE 25
#define FPS 120

CRGB leds[NUM_LEDS];
unsigned long lastMillis;
int numLayers;

// stores information about the peaks to be run - for each one:
// - max height
// - time
// - current step
// - 
int peaks[LAYER_SIZE][3];

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  numLayers = NUM_LEDS / LAYER_SIZE;
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis != lastMillis && currentMillis % floor(1000/FPS) == 0) {
    lastMillis = currentMillis;
    for (int i = 0; i <= LAYER_SIZE; i++) {
      
    }
  }
}
