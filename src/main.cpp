#include <Arduino.h>
#include "TrinketHidCombo.h"
#include <RotaryEncoder.h>
#include "OneButton.h"

#define PIN_ENCODER_A 2
#define PIN_ENCODER_B 0
#define PIN_ENCODER_SWITCH 1

RotaryEncoder encoder(PIN_ENCODER_A, PIN_ENCODER_B);
OneButton button(PIN_ENCODER_SWITCH, true);

void click();

void setup()
{
  TrinketHidCombo.begin();
  button.attachClick(click);
}

void loop()
{
  static int pos = 0;
  encoder.tick();
  button.tick();

  int newPos = encoder.getPosition();
  if (pos != newPos)
  {
    if (newPos > pos)
    {
      TrinketHidCombo.pressMultimediaKey(MMKEY_VOL_UP);
    }
    else
    {
      TrinketHidCombo.pressMultimediaKey(MMKEY_VOL_DOWN);
    }

    pos = newPos;
  }
}

void click()
{
  TrinketHidCombo.pressMultimediaKey(MMKEY_MUTE);
}