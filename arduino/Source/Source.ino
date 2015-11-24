int buttonPin = 13;
int tiltPin = 12;
int piezoPin = 9;
int potPin = 5;
int photoPin = 0;

int buttonState;
int lastButtonState = LOW;

int potval;
int btnval;
int tiltval;
int photoval;

long lastDebounceTime = 0;
long debounceDelay = 50;

unsigned int frequencies[] = {262,294,330,349,392,440,494};
char noteNames[] = {'C','D','E','F','G','a','b'};
const byte noteCount = sizeof(noteNames);

char score[] = "CCGGaaGFFEEDDC GGFFEEDGGFFEED CCGGaaGFFEEDDC";
const byte scoreLen = sizeof(score);

int duration = 333;

void playNote(char note, int duration){
  for (int i = 0; i < noteCount; i++){
    if(noteNames[i] == note){
      tone(piezoPin, frequencies[i], duration);
    }
  }
  delay(duration);
}

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(tiltPin, INPUT);
  pinMode(piezoPin, OUTPUT);
  pinMode(potPin, INPUT);
  pinMode(photoPin, INPUT);
}

void loop() {
  btnval = digitalRead(buttonPin);
  tiltval = digitalRead(tiltPin);
  potval = analogRead(potPin);
  photoval = analogRead(photoPin);

  int frequency = map(potval, 0, 1023, 100, 5000);

  // Play the music
  /*
  for (int i = 0; i < scoreLen; i++){
    playNote(score[i], duration);
  }
  */
  

  // Button Debouncing
  if (btnval != lastButtonState) {
    lastDebounceTime = millis();
  } 
  if ((millis() - lastDebounceTime) > debounceDelay) {
    buttonState = btnval;
  }
  
  // Send Values to Serial/Processing
  Serial.print(buttonState);
  Serial.print(",");
  Serial.print(potval, DEC);
  Serial.print(",");
  Serial.print(tiltval, DEC);
  Serial.print(",");
  Serial.println(photoval, DEC);

  // save the button value for next time through loop
  lastButtonState = btnval;
}
