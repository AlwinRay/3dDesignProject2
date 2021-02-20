#include <Servo.h>
#include <Adafruit_NeoPixel.h>


Servo windMill;  // For the first servo Motor
Servo waterWheel;
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

#define LED_PIN    6

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 1

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB);

void setup() {
  windMill.attach(9); 
  myservo2.attach(8);
 
  strip.begin();           
  strip.show();            
  strip.setBrightness(150);
}

void loop() {

//For the servo motor windmill, I wanted it to do a 360
//so it looked like it's actually spinning
  windMill.write(0);             
    delay(5);
  windMill.write(180);              
    delay(1500);
  windMill.write(0);              
    delay(1500);

//For the servo motor water wheel, same thing with the windmill,
//I wanted it to do a full circle but the servo itself prohibits it
  waterWheel.write(0);              
    delay(5);
  waterWheel.write(0);              
    delay(500);
  waterWheel.write(180);             
    delay(500);


//colorWipe is for the change of the "water" colour
  colorWipe(strip.Color(0,0,255), 1000); // Blue
  colorWipe(strip.Color(0,0, 205), 1000); // Medium Blue
  colorWipe(strip.Color(0,0, 128), 1000); // Navy 
  colorWipe(strip.Color(25,25, 112), 1000); // Midnight Blue

}

//This code is from the tutorial, did not think its relevant for me to tweak it 
//as it is functioning the way I want it to function.
void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { 
    strip.setPixelColor(i, color);         
    strip.show();                          
    delay(wait);                           
  }
}
