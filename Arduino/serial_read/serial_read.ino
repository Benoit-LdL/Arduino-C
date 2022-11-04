#include <String.h>

const int led_red     = 32;
const int led_yellow  = 33;
const int led_green   = 25;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(led_red,OUTPUT);
  pinMode(led_yellow,OUTPUT);
  pinMode(led_green,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.print("donnez une lettre:");

  while (!Serial.available());

  String input = Serial.readString();
  if (input == "red")
  {
    digitalWrite(led_red,HIGH);
  }
  else if (input == "yellow")
  {
    digitalWrite(led_yellow,HIGH);
  }
  else if (input == "green")
  {
    digitalWrite(led_green,HIGH);
  }
  else
    Serial.println("Input not valid!");

  delay(1000);

}
