#include <Adafruit_NeoPixel.h>

#include <DigiKeyboard.h>

const int LED = 1;
const int SWITCH = 2;

const int LEDS = 0;

const int NUM_LEDS = 6;

Adafruit_NeoPixel leds = Adafruit_NeoPixel(NUM_LEDS, LEDS, NEO_GRB + NEO_KHZ800);

void colour(uint8_t r, int8_t g, uint8_t b){
  for (int i = 0; i<= NUM_LEDS-1; i++){
    leds.setPixelColor(i, r, g, b);
  }
  leds.show();
}

uint8_t randcol(){
  return random(0, 127);
}

void leds_on(){
  int a,b,c;
  a = randcol() + 128;
  b = randcol();
  c = randcol();
  switch(random(0,3)){
    case 0:colour(a,b,c); break;
    case 1:colour(b,c,a); break;
    case 2:colour(c,a,b); break;
  }
}

void leds_off(){
  colour(0,0,0);
}

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED, OUTPUT);
  pinMode(SWITCH, INPUT);
  digitalWrite(SWITCH, HIGH);
  DigiKeyboard.update();
  leds.begin();
  leds_off();
}

volatile int blackhole;

int randkey(){
  return random(32, 127);
}

// the loop function runs over and over again forever
void loop() {
  blackhole = randkey(); //bad seeding
  if (digitalRead(SWITCH) == HIGH){
    DigiKeyboard.write(randkey());
    leds_on();
    delay(1000);
    leds_off();
  }
}
