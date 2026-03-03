#include <SR04.h>

const int trig = 4;
const int echo = 3;

SR04 sr04 = SR04(echo, trig);

const int red = 11;
const int green = 10;
const int blue = 9;

const int buzzer = 13;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}
const float gamm = 2.2;
int gamma(int value) {
  float normal = value / 255.0;
  float correct = pow(normal, gamm);
  return (int)(correct * 255);
}
void light(int r, int g, int b) {
  analogWrite(red, gamma(r));
  analogWrite(green, gamma(g));
  analogWrite(blue, gamma(b));
}
long dist;

void write(long d) {
  Serial.print("Distance: ");
  Serial.print(d);
  Serial.println(" cm");
}
void loop() {
  dist = sr04.Distance();
  write(dist);
  if (dist >= 50) {
    light(0, 255, 0);
    noTone(buzzer);
    delay(200);
  } else {
    if (dist > 20) {
      light(255, 255, 0);
      tone(buzzer, 1000, 200);
      delay(250);
    } else {
      light(255, 0, 0);
      tone(buzzer, 1500, 100);
      delay(150);
      tone(buzzer, 1500, 100);
      delay(150);
    }
  }
}