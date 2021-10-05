//The buzzer code that im using is from the arduino examples
//I watch a tutorial about building a DIY simon says game
//Tutorial video #1 - https://www.youtube.com/watch?v=fB4h0hNWz2o
//Tutorial video #2 - https://www.youtube.com/watch?v=ksNbEuhO4fU


//To declare the value, to be use for the button and LED
int value1 = 0;
int value2 = 0;
int value3 = 0;
int value4 = 0;

//To declare the LED bulbs
int LED1 = 4;
int LED2 = 3;
int LED3 = 2;
int LED4 = 1;

//To declare the buttons
int Button1 = 8;
int Button2 = 9;
int Button3 = 10;
int Button4 = 11;

void setup() {
  //Not being used as of right now
  
  // pinmode for the LED lights
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  // pinmode for the buttons
  pinMode(Button1, INPUT);
  pinMode(Button2, INPUT);
  pinMode(Button3, INPUT);
  pinMode(Button4, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  
  //For button 1
  value1 = digitalRead(Button1);

  //For LED 1
  if(value1 != 0){
    digitalWrite(LED1, HIGH);
    Serial.println(LED1);
  } else {
    digitalWrite(LED1, LOW);
  }

  //For button 2
  value2 = digitalRead(Button2);

  //For LED 2
  if(value2 != 0){
    digitalWrite(LED2, HIGH);
    Serial.println(LED2);

  } else {
    digitalWrite(LED2, LOW);
  }

  //For button 3
  value3 = digitalRead(Button3);

  //For LED 3
  if(value3 != 0){
    digitalWrite(LED3, HIGH);
  } else {
    digitalWrite(LED3, LOW);
  }

  //For button 4
  value4 = digitalRead(Button4);
  //For LED 4
  if(value4 != 0){
    digitalWrite(LED4, HIGH);
  } else {
    digitalWrite(LED4, LOW);
  }
}
