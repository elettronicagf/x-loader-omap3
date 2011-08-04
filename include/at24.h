/*
 * at24.h
 *
 * Copyright (C) 2011	Elettronica GF S.r.l
 *
 * Derived from include/linux/i2c/at24.h from  linux kernel 2.6.29
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#ifndef AT24_H_
#define AT24_H_

#include <common.h>


#define AT24_FLAG_ADDR16	0x80	/* address pointer is 16 bit */
#define AT24_FLAG_TAKE8ADDR	0x10	/* take always 8 addresses (24c00) */

#define AT24_SIZE_BYTELEN 5
#define AT24_SIZE_FLAGS 8

#define AT24_BITMASK(x) (BIT(x) - 1)


int at24_eeprom_read_byte(u8 bus_num, u8 slave_address, u8 *buf, unsigned offset);
#endif /* AT24_H_ */
