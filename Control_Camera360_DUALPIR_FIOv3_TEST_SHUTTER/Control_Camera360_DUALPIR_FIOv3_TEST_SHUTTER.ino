/*
   PIR sensor tester
*/


int ledPin = 3;                // choose the pin for the LED
int ledPin2 = 4;                // choose the pin for the LED

int inputFront = A2;               // choose the input pin (for PIR sensor)
int inputBack = A3;               // choose the input pin (for PIR sensor)

int pirState = LOW;             // we start, assuming no motion detected
int valFront = 0;                    // variable for reading the pin status
int valBack = 0;
int onOffControl  = 9;
int shutterControl  = 10;


void setup() {


  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputFront, INPUT);     // declare sensor as input
  pinMode(inputBack, INPUT);     // declare sensor as input

  Serial.begin(9600);

  // initialize digital pin shutterControl  as an output.
  pinMode(shutterControl , OUTPUT);
  pinMode(onOffControl , OUTPUT);
//  analogWrite(shutterControl , 10);   // turn the LED on (HIGH is the voltage level)

 // delay(5000); // 5 seconds to run away

}

void loop() {
        Serial.println("start");

  delay(3000);
        Serial.println("Run Trap");
      runCameraTrap(5000);

      Serial.println("Run Trap");
delay(1000);

      Serial.println("end loop");


}

void runCameraTrap(int recordtime) {
          Serial.println("TURN ON");

  onoff();   //turn on camera
  delay(100);                       // wait a bit

  //          Serial.println("Run Shutter");

  takephoto();
  delay(recordtime);

    takephoto();
  //
    delay(recordtime);

            Serial.println("TURN OFF");

  onoff();
  delay(4000);//sleep for  secs


}



void takephoto() {
  Serial.println("Takephoto");
  digitalWrite(shutterControl , LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(shutterControl , HIGH);    // turn the LED off by making the voltage LOW
  delay(50);                       // fine tuning this parameter
  digitalWrite(shutterControl , LOW);   // turn the LED on (HIGH is the voltage level)



}

void onoff() {

  Serial.println("Turn on/off");

  analogWrite(onOffControl , 0);
  
  analogWrite(onOffControl , 150);
  delay(5);
  analogWrite(onOffControl , 0);


}



