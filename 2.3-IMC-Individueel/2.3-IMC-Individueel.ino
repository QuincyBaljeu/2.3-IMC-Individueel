int ledGreen = 6;
int ledRed = 7;

int buzzer = 8;

String password;

void setup() {
  Serial.begin(9600);

  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);

  pinMode(buzzer, OUTPUT);

  password = getCombination();
  buzzerPasswordSet();
}

void loop() {
  
  String userInput = getCombination();

  if(userInput == password){
    delay(500);
    buzzerCorrect();
    digitalWrite(ledGreen, HIGH);
    delay(1000);
    digitalWrite(ledGreen, LOW);
  } else{
    delay(500);
    buzzerWrong();
    digitalWrite(ledRed, HIGH);
    delay(1000);
    digitalWrite(ledRed, LOW);
  }
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

String getCombination(){

  int passwordIndex = 0;
  String combination = "";

  while(passwordIndex < 4){
    int pressedKey = readKeypad();
    combination += pressedKey;
    buzzerStep();
    //Serial.println(combination);
    passwordIndex++;
    delay(125);
  }

  return combination;
}

void buzzerStep(){
  tone(buzzer, 700, 65); 
}

void buzzerPasswordSet(){
   tone(buzzer, 700, 65); 
   delay(150);
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
