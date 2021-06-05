// Copyright 2021 Ocean (iiot2k@gmail.com) 
// All rights reserved.

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/watchdog.h"
#include "hardware/rtc.h"

#include "sys_time.h"
#include "sys_gpio.h"
#include "sys_fn.h"

void sys_init()
{
    // init stdio
    stdio_init_all();

    // start rtc
    rtc_init();

    // init led
    sys_gpio_output(PICO_DEFAULT_LED_PIN, 0);
}

void sys_ledon()
{
    sys_gpio_set(PICO_DEFAULT_LED_PIN, 1);
}

void sys_logmsg(const int8_t *msg)
{
    puts(msg);
}

void sys_logmsg2(const int8_t *msg1, const int8_t *msg2)
{
    printf("%s %s\n", msg1, msg2);
}

void sys_outerr(const int8_t *msg)
{
    puts(msg); // print error to stdout

    uint64_t ledtimer = 0; 

    bool ledout = true;
    
    // put watchdog from dog house
    watchdog_enable(3000, 1);

    while(1)
    {
        if (sys_timeout_ms(&ledtimer, 100))
        {
            sys_gpio_set(PICO_DEFAULT_LED_PIN, ledout);
            ledout = !ledout;
        }
    }
}

void sys_loop()
{
    tight_loop_contents();
}
