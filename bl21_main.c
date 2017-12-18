
/*
 * arch/arm/cpu/armv8/gxb/firmware/bl21/bl21_main.c
 *
 * Copyright (C) 2015 Amlogic, Inc. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#include "secure_apb.h"
#include "serial.h" //use local serial driver
#include "io.h"
#include "timer.h"
#include "board_init.c"

extern void serial_put_hex(unsigned long data,unsigned int bitlen);
extern int serial_puts(const char *s);

/* cat rom.txt | xxd -r -p > rom.bin */

void bl21_main(void)
{
	unsigned int i;
	unsigned char * sptr = (unsigned char *)0xD9040000;
	volatile unsigned int * wdg_ctrl = (unsigned int *)0xC11098D0;
	unsigned int wdg;

	/* bl2 customer code */
	board_init();
	
	wdg = *wdg_ctrl;
	wdg &= 0xFDFBFFFF;
	*wdg_ctrl = wdg;

	serial_puts("SonOfToil ROM Dumper\n");
	for(i=0;i<0x40000;i++)
		serial_put_hex(*sptr++, 8);

	return;
}
