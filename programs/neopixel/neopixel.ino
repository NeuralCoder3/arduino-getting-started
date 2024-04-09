#include <FastLED.h>

#define NUM_LEDS 10
#define LED_PIN 2

CRGB led[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, LED_PIN>(led,NUM_LEDS);
  for(int i=0;i<NUM_LEDS;i++) {
    led[i] = CRGB(0,0,0);
  }
  FastLED.show();
}

void loop() {
  for(int h=0;h<2*256;h++) {
    // breath mode for first seven LEDs
    for(int i=0;i<7;i++) {
      led[i] = CRGB(abs(255-h),0,0);
    }
    FastLED.show();
    delay(10);
  }
}
