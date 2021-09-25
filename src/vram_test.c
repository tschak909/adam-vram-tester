/**
 * @brief VRAM test, single byte pattern
 * @param byte to test with.
 */

#include <msx.h>
#include <conio.h>
#include "vram_test.h"
#include "error.h"

void vram_test_banner(unsigned char b)
{
  msx_color(INK_WHITE,INK_LIGHT_BLUE,INK_LIGHT_BLUE);
  clrscr();

  gotoxy(4,8);
  cprintf("VRAM TEST -- PATTERN %02X",b);
  gotoxy(8,11);
  cprintf("STARTS IN 5 SECS.");
  sleep(5);
}

void vram_fill_random(void)
{
  for (unsigned short i=0;i<0x4000;i++)
    vpoke(i,rand()&0xFF);
}

void vram_test(unsigned char b)
{
  vram_test_banner(b);
  
  msx_color(INK_BLACK,INK_BLACK,INK_BLACK);
  clrscr();

  for (unsigned char i=1;i<16;i++)
    {
      vram_fill_random();

      for (unsigned short j=0;j<0x4000;j++)
	{
	  unsigned char e;

	  vpoke(j,b);
	  e=vpeek(j);
	  if (e!=b)
	    error(j,e,b);
	}
    }  
}
