// Copyright 2021 Ocean (iiot2k@gmail.com) 
// All rights reserved.

#include "pico/stdlib.h"
#include "pico/mutex.h"

#include "sys_gpio.h"
#include "sys_i2c.h"

// mutex for i2c
auto_init_mutex(i2c_mutex);

#define ENTER_SECTION mutex_enter_blocking(&i2c_mutex)
#define EXIT_SECTION  mutex_exit(&i2c_mutex);

static uint32_t i2c_baudrate[] = {0, 0};

void sys_i2c_setbaudrate(i2c_inst_t* i2c, uint32_t baudrate)
{
    uint8_t idx = (i2c == i2c0) ? 0 : 1;

    // check if baudrate change
    if (baudrate != i2c_baudrate[idx])
    {
        i2c_baudrate[idx] = baudrate;
        i2c_set_baudrate(i2c, baudrate);
    }
}

void sys_i2c_init(i2c_inst_t* i2c, uint32_t sda, uint32_t scl, uint32_t baudrate, bool pullup)
{
    uint8_t idx = (i2c == i2c0) ? 0 : 1;
   
    // init i2c
    i2c_baudrate[idx] = baudrate;
    
    i2c_init(i2c, baudrate);

    // init pins
    gpio_set_function(sda, GPIO_FUNC_I2C);
    gpio_set_function(scl, GPIO_FUNC_I2C);

    if (pullup)
    {
        sys_gpio_setpullup(sda);
        sys_gpio_setpullup(scl);
    }
}

void sys_i2c_init_def(i2c_inst_t* i2c, uint32_t baudrate, bool pullup)
{
    if (i2c == i2c0)
        sys_i2c_init(i2c, SYS_SDA0, SYS_SCL0, baudrate, pullup);
    else
        sys_i2c_init(i2c, SYS_SDA1, SYS_SCL1, baudrate, pullup);
}

int32_t sys_i2c_rbyte_reg(i2c_inst_t* i2c, uint8_t addr, uint8_t reg, uint8_t* rb)
{
    ENTER_SECTION;
    int32_t ret = i2c_write_timeout_us(i2c, addr, &reg, 1, true, I2C_TIMEOUT_CHAR);
    if (ret > 0)
        ret = i2c_read_timeout_us(i2c, addr, rb, 1, false, I2C_TIMEOUT_CHAR);
    EXIT_SECTION;
    return ret;
}

int32_t sys_i2c_wbyte_reg(i2c_inst_t* i2c, uint8_t addr, uint8_t reg, uint8_t wb)
{
    ENTER_SECTION;
    uint8_t buffer[2];
    buffer[0] = reg;
    buffer[1] = wb;
    uint8_t ret = i2c_write_timeout_us(i2c, addr, buffer, 2, false, 2 * I2C_TIMEOUT_CHAR);
    EXIT_SECTION;
    return ret;
}

int32_t sys_i2c_rword_reg(i2c_inst_t* i2c, uint8_t addr, uint8_t reg, uint16_t* rw)
{
    ENTER_SECTION;
    int32_t ret = i2c_write_timeout_us(i2c, addr, &reg, 1, true, I2C_TIMEOUT_CHAR);
    if (ret > 0)
        ret = i2c_read_timeout_us(i2c, addr, (uint8_t*)rw, 2, false, 2 * I2C_TIMEOUT_CHAR);
    EXIT_SECTION;
    return ret;
}

int32_t sys_i2c_wword_reg(i2c_inst_t* i2c, uint8_t addr, uint8_t reg, uint16_t ww)
{
    ENTER_SECTION;
    uint8_t buffer[3];
    buffer[0] = reg;
    buffer[1] = ww;
    buffer[2] = ww >> 8;
    int32_t ret = i2c_write_timeout_us(i2c, addr, buffer, 3, false, 3 * I2C_TIMEOUT_CHAR);
    EXIT_SECTION;
    return ret;
}

int32_t sys_i2c_rbuf_reg(i2c_inst_t* i2c, uint8_t addr, uint8_t reg, uint8_t* pBuf, uint32_t len)
{
    ENTER_SECTION;
    int32_t ret = i2c_write_timeout_us(i2c, addr, &reg, 1, true, I2C_TIMEOUT_CHAR);
    if (ret > 0)
        ret = i2c_read_timeout_us(i2c, addr, pBuf, len, false, len * I2C_TIMEOUT_CHAR);
    EXIT_SECTION;
    return ret;
}

int32_t sys_i2c_wbuf_reg(i2c_inst_t* i2c, uint8_t addr, uint8_t reg, uint8_t* pBuf, uint32_t len)
{
    ENTER_SECTION;
    int32_t ret = i2c_write_timeout_us(i2c, addr, &reg, 1, true, I2C_TIMEOUT_CHAR);
    if (ret > 0)
        ret = i2c_write_timeout_us(i2c, addr, pBuf, len, false, len * I2C_TIMEOUT_CHAR);
    EXIT_SECTION;
    return ret;
}
