// Written by Barnaby Collins, 2020

#include <FastLED.h>

#define LED_PIN 2
#define NUM_LEDS 125
#define LAYER_SIZE 25
#define FPS 10
#define BRIGHTNESS 255

CRGB leds[NUM_LEDS];
unsigned long lastMillis;
int numLayers;

// stores information about the peaks to be run - for each one:
// - max height
// - time
// - current step
float peaks[LAYER_SIZE][3];

void setup() {
  Serial.begin(9600);
  delay(3000);
  FastLED.addLeds<PL9823, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  numLayers = NUM_LEDS / LAYER_SIZE;
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis != lastMillis && currentMillis % (int) (1000/FPS) == 0) {
    lastMillis = currentMillis;
    
    for (int i = 0; i < LAYER_SIZE; i++) {
      if (peaks[i][2] >= peaks[i][1]) {
        peaks[i][0] = random(10, 51)/10;
        peaks[i][1] = random(FPS/2, FPS*2);
        peaks[i][2] = 0;
      }

      int p = peaks[i][1]*2;
      float a = peaks[i][0];
      float x = peaks[i][2];
      // https://en.wikipedia.org/wiki/Triangle_wave
      float curHeight = ((2*a)/p) * abs(fmod((x - p/4), p) - p/2) - a/2;
      int curLED = 0;
      while (curHeight != 0) {
        float value = min(curHeight, 1);
        leds[25 * curLED + i] = CRGB(value * 255, value * 255, value * 255);
        curHeight -= value;
        curLED += 1;
      }
      while (curLED < numLayers) {
        leds[25 * curLED + i] = CRGB(0, 0, 0);
        curLED += 1;
      }
      
      peaks[i][2] += 1;
    }
    FastLED.show();
  }
}
