/*
   PIR sensor tester
*/


#include <OSSex.h>
#include <Wire.h> // fickle library you have to include




int ledPin = 13;                // choose the pin for the LED
int inputFront = A9;               // choose the input pin (for PIR sensor)
int inputBack = A7;               // choose the input pin (for PIR sensor)

int pirState = LOW;             // we start, assuming no motion detected
int valFront = 0;                    // variable for reading the pin status
int valBack = 0;
int onOffControll = A3; // HP0
int photocontroll = A2; //HP1


void setup() {
  Toy.setHackerPort(HACKER_PORT_PWM);
  Toy.attachClick(click); 

  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputFront, INPUT);     // declare sensor as input
  pinMode(inputBack, INPUT);     // declare sensor as input

  Serial.begin(9600);

  // initialize digital pin photocontroll as an output.
  pinMode(photocontroll, OUTPUT);
  pinMode(onOffControll, OUTPUT);
  analogWrite(photocontroll, 10);   // turn the LED on (HIGH is the voltage level)
    //  runCameraTrap();

      delay(5000); // 5 seconds to run away

}

void loop() {
  // analogWrite(onOffControll, 200);


  valFront = analogRead(inputFront);  // read input value
    valBack = analogRead(inputBack);  // read input value

    Serial.print ("Motion reading: Front \t");
  Serial.print(valFront);
  Serial.print ("\t   Back \t ");
    Serial.print(valBack);

  if (valFront || valBack > 100) {            // check if the input is HIGH
    digitalWrite(ledPin, HIGH);  // turn LED ON
    if (pirState == LOW) {
      // we have just turned on
      Serial.print("\t Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;

      runCameraTrap();

    }
  } else {
    digitalWrite(ledPin, LOW); // turn LED OFF
    if (pirState == HIGH) {
      // we have just turned of
      Serial.print("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
  Serial.println();
}

void runCameraTrap() {
  onoff();   //turn on camera
  delay(100);                       // wait for a second


  takephoto();
  delay(4000);
//
//  takephoto();
//  delay(4000);
//
  onoff();
  delay(1000);//sleep for  secs


}



void takephoto() {
  Serial.println("Takephoto");
  digitalWrite(photocontroll, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(photocontroll, HIGH);    // turn the LED off by making the voltage LOW
  delay(50);                       // fine tuning this parameter
  digitalWrite(photocontroll, LOW);   // turn the LED on (HIGH is the voltage level)



}

void onoff() {

  Serial.println("Turn on/off");

  analogWrite(onOffControll, 0);
  analogWrite(onOffControll, 150);
  delay(1);
  analogWrite(onOffControll, 0);


}

void click() {
onoff();
}

