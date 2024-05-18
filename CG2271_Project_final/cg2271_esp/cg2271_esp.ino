#include <DabbleESP32.h>

#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#define TXD2           17
#define FW             1
#define BW             2
#define RIGHT          3
#define LEFT           4

int radius;
int prevRadius = 0;
int angle;
uint8_t dir = 0;
uint8_t prevDir = 0;

void setup() {
  Serial.begin(115200);
  Dabble.begin("iPhone1234"); 
  Serial2.begin(9600, SERIAL_8N1, -1, TXD2);
}

uint8_t encodeDir() {
  if (GamePad.isCirclePressed()) {
    return RIGHT;
  }
  if (GamePad.isSquarePressed()) {
    return LEFT;
  }

  if (radius != 0) {
    if (angle < 135 && angle > 45) {
      return FW;
    }
    else if (angle < 290 && angle > 250) {
      return BW;
    }
    else if (angle <= 45 || angle >= 310) {
      return 0;
    }
    else if (angle <= 230 && angle >= 135) {
      return 0;
    }
    return 0;
  }
  return 0;
}

void loop() {
  Dabble.processInput();        // refresh data from phone
  prevRadius = radius;
  radius = GamePad.getRadius();

  prevDir = dir;
  angle = GamePad.getAngle();
  dir = encodeDir();

  if (dir != 0 && prevDir != dir) {
    uint8_t data = (0b11 << 6) | dir;
    Serial2.write(data);
  }

  // if press circle (0b00111111) -> END (stop + play sound)
  else if (GamePad.isCrossPressed()) {
    Serial2.write(0b00111111);
  }

  // start (0b00101010)
  else if (GamePad.isStartPressed()) { 
    Serial2.write(0b00101010);
    delay(100);
  }
  
  else if (dir == 0 && prevDir != 0) {
    //dir = 0;
    Serial2.write(0b00000000);
  }
}