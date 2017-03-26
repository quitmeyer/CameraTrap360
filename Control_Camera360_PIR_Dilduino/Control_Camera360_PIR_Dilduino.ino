/*
   PIR sensor tester
*/


#include <OSSex.h>
#include <Wire.h> // fickle library you have to include




int ledPin = 13;                // choose the pin for the LED
int inputPin = A2;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status

int onOffControll = 6; // HP0
int photocontroll = 9; //HP1


void setup() {
  Toy.setHackerPort(HACKER_PORT_PWM);


  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input

  Serial.begin(9600);

  // initialize digital pin photocontroll as an output.
  pinMode(photocontroll, OUTPUT);
  pinMode(onOffControll, OUTPUT);
  analogWrite(photocontroll, 10);   // turn the LED on (HIGH is the voltage level)

}

void loop() {
  // analogWrite(onOffControll, 200);


  val = analogRead(inputPin);  // read input value
    Serial.print ("Motion reading:  ");
  Serial.print(val);
  Serial.print ("    ");
  if (val > 100) {            // check if the input is HIGH
    digitalWrite(ledPin, HIGH);  // turn LED ON
    if (pirState == LOW) {
      // we have just turned on
      Serial.print("Motion detected!");
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
  delay(1000);                       // wait for a second


  takephoto();
  delay(4000);

  takephoto();
  delay(4000);

  onoff();
  delay(1000);//sleep for 5 secs


}




void takephoto() {
  Serial.println("Takephoto");
  analogWrite(photocontroll, 15);   // turn the LED on (HIGH is the voltage level)
  analogWrite(photocontroll, 150);    // turn the LED off by making the voltage LOW
  delay(50);                       // fine tuning this parameter
  analogWrite(photocontroll, 15);   // turn the LED on (HIGH is the voltage level)



}

void onoff() {

  Serial.println("Turn on/off");

  analogWrite(onOffControll, 0);
  analogWrite(onOffControll, 150);
  delay(1);
  analogWrite(onOffControll, 0);


}
