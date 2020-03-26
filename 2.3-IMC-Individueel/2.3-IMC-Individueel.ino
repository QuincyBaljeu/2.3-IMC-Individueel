int ledGreen = 6;
int ledRed = 7;

int buzzer = 8;

String password;

void setup() {
  Serial.begin(9600);

  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);

  pinMode(buzzer, OUTPUT);
}

void loop() {
   Serial.println(readKeypad());
   delay(200);
}

int readKeypad(){

 while(true){
    if(digitalRead(2) == HIGH) {
      return 1;
    } else if(digitalRead(3) == HIGH) {
      return 2;
    } else if(digitalRead(4) == HIGH) {
      return 3;
    } else if(digitalRead(5) == HIGH) {
      return 4;
    }
    delay(200);
 }
  
}

int readKeypadOld(){
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
