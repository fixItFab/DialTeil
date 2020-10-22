#include <Arduino.h>
#include "DigiKeyboard.h"
#include <RotaryEncoder.h>

// Use in 0 & 2 for rotary encoder on Digispark, otherwise the rotary wont't detect correctly
RotaryEncoder encoder(0, 2);

bool first = true;

void setup()
{
  // Send empty KetStroke and wait 2 seconds. Why?
  // On the first time sending key stroke, macbook sends adds an fn.
  // eg. send KEY_F12, the input is FN + KEY_F12
  DigiKeyboard.sendKeyStroke(0);
  delay(2000);
}

void loop()
{
  static int pos = 0;
  encoder.tick();

  int newPos = encoder.getPosition();
  if (pos != newPos)
  {
    if (newPos > pos)
    {
      DigiKeyboard.sendKeyStroke(KEY_F12);
    }
    else
    {
      DigiKeyboard.sendKeyStroke(KEY_F11);
    }

    pos = newPos;
  }
}