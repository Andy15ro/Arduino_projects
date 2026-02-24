#define red 6
#define green 5
#define blue 3

void setup(){
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
}

int redv;
int greenv;
int bluev;
float gammavalue=2.2;

int gamma(int value){
  float normal=value/255.0;
  float correct=pow(normal,gammavalue);
  return (int)(255*correct);
}

void loop(){
  
  for(int i=0;i<=255;i++){
    redv=255-i;
    bluev=i;
    analogWrite(red, gamma(redv));
    analogWrite(blue, gamma(bluev));
    delay(10);
  }

  for(int i=0;i<=255;i++){
    bluev=255-i;
    greenv=i;
    analogWrite(blue, gamma(bluev));
    analogWrite(green, gamma(greenv));
    delay(10);
  }

  for(int i=0;i<=255;i++){
    greenv=255-i;
    redv=i;
    analogWrite(red, gamma(redv));
    analogWrite(green, gamma(greenv));
    delay(10);
  }
}