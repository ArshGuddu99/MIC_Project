const int trigPin2 = 13;
const int echoPin2 = 11;
const int trigPin1=3;
const int echoPin1=10;
// defines variables
long duration1;
long duration2;
long distance1;
long distance2;
long distance;
void setup() {
pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
pinMode(trigPin2,OUTPUT);
pinMode(echoPin2,INPUT);
Serial.begin(9600); // Starts the serial communication
}
void loop() {
// Clears the trigPin
digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration1 = pulseIn(echoPin1, HIGH);
digitalWrite(trigPin2,LOW);
delayMicroseconds(2);
digitalWrite(trigPin2,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2,LOW);
duration2 = pulseIn(echoPin2, HIGH);
// Calculating the distance
distance1=duration1*0.034/2;
distance2=duration2*0.034/2;
if(distance1<distance2)
distance=distance1;
else if(distance2<distance1)
distance=38-distance2;
else if(distance1== distance2)
distance=distance1;
if(distance>40||distance<3)
loop();
Serial.println(distance);
delay(100);
}
