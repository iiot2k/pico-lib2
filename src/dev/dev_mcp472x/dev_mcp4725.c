// Copyright 2021 Ocean (iiot2k@gmail.com) 
// All rights reserved.

#include "dev_mcp4725.h"

#define WRITEDAC        0x40
#define WRITEDACEEPROM  0x60

static uint8_t dac_pd = MCP4725_PD_OFF;

void dev_mcp4725_pd(uint8_t pd)
{
	dac_pd = pd;
}

static bool mcp4725_write(i2c_inst_t* i2c, uint8_t cmd, uint8_t addr, uint16_t value)
{
	if (value > 4095)
		value = 4095;
	
	uint8_t buffer[3];

	buffer[0] = cmd | (dac_pd << 1);
	buffer[1] = value >> 4;
	buffer[2] = value << 4;

	// set channel dac
    return (sys_i2c_wbuf(i2c, addr, buffer, sizeof(buffer)) == sizeof(buffer));
}

bool dev_mcp4725_set(i2c_inst_t* i2c, uint8_t addr, uint16_t value)
{
	return mcp4725_write(i2c, WRITEDAC, addr, value);
}

bool dev_mcp4725_save(i2c_inst_t* i2c, uint8_t addr, uint16_t value)
{
	return mcp4725_write(i2c, WRITEDACEEPROM, addr, value);
}
