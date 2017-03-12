#include "../kernel/low_level.h"
#include "keyboard.h"

char read_keyboard() {
  int data = port_byte_in(KEYBOARD_DATA_PORT);
  switch (data) {
  case KEY_1 :
    return '1';
  case KEY_2 :
    return '2';
  case KEY_3 :
    return '3';
  case KEY_4 :
    return '4';
  case KEY_5 :
    return '5';
  case KEY_6 :
    return '6';
  case KEY_7 :
    return '7';
  case KEY_8 :
    return '8';
  case KEY_9 :
    return '9';
  case KEY_0 :
    return '0';
  case KEY_MINUS :
    return '-';
  case KEY_EQUALS :
    return '=';
  case KEY_BACKSPACE :
    return '\\';
  case KEY_Q :
    return 'Q';
  case KEY_W :
    return 'W';
  case KEY_E :
    return 'E';
  case KEY_R :
    return 'R';
  case KEY_T :
    return 'T';
  case KEY_Y :
    return 'Y';
  case KEY_U :
    return 'U';
  case KEY_I :
    return 'I';
  case KEY_O :
    return 'O';
  case KEY_P :
    return 'P';
  case KEY_LEFT_SQUARE_BRACKET :
    return '[';
  case KEY_RIGHT_SQUARE_BRACKET :
    return ']';
  case KEY_A :
    return 'A';
  case KEY_S :
    return 'S';
  case KEY_D :
    return 'D';
  case KEY_F :
    return 'F';
  case KEY_G :
    return 'G';
  case KEY_H :
    return 'H';
  case KEY_J :
    return 'J';
  case KEY_K :
    return 'K';
  case KEY_L :
    return 'L';
  case KEY_SEMICOLON :
    return ';';
  case KEY_SINGLE_QUOTE :
    return '\'';
  case KEY_Z :
    return 'Z';
  case KEY_X :
    return 'X';
  case KEY_C :
    return 'C';
  case KEY_V :
    return 'V';
  case KEY_B :
    return 'B';
  case KEY_N :
    return 'N';
  case KEY_M :
    return 'M';
  case KEY_COMMA :
    return ',';
  case KEY_DOT :
    return '.';
  case KEY_SLASH :
    return '/';
  case KEY_SPACE :
    return ' '; // This one might need changing
  default :
    return ' ';
  }
}
