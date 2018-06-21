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
  // analogWrite(shutterControl , 10);   // turn the LED on (HIGH is the voltage level)
  //  runCameraTrap();

  delay(5000); // 5 seconds to run away

}

void loop() {

  readSensors();


  //Run Functions
  if (valFront || valBack > 100) {            // check if the input is HIGH
    digitalWrite(ledPin, HIGH);  // turn LED ON
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("\t Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;

      runCameraTrap(10000);

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

void readSensors() {
  /**
    Read Sensors
  */
  valFront = analogRead(inputFront);  // read input value
  valBack = analogRead(inputBack);  // read input value

  Serial.print ("Motion reading: Front \t");
  Serial.print(valFront);
  Serial.print ("\t   Back \t ");
  Serial.print(valBack);
}


void runCameraTrap(int recordtime) {
  Serial.println("TURN ON");

  onoff();   //turn on camera
  delay(100);                       // wait a bit

  //Start Recording
  runshutter();
  //Default record time
  delay(recordtime);

  /*
     TODO
     Keep writing about how this code works
     and make sure if there is still movement
     you can keep recording
  */
  int extrarecordtimes = 0;
  boolean stillmoving = true;

  while (stillmoving == true) {
    readSensors();

    if (valFront || valBack > 100) {            // check if the input is HIGH
      digitalWrite(ledPin, HIGH);  // turn LED ON
      Serial.println("\t still some movement!");
      stillmoving = true;
      delay(2000);

    }
    else {
      digitalWrite(ledPin, LOW); // turn LED OFF
        Serial.print("Motion ended!");
        // We only want to print on the output change, not state
        stillmoving = false;
      
    }
    extrarecordtimes = extrarecordtimes + 1;
    Serial.println("How many times have we recorded extra stuff in one video");
    Serial.println(extrarecordtimes);
  }


  //Stop Recording
  Serial.println("stop recording");
  runshutter();
  delay(recordtime);

  Serial.println("TURN OFF");

  onoff();
  delay(500);//sleep


}




void runshutter() {
  Serial.println("Run Shutter");
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

