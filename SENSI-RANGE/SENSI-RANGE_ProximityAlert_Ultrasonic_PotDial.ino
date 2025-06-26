#define trigPin 9
#define echoPin 10
#define whiteLED 5
#define redLED 6
#define buzzerPin 7
#define potPin A0

long duration;
int distance;
int thresholdDistance = 15; // Default threshold (in cm)

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(whiteLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // Ultrasonic sensor pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // Read potentiometer to adjust threshold distance
  thresholdDistance = map(analogRead(potPin), 0, 1023, 5, 50); // Adjust range for threshold

  // Distance logic for LED and buzzer
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm | Threshold: ");
  Serial.print(thresholdDistance);
  Serial.println(" cm");

  if (distance < thresholdDistance && distance > 0) {
    digitalWrite(redLED, HIGH);   // Turn on red LED for proximity alert
    digitalWrite(whiteLED, LOW);  // Turn off white LED
    digitalWrite(buzzerPin, HIGH);  // Buzzer sounds when object is close
  } else {
    digitalWrite(redLED, LOW);    // Turn off red LED
    digitalWrite(whiteLED, HIGH); // Turn on white LED for safe zone
    digitalWrite(buzzerPin, LOW); // Turn off buzzer when object is far
  }

  delay(300); // Small delay to prevent flooding Serial Monitor
}

