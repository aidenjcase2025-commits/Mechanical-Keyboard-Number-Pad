#include <Keyboard.h>

#define ROWS 5
#define COLS 4

byte rowPins[ROWS] = {6, 7, 10, 8, 9};
byte colPins[COLS] = {2, 3, 4, 5};

// HID codes for special keys, normal characters stay as 0-127
uint8_t layout[ROWS][COLS] = {
  {KEY_BACKSPACE, '/', '*', '-'},       // 'n' → NumLock
  {'7', '8', '9', '+'},
  {'4', '5', '6', '\0'},
  {'1', '2', '3', KEY_KP_ENTER},      // Enter on last key
  {'0', '\0', KEY_DELETE, '\0'}       // 'd' → Delete
};

int keyDown[ROWS][COLS] = {0};

void setup() {
  Serial.begin(9600);
  delay(2000);

  Serial.println("Numpad loading. . .");
  Keyboard.begin();

  for (int r = 0; r < ROWS; r++) {
    pinMode(rowPins[r], OUTPUT);
    digitalWrite(rowPins[r], HIGH);
  }

  for (int c = 0; c < COLS; c++) {
    pinMode(colPins[c], INPUT_PULLUP);
  }
}

void loop() {
  for (int r = 0; r < ROWS; r++) {
    digitalWrite(rowPins[r], LOW);
    delayMicroseconds(5);

    for (int c = 0; c < COLS; c++) {
      if (digitalRead(colPins[c]) == LOW) {     // pressed
        if (keyDown[r][c] == 0) {               // first press
          uint8_t code = layout[r][c];
          Serial.print("Key code: ");
          Serial.println(code);

          // If code >= 128, treat as HID, otherwise as normal character
          if (code >= 128 || code == KEY_DELETE || code == KEY_BACKSPACE || code == KEY_KP_ENTER) {
            Keyboard.press(code);
            delay(5);
            Keyboard.release(code);
          } else if (code != '\0') {
            Keyboard.write(code);
          }
        }
        keyDown[r][c] = 1;

      } else {
        keyDown[r][c] = 0;
      }
    }

    digitalWrite(rowPins[r], HIGH);
    delay(2);
  }
}