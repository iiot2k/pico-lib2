// Copyright 2021 Ocean (iiot2k@gmail.com) 
// All rights reserved.

/*!
    @mainpage ../README.md
    @name sys_time - Time Functions
    @file sys_time.h
    @lib lib2_sys
    @n
*/

#ifndef  _SYS_TIME_H_
#define  _SYS_TIME_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include "pico/util/datetime.h"

/*! $## **Functions:**
    @--
*/

/*! @brief - Timeout function, call in loop to update timeout
    @param tm timer variable, must init with 0 on start
    @param timeout_ms timeout in ms
    @return true if timeout
*/
bool sys_timeout_ms(uint64_t* tm, uint32_t timeout_ms);

/*! @brief - Wait microseconds
    @param delay_us Delay in us
*/
void sys_delay_us(uint32_t delay_us);

/*! @brief - Wait miliseconds
    @param delay_ms Delay in ms
*/
static inline void sys_delay_ms(uint32_t delay_ms) { sys_delay_us(delay_ms * 1000); }

/*! @brief - Wait seconds
    @param delay_us Delay in s
*/
static inline void sys_delay_s(uint32_t delay_s) { sys_delay_us(delay_s * 1000 * 1000); }

/*! @brief - Check datetime_t struct for valid values
    @param dt datetime_t to check
    @return true if datetime_t valid
*/
bool sys_check_datetime(datetime_t *dt);

/*! @brief - Set system rtc
    @param dt Datetime_t to set
    @return true if rtc set
*/
bool sys_setrtc(datetime_t *dt);

/*! @brief - Get system rtc
    @param dt Datetime_t to get
    @return true if rtc get
*/
bool sys_getrtc(datetime_t *dt);

/*! @brief - Get system rtc as string
    @param buf String buffer
    @param buflen String buffer length
*/
void sys_getrtc_str(int8_t* buf, size_t buflen);

/*! @brief - Get system rtc as string formated
    @brief Example format: "%H:%M:%S"
    @brief For detail format look in C function strftime()
    @param format Date time format
    @param buf String buffer
    @param buflen String buffer length
*/
void sys_getrtc_format(int8_t* format, int8_t* buf, size_t buflen);

/*! @brief - Calultate day of week from date
    @param dt Datetime_t to calculate
    @return Day of week (0=Sunday)
*/
uint8_t sys_dayOfWeek(datetime_t *dt);

/*! @brief - Convert unix epoch seconds to date time
    @param ts Seconds since unix epoch 
    @param dt Datetime_t to get
*/
void sys_secondsToDate(int64_t ts, datetime_t *dt);

#ifdef __cplusplus
}
#endif

#endif   // _SYS_TIME_H_
