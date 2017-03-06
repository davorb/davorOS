#include "screen.h"

void print_char(char c, unsigned int col, unsigned int row) {
  unsigned char* video_address = (unsigned char*) VIDEO_ADDRESS;
  int pos = col*2 + row*MAX_COLUMNS*2;
  video_address[pos] = c;
  video_address[pos+1] = WHITE_ON_BLACK;
}

void clear_screen() {
  unsigned char* video_address = (unsigned char*) VIDEO_ADDRESS;
  for (int i=0; i < MAX_ROWS * MAX_COLUMNS; i+=2) {
    video_address[i] = 0x00;
    video_address[i+1] = WHITE_ON_BLACK;
  }
}
