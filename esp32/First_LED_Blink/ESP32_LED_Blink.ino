// LED connected to GPIO2
const int ledPin = 2;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);  
  delay(1500);                  
  digitalWrite(ledPin, LOW);    
  delay(1500);                   
}
