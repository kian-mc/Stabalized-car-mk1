//NODE MCU CODE FOR WIFI AND MOTOR CONTROL

 //blynk configuration
#define BLYNK_TEMPLATE_ID "TMPL2VEKtzQ4d"
#define BLYNK_TEMPLATE_NAME "Stabalized car"
#define BLYNK_AUTH_TOKEN "zUOvz-9sPqX2ESdTc87eVwVrYnT0u0Dw"

//debug console
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>




// WiFi credentials.
char ssid[] = "AA54AD";
char pass[] = "otpywgotpywg00";


//char ssid[] = "mechlab";
//char pass[] = "etufh89959";


//blynk uptime counter
BlynkTimer timer;

//motor speed variables
int motorSpeedA = 0;
int motorSpeedB = 0;

//pwm speed control for motors
int sp1 = D4;
int sp2 = D5;

//H-bridge connections
int in1 = D2;
int in2 = D3;
int in3 = D0;
int in4 = D1;

//turning variable for when turning in progress
bool turning = false;


// helper functions for moving the moters
void backward(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void forward(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void left(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void right(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void stop(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
//blynk virtual pin y from joystick
BLYNK_WRITE(V0)
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();

  if (value < 120 && turning == false) {
    backward();
    // have a set backwards speed because its hard to control
    motorSpeedA = 120;
    motorSpeedB = 120;
  }
  else if (value > 135 && turning == false) {
    forward();
    // Convert the increasing Y-axis readings for going forward 
    motorSpeedA = value;
    motorSpeedB = value;
  }
  else if (turning == false){
    //if joystick axis in center and a turn is not in progress then stop
    stop();
  }



  // Update state
  Blynk.virtualWrite(V1, value);
}
//blynk virtual pin x from joystick
BLYNK_WRITE(V1){
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();
  if (value < 80) {
    turning = true;
    left();
    // Move to left with set speed
    motorSpeedA = 120;
    motorSpeedB = 120;
    // Confine the range from 0 to 255
    if (motorSpeedA < 0) {
      motorSpeedA = 0;
    }
    if (motorSpeedB > 255) {
      motorSpeedB = 255;
    }
  }else if (value > 175) {
     turning = true;
     right();
    // Move to right
   motorSpeedA = 120;
    motorSpeedB = 120;
    // Confine the range from 0 to 255
     if (motorSpeedA > 255) {
      motorSpeedA = 255;
    }
    if (motorSpeedB < 0) {
      motorSpeedB = 0;
    }
  } else{
    turning = false;
  }
  
  // Update state
  Blynk.virtualWrite(V1, value);
}
void myTimerEvent()
{
  //blynk time up counter
  Blynk.virtualWrite(V2, millis() / 1000);
}
// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
 //not used
}



void setup()
{
  // Debug console
  Serial.begin(115200);
  
  //motor setup and stop on startup
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT); 
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT); 

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  //start the blynk procces
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  

  




  
}
void loop()
{
  Blynk.run();
  timer.run();
  analogWrite(sp1, motorSpeedA); // Send PWM signal to motor A
  analogWrite(sp2, motorSpeedB); // Send PWM signal to motor B
  
}
