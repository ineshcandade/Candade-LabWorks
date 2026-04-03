#define ENA 25
#define IN1 26
#define IN2 27
#define IN3 32
#define IN4 33
#define ENB 13

#define IR_LEFT 34
#define IR_RIGHT 35

const int LEFT_SPEED  = 160;  
const int RIGHT_SPEED = 140;  

void setup() {
  Serial.begin(115200);
  delay(100);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(IR_LEFT, INPUT);
  pinMode(IR_RIGHT, INPUT);

  ledcAttach(ENA, 2000, 8); 
  ledcAttach(ENB, 2000, 8);

  ledcWrite(ENA, 0);
  ledcWrite(ENB, 0);

  Serial.println("Line follower ready!");
}

void loop() {
  int left = digitalRead(IR_LEFT);   // 0 = black, 1 = white
  int right = digitalRead(IR_RIGHT);

  Serial.printf("Left: %d | Right: %d\n", left, right);

  if (left == 1 && right == 1) {
    forward(); // both sensors on black line
  } 
  else if (left == 1 && right == 0) {
    leftTurn(); // line under left sensor
  } 
  else if (left == 0 && right == 1) {
    rightTurn(); // line under right sensor
  } 
  else {
    stopMotors(); // lost line
  }
}

void forward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  ledcWrite(ENA, LEFT_SPEED);   
  ledcWrite(ENB, RIGHT_SPEED); 
}

void backward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void leftTurn() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void rightTurn() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
