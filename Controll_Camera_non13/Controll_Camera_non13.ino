/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. photocontroll is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino model, check
  the Technical Specs of your board  at https://www.arduino.cc/en/Main/Products

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald

  modified 2 Sep 2016
  by Arturo Guadalupi

  modified 8 Sep 2016
  by Colby Newman
*/

int onOffControll = 6;
int photocontroll = 8;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin photocontroll as an output.
  pinMode(photocontroll, OUTPUT);
  pinMode(onOffControll, OUTPUT);
  Serial.begin(9600);
  analogWrite(photocontroll, 10);   // turn the LED on (HIGH is the voltage level)


}

// the loop function runs over and over again forever
void loop() {
  analogWrite(onOffControll, 200);

  onoff();   //turn on camera
  delay(1000);                       // wait for a second


  takephoto();
  delay(4000);

  takephoto();
  delay(4000);


  takephoto();
  delay(4000);

  //onoff();
  delay(3000);//sleep for 5 secs


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

