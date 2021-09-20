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
  setTime(19,00,0,20,9,21);  //hour, minute, second, day, month, year

}

void loop(){
  digitalClockDisplay();
  delay(1000);  
  time_t t_now=now();
  if(hour(t_now)==12 && minute(t_now)==00){
      printf("servo turning"); 
  }

  /*if(t.hour == 12 && t.min == 00){
   *  turnservo();
   * }
   */
  

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
  myservo.detach(); //out position
  delay(2000);
  myservo.attach(9);  //servo attached
  myservo.write(180); //spin 1 direction
  delay(180);   //spin 180 deg
  myservo.detach(); //in position
  delay(2000);  
  myservo.attach(9);  
  myservo.write(0); //spin other direction
  delay(180);   //spin 180 deg
  myservo.detach(); //servo stop
}
