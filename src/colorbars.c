/**
 * Color Bars
 */

#include <msx.h>
#include <conio.h>
#include "colorbars.h"

char bars_text[] =
  {
   'T', ' ', 'B', ' ', 'M', ' ', 'L', ' ', 'D', ' ', 'L', ' ', 'D', ' ', 'C', ' ', 'M', ' ', 'L', ' ', 'D', ' ', 'L', ' ', 'D', ' ', 'M', ' ', 'G', ' ', 'W', ' ',
   'R', ' ', 'L', ' ', 'E', ' ', 'I', ' ', 'A', ' ', 'I', ' ', 'A', ' ', 'Y', ' ', 'E', ' ', 'I', ' ', 'A', ' ', 'I', ' ', 'A', ' ', 'A', ' ', 'R', ' ', 'H', ' ',
   'A', ' ', 'A', ' ', 'D', ' ', 'G', ' ', 'R', ' ', 'G', ' ', 'R', ' ', 'A', ' ', 'D', ' ', 'G', ' ', 'R', ' ', 'G', ' ', 'R', ' ', 'G', ' ', 'A', ' ', 'I', ' ',
   'N', ' ', 'C', ' ', 'I', ' ', 'H', ' ', 'K', ' ', 'H', ' ', 'K', ' ', 'N', ' ', 'I', ' ', 'H', ' ', 'K', ' ', 'H', ' ', 'K', ' ', 'E', ' ', 'Y', ' ', 'T', ' ',
   'S', ' ', 'K', ' ', 'U', ' ', 'T', ' ', ' ', ' ', 'T', ' ', ' ', ' ', ' ', ' ', 'U', ' ', 'T', ' ', ' ', ' ', 'T', ' ', ' ', ' ', 'N', ' ', ' ', ' ', 'E', ' ',
   'P', ' ', ' ', ' ', 'M', ' ', ' ', ' ', 'B', ' ', ' ', ' ', 'R', ' ', ' ', ' ', 'M', ' ', ' ', ' ', 'Y', ' ', ' ', ' ', 'G', ' ', 'T', ' ', ' ', ' ', ' ', ' ',
   'A', ' ', ' ', ' ', ' ', ' ', 'G', ' ', 'L', ' ', 'B', ' ', 'E', ' ', ' ', ' ', ' ', ' ', 'R', ' ', 'E', ' ', 'Y', ' ', 'R', ' ', 'A', ' ', ' ', ' ', ' ', ' ',
   'R', ' ', ' ', ' ', 'G', ' ', 'R', ' ', 'U', ' ', 'L', ' ', 'D', ' ', ' ', ' ', 'R', ' ', 'E', ' ', 'L', ' ', 'E', ' ', 'E', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
   'E', ' ', ' ', ' ', 'R', ' ', 'E', ' ', 'E', ' ', 'U', ' ', ' ', ' ', ' ', ' ', 'E', ' ', 'D', ' ', 'L', ' ', 'L', ' ', 'E', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
   'N', ' ', ' ', ' ', 'E', ' ', 'E', ' ', ' ', ' ', 'E', ' ', ' ', ' ', ' ', ' ', 'D', ' ', ' ', ' ', 'O', ' ', 'L', ' ', 'N', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
   'T', ' ', ' ', ' ', 'E', ' ', 'N', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'W', ' ', 'O', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
   ' ', ' ', ' ', ' ', 'N', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'W', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
   ' ', ' ', ' ', ' ', 'P', 'R', 'E', 'S', 'S', ' ', 'S', 'P', 'A', 'C', 'E', ' ', 'T', 'O', ' ', 'C', 'O', 'N', 'T', 'I', 'N', 'U', 'E', ' ', ' ', ' ', ' ', ' ',
   0x00
  };

void colorbars(void)
{
  clrscr();
  cputs(bars_text);

  for (char x=0;x<16;x++)
    {
      char c = 0xF0 | x; // Default white text, merge in current background color
      msx_vfill_v(MODE2_ATTR + (x << 4), c, 192);
      msx_vfill_v(MODE2_ATTR + (x << 4) + 8, c, 192);
    }

  cgetc();
}