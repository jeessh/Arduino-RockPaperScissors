//Arduino scissors
int greenLED = 5;

//Arduino paper
int blueLED = 6;

//Arduino rock
int redLED = 7;

//You choose scissors
int greenbutton = 10 ;

//You choose paper
int bluebutton = 11;

//You choose rock
int redbutton = 12 ;
 
int randNumber;

int speakerPin = 4;
 
int numTones = 2;
int tones[] = {370};

#include <LiquidCrystal.h>

//LiquidCrystal identifies the pins for the lcd
const int rs = 9, en = 8, d4 = 3, d5 = 2, d6 = A4, d7 = A5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//This is to track the score
int Playerchoice = -1;
int Playerscore = 0;
int Arduinoscore = 0;

void setup()
{
{

  lcd.begin(16, 2);

//This makes the lcd print Rock Paper Scissors for the title screen
  lcd.print("   Rock Paper");
  lcd.setCursor(0,1);
  lcd.print ("    Scissors");
}

//This identifies the LEDs as outputs
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);  

//This identifies the buttons as inputs that pullup
  pinMode(greenbutton, INPUT_PULLUP);
  pinMode(redbutton, INPUT_PULLUP);
  pinMode(bluebutton, INPUT_PULLUP);


 Serial.begin(9600);  
 

  for (int i = 0; i < numTones; i++)
  {
    tone(speakerPin, tones[i]);
    delay(500);
  }
  noTone(speakerPin);
    delay(500);
    randomSeed(randNumber);
}

void loop()

//This is for the Throw Down Now which includes a held note and a sound each time a word is displayed. The LEDs also light up.
{
  randNumber = random(3);
lcd.clear();
keepScore();
lcd.setCursor(0 ,0);
  lcd.print(" Throw");
  digitalWrite(greenLED, HIGH);
  tone (speakerPin, 349, 500);
  delay(500);
    lcd.print(" Down");
  digitalWrite(blueLED, HIGH);
  tone (speakerPin, 370, 500);
  delay(500);
   lcd.print(" Now");
  digitalWrite(redLED, HIGH);
  tone (speakerPin, 392, 500);
  delay(500);
  digitalWrite(greenLED, LOW);
  digitalWrite(blueLED, LOW);
  digitalWrite(redLED, LOW);
    Serial.println(randNumber);
while (randNumber < 4)
{

//These are the different possibilites for when the redbutton is pressed, which is the rock button
if (digitalRead(redbutton) == LOW)

//This what happens if the redLED (rock LED) lights up when the redbutton is pressed
      {
        if (randNumber == 0) {
            digitalWrite(redLED, HIGH);
            digitalWrite(greenLED, LOW);
            digitalWrite(blueLED, LOW);
            delay(1000);
            lcd.clear();
            keepScore();
            lcd.print("   It's a Tie");
            lcd.setCursor(10,1);
   lcd.print("P");
  lcd.print(Playerscore);
  lcd.print("|");
  lcd.print(Arduinoscore);
  lcd.print("A");
            tone (speakerPin, 466, 1000);
            delay(1000);
            lcd.clear();

//This is what happens if the greenLED (scissors LED) lights up when the redbutton is pressed
        } else if (randNumber == 1) {
            digitalWrite(redLED, LOW);
            digitalWrite(greenLED, HIGH);
            digitalWrite(blueLED, LOW);
            delay(1000);
             lcd.clear();
             keepScore();
            lcd.print("  Rock Crushes");
            lcd.setCursor(0,1);
            lcd.print(" Scissors");
             lcd.print("P");
  lcd.print(Playerscore);
  lcd.print("|");
  lcd.print(Arduinoscore);
  lcd.print("A");
            Playerscore ++;
            tone (speakerPin, 392, 500);
            delay (550);
            tone (speakerPin, 392, 250);
            delay (250);
            tone (speakerPin, 523, 1000);
            delay (500);
            lcd.clear();

//This is what happens if the blueLED (paper LED) lights up when the redbutton is pressed
        }else if (randNumber == 2){
            digitalWrite(redLED, LOW);
            digitalWrite(greenLED, LOW);
            digitalWrite(blueLED, HIGH);
            delay(1000);    
            lcd.clear();
            keepScore();
            lcd.setCursor(0,0);
            lcd.print("  Rock Covered");
            lcd.setCursor(0,1);
            lcd.print("By Paper");  
             lcd.print("P");
  lcd.print(Playerscore);
  lcd.print("|");
  lcd.print(Arduinoscore);
  lcd.print("A");
            Arduinoscore ++;
            tone (speakerPin, 330, 500);
            delay (500);
            tone (speakerPin, 311, 500);
            delay (500);
            tone (speakerPin, 294, 500);
            lcd.clear();
      }
   break;
  }

//These are the different possibilites for when the bluebutton is pressed, which is the paper button
  if (digitalRead(bluebutton) == LOW)

//This is what happens if the redLED (rock LED) lights up when the bluebutton is pressed
      {
        if (randNumber == 0) {
            digitalWrite(redLED, HIGH);
            digitalWrite(greenLED, LOW);
            digitalWrite(blueLED, LOW);
            delay(1000);
            lcd.clear();
            keepScore();
            lcd.setCursor(0,0);
            lcd.print("  Paper Covers");
            lcd.setCursor(0,1);
            lcd.print(" Rock");
             lcd.print("P");
  lcd.print(Playerscore);
  lcd.print("|");
  lcd.print(Arduinoscore);
  lcd.print("A");
            Playerscore ++;
            tone (speakerPin, 392, 500);
            delay (550);
            tone (speakerPin, 392, 250);
            delay (250);
            tone (speakerPin, 523, 1000);
            delay (500);
            lcd.clear();

//This is what happens if the greenLED (scissors LED) lights up when the bluebutton is pressed
        } else if (randNumber == 1) {
            digitalWrite(redLED, LOW);
            digitalWrite(greenLED, HIGH);
            digitalWrite(blueLED, LOW);
            delay(1000);
            lcd.clear();
            keepScore();
            lcd.setCursor(0,0);
            lcd.print("    Paper Cut");
            lcd.setCursor(0,1);
            lcd.print("By Scissors");
             lcd.print("P");
  lcd.print(Playerscore);
  lcd.print("|");
  lcd.print(Arduinoscore);
  lcd.print("A");
            Arduinoscore ++;
            tone (speakerPin, 330, 500);
            delay (500);
            tone (speakerPin, 311, 500);
            delay (500);
            tone (speakerPin, 294, 500);
            lcd.clear();

//This is what happens if the blueLED (paper LED) lights up when the bluebutton is pressed
        }else if (randNumber == 2){
            digitalWrite(redLED, LOW);
            digitalWrite(greenLED, LOW);
            digitalWrite(blueLED, HIGH);
            delay(1000);      
            lcd.clear();
            keepScore();
            lcd.setCursor(0,0);
            lcd.print("   It's a Tie");
            lcd.setCursor(10,1);
          lcd.print("P");
  lcd.print(Playerscore);
  lcd.print("|");
  lcd.print(Arduinoscore);
  lcd.print("A");
            tone (speakerPin, 466, 1000);
            delay (1000);
            lcd.clear();
             }
           break;
  }

//These are the different possibilites for when the greenbutton is pressed, which is the scissors button
  if (digitalRead(greenbutton) == LOW)
     
//This is what happens if the redLED (rock LED) lights up when the greenbutton is pressed
      {
        if (randNumber == 0) {
            digitalWrite(redLED, HIGH);
            digitalWrite(greenLED, LOW);
            digitalWrite(blueLED, LOW);
            delay(1000);
            lcd.clear();
            keepScore();
            lcd.setCursor(0,0);
            lcd.print("Scissors Crushed");
            lcd.setCursor(0,1);
            lcd.print(" By Rock");
             lcd.print("P");
  lcd.print(Playerscore);
  lcd.print("|");
  lcd.print(Arduinoscore);
  lcd.print("A");
            Arduinoscore ++;
            tone (speakerPin, 330, 500);
            delay (500);
            tone (speakerPin, 311, 500);
            delay (500);
            tone (speakerPin, 294, 500);
            lcd.clear();

//This is what happens if the greenLED (scissors LED) lights up when the greenbutton is pressed
        } else if (randNumber == 1) {
            digitalWrite(redLED, LOW);
            digitalWrite(greenLED, HIGH);
            digitalWrite(blueLED, LOW);
            delay(1000);      
            lcd.clear();
            keepScore();
            lcd.setCursor(0,0);
            lcd.print("   It's a Tie");
            lcd.setCursor(10,1);
             lcd.print("P");
  lcd.print(Playerscore);
  lcd.print("|");
  lcd.print(Arduinoscore);
  lcd.print("A");
            tone (speakerPin, 466, 1000);
            delay (1000);

//This is what happens if the blueLED (paper LED) lights up when the greenbutton is pressed
//This turns all of the LEDs off for a second
digitalWrite(greenLED, LOW);
  digitalWrite(blueLED, LOW);
  digitalWrite(redLED, LOW);
  delay(1000);


//This is what happens when the player wins
//This is what happens when the player loses and the Arduino wins
//This is for keeping score of the points
void readInput(){
 
  while (Playerscore < 5){
    if (redLED == LOW)
     Playerchoice = 0; return;
    if (blueLED == LOW)
     Playerchoice = 0; return;
     if (greenLED == LOW)
     Playerchoice = 0; return;
    char chr = Serial.read();
    if (chr = 0)
    Playerchoice = 0;
  }
}

//This is the song for when the player wins
void winsong ()
{
  tone (speakerPin, 392, 500);
  delay (1000);
  tone (speakerPin, 392, 250);
  delay (500);
  tone (speakerPin, 523, 1000);
  delay (500);
}

//This is the song for when the player and Arduino ties
void tiesong ()
{
  tone (speakerPin, 466, 1000);
  delay (500);
}

//This is the song for when the player loses, and the Arduino wins
void losesong () {
  tone (speakerPin, 330, 500);
  delay (500);
  tone (speakerPin, 311, 500);
  delay (500);
  tone (speakerPin, 294, 500);
}

//This keeps score, which is displayed on the LCD
