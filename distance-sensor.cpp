#define TRIG_PIN 9
#define ECHO_PIN 10
#define LED_PIN 11

long duration;
int distance;

unsigned long previousMillis = 0;
int ledState = LOW;
int blinkInterval = 1000; // Default to slow blink

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // 1. Fire the ultrasonic pulse 
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // 2. Measure the echo 
  duration = pulseIn(ECHO_PIN, HIGH);

  // 3. Calculate distance in cm
  distance = duration * 0.034 / 2;

  // 4. Simple, clear threshold logic! 
  // Instead of math formulas, we just create "zones"
  
  if (distance <= 10) {
    // ZONE 1: Dangerously close! (0 to 10cm)
    blinkInterval = 100;  // Very fast blink
  } 
  else if (distance <= 20) {
    // ZONE 2: Getting closer (11 to 20cm)
    blinkInterval = 300;  // Fast blink
  } 
  else if (distance <= 40) {
    // ZONE 3: Medium range (21 to 40cm)
    blinkInterval = 600;  // Medium blink
  } 
  else {
    // ZONE 4: Far away or nothing detected (41cm and beyond)
    // This catches everything else, acting as our "constrain"
    blinkInterval = 1000; // Slow, relaxed blink
  }

  // 5. The Non-Blocking Blink Logic 💡
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= blinkInterval) {
    previousMillis = currentMillis; // Reset the timer
    
    // Toggle the LED state
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    digitalWrite(LED_PIN, ledState);
  }
}
