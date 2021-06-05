// Copyright 2021 Ocean (iiot2k@gmail.com) 
// All rights reserved.

#include "dev_mcp4728.h"

#define MCP4728_ADDR 0x60
#define MULTIWRITE   0x40
#define SINGLEWRITE  0x58

static uint8_t dac_pd[] = { MCP4728_PD_OFF, MCP4728_PD_OFF, MCP4728_PD_OFF, MCP4728_PD_OFF };
static uint8_t dac_vref[] = { MCP4728_VREF_INT, MCP4728_VREF_INT, MCP4728_VREF_INT, MCP4728_VREF_INT };
static uint8_t dac_gain[] = { MCP4728_GAIN2, MCP4728_GAIN2, MCP4728_GAIN2, MCP4728_GAIN2 };

void dev_mcp4728_pd(uint8_t ch, uint8_t pd)
{
	if ((ch >= MCP4728_CH_NUM) || (pd >= MCP4728_PD_NUM))
		return;

	dac_pd[ch] = pd;
}

void dev_mcp4728_vref(uint8_t ch, uint8_t vref)
{
	if ((ch >= MCP4728_CH_NUM) || (vref >= MCP4728_VREF_NUM))
		return;

	dac_vref[ch] = vref;
}

void dev_mcp4728_gain(uint8_t ch, uint8_t gain)
{
	if ((ch >= MCP4728_CH_NUM) || (gain >= MCP4728_GAIN_NUM))
		return;
		
	dac_gain[ch] = gain;
}

static bool mcp4728_write(i2c_inst_t* i2c, uint8_t cmd, uint8_t ch, uint16_t value)
{
	if (ch >= MCP4728_CH_NUM)
		return false;

	if (value > 4095)
		value = 4095;
	
	uint8_t buffer[3];

	buffer[0] = cmd | (ch << 1);
	buffer[1] = (value >> 8) | (dac_vref[ch] << 7) | (dac_pd[ch] << 5) | (dac_gain[ch] << 4);
	buffer[2] = value & 0xFF;

	// set channel dac
    return (sys_i2c_wbuf(i2c, MCP4728_ADDR, buffer, sizeof(buffer)) == sizeof(buffer));
}

bool dev_mcp4728_set(i2c_inst_t* i2c, uint8_t ch, uint16_t value)
{
	return mcp4728_write(i2c, MULTIWRITE, ch, value);
}

bool dev_mcp4728_save(i2c_inst_t* i2c, uint8_t ch, uint16_t value)
{
	return mcp4728_write(i2c, SINGLEWRITE, ch, value);
}
