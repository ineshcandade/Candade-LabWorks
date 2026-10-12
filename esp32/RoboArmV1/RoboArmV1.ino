#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define BUTTON_PIN 4
#define GREEN_LED 18
#define RED_LED 19

#define MG996R_MIN 120
#define MG996R_MAX 650

#define MG90S_MIN 120
#define MG90S_MAX 520

// Servo channels
int channels[6] = {0, 1, 2, 3, 4, 5};

// Target angles
int angles[6] = {77, 26, 13, 10, 47, 59};

void setServoAngle(int channel, int angle)
{
  int pulse;

  if (channel <= 2) // MG996R
  {
    pulse = map(angle, 0, 180, MG996R_MIN, MG996R_MAX);
  }
  else // MG90S
  {
    pulse = map(angle, 0, 180, MG90S_MIN, MG90S_MAX);
  }

  pwm.setPWM(channel, 0, pulse);
}

void smoothMoveServo(int channel, int startAngle, int endAngle)
{
  if (startAngle < endAngle)
  {
    for (int angle = startAngle; angle <= endAngle; angle++)
    {
      setServoAngle(channel, angle);
      delay(25);
    }
  }
  else
  {
    for (int angle = startAngle; angle >= endAngle; angle--)
    {
      setServoAngle(channel, angle);
      delay(25);
    }
  }
}

void setup()
{
  Serial.begin(115200);

  pinMode(BUTTON_PIN, INPUT_PULLUP);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, HIGH);

  Wire.begin(21, 22);

  pwm.begin();
  pwm.setPWMFreq(50);

  delay(1000);

  for (int i = 0; i < 6; i++)
  {
    setServoAngle(channels[i], 0);
    delay(300);
  }

  Serial.println("RoboArm Ready - Press Button");
}

void loop()
{
  if (digitalRead(BUTTON_PIN) == LOW)
  {
    delay(50);

    if (digitalRead(BUTTON_PIN) == LOW)
    {
      while (digitalRead(BUTTON_PIN) == LOW)
      {
        delay(10);
      }

      digitalWrite(RED_LED, LOW);
      digitalWrite(GREEN_LED, HIGH);

      Serial.println("Sequence Started");

      for (int i = 0; i < 6; i++)
      {
        smoothMoveServo(channels[i], 0, angles[i]);
        delay(500);
      }

      delay(5000);

      for (int i = 5; i >= 0; i--)
      {
        smoothMoveServo(channels[i], angles[i], 0);
        delay(500);
      }

      // Extra movement of Servo 6
      smoothMoveServo(channels[5], 0, angles[5]);
      delay(500);

      smoothMoveServo(channels[5], angles[5], 0);
      delay(500);

      // SEQUENCE COMPLETE
      digitalWrite(GREEN_LED, LOW);
      digitalWrite(RED_LED, HIGH);

      Serial.println("Sequence Complete - Waiting for Button");
    }
  }

  delay(20);
}
