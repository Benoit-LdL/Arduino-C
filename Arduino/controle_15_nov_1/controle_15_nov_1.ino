// ODOM
#define PI                3.1415926535897932384626433832795
#define ODOM_SECTIONS     40.0
#define L_ENTRE_ROUE      135.0
#define DIAMETRE_ROUE     65.0
#define PERIMETRE_ROUE    PI * DIAMETRE_ROUE
#define ODOM_STEP_MM      2.5 //PERIMETRE_ROUE / ODOM_SECTIONS

// Motors
#define MOTOR_RIGHT_IN1   16
#define MOTOR_RIGHT_IN2   17
#define MOTOR_LEFT_IN3    18
#define MOTOR_LEFT_IN4    19

// IR Sensors
#define IR_LEFT           15

// ODOM
#define ODOM_LEFT         2
#define ODOM_RIGHT        4

int IR_left_value         = 0;

int odom_left_counter     = 0;
int odom_right_counter    = 0;

int state                 = 0;

int distance1             = 2000; // in mm
int distance2             = 500; // in mm

int start_rotation;

void setup() {
  Serial.begin(115200);

  pinMode(MOTOR_RIGHT_IN1,  OUTPUT);
  pinMode(MOTOR_RIGHT_IN2,  OUTPUT);
  pinMode(MOTOR_LEFT_IN3,   OUTPUT);
  pinMode(MOTOR_LEFT_IN4,   OUTPUT);

  attachInterrupt(IR_LEFT,    Read_IR_left,     CHANGE);

  attachInterrupt(ODOM_LEFT,  Read_odom_left,   CHANGE);
  attachInterrupt(ODOM_RIGHT, Read_odom_right,  CHANGE);

  //#######
  //  1
  //#######
  // Reset counters to avoid unexpected triggers after initialisation
  delay(2000);

  odom_left_counter   = 0;
  odom_right_counter  = 0;
}


void loop() {
  /*
  Drive_forwards();
  Serial.println("------DEBUG-------");
  Serial.print("left:");            Serial.println(IR_left_value);
  
  Serial.print("odom step:  ");     Serial.println(ODOM_STEP_MM);
  Serial.print("odom counter: ");   Serial.println(odom_left_counter);
  Serial.print("odom L en mm: ");   Serial.println(odom_left_counter*ODOM_STEP_MM);

  delay(100);
  */


  // /*
  switch(state)
  {  
    case 0: // Drive left
      Serial.println("Drive left");
      Drive_left();

      if (  IR_left_value ){state = 1;}
      if (  odom_left_counter >= distance1 / ODOM_STEP_MM){state = 2;}  // if distance >= stop 1
      break;


    case 1: // Drive right
      Serial.println("Drive right");
      Drive_right();
      
      if (  !IR_left_value ){state = 0;}
      if (  odom_left_counter >= distance1 / ODOM_STEP_MM ){state = 2;}  // if distance >= stop 1
      break;
    
    case 2: // rotate 180 deg
      Drive_stop();
      Serial.println("Rotate");
      //#######
      //  4
      //#######
      delay(1000);
      
      //#######
      //  5
      //#######
      start_rotation = odom_left_counter;


      Rotate();
      delay(600);
      // while (odom_left_counter-start_rotation < ODOM_SECTIONS/2) // rotate half a turn
      // {
      // }
      Drive_stop();
      odom_left_counter = 0;
      state = 0;
      break;

    case 3: // stop
      Serial.println("Stop");
      Drive_stop();
      break;
  }
  // */

}

ICACHE_RAM_ATTR void Read_IR_left()
{
  IR_left_value = digitalRead(IR_LEFT);
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
  Motor_right(-1);
  Motor_left(-1);
}

void Drive_backwards(){
  Motor_right(-1);
  Motor_left(-1);
}

void Drive_right(){
  Motor_right(0);
  Motor_left(-1);
}

void Drive_left(){
  Motor_right(-1);
  Motor_left(0);
}

void Rotate(){
  Motor_right(1);
  Motor_left(-1);
}

void Drive_stop(){
  Motor_right(0);
  Motor_left(0);
}