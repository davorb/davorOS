#include "../drivers/screen.h"
#include "../drivers/keyboard.h"

void main() {
  clear_screen();
  set_cursor(0,0);
  print_string("hello world!", -1, -1);
  char key;
  while (1) {
    key = read_keyboard();
    print_char(key, 0, 2);
  }
  return;
}
