#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 21

#define DATA_PIN 3

// Define the array of leds
CRGB leds[NUM_LEDS];

int led = -1;      // which LED to light up in our background animation
int sensorLED;     // which LED to light up in response to sensor

void setup() {
  // GRB ordering is assumed
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);

  Serial.begin(57600);
}

void loop() {
  
  // SENSOR CONTROLLED MOVING DOT (on top of the animation):
  int val = analogRead(A0);
  // A pot would be mapped from 0-1023, but an IR distance sensor might be 5-695
  sensorLED = map(val,  0, 1023,  0, NUM_LEDS);   

  // make sure numbers stay within range:
  sensorLED = constrain(sensorLED, 0, NUM_LEDS);

  Serial.print(val);
  Serial.print(" = ");
  Serial.println(sensorLED);

  leds[sensorLED] = CRGB::Green;
  FastLED.show();

  // clear that LED for next time, but don't show right away
  leds[sensorLED] = CRGB::Black;


  // background animation, increment a dot through the whole strip:
  EVERY_N_MILLISECONDS(100) {       // change number to speed up or slow down
    // clear the *most recent* LED
    leds[led] = CRGB::Black;
    
    // increment to next LED
    led = led + 1;
    if (led > NUM_LEDS) led = 0;    // at the end of the strip, go back to the start
    leds[led] = CRGB::Blue;
  }

}
