/**
 * VRAM Test
 *
 * @author Thomas Cherryhomes
 * @email  thom.cherryhomes at gmail.com
 */

#include <msx.h>
#include <conio.h>
#include "colorbars.h"
#include "vram_test.h"

void setup(void)
{
  msx_set_mode(2);
  msx_color(INK_WHITE,INK_LIGHT_BLUE,INK_LIGHT_BLUE);
  clrscr();
}

void banner(void)
{
  cprintf("THIS IS A COLECO ADAM VRAM TEST.\nIT WILL START WITH A COLOR BAR\nDISPLAY, FOLLOWED BY TESTING 15\nDIFFERENT PATTERNS, WRITING EACHPATTERN TO ALL VRAM ADDRESSES\n(0-3FFF) AND READING BACK THE\nRESULT. EACH PATTERN WILL BE\nTRIED 16 TIMES. IF AN ERROR IS\nFOUND, A RED SCREEN WILL BE\nDISPLAYED WITH THE ADDRESS, THE EXPECTED PATTERN, AND THE ACTUALPATTERN. IF ALL TESTS PASS, YOU WILL SEE A GREEN SCREEN WITH\n'ALL GOOD'\n\nPRESS ANY KEY TO START");
  cgetc();
}

void good(void)
{
  msx_color(INK_WHITE,INK_DARK_GREEN,INK_DARK_GREEN);
  clrscr();

  gotoxy(4,8);

  cprintf("ALL GOOD. PROGRAM HALTED.");
  while(1) { }
}

void main(void)
{
  setup();
  banner();
  colorbars();
  vram_test(0x00);
  vram_test(0xFF);
  vram_test(0xA5);
  vram_test(0x5A);
  vram_test(0xAA);
  vram_test(0x55);
  vram_test(0x01);
  vram_test(0x02);
  vram_test(0x04);
  vram_test(0x08);
  vram_test(0x10);
  vram_test(0x20);
  vram_test(0x40);
  vram_test(0x80);
  good();
}
