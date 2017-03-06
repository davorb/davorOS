#include "../drivers/screen.h"

void main() {
  clear_screen();
  print_char('X', 1, 1);
  print_char('Y', 2, 2);
  print_char('Z', 3, 3);
  return;
}
