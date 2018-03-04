#include <stdio.h>
#include "lpc11xx.h"
#include "oled2864.h" 
#include "menu.h"


void Dis_Menu(Menu_TypeDef menu) {
  uint16_t	page, row, i;

  page = (menu.numb-1) / 6;
  i = (page+1) * 6;
  if(i < menu.max_numb)
    row = 5;
  else
    row = (menu.max_numb-1) % 6;

  //OLED_ClearScreen();
  OLED_DisStrLine(0, 0, (uint8_t *)menu.title);
  OLED_DisChar(0, 6*17, 0, 'P');
  OLED_DisChar(0, 6*18, 0, 'g');
  OLED_DisChar(0, 6*19, 0, ' ');
  OLED_DisChar(0, 6*20, 0, 0x30+1+page);
	OLED_DisStrLine(1, 0, (uint8_t *)menu.table);
	
  for(i=0; i<=row; i++)
  {
    if(menu.numb == (page*6 + i + 1))
	  OLED_DisStrLine(2+ i, 1, (uint8_t *)menu.item[page*6+i]);
	else
	  OLED_DisStrLine(2+ i, 0, (uint8_t *)menu.item[page*6+i]);
  }
}

/**** End of File ****/
