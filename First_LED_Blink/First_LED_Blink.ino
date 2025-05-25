void setup() {
  // set LED pin to output 
  pinMode(12, OUTPUT);
}

void loop() {
  // blinking
  digitalWrite(12, HIGH);
  delay(1000);
  digitalWrite(12, LOW);
  delay(1000);
}

