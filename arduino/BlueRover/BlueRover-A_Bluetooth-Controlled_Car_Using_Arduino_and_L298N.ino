char command;

void setup() {
  Serial.begin(9600); 

  // Motor control pins
  pinMode(4, OUTPUT); // IN1
  pinMode(5, OUTPUT); // IN2
  pinMode(6, OUTPUT); // IN3
  pinMode(7, OUTPUT); // IN4

  // Enable pins
  pinMode(9, OUTPUT);  // ENA
  pinMode(10, OUTPUT); // ENB

  // Set initial motor speed
  analogWrite(9, 255);   // Left motors (ENA)
  analogWrite(10, 255);  // Right motors (ENB)
}

void loop() {
  if (Serial.available()) {
    command = Serial.read();

    switch (command) {
      case 'L':  
        digitalWrite(4, LOW);  
        digitalWrite(5, HIGH);
        digitalWrite(6, LOW);  
        digitalWrite(7, HIGH);
        break;

      case 'R':  
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);
        digitalWrite(6, HIGH);
        digitalWrite(7, LOW);
        break;

      case 'F':  
        digitalWrite(4, HIGH);  
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);  
        digitalWrite(7, HIGH);
        break;

      case 'B':  
        digitalWrite(4, LOW);   
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);  
        digitalWrite(7, LOW);
        break;

      case 'S': 
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        break;
    }
  }
}
