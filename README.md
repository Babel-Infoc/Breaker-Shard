# Breaker-Shard

To upload this code to your Breaker Shard, first download and install the Arduino IDE
https://www.arduino.cc/en/software

Once installed and launched, we need to configure your Arduino IDE software for the RP2040 platform
  Click on Tools -> Board -> Boards Manager
  Search for "RP2040"
  Select "Arduino Mbed OS RP2040 Boards"
  Install the latest version

You will then need to install the Adafruit NeoPixel Library
  Click on Tools -> Manage Libraries
  Search for Adafruit NeoPixel, Select Adafruit NeoPixel (ignore other libraries that show up that arent named specifically named Adafruit NeoPixel)
  Install the latest version

You can now write your own code or modify the example code from this Repo

When you are ready to upload, plug your Breaker Shard into your computer
  Slide the power switch to Off
  Press and hold the Boot button
  Slide the power switch to On
Your computer should detect a new device connected called RPI-RP2
  In the Arduino IDE, click on Tools -> Boards -> Raspberry Pi RP2040 Boards
  Click on Raspberry Pi Pico
  Click the Arrow icon in the top left to compile and upload your code to the Breaker Shard
