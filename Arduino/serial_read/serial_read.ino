#include <String.h>

const int led_red     = 32;
const int led_yellow  = 33;
const int led_green   = 25;

bool led_red_state    = false;
bool led_yellow_state = false;
bool led_green_state = false;

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
  Serial.println(input);
  if (input == "red\n")
  {
    led_red_state = !led_red_state;
    UpdateLed(led_red,led_red_state);
  }
  else if (input == "yellow\n")
  {
    led_yellow_state = !led_yellow_state;
    UpdateLed(led_yellow,led_yellow_state);
  }
  else if (input == "green\n")
  {
    led_green_state = !led_green_state;
    UpdateLed(led_green,led_green_state);
  }
  else
    Serial.println("Wrong input");

  delay(1000);

}

void UpdateLed(int ledPin,bool led_state)
{
  if (led_state == true)
    digitalWrite(ledPin,HIGH);
  else
    digitalWrite(ledPin,LOW);
}
