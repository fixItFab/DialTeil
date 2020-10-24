#include <Arduino.h>
#include "TrinketHidCombo.h"
#include <RotaryEncoder.h>

// Use in 0 & 2 for rotary encoder on Digispark, otherwise the rotary wont't detect correctly
RotaryEncoder encoder(0, 2);

void setup()
{
  TrinketHidCombo.begin();
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
      // DigiKeyboard.sendKeyStroke(KEY_VOLUME_UP);
      TrinketHidCombo.pressMultimediaKey(MMKEY_VOL_UP);
    }
    else
    {
      TrinketHidCombo.pressMultimediaKey(MMKEY_VOL_DOWN);
    }

    pos = newPos;
  }
}