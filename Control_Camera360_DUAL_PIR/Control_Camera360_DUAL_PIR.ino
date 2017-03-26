/*
 * PIR sensor tester
 * Very basic
 * Just turns camera on an takes a photo when motion is detected
 * //Camera needs to start in OFF position
 * For use with a SINGLE PIR sensor
 */
 
int ledPin = 13;                // choose the pin for the LED


int inputPin = A2;               // choose the input pin (for PIR sensor)
int inputPin1 = A3;               // choose the input pin (for PIR sensor)


int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status

int onOffControll = 6;
int photocontroll = 8;

 
void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input
   pinMode(inputPin1, INPUT);     // declare sensor as input

  Serial.begin(9600);

   // initialize digital pin photocontroll as an output.
  pinMode(photocontroll, OUTPUT);
  pinMode(onOffControll, OUTPUT);
  analogWrite(photocontroll, 10);   // turn the LED on (HIGH is the voltage level)

}
 
void loop(){
 // analogWrite(onOffControll, 200);

  
  val = analogRead(inputPin)+analogRead(inputPin1);  // read input value of both of them, ususally it's zero
  Serial.print(val);
  Serial.print ("    ");
  if (val > 100) {            // check if the input is HIGH
    digitalWrite(ledPin, HIGH);  // turn LED ON
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;

runCameraTrap();
      
    }
  } else {
    digitalWrite(ledPin, LOW); // turn LED OFF
    if (pirState == HIGH){
      // we have just turned of
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
  Serial.println();
}

void runCameraTrap(){
 onoff();   //turn on camera
  delay(10);                       // wait for a second


  takephoto();
  delay(3000);

  onoff();
  delay(1000);//sleep 


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
