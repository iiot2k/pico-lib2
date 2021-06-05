// Copyright 2021 Ocean (iiot2k@gmail.com) 
// All rights reserved.

#include "pico/stdlib.h"
#include "pico/mutex.h"

#include "sys_gpio.h"
#include "sys_spi.h"

// mutex for spi
auto_init_mutex(spi_mutex);
#define ENTER_SECTION mutex_enter_blocking(&spi_mutex)
#define EXIT_SECTION  mutex_exit(&spi_mutex)

// **** cs pin handling

void sys_spi_cs_init(uint32_t cs)
{
    sys_gpio_output(cs, true);
}

void sys_spi_cs_sel(uint32_t cs) 
{
    ENTER_SECTION;
    asm volatile("nop \n nop \n nop");
    sys_gpio_set(cs, false);
    asm volatile("nop \n nop \n nop");
}

void sys_spi_cs_desel(uint32_t cs)
{
    asm volatile("nop \n nop \n nop");
    sys_gpio_set(cs, true);
    asm volatile("nop \n nop \n nop");
    EXIT_SECTION;
}

static uint32_t spi_baudrate[] = {0, 0};

void sys_spi_setbaudrate(spi_inst_t *spi, uint32_t baudrate)
{
    uint8_t idx = (spi == spi0) ? 0 : 1;

    // check if baudrate change
    if (baudrate != spi_baudrate[idx])
    {
        spi_baudrate[idx] = baudrate;
        spi_set_baudrate(spi, baudrate);
    }
}

void sys_spi_init(spi_inst_t *spi, uint32_t tx, uint32_t rx, uint32_t sck, uint32_t baudrate)
{
    uint8_t idx = (spi == spi0) ? 0 : 1;
   
    spi_baudrate[idx] = baudrate;

    // init spi
    spi_init(spi, baudrate);
    
    // init pins
    gpio_set_function(tx, GPIO_FUNC_SPI);
    gpio_set_function(rx, GPIO_FUNC_SPI);
    gpio_set_function(sck, GPIO_FUNC_SPI);
}

void sys_spi_init_def(spi_inst_t *spi, uint32_t baudrate)
{
    if (spi == spi0)
    {
        sys_spi_init(spi, SYS_TX0, SYS_RX0, SYS_SCK0, baudrate);
        sys_spi_cs_init(SYS_CS0);
    }
    else
    {
        sys_spi_init(spi, SYS_TX1, SYS_RX1, SYS_SCK1, baudrate);
        sys_spi_cs_init(SYS_CS1);
    }
}
