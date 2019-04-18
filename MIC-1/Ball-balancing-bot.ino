const int trigPin2=13;
const int echoPin2= 11;
const int trigPin1 =3;
const int echoPin1 =10;
#include<Servo.h>
#include<PID_v1.h>
long duration1;
long duration2;
double distance1;
double distance2;
double distance;
double angle=0;
int value;
int value_final;
double Kpagg=5;
double Kiagg=0.025 ;
double Kdagg=1.5;
/*double KpCons=0.5;
double KiCons=0.05;
double KdCons=0.25;*/
double Setpoint=18;
double error;
int value_prev=0;
int a;
PID myPID=PID(&distance,&angle,&Setpoint,Kpagg,Kiagg,Kdagg,DIRECT);
Servo abc;
void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin1,OUTPUT);
  pinMode(echoPin1,INPUT);
  pinMode(trigPin2,OUTPUT);
  pinMode(echoPin2,INPUT);
  Serial.begin(9600);
  value=0;
  abc.attach(5);
  myPID.SetMode(AUTOMATIC);
  myPID.SetOutputLimits(-60,60);
  abc.write(0);
  delay(15);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin1,LOW);
  delayMicroseconds(2);
 
  digitalWrite(trigPin1,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1,LOW);

  duration1=pulseIn(echoPin1,HIGH) ;
  
  digitalWrite(trigPin2,LOW);
  delayMicroseconds(2);
 
  digitalWrite(trigPin2,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2,LOW);

  duration2=pulseIn(echoPin2,HIGH);
  
  distance1= duration1*0.034/2;
  distance2= duration2*0.034/2;

 if(distance1<distance2)
    distance=distance1;
    
  else if(distance2<distance1)
      distance=38-distance2;

  else if(distance1== distance2)
      distance=distance1;
      
 if(distance>40||distance<3)
    loop();
    
  Serial.print("Distance:");
  Serial.println(distance);
  
 myPID.SetTunings(Kpagg,Kiagg,Kdagg);
 myPID.Compute();
 value=floor(angle);
 Serial.print("Value: ");
 Serial.println(value);
 value_final = 90 + value;
 Serial.print("Value_final:");
 Serial.println(value_final);
 abc.write(value_final);
 delay(30);
 delay(500);
}
