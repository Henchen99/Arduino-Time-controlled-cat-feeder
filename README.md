# Arduino-Time-controlled-cat-feeder

This project uses and arduino and a servo to create a cat food dispenser.

The containter and linear actuator is 3D printed.

A servo is placed on the linear actuator contraption converting rotational motion into linear.

I currently do not have a RTC therefore I am using just the arduino itself to keep track of time although I realise it is not most accurate (by a few minutes a day) however it is sufficient in this case.

I wrote some simple code that constantly reads the time and at a specific time, it will turn the servo back and forth as many times as required.

It works well and is very important when nobedy is at home to feed the cat
