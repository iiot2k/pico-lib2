// Copyright 2021 Ocean (iiot2k@gmail.com) 
// All rights reserved.

/*!
    @mainpage ../README.md
    @name dev_ds3231 - DS3231 extremely accurate RTC
    @file dev_ds3231.h
    @lib dev_ds3231
    @n
*/

/*! $## **Description:**
    The DS3231 is a extremely accurate real-time clock.
    I2C interface with up to 400kHz.
    Battery-Backup input for continuous timekeeping.
*/

/*! $### DS3231 extremely accurate RTC
    @image images\ds3231.png
    @n
*/

#ifndef _DEV_DS3231_H_
#define _DEV_DS3231_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include "pico/util/datetime.h"

#include "sys_i2c.h"

/*! $## **Functions:**
    @--
*/

/*! @brief - Set DS3231
    @param i2c I2C channel i2c0 or i2c1
    @param dt datetime_t with data to set
    @return true if set
    @return[error] false comm. error
*/
bool dev_ds3231_setdatetime(i2c_inst_t* i2c, datetime_t *dt);

/*! @brief - Get DS3231
    @param i2c I2C channel i2c0 or i2c1
    @param dt datetime_t struct where get data
    @return true if get
    @return[error] false comm. error
*/
bool dev_ds3231_getdatetime(i2c_inst_t* i2c, datetime_t *dt);

/*! @brief - Set Pico RTC from date-time of DS3231
    @param i2c I2C channel i2c0 or i2c1
    @return true if set
    @return[error] false comm. error
*/
bool dev_ds3231_setrtc(i2c_inst_t* i2c);

#ifdef __cplusplus
 }
#endif

#endif // _DEV_DS3231_H_
