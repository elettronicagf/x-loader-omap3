#include <common.h>
#include <part.h>
#include <fat.h>
#include <i2c.h>
#include <asm/arch/gpio.h>
#include <mmc.h>
#include "gf_eeprom_port.h"

#define EEPROM_WP_GPIO		138

struct wid_translation legacy_wid_translation_table[] = {
		{"0385_A01","WID0385_AA01.01"},
		{"0385_B01","WID0385_AA01.01"},
		{"0385_C01","WID0385_AA01.01"},
		{"0385_B02","WID0385_AA01.01"},
};

void gf_i2c_init(void)
{
	return;
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
	omap_request_gpio(EEPROM_WP_GPIO);
	omap_set_gpio_direction(EEPROM_WP_GPIO,0);
	omap_set_gpio_dataout(EEPROM_WP_GPIO,1);
	omap_free_gpio(EEPROM_WP_GPIO);
}

void gf_som_eeprom_lock(void)
{
	omap_request_gpio(EEPROM_WP_GPIO);
	omap_set_gpio_direction(EEPROM_WP_GPIO,0);
	omap_set_gpio_dataout(EEPROM_WP_GPIO,0);
	omap_free_gpio(EEPROM_WP_GPIO);
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
