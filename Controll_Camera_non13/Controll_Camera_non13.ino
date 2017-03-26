/*
turn on camera and off
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

