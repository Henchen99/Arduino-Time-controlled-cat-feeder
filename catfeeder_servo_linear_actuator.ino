/* Sweep
  by BARRAGAN <http://barraganstudio.com>
  This example code is in the public domain.

  modified 8 Nov 2013
  by Scott Fitzgerald
  http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>
#include <TimeLib.h>
//#include <Time.h>



Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

//Time t;



void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object

  Serial.begin(9600);
  setTime(19,46,50,20,9,21);  //set own time before plug into wall by: hour, minute, second, day, month, year

}

void loop(){
  digitalClockDisplay();
  delay(1000);  
  time_t t_now=now();
  
  if(hour(t_now)==19 && minute(t_now)==47 && second(t_now)==00){  //runs 'turnservo' function at exactly 12:00:00
      turnservo(); 
  }
  

}




void digitalClockDisplay()
{
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.print(" ");
  Serial.print(day());
  Serial.print(" ");
  Serial.print(month());
  Serial.print(" ");
  Serial.print(year());
  Serial.println();  
}



void printDigits(int digits)
{
  Serial.print(":");
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits);  
}



void turnservo(){
  myservo.attach(9);  //servo attached
  myservo.write(0); //RETRACT
  delay(400);   //spin 360 degrees 
  myservo.write(90); //servo stop
  delay(3000);   //PAUSE
  myservo.write(180); //PUSH
  delay(400);   //spin 360 degrees
  myservo.write(90); //servo stop
  delay(3000);   //PAUSE
  myservo.write(0); //RETRACT
  delay(400);   //spin 360 degrees 
  myservo.write(90); //servo stop
  delay(3000);   //PAUSE
  myservo.write(180); //PUSH
  delay(400);   //spin 360 degrees
  myservo.write(90); //servo stop
}
