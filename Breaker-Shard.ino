/*
 * This code is shared under a Creative Commons license
 * Attribution-NonCommercial-ShareAlike 4.0 International
 * https://creativecommons.org/licenses/by-nc-sa/4.0/
 * 
 * TLDR; You can remix and share this code with others.
 * You must give appropriate credit, provide a link to the license, and indicate if changes were made.
 * You may not use the material for commercial purposes.
 * If you remix, transform, or build upon the material, you must distribute your contributions
 * under the same license.
*/

//////////////////////////////////////////////////////////

// Breaker Shard 1.0 setup

#include <Adafruit_NeoPixel.h>
#define NUM_LEDS 12
Adafruit_NeoPixel strip(NUM_LEDS, 10, NEO_GRB + NEO_KHZ800);

#define brightness 1
#define magic_fix_code_juice 255
#define flaot float

// Animation values

#define SPEED 40          // Miliseconds between updates, larger numbers make for slower, jerkier animations
#define SHADERSPEED 0.2   // shadertoy shit needs lower numbers to go slower

uint32_t flash    = strip.Color( 200,   0,   0);    // Default flasher colour, medium red
uint32_t flash2   = strip.Color(   0, 100, 150);    // Sparkle colour, teal
uint32_t bg       = strip.Color(   0,   1,   5);    // Default background colour, dim blue
uint32_t arcwash1 = strip.Color(  30,  30,  80);    // Cool white
uint32_t arcwash2 = strip.Color( 200,   0,  10);    // Magenta
uint32_t strobe   = strip.Color( 100, 100, 100);    // Full send

uint32_t anodize[10]={
strip.Color(100, 80, 10),
strip.Color(100, 20,  5),
strip.Color(100, 20,  5),
strip.Color( 75, 10,  5),
strip.Color( 50,  5,  5),
strip.Color( 25,  0,  5),
strip.Color( 20,  0, 10),
strip.Color( 15,  0, 20),
strip.Color( 10,  0, 25),
strip.Color(  0,  0, 30),
};

uint32_t bisexual[10]={
strip.Color( 50, 50, 50),
strip.Color( 50,  0, 50),
strip.Color(  1,  0,  1),
strip.Color( 40,  0, 20),
strip.Color( 10,  0,  8),
strip.Color(  5,  0,  2),
strip.Color(  2,  0,  0),
strip.Color( 20,  0, 40),
strip.Color(  8,  0, 10),
strip.Color(  2,  0,  5),
};

void setup() {
  strip.begin();           // Initialise LED's (do not remove this)
  strip.show();            // Reset all pixels
}

// End Setup

/////////////////////////////////////////////////////////

// Main operational loop

void loop() {
  glitchblink2(60);
  ripples_abberation(40000); // Time to run in ms
  anodizemirrorwipe(10);
  anodizepixelmirror(60);
  anodizemirrorwipe(10);
  anodizepixelmirror(60);
  anodizemirrorwipe(10);
  anodizepixelmirror(60);
  ripples_tron(40000);
  megastrobe(2);
  anodizemirrorwipe(10);
  anodizepixelmirror(60);
  anodizemirrorwipe(10);
  anodizepixelmirror(60);
  anodizemirrorwipe(10);
  anodizepixelmirror(60);
  ripples_heat(40000);
  bisexualpixelmirror(60);
  
}

/////////////////////////////////////////////////////////

// Subroutines

// Randomly flashes a group of 3 LED's red
void glitchblink(int cycle) {
  for(int a=0; a<cycle; a++) {
    int r= random(1,11); //Select a random starting point
    strip.setPixelColor(r, flash);
    strip.setPixelColor(r+1, flash);
    strip.setPixelColor(r-1, flash);
    strip.show();
    delay((SPEED)*2);

    strip.fill(bg);
    strip.show();
    delay((SPEED));
  }
}

void glitchblink2(int cycle) {
  for(int i=0; i<(strip.numPixels())/2; i++) { 
        strip.setPixelColor((5-i), bg);
        strip.setPixelColor((6+i), bg);
        strip.show();
        delay(SPEED);
      }
  for(int a=0; a<cycle; a++) {
    strip.setPixelColor(random(0,12), flash2);
    strip.show();
    delay(10);
    background();
    strip.show();
    delay(SPEED);
  }
}

void wipe(int cycle) {
  for(int a=0; a<cycle; a++) {
    for(int i=0; i<strip.numPixels(); i++) { 
      strip.setPixelColor(i, arcwash1);
      strip.show();
      delay(SPEED);
    }
      for(int i=0; i<strip.numPixels(); i++) { 
      strip.setPixelColor(i, arcwash2);
      strip.show();
      delay(SPEED);
    }
  }
}

void megastrobe(int cycle) {
  for(int a=0; a<cycle; a++) {
    strip.fill(strobe);
    strip.show();
    delay((SPEED)/2);
    strip.fill(bg);
    strip.show();
    delay((SPEED)/2);
    strip.fill(strobe);
    strip.show();
    delay((SPEED)/2);
    strip.fill(bg);
    strip.show();
    delay((SPEED)/2);
  }
}

// get rid of this later
void background() {
  strip.fill(bg);
  strip.show();
  delay(SPEED);
}

void anodizepixel(int cycle) {
  for(int a=0; a<cycle; a++) {
    int i= random(0,11);
    int c= random(0,11);
    strip.setPixelColor(i, anodize[c]);
    strip.show();
    delay(SPEED);
  }
}

void bisexualpixel(int cycle) {
  for(int a=0; a<cycle; a++) {
    int i= random(0,11);
    int c= random(0,11);
    strip.setPixelColor(i, bisexual[c]);
    strip.show();
    delay(SPEED);
  }
}

void anodizepixelmirror(int cycle) {
  for(int a=0; a<cycle; a++) {
    int i= random(0,5);
    int c= random(0,11);
    strip.setPixelColor((5-i), anodize[c]);
    strip.setPixelColor((6+i), anodize[c]);
    strip.show();
    delay(SPEED);
  }  
}

void bisexualpixelmirror(int cycle) {
  for(int a=0; a<cycle; a++) {
    int i= random(0,5);
    int c= random(0,11);
    strip.setPixelColor((5-i), bisexual[c]);
    strip.setPixelColor((6+i), bisexual[c]);
    strip.show();
    delay(SPEED);
  }  
}

void anodizemirrorwipe(int cycle) {
  for(int a=0; a<cycle; a++) {
    int r= random(0,5);
    int c= random(1,10);
    int d= random(0,1);

    if (d==0){
      for(int i=r; (i+r)<(strip.numPixels())/2; i++) { 
        strip.setPixelColor((5-i), anodize[c]);
        strip.setPixelColor((6+i), anodize[c]);
        strip.show();
        delay(SPEED);
      }
    }else{
      for(int i=r; (i+r)<(strip.numPixels())/2; i++) { 
        strip.setPixelColor((0+i), anodize[c]);
        strip.setPixelColor((11-i), anodize[c]);
        strip.show();
        delay(SPEED);
      }
    }
  }
}

void bisexualmirrorwipe(int cycle) {
  for(int a=0; a<cycle; a++) {
    int r= random(0,5);
    int c= random(0,11);
    int d= random(0,1);

    if (d==0){
      for(int i=r; (i+r)<(strip.numPixels())/2; i++) { 
        strip.setPixelColor((5-i), bisexual[c]);
        strip.setPixelColor((6+i), bisexual[c]);
        strip.show();
        delay(SPEED);
      }
    }else{
      for(int i=r; (i+r)<(strip.numPixels())/2; i++) { 
        strip.setPixelColor((0+i), bisexual[c]);
        strip.setPixelColor((11-i), bisexual[c]);
        strip.show();
        delay(SPEED);
      }
    }
  }
}


/////////////////////////////////////////////////////////
void ripples_abberation(uint32_t runtime_ms) { // give it a runtime instead of a cycle count?
  uint32_t start_time = millis();

  while( millis() < start_time +runtime_ms ) {

    for(int i=0; i<NUM_LEDS; i++){
      float x,y;
      float time = SHADERSPEED * millis() / 1000.0;
      locatepixel_abberation(i, x, y);
      uint32_t c = shader_abberation(x, y, time);
      strip.setPixelColor(i, c);
    }
    // write to strip
    strip.show();
  }
}

// compute the real-space coordinates of the pixel
void locatepixel_abberation(int i, float &x, float &y) {
  y = float(i + 0.5) / float(NUM_LEDS);
  float scale=0.5;
  y = ((y-0.5)*scale)+0.5;  // reduce the size of the pixel strip in the animation space
  x = 0.5;
}

/*
float locations[NUM_LEDS][2] = {
//  X , Y
  { 0 , 0},
  { 0 , 0},
  { 0 , 0},
  { 0 , 0},
  { 0 , 0},
  { 0 , 0},
};
*/

// shader language builtin functions
float length_abberation(float x, float y, float z = 0.0){
  return sqrt(x*x + y*y + z*z);
}
float mod_abberation(float x, float y){
  return x - y * floor(x/y);
}

// The animation
// https://www.shadertoy.com/view/XsXXDn
// http://www.pouet.net/prod.php?which=57245
// Credits to Danilo Guanabara
uint32_t shader_abberation(float x, float y, float t) {
  // #define t iTime
  
  float c[3];   //vec3 c;
  float l, z=t;
  for(int i=0; i<3; i++) {
    float uv[2];
    float p[2];
    p[0] = x;  // = fragCoord.xy/r;
    p[1] = y;  // = fragCoord.xy/r;
    //uv=p
    uv[0] = p[0];
    uv[1] = p[1];

    p[0] -= .5;
    p[1] -= .5;
    z += 0.07; // ¯\_(ツ)_/¯
    l = length_abberation(p[0], p[1]);
    uv[0] += p[0] / l * (sin(z)+1.) * abs(sin(l*9.-z-z));
    uv[1] += p[1] / l * (sin(z)+1.) * abs(sin(l*9.-z-z));
    c[i] = 0.01 / length_abberation(mod_abberation(uv[0],1.) - 0.5, mod_abberation(uv[1],1.) - 0.5); // Here be dragons
  }

  //fragColor = vec4(c/l,t);

  float hue_abberation[3][3]={
    {  1,  1,0.1},  // R,G,B
    {0.1,  1,0.7},  // R,G,B
    {0.7,  1,  1}   // R,G,B
  };

  uint8_t r = float(brightness) * (
    hue_abberation[0][0] * c[0]/l +
    hue_abberation[0][1] * c[1]/l +
    hue_abberation[0][2] * c[2]/l );
  uint8_t g = float(brightness) * (
    hue_abberation[1][0] * c[0]/l +
    hue_abberation[1][1] * c[1]/l +
    hue_abberation[1][2] * c[2]/l );
  uint8_t b = float(brightness) * (
    hue_abberation[2][0] * c[0]/l +
    hue_abberation[2][1] * c[1]/l +
    hue_abberation[2][2] * c[2]/l );

  return Adafruit_NeoPixel::Color(r,g,b);
  
}


/////////////////////////////////////////////////////////
void ripples_heat(uint32_t runtime_ms) { // give it a runtime instead of a cycle count?
  uint32_t start_time = millis();

  while( millis() < start_time +runtime_ms ) {

    for(int i=0; i<NUM_LEDS; i++){
      float x,y;
      float time = SHADERSPEED * millis() / 1000.0;
      locatepixel_heat(i, x, y);
      uint32_t c = shader_heat(x, y, time);
      strip.setPixelColor(i, c);
    }
    // write to strip
    strip.show();
  }
}

// compute the real-space coordinates of the pixel
void locatepixel_heat(int i, float &x, float &y) {
  y = float(i + 0.5) / float(NUM_LEDS);
  float scale=0.5;
  y = ((y-0.5)*scale)+0.5;  // reduce the size of the pixel strip in the animation space
  x = 0.5;
}

// shader language builtin functions
float length_heat(float x, float y, float z = 0.0){
  return sqrt(x*x + y*y + z*z);
}
float mod_heat(float x, float y){
  return x - y * floor(x/y);
}

// The animation
// https://www.shadertoy.com/view/XsXXDn
// http://www.pouet.net/prod.php?which=57245
// Credits to Danilo Guanabara
uint32_t shader_heat(float x, float y, float t) {
  // #define t iTime
  
  float c[3];   //vec3 c;
  float l, z=t;
  for(int i=0; i<3; i++) {
    float uv[2];
    float p[2];
    p[0] = x;  // = fragCoord.xy/r;
    p[1] = y;  // = fragCoord.xy/r;
    //uv=p
    uv[0] = p[0];
    uv[1] = p[1];

    p[0] -= .5;
    p[1] -= .5;
    z += 0.07; // ¯\_(ツ)_/¯
    l = length_heat(p[0], p[1]);
    uv[0] += p[0] / l * (sin(z)+1.) * abs(sin(l*9.-z-z));
    uv[1] += p[1] / l * (sin(z)+1.) * abs(sin(l*9.-z-z));
    c[i] = 0.01 / length_heat(mod_heat(uv[0],1.) - 0.5, mod_heat(uv[1],1.) - 0.5); // Here be dragons
  }

  //fragColor = vec4(c/l,t);

  float hue_heat[3][3]={
    {  1,  1,0.5},  // R,G,B
    {0.3,0.7,0.3},  // R,G,B
    {0.1,0.2,0.8}   // R,G,B
  };

  uint8_t r = float(brightness) * (
    hue_heat[0][0] * c[0]/l +
    hue_heat[0][1] * c[1]/l +
    hue_heat[0][2] * c[2]/l );
  uint8_t g = float(brightness) * (
    hue_heat[1][0] * c[0]/l +
    hue_heat[1][1] * c[1]/l +
    hue_heat[1][2] * c[2]/l );
  uint8_t b = float(brightness) * (
    hue_heat[2][0] * c[0]/l +
    hue_heat[2][1] * c[1]/l +
    hue_heat[2][2] * c[2]/l );

  return Adafruit_NeoPixel::Color(r,g,b);
  
}

void ripples_tron(uint32_t runtime_ms) { // give it a runtime instead of a cycle count?
  uint32_t start_time = millis();

  while( millis() < start_time +runtime_ms ) {

    for(int i=0; i<NUM_LEDS; i++){
      float x,y;
      float time = SHADERSPEED * millis() / 1000.0;
      locatepixel_tron(i, x, y);
      uint32_t c = shader_tron(x, y, time);
      strip.setPixelColor(i, c);
    }
    // write to strip
    strip.show();
  }
}

// compute the real-space coordinates of the pixel
void locatepixel_tron(int i, float &x, float &y) {
  y = float(i + 0.5) / float(NUM_LEDS);
  float scale=0.5;
  y = ((y-0.5)*scale)+0.5;  // reduce the size of the pixel strip in the animation space
  x = 0.5;
}

/*
float locations[NUM_LEDS][2] = {
//  X , Y
  { 0 , 0},
  { 0 , 0},
  { 0 , 0},
  { 0 , 0},
  { 0 , 0},
  { 0 , 0},
};
*/

// shader language builtin functions
float length_tron(float x, float y, float z = 0.0){
  return sqrt(x*x + y*y + z*z);
}
float mod_tron(float x, float y){
  return x - y * floor(x/y);
}

// The animation
// https://www.shadertoy.com/view/XsXXDn
// http://www.pouet.net/prod.php?which=57245
// Credits to Danilo Guanabara
uint32_t shader_tron(float x, float y, float t) {
  // #define t iTime
  
  float c[3];   //vec3 c;
  float l, z=t;
  for(int i=0; i<3; i++) {
    float uv[2];
    float p[2];
    p[0] = x;  // = fragCoord.xy/r;
    p[1] = y;  // = fragCoord.xy/r;
    //uv=p
    uv[0] = p[0];
    uv[1] = p[1];

    p[0] -= .5;
    p[1] -= .5;
    z += 0.07; // ¯\_(ツ)_/¯
    l = length_tron(p[0], p[1]);
    uv[0] += p[0] / l * (sin(z)+1.) * abs(sin(l*9.-z-z));
    uv[1] += p[1] / l * (sin(z)+1.) * abs(sin(l*9.-z-z));
    c[i] = 0.01 / length_tron(mod_tron(uv[0],1.) - 0.5, mod_tron(uv[1],1.) - 0.5); // Here be dragons
  }

  //fragColor = vec4(c/l,t);

  float hue_tron[3][3]={
    {0.3,0.5,0.1},  // R,G,B
    {0.5,0.9,0.3},  // R,G,B
    {  1,  1,  1}   // R,G,B
  };

  uint8_t r = float(brightness) * (
    hue_tron[0][0] * c[0]/l +
    hue_tron[0][1] * c[1]/l +
    hue_tron[0][2] * c[2]/l );
  uint8_t g = float(brightness) * (
    hue_tron[1][0] * c[0]/l +
    hue_tron[1][1] * c[1]/l +
    hue_tron[1][2] * c[2]/l );
  uint8_t b = float(brightness) * (
    hue_tron[2][0] * c[0]/l +
    hue_tron[2][1] * c[1]/l +
    hue_tron[2][2] * c[2]/l );

  return Adafruit_NeoPixel::Color(r,g,b);
  
}
