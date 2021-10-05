//The buzzer code that im using is from the arduino examples
//I watch a tutorial about building a DIY simon says game
//Tutorial video #1 - https://www.youtube.com/watch?v=fB4h0hNWz2o
//Tutorial video #2 - https://www.youtube.com/watch?v=ksNbEuhO4fU
//Tutorial video #3 - https://www.youtube.com/watch?v=Tcp_6L80kY0
//Tutorial video #3's website where I got the example codes

#define BUZZER 5

int buttonValue1 = 0; //For reading the button assigned to Yellow LED
int buttonValue2 = 0; //For reading the button assigned to Blue LED
int buttonValue3 = 0; //For reading the button assigned to Red LED
int buttonValue4 = 0; //For reading the button assigned to Green LED
int buttonValue5 = 0; //For reading the button assigned to start the game

//Some the numbers are not in order for this one just because of 
//the components in sensor kit. 

//Declare the LED bulbs
const int greenLED = 7; 
const int redLED = 2;
const int blueLED = 6;
const int yellowLED = 3;

//Declare the buttons
const int greenButton = 11;
const int redButton = 10;
const int blueButton = 9;
const int yellowButton = 8;
const int startButton = 4; //start button is the seonsor kit button. 

int sequence =  1; //To keep count of whicch sequence is the game in

void setup() {
  pinMode(BUZZER, OUTPUT);
  
  // pinmode for the LED lights
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);

  // pinmode for the buttons
  pinMode(greenButton, INPUT);
  pinMode(redButton, INPUT);
  pinMode(blueButton, INPUT);
  pinMode(yellowButton, INPUT);

  pinMode(startButton, INPUT);
  
  Serial.begin(9600);

}

void loop() {
  //To make void loop a bit more cleaner, i put them in their own functions
  startSequence();
  //buttonMenu();
}

void startSequence(){
  //Not sure if its necessary to define them in here but just in case.
  YELLOW_LED();
  BLUE_LED();
  RED_LED();
  GREEN_LED();

  //the buttonValue5 is the button on the sensor kit
  //check if the user started the game or not
  buttonValue5 = digitalRead(startButton);
  
  if (buttonValue5 == sequence){
    //Start
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, HIGH);
    digitalWrite(blueLED, HIGH);
    delay(2000);

    //If i dont write the LOW value, the second sequence will start
    //while the other lights are still on.
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
    digitalWrite(blueLED, LOW);

    //To advance to the second sequence
    sequence++;
  } 

  //Start of Sequence 2
  if (sequence == 2) {
    digitalWrite(greenLED, HIGH);
    delay(1000);
    digitalWrite(greenLED, LOW);
    delay(1000);
    Serial.println(sequence);
  } 
  
  //Start of Sequence 3
  if (sequence == 3){
    digitalWrite(greenLED, HIGH);
    delay(750);
    digitalWrite(greenLED, LOW);
    delay(750);
    digitalWrite(blueLED, HIGH);
    delay(750);
    digitalWrite(blueLED, LOW);
    delay(1500);
    Serial.println(sequence);
  }

  //Start of Sequence 4
  if (sequence == 4){
    digitalWrite(greenLED, HIGH);
    delay(750);
    digitalWrite(greenLED, LOW);
    delay(750);
    digitalWrite(blueLED, HIGH);
    delay(750);
    digitalWrite(blueLED, LOW);
    delay(750);
    digitalWrite(yellowLED, HIGH);
    delay(750);
    digitalWrite(yellowLED, LOW);
    delay(1500);
  }
  
  else {
    //End
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, HIGH);
    digitalWrite(blueLED, HIGH);
    delay(500);
    
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
    digitalWrite(blueLED, LOW);
    delay(500);

    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, HIGH);
    digitalWrite(blueLED, HIGH);
    delay(500);
    
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
    digitalWrite(blueLED, LOW);
    delay(500);
    
    Serial.println(sequence);
  }
}

void YELLOW_LED(){
  buttonValue1 = digitalRead(yellowButton);

  if(buttonValue1 != 0){
    digitalWrite(yellowLED, HIGH);
    sequence++; //This is where i add the sequence to advance the game
  } else {
    digitalWrite(yellowLED, LOW);

  }
}

void BLUE_LED(){
  buttonValue2 = digitalRead(blueButton);

  if(buttonValue2 != 0){
    digitalWrite(blueLED, HIGH);
    sequence++; //This is where i add the sequence to advance the game
  } else {
    digitalWrite(blueLED, LOW);
  }
}

void RED_LED(){
  buttonValue3 = digitalRead(redButton);

  if(buttonValue3 != 0){
    digitalWrite(redLED, HIGH);
    sequence++; //This is where i add the sequence to advance the game
  } else {
    digitalWrite(redLED, LOW);
  }
}

void GREEN_LED(){
  buttonValue4 = digitalRead(greenButton);

  if(buttonValue4 != 0){
    digitalWrite(greenLED, HIGH);
    sequence++; //This is where i add the sequence to advance the game
  } else {
    digitalWrite(greenLED, LOW);
  }
}

//Early editions of the button light functions

//void buttonMenu(){
//    buttonValue1 = digitalRead(yellowButton);
//
//  if(buttonValue1 != 0){
//    digitalWrite(yellowLED, HIGH);
//    Serial.println("Yellow is ON ++++");
//  } else {
//    digitalWrite(yellowLED, LOW);
//    Serial.println("Yellow is OFF ----");
//  }
//
//  buttonValue2 = digitalRead(blueButton);
//
//  if(buttonValue2 != 0){
//    digitalWrite(blueLED, HIGH);
//    Serial.println("Blue is ON ++++");
//  } else {
//    digitalWrite(blueLED, LOW);
//    Serial.println("Blue is OFF ----");
//  }
//
//  buttonValue3 = digitalRead(redButton);
//
//  if(buttonValue3 != 0){
//    digitalWrite(redLED, HIGH);
//    Serial.println("Red is ON ++++");
//  } else {
//    digitalWrite(redLED, LOW);
//    Serial.println("Red is OFF ----");
//  }
//
//  buttonValue4 = digitalRead(greenButton);
//
//  if(buttonValue4 != 0){
//    digitalWrite(greenLED, HIGH);
//    Serial.println("Green is ON ++++");
//  } else {
//    digitalWrite(greenLED, LOW);
//    Serial.println("Green is OFF ----");
//  }
//}
