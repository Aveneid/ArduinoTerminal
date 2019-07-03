#include "commands.h"

// command structure (function name, parameter, actual function)
struct command {
  char* functionName;
  void (*function)(String);
};

void Free(String data[]) {
  free(data); free(tmp);
  lcd.print(freeMemory()); lcd.print(" bytes");
}
void Clear(String data[]) {lcd.clear();}
void Send(String data[]) {Serial.print(data);}
void dWrite(String args[]) { digitalWrite(args[0].toInt(), args[1].toUpperCase()); }
void pSet(String args[]) { pinMode(args[0].toInt(), args[1].toUpperCase()); }
// array of command structures
struct command commands[] = {
  {"free", Free},
  {"clear", Clear},
  {"send", Send},
  {"dWrite", dWrite},
  {"pSet", pSet}
};

void exec(String data, String args[]) {
  String command = data.substring(0, data.indexOf(' '));
  struct command *scan;
  for (scan = commands; scan->function; scan++) {
    if (command == scan->functionName) {
      scan->function(args);
      break;
    }
  }
}

