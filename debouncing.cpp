const int buttonPin = 2; 
const int ledPin = 13;    

// Variables will change:
int ledState = HIGH;
int btn;            
int lastBtn = LOW; 

unsigned long prev = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState);
}

void loop() {
  int reading = digitalRead(buttonPin);

  // If the switch changed, due to noise or pressing:
  if (reading != lastBtn) {
      // reset the debouncing timer
      prev = millis();
  }

  if ((millis() - prev) >= 50) {
    // if the button state has changed:
    if (reading != btn) {
        btn = reading;

        // only toggle the LED if the new button state is HIGH
      	// do whatever with btn.
        if (btn == HIGH) {
          ledState = !ledState;
        }
    }
  }

  // set the LED:
  digitalWrite(ledPin, ledState);
  lastBtn = reading;
}
