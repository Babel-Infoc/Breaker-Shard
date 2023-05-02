<body>
	<div class="container">
	<header>
		<div class="header">
			<h1>Breaker Shard IDE setup</h1>
		</div>
	</header>
		<div class="main">
			<h2>To upload code to your Breaker Shard, first download and install the Arduino IDE
      </h2>
      <a href="https://www.arduino.cc/en/software">Arduino IDE Software</a>
		</div>
		<div class="feature">
			<h3>Board Manager</h3>
			<p>Once installed and launched, we need to configure your Arduino IDE software for the RP2040 platform<br>
        &emsp;Click on Tools -> Board -> Boards Manager<br>
        &emsp;Search for "RP2040"<br>
        &emsp;Select "Arduino Mbed OS RP2040 Boards"<br>
        &emsp;Install the latest version<br></p>
		</div>
		<div class="feature">
			<h3>Neopixel Library</h3>
			<p>You will then need to install the Adafruit NeoPixel Library<br>
        &emsp;1. Click on Tools -> Manage Libraries<br>
        &emsp;2. Search for Adafruit NeoPixel, Select Adafruit NeoPixel<br>
        &emsp;<i>(ignore other libraries that show up that arent named specifically named Adafruit NeoPixel)</i><br>
        &emsp;3. Install the latest version<br></p>
		</div>
    <div class="feature">
			<h3>Upload code</h3>
			<p>When you are ready to upload, plug your Breaker Shard into your computer<br><br>
        &emsp;1. Slide the power switch to Off<br>
        &emsp;2. Press and hold the Boot button<br>
        &emsp;3. Slide the power switch to On<br>
        &emsp;<i>Your computer should detect a new device connected called <b>RPI-RP2</b></i><br>
        &emsp;4. In the Arduino IDE, click on Tools -> Boards -> Raspberry Pi RP2040 Boards<br>
        &emsp;5. Click on Raspberry Pi Pico<br>
        &emsp;6. Click the Arrow icon in the top left to compile and upload your code to the Breaker Shard<br></p>
		</div>
	<footer>
		#babelinfocalypse
	</footer>
	</div>
</body>
</html>
