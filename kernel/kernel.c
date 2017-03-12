#include "../drivers/screen.h"
#include "../drivers/keyboard.h"

void main() {
  clear_screen();
  set_cursor(0,0);
  print_string("C:\\", -1, -1);
  while (1) {
    char key = read_keyboard();
    if (key != '\0') {
      print_char(key, -1, -1);
    }
  }
  return;
}
