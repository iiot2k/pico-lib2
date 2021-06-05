// Copyright 2021 Ocean (iiot2k@gmail.com) 
// All rights reserved.

#include "dev_ds3231.h"

#include "sys_time.h"

#define DEV_DS3231_ADDR 0x68

// convert BCD to number
static inline uint8_t bcdnum(uint8_t bcd)
{
    return ((bcd/16) * 10) + (bcd % 16);
}

// convert number to BCD
static inline uint8_t numbcd(uint8_t num)
{
    return ((num/10) * 16) + (num % 10);
}

bool dev_ds3231_setdatetime(i2c_inst_t* i2c, datetime_t *dt)
{
    // check datetime
    if (!sys_check_datetime(dt))
        return false;

    uint8_t dt_buffer[8];
    dt_buffer[0] = 0;
    dt_buffer[1] = numbcd(dt->sec);
    dt_buffer[2] = numbcd(dt->min);
    dt_buffer[3] = numbcd(dt->hour);
    dt_buffer[4] = numbcd(dt->dotw + 1);
    dt_buffer[5] = numbcd(dt->day);
    dt_buffer[6] = numbcd(dt->month);
    dt_buffer[7] = numbcd(dt->year - 2000);

    return sys_i2c_wbuf(i2c, DEV_DS3231_ADDR, dt_buffer, sizeof(dt_buffer)) != sizeof(dt_buffer);
}

bool dev_ds3231_getdatetime(i2c_inst_t* i2c, datetime_t *dt)
{
    uint8_t dt_buffer[7];

    if (sys_i2c_rbuf_reg(i2c, DEV_DS3231_ADDR, 0, dt_buffer, sizeof(dt_buffer)) != sizeof(dt_buffer))
        return false;

    dt->sec = bcdnum(dt_buffer[0]);
    dt->min = bcdnum(dt_buffer[1]);
    dt->hour = bcdnum(dt_buffer[2]);
    dt->dotw = bcdnum(dt_buffer[3]) - 1;
    dt->day = bcdnum(dt_buffer[4]);
    dt->month = bcdnum(dt_buffer[5] & 0x1F);
    dt->year = bcdnum(dt_buffer[6]) + 2000;

    return sys_check_datetime(dt);
}

bool dev_ds3231_setrtc(i2c_inst_t* i2c)
{
    datetime_t dt;
    
    if (!dev_ds3231_getdatetime(i2c, &dt))
        return false;

    return sys_setrtc(&dt);
}