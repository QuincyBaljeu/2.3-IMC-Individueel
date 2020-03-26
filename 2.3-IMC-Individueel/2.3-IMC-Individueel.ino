int ledGreen = 6;
int ledRed = 7;

int buzzer = 8;

String password;

void setup() {
  Serial.begin(9600);

  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);

  pinMode(buzzer, OUTPUT);

  buzzerWrong();
  delay(2000);
  buzzerCorrect();
  
}

void loop() {
   
}

int readKeypad(){
  //set this value the pin number of first keypad
  int firstPin = 2;
  //set this value the pin number of last keypad
  int lastPin = 5;

  while(firstPin <= lastPin){
    if(digitalRead(firstPin) == HIGH && digitalRead(firstPin) < 10){
      return firstPin - 1;
    }
    firstPin++;    
    delay(50);
  }
}


void setPassword(){

  int passwordIndex = 0;

  while(passwordIndex < 4){
    int pressedKey = readKeypad();
    password += pressedKey;
    delay(2000);
    Serial.println(password);
    passwordIndex++;
  }
}

void buzzerWrong(){
  tone(buzzer, 300, 65); 
  delay(150);
  tone(buzzer, 300, 65);   
}

void buzzerCorrect(){
  tone(buzzer, 300, 65); 
  delay(150);
  tone(buzzer, 500, 65);  
}
