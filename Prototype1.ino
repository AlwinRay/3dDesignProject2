//The buzzer code that im using is from the arduino examples
//I watch a tutorial about building a DIY simon says game
//Tutorial video - https://www.youtube.com/watch?v=fB4h0hNWz2o
//

#define BUZZER 5
 
void setup()
{  
  //Not being used as of right now
  pinMode(BUZZER, OUTPUT);

  // pinmode for the LED lights
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  // pinmode for the buttons
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);

  Serial.begin(9600);
}
 
void loop()
{
  setPins();
  
  //tone(BUZZER, 85); //Set the voltage to high and makes a noise
  //delay(1000);//Waits for 1000 milliseconds
  //noTone(BUZZER);//Sets the voltage to low and makes no noise
  //delay(1000);//Waits for 1000 milliseconds

  buttonsMenu();
}

void buttonsMenu() {
  bool buttonPress = false;
  
  if (digitalRead(8) == HIGH) {
    buttonPress = true;
    Serial.println(buttonPress);
  } else {
    buttonPress = false;
  }
  // if (digitalRead(9) == LOW) {
  //  Serial.println(digitalRead(9));
  //} if (digitalRead(10) == LOW) {
  //  Serial.println(digitalRead(10));
  //} if (digitalRead(11) == LOW) {
  //  Serial.println(digitalRead(11));
  //}
}

void setPins(){
  for (int i = 2; i<10; i++) {
    digitalWrite(i, HIGH);
    Serial.println(i);
  }
}
