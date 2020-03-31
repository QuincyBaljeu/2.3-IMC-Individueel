//Assign pins HW-138
int key1 = 2;
int key2 = 3;
int key3 = 4;
int key4 = 5;

//Assign pins 7 segment display
int segmentA = 9;
int segmentB = 10;
int segmentC = 13;
int segmentD = 12;
int segmentE = 11;
int segmentF = 8;
int segmentG = 7;

//Assing pins buzzer
int buzzer = 6;

String password;

boolean passwordSet;
boolean passwordGuessed;

void setup() 
{
  Serial.begin(9600);

  passwordSet = false;
  passwordGuessed = false;

  pinModeSetup();
  //Buzz to indicate that arduino is ready
  buzzerStartup();
}

void loop() 
{
  //Checks if user has set a password. if not, sets this password to user input
  if(passwordSet == false)
  {
    password = getCombination();
    passwordSet = true;
    buzzerPasswordSet();
  }

  //Checks if user has guessed password
  if(passwordGuessed)
  {
    //Clears 7 segment display
    clearSegments();

    //Displays pressed key on 7 segment display
    int pressedKey = readKeypad();
    displaySegments(pressedKey);
    
  } else {
    //Read guessed combination from user
    String userInput = getCombination();

    //Check if gussed combination is correct
    if(userInput == password)
    {
      delay(500);
      buzzerCorrect();
      passwordGuessed = true;
    } else{
      delay(500);
      buzzerWrong();
    }
  }
}

//Sets correct pinmode of pins
void pinModeSetup()
{
  pinMode(segmentA, OUTPUT);  
  pinMode(segmentB, OUTPUT);  
  pinMode(segmentC, OUTPUT);  
  pinMode(segmentD, OUTPUT);  
  pinMode(segmentE, OUTPUT);  
  pinMode(segmentF, OUTPUT);  
  pinMode(segmentG, OUTPUT);  

  pinMode(buzzer, OUTPUT);
}

//Read the pressed key on the HW-138 keypad
int readKeypad()
{
 while(true)
 {
    if(isPressed(key1)) {
      return 1;
    } else if(isPressed(key2)) {
      return 2;
    } else if(isPressed(key3)) {
      return 3;
    } else if(isPressed(key4)) {
      return 4;
    }
 }
}

//Return string composed of the 4 guessed numbers
String getCombination()
{
  int passwordIndex = 0;
  String combination = "";

  while(passwordIndex < 4)
  {
    int pressedKey = readKeypad();
    
    combination += pressedKey;
    buzzerStep();
    passwordIndex++;
    delay(125);
  }

  return combination;
}

//Check if key given in parameter is pressed
boolean isPressed(int key)
{
  if(digitalRead(key) == HIGH)
  {
    return true; 
  } else {
    return false;
  }
}

//Turns on segments based on parameter
void displaySegments(int number)
{
  switch(number)
  {
    case 1:
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      
      break;
    case 2:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentG, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentD, HIGH);
      
      break;
    case 3:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentG, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      
      break;
    case 4:
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      
      break;
    default:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, LOW);
    
      break;    
  }
}

void clearSegments()
{
   digitalWrite(segmentA, LOW);
   digitalWrite(segmentB, LOW);
   digitalWrite(segmentC, LOW);
   digitalWrite(segmentD, LOW);
   digitalWrite(segmentE, LOW);
   digitalWrite(segmentF, LOW);
   digitalWrite(segmentG, LOW);
  
}

void buzzerStartup()
{
    tone(buzzer, 700, 65); 
    delay(150);
    tone(buzzer, 500 , 65); 
    delay(150);
    tone(buzzer, 300, 65); 
    delay(150);
    tone(buzzer, 400, 65); 
}

void buzzerPasswordSet()
{
   tone(buzzer, 700, 65); 
   delay(150);
   tone(buzzer, 700, 65); 
}

void buzzerStep()
{
   tone(buzzer, 700, 65); 
}

void buzzerWrong()
{
  tone(buzzer, 300, 65); 
  delay(150);
  tone(buzzer, 300, 65);   
}

void buzzerCorrect()
{
  tone(buzzer, 300, 65); 
  delay(150);
  tone(buzzer, 500, 65);  
}
