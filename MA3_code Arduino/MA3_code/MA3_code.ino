int led = 10;
int buttonPin = 9;
 int mappedMin = 0; 

void setup() {
  // put your setup code here, to run once:

  //configure our pins
  //set our LED pin as an output
  pinMode(led, OUTPUT);
  pinMode(buttonPin, INPUT);

  Serial.begin(9600); //initalise Serial comms 
  Mouse.begin();

  //map an initial minimum depending on the weight of the chair
  int average = 0;
  for(int i = 0; i < 20; i++){
    average = average + analogRead(A9);
  }
  mappedMin = average/20;
}

void loop() {
  
 int buttonPinState = digitalRead(buttonPin); //0,1 (HIGH,LOW)
 
 digitalWrite(led, buttonPinState);
  delay(10);

  //if the button is pressed user can use the mouse as usual, if not pressed code will run
  
  if(buttonPinState == 0){
  int val = analogRead(A9);
  Serial.println(val);
  int moveVal = map(val, mappedMin, mappedMin + 600, 0, 1023);
  Mouse.move(moveVal, 0, 0);
  delay(2);
  
   }
  

}
