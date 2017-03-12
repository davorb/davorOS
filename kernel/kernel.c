#include "../drivers/screen.h"

void main() {
  clear_screen();
  print_char('X', 1, 1);
  print_char('Y', 2, 2);
  print_char('Z', 3, 3);

  print_string("hello, world!", 5, 5);
  print_string("multiline strings", 75, 7);

  set_cursor(0, 5);
  return;
}
