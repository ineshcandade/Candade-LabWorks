#define trigPin 9
#define echoPin 10
#define redLed 7
#define blueLed 6
#define buzzer 5
#define buttonPin 8

long duration;
int distance;
int count = 0;
bool objectDetected = false;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 200;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Internal pull-up enabled

  digitalWrite(blueLed, HIGH); // Blue LED ON (default/idle)
  digitalWrite(redLed, LOW);
  digitalWrite(buzzer, LOW);

  Serial.begin(9600);
}

void loop() {
  // Trigger ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // Detection logic
  if (distance > 0 && distance < 10) {
    if (!objectDetected) {
      count++;
      objectDetected = true;
      Serial.print("Object Counted: ");
      Serial.println(count);

      // Alert: red LED + buzzer ON, blue LED OFF
      digitalWrite(redLed, HIGH);
      digitalWrite(buzzer, HIGH);
      digitalWrite(blueLed, LOW);
      delay(200); // Beep duration
      digitalWrite(buzzer, LOW);
    }
  } else {
    objectDetected = false;
    digitalWrite(redLed, LOW);
    digitalWrite(blueLed, HIGH); // Back to idle
  }

  // Debounced Reset Button
  if (digitalRead(buttonPin) == LOW) {
    if (millis() - lastDebounceTime > debounceDelay) {
      count = 0;
      Serial.println("Counter Reset!");
      lastDebounceTime = millis();
    }
  }

  delay(100); // Sensor refresh delay
}
