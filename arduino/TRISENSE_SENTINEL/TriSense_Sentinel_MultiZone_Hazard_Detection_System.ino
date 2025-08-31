int flamePin = A0;      
int irPin = 2;          
int redLED = 8;        
int yellowLED = 9;   
int buzzer = 10;       

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(irPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int flameValue = analogRead(flamePin);
  int motionDetected = digitalRead(irPin);

  // Both fire and motion
  if (flameValue < 200 && motionDetected == LOW) {
    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, HIGH);
    Serial.println("Fire and Motion Detected! Alarm Activated");
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
  }
  // Only fire
  else if (flameValue < 200) {
    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, LOW);
    Serial.println("Fire Detected!");
    digitalWrite(buzzer, HIGH);
    delay(150);
    digitalWrite(buzzer, LOW);
    delay(150);
  }
  // Only motion
  else if (motionDetected == LOW) {
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, HIGH);
    Serial.println("Motion Detected (No Fire)");
    digitalWrite(buzzer, HIGH);
    delay(300);
    digitalWrite(buzzer, LOW);
    delay(200);
  }
  // Safe zone
  else {
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(buzzer, LOW);
    Serial.println("Safe Zone");
  }

  // Very short delay to avoid overwhelming the serial monitor
  delay(50);  
}
