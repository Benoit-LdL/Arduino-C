
char    char_list[6] ={'b','e','n','o','i','t'};
String  morse_list[6] = {"-...",".","-.","---","..","-"};

const int led_red     = 32;
const int led_yellow  = 33;
const int led_green   = 25;

const int morse_long  = 600;
const int morse_short = 200;
const int morse_pause = 300;

void setup() {
  Serial.begin(9600);

  pinMode(led_red,OUTPUT);
  pinMode(led_yellow,OUTPUT);
  pinMode(led_green,OUTPUT);
}

void loop() {
  Serial.print("donnez votre nom:");
  while (!Serial.available());

  String input = Serial.readString();
  Serial.println();
  int input_lenght = sizeof(input);
  for (int i=0;i < input_lenght;i++)
  {
    for (int j=0;j < sizeof(char_list);j++)
    {
      if (input[i] == char_list[j])
      {
        Serial.print("Letter: "); Serial.print(char_list[j]); Serial.print(" => ");  Serial.println(morse_list[j]);
        MorseToLight(morse_list[j]);
      }
    }
  }
}

void MorseToLight(String input)
{
  for (int i=0;i<input.length();i++)
  {
    
    Serial.println(input[i]);

    if (input[i] == '-')
    {
      digitalWrite(led_red,HIGH);
      delay(morse_long);
      digitalWrite(led_red,LOW);
      delay(morse_long);
    }
    else
    {
      digitalWrite(led_green,HIGH);
      delay(morse_short);
      digitalWrite(led_green,LOW);
      delay(morse_short);
    }
  }
  delay(morse_pause);
  
}
