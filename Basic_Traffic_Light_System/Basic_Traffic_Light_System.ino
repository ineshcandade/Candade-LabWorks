#define LED_1_PIN 10
#define LED_2_PIN 11
#define LED_3_PIN 12

void setup() {
  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);
  pinMode(LED_3_PIN, OUTPUT);
 
  digitalWrite(LED_1_PIN, LOW);
  digitalWrite(LED_2_PIN, LOW);
  digitalWrite(LED_3_PIN, LOW);
}

void loop() {
  digitalWrite(LED_1_PIN, HIGH);
  digitalWrite(LED_2_PIN, LOW);
  digitalWrite(LED_3_PIN, LOW);
  delay(2000);
  digitalWrite(LED_1_PIN, LOW);
  digitalWrite(LED_3_PIN, LOW);
  digitalWrite(LED_2_PIN, HIGH);
  delay(500);
  digitalWrite(LED_1_PIN, LOW);
  digitalWrite(LED_3_PIN, HIGH);
  digitalWrite(LED_2_PIN, LOW);
  delay(2000);
}
