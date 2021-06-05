// Copyright 2021 Ocean (iiot2k@gmail.com) 
// All rights reserved.

/*!
    @mainpage ../README.md
    @name sys_gpio - GPIO Functions
    @file sys_gpio.h
    @lib lib2_sys
    @n
*/

#ifndef _SYS_GPIO_H_
#define _SYS_GPIO_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include "hardware/gpio.h"

/*! $## **Functions:**
    @--
*/

/*! @brief - Init gpio as output
    @param pin GP pin number
    @param init Init output (true or false)
*/
static inline void sys_gpio_output(uint32_t pin, bool init)
{
    gpio_init(pin);
    gpio_set_dir(pin, GPIO_OUT);
    gpio_put(pin, init);
}

/*! @brief - Set gpio output
    @param pin GP pin number
    @param value Set value (true or false)
*/
static inline void sys_gpio_set(uint32_t pin, bool value)
{
    gpio_put(pin, value);
}

/*! @brief - Init gpio as input
    @param pin GP pin number
*/
static inline void sys_gpio_input(uint32_t pin)
{
    gpio_init(pin);
    gpio_set_dir(pin, GPIO_IN);
}

/*! @brief - Set gpio input pullup resistor
    @param pin GP pin number
*/
static inline void sys_gpio_setpullup(uint32_t pin)
{
    gpio_pull_up(pin);
}

/*! @brief - Set input pulldown resistor
    @param pin GP pin number
*/
static inline void sys_gpio_setpulldown(uint32_t pin)
{
    gpio_pull_down(pin);
}

/*! @brief - Init gpio as input with pullup resistor
    @param pin GP pin number
*/
static inline void sys_gpio_pullup(uint32_t pin)
{
    gpio_init(pin);
    gpio_set_dir(pin, GPIO_IN);
    gpio_pull_up(pin);
}

/*! @brief - Init gpio as input with pulldown resistor
    @param pin GP pin number
*/
static inline void sys_gpio_pulldown(uint32_t pin)
{
    gpio_init(pin);
    gpio_set_dir(pin, GPIO_IN);
    gpio_pull_down(pin);
}

/*! @brief - Get input gpio state
    @param pin GP pin number
    @return true if pullup input connected to ground, else connected to vcc
*/
static inline bool sys_gpio_get(uint32_t pin)
{
    if (gpio_is_pulled_up(pin))
        return !gpio_get(pin);
    else
        return gpio_get(pin);
}

#ifdef __cplusplus
}
#endif

#endif   // _SYS_GPIO_H_
