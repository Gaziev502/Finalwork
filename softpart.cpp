Khurshed, [04.06.19 15:57]
#include <Wire.h>
#include <VL53L0X.h>

int piezoPin = 8;
int piezoPin1 = 7;
VL53L0X sensor;
VL53L0X sensor2;

void setup()
{

  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
  digitalWrite(3, LOW);
  digitalWrite(5, LOW);

  delay(500);
  Wire.begin();


  Serial.begin (9600);

  digitalWrite(3, HIGH);
  delay(150);
  Serial.println("00");
  sensor.init(true);

  Serial.println("01");
  delay(100);
  sensor.setAddress((uint8_t)22);
  Serial.println("02");

  digitalWrite(5, HIGH);
  delay(150);
  sensor2.init(true);
  Serial.println("03");
  delay(100);
  sensor2.setAddress((uint8_t)25);
  Serial.println("04");

  Serial.println("addresses set");

}

void loop()
{
  Serial.print(sensor.readRangeSingleMillimeters());
  if (sensor.timeoutOccurred()) {
    Serial.print(" TIMEOUT");
  }
  Serial.print("     ");
  Serial.print(sensor2.readRangeSingleMillimeters());
  if (sensor2.timeoutOccurred()) {
    Serial.print(" TIMEOUT");
  }

 if (sensor.readRangeSingleMillimeters() <700 && sensor.readRangeSingleMillimeters() >= 600)
  {
         tone(piezoPin, 2000, 500);
         
         delay(100);
  }
  else  if ( sensor.readRangeSingleMillimeters() <600 && sensor.readRangeSingleMillimeters() >= 500)
  {
         tone(piezoPin, 2500, 500);
         
         delay(100);
  }
  else  if ( sensor.readRangeSingleMillimeters() <500 && sensor.readRangeSingleMillimeters() >= 400)
    {
         tone(piezoPin, 3000, 500);
         
         delay(100);
  }
  else if (sensor.readRangeSingleMillimeters() <400 && sensor.readRangeSingleMillimeters() >= 300)
  {
         tone(piezoPin, 3500, 500);
         
         delay(100);
  }
  else  if ( sensor.readRangeSingleMillimeters() <300 && sensor.readRangeSingleMillimeters() >= 200)
  {
         tone(piezoPin, 4000, 500);
         
         delay(100);
  }
  else  if ( sensor.readRangeSingleMillimeters() <200 && sensor.readRangeSingleMillimeters() >= 100)
    {
         tone(piezoPin, 4500, 500);
         
         delay(100);
  } 
  else  if ( sensor.readRangeSingleMillimeters() <100 && sensor.readRangeSingleMillimeters() >= 50)
    {
         tone(piezoPin, 5000, 500);
         
         delay(100);
  } 


  else noTone;  //SENSORPART2

   if (sensor2.readRangeSingleMillimeters() <700 && sensor2.readRangeSingleMillimeters() >= 600)
  {
         tone(piezoPin1, 2000, 500);
         
         delay(100);
  }
  else  if ( sensor2.readRangeSingleMillimeters() <600 && sensor2.readRangeSingleMillimeters() >= 500)
  {
         tone(piezoPin1, 2500, 500);
         
         delay(100);
  }
  else  if ( sensor2.readRangeSingleMillimeters() <500 && sensor2.readRangeSingleMillimeters() >= 400)
    {
         tone(piezoPin1, 3000, 500);
         
         delay(100);
  }
  else if (sensor2.readRangeSingleMillimeters() <400 && sensor2.readRangeSingleMillimeters() >= 300)
  {
         tone(piezoPin1, 3500, 500);
         
         delay(100);
  }
  else  if ( sensor2.readRangeSingleMillimeters() <300 && sensor2.readRangeSingleMillimeters() >= 200)
  {
         tone(piezoPin1, 4000, 500);
         
         delay(100);
  }
  else  if ( sensor2.readRangeSingleMillimeters() <200 && sensor2.readRangeSingleMillimeters() >= 100)
    {
         tone(piezoPin1, 4500, 500);
         
         delay(100);
  } 
  else  if ( sensor2.readRangeSingleMillimeters() <100 && sensor2.readRangeSingleMillimeters() >= 50)
    {
         tone(piezoPin1, 5000, 500);
         
         delay(100);
  } 


  else noTone;

   
  Serial.println();
}
