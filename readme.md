# DialTeil

## Hardware:
-  [Digispark](http://digistump.com/products/1)
-  Rotary Encoder ; e.g [WayinTop KY-040](https://www.amazon.de/gp/product/B07T3672VK/)


## Wiring
Digispark| Rotary Encoder
-|-
P0|CLK OR DT
P1|SW
P2|DT OR CLK

My rotary encoder has an active low switch which is pulled up by an 10k ohm resistor.
Together with the build in led (connected also to pin 1) the Digispark detect always a low, doesn't matter the switch is pressed or not.

Here are two solutions:
- Replace the 10k ohm pull up switch resistor with a 1.5k ohm resistor on rotary encoder
- Desolder build in led on the digispark

<img src="https://raw.githubusercontent.com/fixItFab/DialTeil/master/assets/readme/rotary-encoder-pull-up.jpg" width="250" />


## Recommended Software
- VS-Code + Platformio Extension


## Flashing Preparation


### Clone this project
```bash 
git clone https://github.com/fixItFab/KeyBoardLight.git
``` 


### Download TrinketHidCombo 
TrinketHidCombo is not available on the platformio libraries.
So we have to download the TrinketHidCombo library manually.

**TLDR:**

```bash
curl -s -L -o trinket-usb.zip https://github.com/adafruit/Adafruit-Trinket-USB/archive/master.zip && unzip trinket-usb.zip && cp -R ./Adafruit-Trinket-USB-master/TrinketHidCombo ./lib/ && rm -rf ./trinket-usb.zip ./Adafruit-Trinket-USB-master ./lib/TrinketHidCombo/usbdrv/usbdrvasm.asm
```


1. Download [TrinketHidCombo Library](https://github.com/adafruit/Adafruit-Trinket-USB) from Github 
2. Unzip it
3. Copy only the `TrinketHidCombo` folder to your `lib` folder
4. The file `TrinketHidCombo/TrinketHidCombousbdrv/usbdrvasm.asm` maybe make trouble processing compiling & flashing. In short, delete the file, we don't need it! :)
5. clean up downloaded & unziped files


## Flashing & Testing
Now, you can start flashing.

First start the flash process and when the console print `Uploading .pio/build/digispark-tiny/firmware.hex`, plug the Digispark into the USB port

After flashing, the Digisparks reboot and after a few seconds, the DialTail is ready to use.



