#include <Timer.h>

Timer t;

#define interruptPin 19
int i = 0;

void setup() {
  pinMode(interruptPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), counter, RISING);
  Serial.begin(9600);
  t.every(500, print_speed);
}

void loop() {
  t.update();
}


void print_speed()
{
  Serial.print("Speed:  ");
  Serial.print(i * 120 / 100);
  Serial.println(" rpm");
  i = 0;
}

void counter() {
  i++;
}