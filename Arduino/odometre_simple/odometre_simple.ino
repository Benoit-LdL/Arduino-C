
#define PI 3.1415926535897932384626433832795

#define ODOM_SECTIONS   40
#define L_ENTRE_ROUE    135
#define DIAMETRE_ROUE   65
#define PERIMETRE_ROUE  PI*DIAMETRE_ROUE
#define L_PER_INTER     PERIMETRE_ROUE / ODOM_SECTIONS

#define PIN_ODOM 12

int odom_counter;

void setup() {
  Serial.begin(115200);
  attachInterrupt(PIN_ODOM,Read_odom,CHANGE);


}

void loop() {
  Serial.println("---");
  Serial.println(odom_counter);
  delay(100); 
}

ICACHE_RAM_ATTR void Read_odom()
{
  odom_counter++;
}
