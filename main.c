#include <LiquidCrystal_I2C.h>
#include <MemoryFree.h>
#include <PS2Keyboard.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);
PS2Keyboard keyboard;


int getSize(String data[]) {
  int i = 0;
  while (data[i] != NULL)
    i++;
  return i;
}
const String commands[] = {"free", "clear", "send"};
const int commandsC = getSize(commands);

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.noAutoscroll();
  lcd.backlight();
  lcd.setCursor(0, 1);
  lcd.print(">");
  keyboard.begin(2, 3);
}
String split(String data) {
  int s = data.length();
  int c = 0;
  for (int a = 0; a < s; a++)
    if (data[a] == ' ') c++;
  char * arr[c + 1];
  for (int a = 0; a < c; a++) {
    arr[a] = data.substring(0, data.indexOf(' '));
    data = data.substring(data.indexOf(' '));
  }
  return arr;
}

void exec(String data, String args[]) {
  String command = data.substring(0, data.indexOf(' '));
  for (int i = 0; i < commandsC ; i++) {
    if (String(commands[i]) == String(command)) {
      switch (i) {
        case 0: lcd.print(freeMemory()); lcd.print(" bytes"); break;
        case 1: lcd.clear(); break;
        case 2: Serial.println(args[0]); break;
      }
    }
  }
}


String data;
String tmp;
void loop() {
  lcd.setCursor(0, 0);
  if (keyboard.available()) {
    char c = keyboard.read();
    Serial.print(c);
    String args*;
    switch (c) {
      case PS2_ENTER: exec(data, split(data)); data = ""; lcd.clearLine(1); break;
      case PS2_BACKSPACE: data = data.substring(0, data.length() - 1); break;
      case 'a' ... 'z': data += c; break;
      case 'A' ... 'Z': data += c; break;
      case '0' ... '9': data += c; break;
      case ' ': data += ' '; break;
      case '/': data += '/'; break;
      case ':': data += ':'; break;
      case ';': data += ';'; break;
      case '.': data += '.'; break;
      case '!': data += '!'; break;
      case '@': data += '@'; break;
      case '#': data += '#'; break;
      case '$': data += '$'; break;
      case '%': data += '%'; break;
      case '^': data += '^'; break;
      case '&': data += '&'; break;
      case '*': data += '*'; break;
      case '(': data += '('; break;
      case ')': data += ')'; break;
      case '\\': data += '\\'; break;
      case '-': data += '-'; break;
      case '_': data += '_'; break;
      case '=': data += '='; break;
      case '+': data += '+'; break;
      case '<': data += '<'; break;
      case '>': data += '>'; break;
      case ',': data += ','; break;
      case '"': data += '"'; break;
      case '\'': data += '\''; break;
      case '?': data += '?'; break;
    }
  }
  if (tmp != data) {
    tmp = data;
    lcd.setCursor(0, 1);
    lcd.print(">");
    lcd.print(data);
  }
}
