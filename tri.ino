#include <dht.h>
#include<LiquidCrystal.h>
// defines variables
dht DHT;
#define DHT11_PIN 9
LiquidCrystal lcd(12,11,5,4,3,2);
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
const int trigPin=7;
const int echoPin=8;
#define watrPump 10
void setup() {
  Serial.begin(9600); // Serial Communication is starting with 9600 of baudrate speed
  pinMode(watrPump, OUTPUT);
  pinMode(trigPin, OUTPUT); //Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); //Sets the echoPin as an INPUT

}
void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
if(distance <=15) //You can adjust the distance in cm
{
    delay(300);//initial delay
  digitalWrite(watrPump, HIGH);
   Serial.println("Motor = ON");
  int chk = DHT.read11(DHT11_PIN);
   lcd.setCursor(0,1);
   lcd.print("Tmp:");
   lcd.print(DHT.temperature);
   delay(3000);
   lcd.clear();
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);

}
else
digitalWrite(watrPump, LOW); // To turn off the Water pump
}
