// C++ code
//
# define BTN 2
# define LED 12
volatile bool isBtnPressed = false;
int prev = 0;
int state = 0;
void btnPressed(){
  prev = millis();  // set the prev whenever the button is pressed.
  isBtnPressed = true;
}
void setup(){
  pinMode(LED, OUTPUT);
  pinMode(BTN , INPUT);
  attachInterrupt(digitalPinToInterrupt(BTN),btnPressed,RISING);
  Serial.begin(9600);
}

void loop(){
  unsigned int curr = millis();
  if(curr - prev >= 50){
    if(isBtnPressed){
      state= state^1;
      isBtnPressed = false;
    }
    prev = curr;
  }
  digitalWrite(LED,state);
}
