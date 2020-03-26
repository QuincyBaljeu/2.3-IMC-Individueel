int ledGreen = 6;
int ledRed = 7;

void setup() {
  Serial.begin(9600);

  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);

  digitalWrite(ledGreen, HIGH);
  digitalWrite(ledRed, HIGH);
}

void loop() {
   Serial.println(readKeypad());
   
}

int readKeypad(){
  //set this value the pin number of first keypad
  int firstPin = 2;
  //set this value the pin number of last keypad
  int lastPin = 5;

  while(firstPin <= lastPin){
    if(digitalRead(firstPin) == HIGH){
      return firstPin - 1;
    }
    firstPin++;    
    delay(50);
  }
}
