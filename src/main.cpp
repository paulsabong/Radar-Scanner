#include <Arduino.h>
#include <Servo.h> 

//Servo objects
Servo SG90; 

//variable declarations
const int ECHO_PIN = 10; //sensor echo pin
const int TRIG_PIN = 9; //sensor trigger pin
const int SERVO_PIN = 8; //servo motor pin
int angle; //Current angle of servo motor
long distance; //Current distance calculated from sensor echoing duration
const float SPEED_OF_SOUND = 0.0343f; //Speed travelled by ultrasonic waves in cm/us
const int STARTING_ANGLE = 0; //Starting angle of servo motor
const int ENDING_ANGLE = 180; //Ending angle of servo motor
const int STEP = 1; //Number of steps by servo motor 

//Function declarations
void SweepAndDetect();
long GetDistance();
void OutputObjectLocation(int angle, long distance);

void setup(){
    SG90.attach(SERVO_PIN);
    pinMode(ECHO_PIN,INPUT);
    pinMode(TRIG_PIN,OUTPUT); 
    Serial.begin(9600);
}

void loop(){ 
    SweepAndDetect();
}

//Function definitions
void SweepAndDetect(){
    for(angle = STARTING_ANGLE; angle <= ENDING_ANGLE; angle+=STEP){ 
        SG90.write(angle);
        delay(15);
        distance = GetDistance();
        OutputObjectLocation(angle,distance); 
    }
    for(angle = ENDING_ANGLE; angle >= STARTING_ANGLE; angle-=STEP){
        SG90.write(angle);
        delay(15);
        distance = GetDistance(); 
        OutputObjectLocation(angle,distance); 
    }
}

long GetDistance(){
    digitalWrite(TRIG_PIN, LOW); 
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10); 
    digitalWrite(TRIG_PIN, LOW);
    unsigned long duration = pulseIn(ECHO_PIN, HIGH, 30000);
    distance = (SPEED_OF_SOUND * duration)/2; 
    return distance; 
}

void OutputObjectLocation(int angle, long distance){
    Serial.print(angle);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
}
