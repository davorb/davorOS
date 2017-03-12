#include "screen.h"
#include "../kernel/low_level.h"

void print_char(char c, unsigned int col, unsigned int row) {
  if (col >= MAX_COLUMNS || row >= MAX_ROWS) {
    return;
  }

  unsigned char* video_address = (unsigned char*) VIDEO_ADDRESS;
  int pos = col*2 + row*MAX_COLUMNS*2;
  video_address[pos] = c;
  video_address[pos+1] = WHITE_ON_BLACK;
}

void print_string(char* string, unsigned int col, unsigned int row) {
  int i = col;
  while (*string != '\0') {
    if (i > MAX_COLUMNS) {
      i = 0;
      row++;
    }

    print_char(*string, i, row);
    string++;
    i++;
  }
}

void clear_screen() {
  unsigned char* video_address = (unsigned char*) VIDEO_ADDRESS;
  for (int i=0; i < MAX_ROWS * MAX_COLUMNS; i+=2) {
    video_address[i] = 0x00;
    video_address[i+1] = WHITE_ON_BLACK;
  }
  set_cursor(0, 0);
}

void set_cursor(unsigned int col, unsigned int row) {
  if (col == -1 && row == -1) {
    col = 0;
    row = 0;
  }

  unsigned short pos = (row*80) + col;

  /* register DH sets the column */
  port_byte_out(REG_SCREEN_CTRL, 0x0f);
  port_byte_out(REG_SCREEN_DATA, (unsigned char) (pos & 0xff));

  /* register DL sets the row */
  port_byte_out(REG_SCREEN_CTRL, 0x0e);
  port_byte_out(REG_SCREEN_DATA, (unsigned char) (pos>>8) & 0xff);
}
