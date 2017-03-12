#include "../drivers/screen.h"

void main() {
  clear_screen();
  set_cursor(2,2);
  print_string("world!", -1, -1);
  return;
}
