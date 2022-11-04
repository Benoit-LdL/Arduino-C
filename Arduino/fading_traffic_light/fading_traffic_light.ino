const int led_red     = 32;
const int led_yellow  = 33;
const int led_green   = 25;

const int iteration_speed   = 2;
const int main_delay        = 2000;

void setup() {

  Serial.begin(115200);

  pinMode(led_red,OUTPUT);
  pinMode(led_yellow,OUTPUT);
  pinMode(led_green,OUTPUT);
}

void loop() {
  
  Serial.println("DING!");
  FadeIn(led_green,iteration_speed);
  delay(main_delay);

  Serial.println("Attention!");

  FadeOut(led_green,iteration_speed);
  FadeIn(led_yellow,iteration_speed);
  delay(main_delay/10);

  FadeOut(led_yellow,iteration_speed);

  Serial.println("DONG!");
  Serial.println("___________");
  FadeIn(led_red,iteration_speed);
  delay(main_delay);

  FadeOut(led_red,iteration_speed);
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
