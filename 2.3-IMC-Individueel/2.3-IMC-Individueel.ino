int buzzer = 8;


void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
}

void loop() {

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
