
const int pirPin = 2;    
const int buzzerPin = 3;  
const int ledPin = 4;     

unsigned long prev = 0; 
const long blinkInterval = 250;   
int ledState = LOW;               

void setup() {
  pinMode(pirPin, INPUT);   
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int motionDetected = digitalRead(pirPin);
  
  if (motionDetected == HIGH) {
    tone(buzzerPin, 1000); 

    unsigned long curr = millis();
    
    if (curr - prev >= blinkInterval) {
      prev = curr; 
      
      if (ledState == LOW) {
        ledState = HIGH;
      } else {
        ledState = LOW;
      }
       
    }
    
  } else {
    noTone(buzzerPin);         
    ledState = LOW;           
  }
  
  digitalWrite(ledPin, ledState);
}
