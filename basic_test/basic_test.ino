#include <FastLED.h>

CRGB leds[125];

void setup() {
  Serial.print("Hello");
  delay(3000);
  FastLED.addLeds<PL9823, 2>(leds, 125);
  for (int i = 0; i < 125; i++) {
    leds[i] = CRGB(random(256), random(256), random(256));
  }
  FastLED.show();
}

void loop() {
  for (int i = 0; i < 125; i++) {
    leds[i] = CRGB(random(256), random(256), random(256));
  }
  FastLED.show();

}
