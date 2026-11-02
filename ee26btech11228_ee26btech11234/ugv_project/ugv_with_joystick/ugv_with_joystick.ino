
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE

#include <DabbleESP32.h>

#define IN1 32
#define IN2 33
#define IN3 25
#define IN4 26

// Joystick sensitivity threshold
const float THRESHOLD = 2.0;

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void moveForward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBackward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnLeft() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void setup() {
  Serial.begin(115200);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  stopMotors();

  Dabble.begin("UGV_Dabble");

  Serial.println("UGV Started");
  Serial.println("Connect using Dabble App");
}

void loop() {
  Dabble.processInput();

  // Read joystick values
  float x = GamePad.getXaxisData();
  float y = GamePad.getYaxisData();

  // Digital directional buttons
  if (GamePad.isUpPressed()) {
    moveForward();
  }
  else if (GamePad.isDownPressed()) {
    moveBackward();
  }
  else if (GamePad.isRightPressed()) {
    turnRight();
  }
  else if (GamePad.isLeftPressed()) {
    turnLeft();
  }

  // Analog joystick control
  else if (y > THRESHOLD) {
    moveForward();
  }
  else if (y < -THRESHOLD) {
    moveBackward();
  }
  else if (x < -THRESHOLD) {
    turnLeft();
  }
  else if (x > THRESHOLD) {
    turnRight();
  }
  else {
    stopMotors();
  }

  delay(20);
}

