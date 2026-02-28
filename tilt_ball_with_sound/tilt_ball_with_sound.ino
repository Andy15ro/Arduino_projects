const int ledPin = 3;
int tilt = 7;
int buzzer = 12;

void setup(){
  pinMode(ledPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(tilt, INPUT_PULLUP);
  Serial.begin(9600);
}
int nr = 0;
void loop(){
  int val = digitalRead(tilt);
  if(val == LOW){
    nr++;
    digitalWrite(ledPin, HIGH);
    tone(buzzer, 532, 200);
    Serial.print("Tilt activat! Total: ");
    Serial.println(nr);

    delay(300);
  }
  else{
    digitalWrite(ledPin, LOW);
    noTone(buzzer);
  }
}