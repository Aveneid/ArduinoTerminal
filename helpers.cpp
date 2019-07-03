#include "helpers.h"
#include <string.h>

void init(){
  Serial.begin(9600);
  lcd.init();
  lcd.noAutoscroll();
  lcd.backlight();
  lcd.setCursor(0, 1);
  lcd.print(">");
  keyboard.begin(2, 3);
}
//splitting strings
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
  arr[0] = "";
  return arr;
}
//get size of String array
int getSize(String data[]) {
  int i = 0;
  while (data[i] != NULL)
    i++;
  return i;
}
String data;
String tmp;
void keyboard_handler(){
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
    if (tmp != data) {
    tmp = data;
    lcd.setCursor(0, 1);
    lcd.print(">");
    lcd.print(data);
  }
}

