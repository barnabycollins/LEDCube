#include <FastLED.h>
#define DATA_PIN 2
#define LED_TYPE WS2812
#define COLOR_ORDER GRB
#define NUM_LEDS 125
#define analogin A0
CRGB leds[NUM_LEDS];
int BRIGHTNESS;
int i;
int x;
int y;

void setup() {
  FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
  x=0;
  y=200;
}

void loop() {
  BRIGHTNESS=map(analogRead(analogin),0,1023,0,255);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear();
  for (i=(0+x);i<(25+x);i++){
  leds[i] = CRGB::Red;}
  FastLED.show();
  x=x+25;
  if (x>=125){
    x=0;
    y=y-10;}
  if(y==10){y=200;}
  delay(y);
  

}
