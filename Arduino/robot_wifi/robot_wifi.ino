#include <WiFi.h>
#include <WiFiServer.h>
#include <WiFiClient.h>

//######################################
//##                                  ##
//##           DEFINITION             ##
//##                                  ##
//######################################

// Motors
#define MOTOR_RIGHT_IN1 32
#define MOTOR_RIGHT_IN2 33
#define MOTOR_LEFT_IN3 25
#define MOTOR_LEFT_IN4 26


// IR Sensors
#define IR_LEFT 27
#define IR_RIGHT 14


//######################################
//##                                  ##
//##            VARIABLES             ##
//##                                  ##
//######################################

void setup()
{
  // Reglage du port UART :
  Serial.begin(115200);

  pinMode(MOTOR_RIGHT_IN1,OUTPUT);
  pinMode(MOTOR_RIGHT_IN2,OUTPUT);
  pinMode(MOTOR_LEFT_IN3,OUTPUT);
  pinMode(MOTOR_LEFT_IN4,OUTPUT);

  pinMode(IR_LEFT,INPUT);
  pinMode(IR_LEFT,INPUT);

}

//######################################
//##                                  ##
//##             LOOP                 ##
//##                                  ##
//######################################

void loop()
{
  int state = 1;

  int ir_left_value = digitalRead(IR_LEFT);

  switch(state)
  {
    case 1:
      Serial.println(ir_left_value);
  }
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

void Drive_forwards(int time){
  Motor_right(1);
  delay(250);
  Motor_left(1);
}

void Drive_backwards(int time){
  Motor_right(-1);
  Motor_left(-1);
}

void Drive_right(int time){
  Motor_right(0);
  Motor_left(1);
}

void Drive_left(int time){
  Motor_right(1);
  Motor_left(0);
}

void Drive_stop(){
  Motor_right(0);
  delay(5);
  Motor_left(0);
}