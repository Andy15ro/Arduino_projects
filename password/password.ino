
int ledPins[4] = {A3, A2, A1, A0};
int buttonPins[4] = {3, 4, 5, 6};
int buttonStare = 7;

int buzzer = 12;
int red = 11;
int green = 10;
int blue = 9;

int password[4] = {0,0,0,0};
bool passwordSet = false;
bool deviceLocked = true;
int currentOption = 0;

float gmm = 2.2;
int gamma(int value){
  float normal = value / 255.0;
  float correct = pow(normal, gmm);
  return (int)(255 * correct);
}


void beep(int f,int d){
  tone(buzzer,f);
  delay(d);
  noTone(buzzer);
}

void waitRelease(int pin){
  while(digitalRead(pin)==LOW);
}


void setRGB(int r,int g,int b){
  analogWrite(red,gamma(r));
  analogWrite(green,gamma(g));
  analogWrite(blue,gamma(b));
}

void setMenuColor(){
  switch(currentOption){
    case 0: setRGB(255,0,0); break;       
    case 1: setRGB(255,255,0); break;     
    case 2: setRGB(0,255,0); break;      
    case 3: setRGB(0,0,255); break;      
  }
}

void enterPassword(int passArray[4]){

  int index = 0;

  while(index < 4){

    for(int i=0;i<4;i++){
      if(digitalRead(buttonPins[i])==LOW){
        delay(50);
        if(digitalRead(buttonPins[i])==LOW){

          passArray[index++] = i;

          digitalWrite(ledPins[i],HIGH);
          delay(200);
          digitalWrite(ledPins[i],LOW);

          waitRelease(buttonPins[i]);
        }
      }
    }
  }
}

bool checkPassword(){

  if(!passwordSet) return false;

  int temp[4];
  enterPassword(temp);

  for(int i=0;i<4;i++){
    if(temp[i] != password[i])
      return false;
  }

  return true;
}

void executeOption(){

  beep(500,150);

  switch(currentOption){

    case 0: 
      enterPassword(password);
      passwordSet = true;
      deviceLocked = true;
      beep(1000,300);
      break;

    case 1: 
      if(checkPassword()){
        deviceLocked = false;
        beep(1200,300);
      } else {
        beep(200,500);
      }
      break;

    case 2: 
      deviceLocked = true;
      beep(300,300);
      break;

    case 3:
      if(checkPassword()){
        enterPassword(password);
        beep(1200,300);
      } else {
        beep(200,500);
      }
      break;
  }
}


void setup(){

  for(int i=0;i<4;i++){
    pinMode(ledPins[i],OUTPUT);
    pinMode(buttonPins[i],INPUT_PULLUP);
  }

  pinMode(buttonStare,INPUT_PULLUP);
  pinMode(buzzer,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);

  setMenuColor();
}

void loop(){

  for(int i=0;i<4;i++){
    if(digitalRead(buttonPins[i])==LOW){
      delay(50);
      if(digitalRead(buttonPins[i])==LOW){
        currentOption = i;
        setMenuColor();
        waitRelease(buttonPins[i]);
      }
    }
  }

  if(digitalRead(buttonStare)==LOW){
    delay(50);
    if(digitalRead(buttonStare)==LOW){
      waitRelease(buttonStare);
      executeOption();
      setMenuColor();
    }
  }
}