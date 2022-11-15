// ODOM
#define PI                3.1415926535897932384626433832795
#define ODOM_SECTIONS     40.0
#define L_ENTRE_ROUE      135.0
#define DIAMETRE_ROUE     65.0
#define PERIMETRE_ROUE    PI * DIAMETRE_ROUE
#define ODOM_STEP_MM      2.5 //PERIMETRE_ROUE / ODOM_SECTIONS

// Motors
#define MOTOR_RIGHT_IN1   32
#define MOTOR_RIGHT_IN2   33
#define MOTOR_LEFT_IN3    25
#define MOTOR_LEFT_IN4    26

// IR Sensors
#define IR_LEFT           27
#define IR_RIGHT          35

// ODOM
#define ODOM_LEFT         12
#define ODOM_RIGHT        13

int IR_left_value         = 0; // Boolean?
int IR_right_value        = 0;

int odom_left_counter     = 0;
int odom_right_counter    = 0;

int state                 = 2;

int input_distance        = 100000; // in mm

void setup()
{
  Serial.begin(115200);

  pinMode(MOTOR_RIGHT_IN1,  OUTPUT);
  pinMode(MOTOR_RIGHT_IN2,  OUTPUT);
  pinMode(MOTOR_LEFT_IN3,   OUTPUT);
  pinMode(MOTOR_LEFT_IN4,   OUTPUT);

  attachInterrupt(IR_LEFT,    Read_IR_left,     CHANGE);
  attachInterrupt(IR_RIGHT,   Read_IR_right,    CHANGE);

  attachInterrupt(ODOM_LEFT,  Read_odom_left,   CHANGE);
  attachInterrupt(ODOM_RIGHT, Read_odom_right,  CHANGE);

  // Reset counters to avoid unexpected triggers after initialisation
  delay(1000);
  odom_left_counter   = 0;
  odom_right_counter  = 0;

}

void loop()
{
  /*
  Serial.println("------DEBUG-------");
  Serial.print("left:");            Serial.println(IR_left_value);                   Serial.print("right:"); Serial.println(IR_right_value);
  
  Serial.print("odom step:  ");     Serial.println(ODOM_STEP_MM);
  Serial.print("odom counter: ");   Serial.println(odom_left_counter);
  Serial.print("odom L en mm: ");   Serial.println(odom_right_counter*ODOM_STEP_MM);

  delay(100);
  */
  
  // /*
  switch(state)
  {
    case 0:
      Serial.println("driving left");

      Drive_left();

      if (  IR_right_value  && !IR_left_value   ){state = 1;}
      if (  !IR_right_value && !IR_left_value   ){state = 2;}
      if (  IR_right_value  && IR_left_value    ){state = 2;}
      if (  odom_left_counter >= input_distance / ODOM_STEP_MM){state = 3;}
      break;
    
    case 1:
      Serial.println("driving right");

      Drive_right();

      if (  IR_left_value   && !IR_right_value  ){state = 0;}
      if (  !IR_right_value && !IR_left_value   ){state = 2;}
      if (  IR_right_value  && IR_left_value    ){state = 2;}
      if (  odom_left_counter >= input_distance / ODOM_STEP_MM){state = 3;}
      break;

    case 2:
      Serial.println("driving forwards");

      Drive_forwards();

      if (  IR_left_value   && !IR_right_value  ){state = 0;}
      if (  IR_right_value  && !IR_left_value   ){state = 1;}
      if (  odom_left_counter >= input_distance / ODOM_STEP_MM){state = 3;}
      break;

    case 3:
      Serial.println("stopping.");
      
      Drive_stop();
      break;

  }
  // */
}

ICACHE_RAM_ATTR void Read_IR_left()
{
  IR_left_value = digitalRead(IR_LEFT);
}

ICACHE_RAM_ATTR void Read_IR_right()
{
  IR_right_value = digitalRead(IR_RIGHT);
}

ICACHE_RAM_ATTR void Read_odom_left()
{
  odom_left_counter++;
}

ICACHE_RAM_ATTR void Read_odom_right()
{
  odom_right_counter++;
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