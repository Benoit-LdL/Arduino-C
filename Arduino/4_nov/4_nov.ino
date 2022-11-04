const int led_red     = 32;
const int led_yellow  = 33;
const int led_green   = 25;

void setup() {

  Serial.begin(115200);

  pinMode(led_red,OUTPUT);
  pinMode(led_yellow,OUTPUT);
  pinMode(led_green,OUTPUT);
}

void loop() {
  
  FadeIn(led_green,2);
  delay(2000);

  Serial.println("Attention!");

  FadeOut(led_green,2);
  FadeIn(led_yellow,2);
  delay(200);

  FadeOut(led_yellow,2);
  FadeIn(led_red,2);
  delay(2000);

  FadeOut(led_red,2);
}

void FadeIn(int pin_number, int delay_ms)
{
  for (int i=0;i<255;i++)
  {
    analogWrite(pin_number,i);
    delay(delay_ms);
  }
}

void FadeOut(int pin_number,int delay_ms)
{
  for (int i=255;i>0;i--)
  {
    analogWrite(pin_number,i);
    delay(delay_ms);
  }
}
