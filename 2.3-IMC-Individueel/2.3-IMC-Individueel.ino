const int keysAmount = 4;
int keys[keysAmount] = {2,3,4,5};

void setup() {
  Serial.begin(9600);
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
