#define VIDEO_ADDRESS 0xb8000
#define MAX_ROWS 25
#define MAX_COLUMNS 80
#define WHITE_ON_BLACK 0x0f

/* Device I/O ports */
#define REG_SCREEN_CTRL 0x3d4
#define REG_SCREEN_DATA 0x3d5

void print_char(char,unsigned int, unsigned int);
void print_string(char*, unsigned int, unsigned int);
void clear_screen();
void set_cursor(unsigned int, unsigned int);
