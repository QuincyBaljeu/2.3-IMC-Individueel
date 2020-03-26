int ledGreen = 6;
int ledRed = 7;

int buzzer = 8;

String password;

void setup() {
  Serial.begin(9600);

  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);

  pinMode(buzzer, OUTPUT);

  setPassword();
}

void loop() {
 // Serial.println(readKeypad());
  
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
 }
}

void setPassword(){

  int passwordIndex = 0;

  while(passwordIndex < 4){
    int pressedKey = readKeypad();
    password += pressedKey;
    buzzerStep();
    Serial.println(password);
    passwordIndex++;
    delay(125);
  }
}

void buzzerStep(){
  tone(buzzer, 700, 65); 
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
