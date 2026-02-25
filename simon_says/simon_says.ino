const int ledPins[4]={2,3,4,5};// 2-R, 3-Y, 4-G, 5-B
const int buttonPins[4]={8,9,10,11};// 8-bR, 9-bY, 10-bG, 11-bB

int sequence[100];
int level=1;
void setup(){
  for(int i=0;i<4;i++){
    pinMode(ledPins[i], OUTPUT);
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
  randomSeed(analogRead(A0));
}

void generateSequence() {
  sequence[level-1] = random(0,4);
}

void showSequence() {
  for(int i = 0; i < level; i++) {
    digitalWrite(ledPins[sequence[i]], HIGH);
    delay(500);
    digitalWrite(ledPins[sequence[i]], LOW);
    delay(250);
  }
}

bool checkInput() {
  for(int i = 0; i < level; i++) {
    int pressed = waitForButton();
    if(pressed != sequence[i]) {
      return false;
    }
  }
  return true;
}

int waitForButton() {
  while(true) {
    for(int i = 0; i < 4; i++) {
      if(digitalRead(buttonPins[i]) == LOW) {
        digitalWrite(ledPins[i], HIGH);
        delay(200);
        digitalWrite(ledPins[i], LOW);
        while(digitalRead(buttonPins[i]) == LOW);
        return i;
      }
    }
  }
}

void gameOver() {
  for(int i=0;i<4;i++){
    digitalWrite(ledPins[i], HIGH);
  }
  delay(1000);
  for(int i=0;i<4;i++){
    digitalWrite(ledPins[i], LOW);
  }
  level = 1;
}


void loop() {
  generateSequence();
  showSequence();
  if (!checkInput()) {
    gameOver();
  } else {
    level++;
    delay(1000);
  }
}