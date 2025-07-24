/**********Pokenom Chicken Protecter  **********/


/* Adjust these two values to reflect the
   position of the X ultrasonic sensor. */
 
 
 #include <Servo.h>

const int A = 14; /*14cm is the vertical distance from ultrasonicY(The one that detects the vertical distance)
to ultrasonicX (The one thatdetects the horizontal distance.)*/
const int B = 9; // 9cm is the horizontal distance from  ultrasonicX to ultrasonicY

/* Hardware connections */

const int trigPinX = 2, echoPinX = 4;
const int trigPinY = 5, echoPinY = 6;
// There are the pins for the ultrasonicX and ultrasonicY
/* Each ultrsonic has a trigPin to trig the ultrasonic sound pulse and echoPin to produce the pulse
  when the reflected signal is recieved*/

const int servoPinL = 8;//The pin for the right servo
const int servoPinR = 10;// the pin for the left servo

const int ledx = 11;// The pin for the red led which change brightness based on ultrasonicX
const int ledy = 3; // The pin for the green led which change brightness based on ultrasonicX

const int speaker = 7; //The pin for the speaker which produce the alarm if the object gets too close.
int brightnessX = 0, brightnessY = 0; // determine the brightness of the leds based on the distance. 
Servo servoL;// create an object for the right servo  to control it.
Servo servoR;//create an object for the left servo  to control it.

/*This is a function which calculate the distance by creating a sound pulse and find the distance
using the speed of the sound and detect the number of the pulse that come back within this time using 
echo pin*/
float measureDist(int trigPin, int echoPin)
{
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);
  return pulseIn(echoPin, HIGH)/ 2*.0343;  
} 


void setup()
{
  pinMode(trigPinX, OUTPUT);
  pinMode(trigPinY, OUTPUT);
  pinMode(servoPinL, OUTPUT);
  pinMode(servoPinR, OUTPUT);
  pinMode(ledx, OUTPUT);
  pinMode(ledy, OUTPUT);
  pinMode(speaker, OUTPUT);
  servoL.attach(servoPinL);//attach the left servo to the pin (functins of the library)
  servoR.attach(servoPinR); //attacn the right servo to the pin (funstions of the library)
  servoR.write(40); /*The right servo was too far to the left compared to the object so I gave it 
  initial angle so it works more accuratly*/
  servoL.write(75);/*The left servo was too far to the right compared to the object so I gave it 
  initial angle so it works more accuratly*/
}


void loop()
{
  float distX, distY;
  int pos, diff;
  int limDistX, limDistY;
  distX = measureDist(trigPinX, echoPinX);// measure the horizontal distance using the measureDist function
  limDistX = (int) constrain(distX, 4, 2*A);// it will constrain the value within a range of 4cm and twice the horizontal distance
  pos = map(limDistX, 4, 2*A, 45, 135);// map the angle based on the horizontal distance
  
  distY = measureDist(trigPinY, echoPinY); // measure the vertical distance using the measureDist function
  limDistY = (int)constrain(distY, 4, B);// it will constrain the value within a range of 4cm and the vertical distance
  diff = map(limDistY, 4, B, 40, 0);//map the angle based on the vertical distance

 /* if the angle is 135 it means that it is on the max horizontal distance so 
 it will reset the angles so the servo stay on a 90 angles which is when they 
 are not detecting anything*/
  if(pos == 135)
  {
    pos = 90;
    diff = 0;
  }

/*It will determine the brightness of the light based on the distance of the object form
the ultrasonicX and ultrasonicY */
   brightnessX = map(distX, 0,20, 255, 0); 
   brightnessY = map(distY, 0,20, 255, 0);

 /* If it detect the object out of the range of 20cm it will change the 
 brightness of the led to 0*/
  if (distX > 20){
    brightnessX = 0;
  }
  
  if (distY > 20){
    brightnessY = 0;
  }

 
  analogWrite(ledx, brightnessX);//Tuen on the red led and the brighness is besed on the distance of the object.
  analogWrite(ledy, brightnessY);//Tuen on the green led and the brighness is besed on the distance of the object.
  
  
  /* if the object is closer than 7cm to any of the ultrasonics the speaker will make an alaram and the led will blink*/
  if (distX < 7|| distY< 7){
     tone(speaker, 800);// 800 is the frequency of the speaker
     delay(50);// it delayed for 0.05 second
     noTone(speaker);// turn off
     delay(50);// delay for 0.05 seconds

     /* the ledx and the ledy will both starts to blink if the object is closer than 7cm to any of the
     ultrasonics */
     analogWrite( ledy, 255);
     analogWrite( ledx, 255);
     delay(250);
     analogWrite(ledy, 0);
     analogWrite(ledx, 0);
  } 
  
  else {
    noTone(speaker); //the speaker willnot turn off if no object is within the range
  }

  /*It will write the angles into the servo using the variables that
   are based on the vertical and horizontal distance*/
   servoL.write(pos - diff-25);
   servoR.write(pos + diff-50);
  delay(60);
}


   
