#include <LiquidCrystal_I2C.h>
#include <MemoryFree.h>
#include <PS2Keyboard.h>

#include "helpers.h"
#include "commands.h"

LiquidCrystal_I2C lcd(0x27, 20, 4);
PS2Keyboard keyboard;
void setup() {init();}
void loop() {
  lcd.setCursor(0, 0);
  if (keyboard.available()) {
    keyboard_handler();
  }
}
