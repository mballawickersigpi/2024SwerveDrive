#include "FastLED.h"

#define LED_PIN 7
#define NUM_LEDS 60

CRGB leds[NUM_LEDS];

const unsigned long MAX_MESSAGE_LENGTH = 20;

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  set_leds(100, 100, 100);
}

void loop() {
  //Check to see if anything is available in the serial receive buffer
  while (Serial.available() > 0) {
    //Create a place to hold the incoming message
    static char message[MAX_MESSAGE_LENGTH];
    static unsigned int message_pos = 0;

    //Read the next available byte in the serial receive buffer
    char inByte = Serial.read();

    //Message coming in (check not terminating character) and guard for over message size
    if (inByte != '\n' && (message_pos - MAX_MESSAGE_LENGTH - 1)) {
      //Add the incoming byte to our message
      message[message_pos] = inByte;
      message_pos++;
    } else {
      //Add null character to string
      message[message_pos] = '\0';
      //Print the message (or do other things)
      String command = message;

      int index = command.substring(command.indexOf("i") + 1, command.indexOf("r")).toInt();
      int red = command.substring(command.indexOf("r") + 1, command.indexOf("g")).toInt();
      int green = command.substring(command.indexOf("g") + 1, command.indexOf("b")).toInt();
      int blue = command.substring(command.indexOf("b") + 1).toInt();
      
      if(index == -1) {
        set_leds(red, green, blue);
      } else {
        leds[index] = CRGB(red, green, blue);
        FastLED.show();
      }
      
      //Reset for the next message
      message_pos = 0;
    }
  }
}

void set_leds(unsigned int r, unsigned int g, unsigned int b) {  //this does block execution but its probably fine for now
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(r, g, b);
  }
  FastLED.show();
}