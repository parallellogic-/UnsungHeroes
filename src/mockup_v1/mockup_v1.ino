#include <Adafruit_NeoPixel.h>
#define PIN 6
#define NUM_LEDS 8

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);
const int scale=4;
int delay_ms[3]={171/scale,331/scale,579/scale};

void setup() {
  pinMode(13,OUTPUT);
  pinMode(4,INPUT_PULLUP);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  // Set all 8 LEDs to green
  for(int iter_color=0;iter_color<3;iter_color++)
  {
    delay_ms[iter_color]=analogRead(iter_color)/8;
  }

  for(int i=0; i<NUM_LEDS; i++) {
    int color[3];
    for(int iter_color=0;iter_color<3;iter_color++)
    {
      int out_idx=iter_color;
      if(!digitalRead(4)) out_idx=(out_idx+i)%3;
      color[out_idx]=(((millis()/delay_ms[iter_color])+i)%16>8)*255;
    }
    strip.setPixelColor(i, strip.Color(color[0], color[1], color[2])); 
  }
  strip.show();
}