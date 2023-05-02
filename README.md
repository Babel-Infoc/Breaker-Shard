# Breaker-Shard

To upload this code to your Breaker Shard, first download and install the Arduino IDE
https://www.arduino.cc/en/software

Once installed and launched, we need to configure your Arduino IDE software for the RP2040 platform
Go to Preferences, and look for "Additional Boards Manager URLs"
Paste the following link
https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json
Hit Ok to close Preferences
Next, click on Tools -> Board -> Boards Manager
Search for Raspberry Pi Pico/RP2040
Select Raspberry Pi Pico/RP2040 by Earle F. Philhower
Install the latest version

You will then need to add the Adafruit NeoPixel Library
At the top of the window, click on Tools -> Manage Libraries
Search for Adafruit NeoPixel, Select Adafruit NeoPixel (ignore other libraries that show up that arent named specifically Adafruit NeoPixel)
Install the latest version

You can now write your own code or modify the example code from this Repo

When you are ready to upload, plug in your Breaker Shard to your computer
Slide the power switch to Off, press and hold the Boot button, then switch it back on. Your computer should detect a new device connected called RPI-PR2
In the Arduino IDE, click on Tools -> Boards -> Raspberry Pi RP2040 Boards
Click on Raspberry Pi Pico
Click the Arrow icon in the top left to verify your code and upload
