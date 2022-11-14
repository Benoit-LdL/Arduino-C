// Motors
#define MOTOR_RIGHT_IN1   32
#define MOTOR_RIGHT_IN2   33
#define MOTOR_LEFT_IN3    25
#define MOTOR_LEFT_IN4    26

// IR Sensors
#define IR_LEFT     27
#define IR_RIGHT    14

int IR_left_value   = 0; // Boolean?
int IR_right_value  = 0; // Boolean?

int state = 2;

void setup()
{
  // Reglage du port UART :
  Serial.begin(115200);

  pinMode(MOTOR_RIGHT_IN1,  OUTPUT);
  pinMode(MOTOR_RIGHT_IN2,  OUTPUT);
  pinMode(MOTOR_LEFT_IN3,   OUTPUT);
  pinMode(MOTOR_LEFT_IN4,   OUTPUT);

  // pinMode(IR_LEFT,INPUT);
  // pinMode(IR_LEFT,INPUT);
  attachInterrupt(IR_LEFT,  Read_IR_Left,   CHANGE);
  attachInterrupt(IR_RIGHT, Read_IR_Right,  CHANGE);

}

void loop()
{
  /*
  Serial.println("-------------");
  Serial.print("left:"); Serial.println(IR_left_value);
  Serial.print("right:"); Serial.println(IR_right_value);
  delay(100);
  */
  // /*
  switch(state)
  {
    case 0:
      Serial.println("driving right");
      Drive_right();
      if (IR_right_value == 1)
      {
        Serial.println("changing state to 1");
        state = 1;
      }
      break;
    
    case 1:
      Serial.println("driving left");
      Drive_left();
      if (IR_left_value == 1)
      {
        Serial.println("changing state to 0");
        state = 0;
      }
      break;

    case 2:
      Drive_stop();
      if (IR_left_value == 1)
      {
        state = 0;
      }
      if (IR_right_value == 1)
      {
        state = 1;
      }
  }
  // */
}

ICACHE_RAM_ATTR void Read_IR_Left()
{
  IR_left_value = digitalRead(IR_LEFT);
}

ICACHE_RAM_ATTR void Read_IR_Right()
{
  IR_right_value = digitalRead(IR_RIGHT);
}



void Motor_right(int direction){
  if (direction == 1)
  {
    digitalWrite(MOTOR_RIGHT_IN1,HIGH);
    digitalWrite(MOTOR_RIGHT_IN2,LOW);
  }
  else if (direction == -1)
  {
    digitalWrite(MOTOR_RIGHT_IN1,LOW);
    digitalWrite(MOTOR_RIGHT_IN2,HIGH);
  }
  else if (direction == 0)
  {
    digitalWrite(MOTOR_RIGHT_IN1,LOW);
    digitalWrite(MOTOR_RIGHT_IN2,LOW);
  }
  else
  {
    Serial.println("error");
  }
}

void Motor_left(int direction){
  if (direction == 1)
  {
    digitalWrite(MOTOR_LEFT_IN3,LOW);
    digitalWrite(MOTOR_LEFT_IN4,HIGH);
  }
  else if (direction == -1)
  {
    digitalWrite(MOTOR_LEFT_IN3,HIGH);
    digitalWrite(MOTOR_LEFT_IN4,LOW);
  }
  else if (direction == 0)
  {
    digitalWrite(MOTOR_LEFT_IN3,LOW);
    digitalWrite(MOTOR_LEFT_IN4,LOW);
  }
  else
  {
    Serial.println("error");
  }
}

void Drive_forwards(){
  Motor_right(1);
  Motor_left(1);
}

void Drive_backwards(){
  Motor_right(-1);
  Motor_left(-1);
}

void Drive_right(){
  Motor_right(0);
  Motor_left(1);
}

void Drive_left(){
  Motor_right(1);
  Motor_left(0);
}

void Drive_stop(){
  Motor_right(0);
  Motor_left(0);
}