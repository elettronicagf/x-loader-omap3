#include <common.h>
#include <part.h>
#include <fat.h>
#include <i2c.h>
#include <asm/arch-omap3/omap3_egf_cpld.h>
#include <asm/arch/gpio.h>
#include <mmc.h>
#include "gf_eeprom_port.h"

struct wid_translation legacy_wid_translation_table[] = {
		{"0336_A01","WID0336_AA01.00"},
		{"0336_B01","WID0336_AA01.00"},
		{"0336_C01","WID0336_AA01.00"},
		{"0336_D01","WID0336_AA01.00"},
		{"0336_E01","WID0336_AA01.00"},
		{"0336_F01","WID0336_AB01.00"},
		{"0336_F02","WID0336_AB01.00"},
		{"0336_H01","WID0336_AA01.00"},
};

static void reset_tvp5150_to_free_i2cbus(void)
{
	omap_request_gpio(163);
	omap_request_gpio(164);
	omap_set_gpio_direction(163,0);
	omap_set_gpio_direction(164,0);
	omap_set_gpio_dataout(163,1);
	omap_set_gpio_dataout(164,0);
}

void gf_i2c_init(void)
{
	init_cpld_gpio();
	reset_tvp5150_to_free_i2cbus();
}

int gf_i2c_set_bus_num(unsigned int bus)
{
	return i2c_set_bus_num(bus);
}

int gf_i2c_probe (u8 chip)
{
	return i2c_probe(chip);
}

int gf_serial_getc(void)
{

	return serial_getc();
}

void gf_serial_init(void)
{
	char c;
	/* Empty serial input buffer fifo */
	while(serial_data_present_in_read_buffer())
		c = gf_serial_getc();
}

void gf_som_eeprom_unlock(void)
{
	set_cpld_gpio(EEPROM_WP_107,1);
}

void gf_som_eeprom_lock(void)
{
	set_cpld_gpio(EEPROM_WP_107,0);
}

int gf_eeprom_read(u8 address,u16 start_address,u8 * buffer,int len)
{
	int i;
	for(i=0; i<len; i++){
		if(i2c_read_byte_16bitoffset(address, i+start_address, &buffer[i])){
			return 1;
		}
	}
	return 0;
}

int gf_eeprom_write(u8 address,u16 start_address,u8 * buffer,int len)
{
	int i;
	int ret;
	for(i=0; i<len; i++){
		ret = i2c_write_byte_16bitoffset(address, i+start_address, buffer[i]);
		if(ret){
			return 1;
		}
		udelay(1000000);
	}
	return 0;
}

int gf_read_programmer_file(const char * file_name,char * file_buffer,int buffer_length)
{
	int ret;
	ret = mmc_init(1);
	if(ret == 0){
		printf("\n MMC init failed \n");
		return -1;
	}
	ret = file_fat_read(file_name,
			file_buffer,buffer_length);
	if (ret == -1)
	{
		/* Programmer file is not available. Boot cannot be completed */
		printf("GF Eeprom programmer file not found\n");
		return -1;
		//printf("System Hang.\n");
		//while(1);
	}
	file_buffer[ret] = 0;
	return 0;
}
