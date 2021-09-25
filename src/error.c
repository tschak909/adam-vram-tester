#include <msx.h>
#include <conio.h>
#include "error.h"

/**
 * Error page
 * @param addr Errant addresss
 * @param Expected value
 * @param actual value
 */

void error(unsigned short addr, unsigned char e, unsigned char b)
{
  msx_color(INK_WHITE,INK_DARK_RED,INK_DARK_RED);
  clrscr();

  gotoxy(0,8);
  cprintf("VRAM ERROR!\n\n ADDRESS: %04X\nEXPECTED: %02X\n  ACTUAL: %02X\n",addr,e,b);

  while(1) { }
}
