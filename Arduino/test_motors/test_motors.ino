
// Motors
#define MOTOR_RIGHT_IN1 32
#define MOTOR_RIGHT_IN2 33
#define MOTOR_LEFT_IN3 25
#define MOTOR_LEFT_IN4 26

void setup() {
  Serial.begin(115200);

  pinMode(MOTOR_RIGHT_IN1,OUTPUT);
  pinMode(MOTOR_RIGHT_IN2,OUTPUT);
  pinMode(MOTOR_LEFT_IN3,OUTPUT);
  pinMode(MOTOR_LEFT_IN4,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(MOTOR_RIGHT_IN1,HIGH);
  digitalWrite(MOTOR_RIGHT_IN2,LOW);

  digitalWrite(MOTOR_LEFT_IN3,LOW);
  digitalWrite(MOTOR_LEFT_IN4,HIGH);
}
