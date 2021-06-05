// Copyright 2021 Ocean (iiot2k@gmail.com) 
// All rights reserved.

#include "dev_ads1115.h"

#include "sys_util.h"
#include "sys_time.h"

#include <math.h>

#define POINTER_CONVERT 0
#define POINTER_CONFIG  1

bool dev_ads1115_read_ex(i2c_inst_t* i2c, uint8_t addr, uint8_t channel, uint8_t mux, uint8_t gain, double *value)
{
    // check parameter
    if ((i2c == NULL) || (channel >= ADS1115_CH_NUM) || (mux >= ADS1115_MUX_NUM) || (gain >= ADS1115_GAIN_NUM)|| (value == NULL))
        return false;
    
    #pragma pack(1)
    union
    {
        struct
        {
            uint16_t cq:  2; // comparator queue
            uint16_t cl:  1; // comparator latch
            uint16_t cp:  1; // comparator polarity
            uint16_t cm:  1; // comparator mode
            uint16_t dr:  3; // data rate
            uint16_t mod: 1; // mode  1 = One shot
            uint16_t pga: 3; // gain
            uint16_t mux: 3; // multiplex
            uint16_t os:  1; // operation 1 = One shot
        };
        uint16_t cfg;
    } ads1115_cfg;
    
    ads1115_cfg.cfg = 0;
    ads1115_cfg.os = 1;
    ads1115_cfg.mux = mux;
    ads1115_cfg.pga = gain;
    ads1115_cfg.mod = 1;
    ads1115_cfg.dr = 4; // 128 SPS
    ads1115_cfg.cq = 3;

    // start conversion
    if (sys_i2c_wword_reg(i2c, addr, POINTER_CONFIG, sys_swap_word(ads1115_cfg.cfg)) != 3)
        return false;
    
    // wait for finish conversion
    sys_delay_ms(10);

	union
	{
		uint16_t uintdata;
		int16_t  intdata;
	} readval;

    // read conversion
    if (sys_i2c_rword_reg(i2c, addr, POINTER_CONVERT, &readval.uintdata) != 2)
        return false;

    readval.uintdata = sys_swap_word(readval.uintdata);

    // single end is always positive
	if (ads1115_cfg.mux >= ADS1115_AI0_GND)
		if (readval.intdata < 0.0)
			readval.intdata = 0.0;

    *value = (double)readval.intdata;

    // convert to milivolt
    switch(ads1115_cfg.pga)
    {
        case ADS1115_GAIN_6114: *value /= 6.0; break;
        case ADS1115_GAIN_4096: *value /= 8.0; break;
        case ADS1115_GAIN_2048: *value /= 16.0; break;
        case ADS1115_GAIN_1024: *value /= 32.0; break;
        case ADS1115_GAIN_0512: *value /= 64.0; break;
        case ADS1115_GAIN_0256: *value /= 128.0; break;
    }

    // convert to volt 
    *value = round(*value)/1000.0;

    return true;
}
