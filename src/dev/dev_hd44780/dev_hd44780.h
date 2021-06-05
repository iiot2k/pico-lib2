// Copyright 2021 Ocean (iiot2k@gmail.com) 
// All rights reserved.

/*!
    @mainpage ../README.md
    @name dev_hd44780 - HD44780 LCD Driver with PCF8574
    @file dev_hd44780.h
    @lib dev_hd44780
    @n
*/

/*! $## **Description:**
    The Hitachi HD44780 LCD controller drives alphanumeric LCD displays
    with 2x16 (1602) or 4x20 (2004) LCD displays.
    This driver supports HD44780 with I2C on PCF8574 port expander.
    Use level shifter to interface with Raspberry Pico.
    LCD needs 5V for valid operation or use 3.3V LCD displays.  
*/

/*! $### 2004 and 1602 LCD Display
    @image images\hd44780.png
    @n
*/

#ifndef _DEV_HD44780_H_
#define _DEV_HD44780_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

#include "sys_i2c.h"

/*! $## **Functions:**
    @--
*/

/*! @brief - Init hd44780
    @param i2c I2c channel i2c0 or i2c1
    @param addr I2c address (0x27..)
*/
void dev_hd44780_init(i2c_inst_t* i2c, uint8_t addr);

/*! @brief Write text to hd44780 lcd
    @param i2c I2c channel i2c0 or i2c1
    @param addr I2c address (0x27..)
    @param line Line number 0..3 (4 line lcd), 0..1 (2 line lcd)
    @param is4line True for 4 line lcd type
    @param txt Text in format col;text, without col format, text is written to column 0
*/
void dev_hd44780_text(i2c_inst_t* i2c, uint8_t addr, uint8_t line, bool is4line, uint8_t* txt);

/*! @brief Display bargraph on hd44780 lcd
    @param i2c I2c channel i2c0 or i2c1
    @param addr I2c address (0x27..)
    @param line Line number 0..3 (4 line lcd), 0..1 (2 line lcd)
    @param is4line True for 4 line lcd type
    @param data In range 0..100 
*/
void dev_hd44780_bargraph(i2c_inst_t* i2c, uint8_t addr, uint8_t line, bool is4line, uint8_t data);

#ifdef __cplusplus
 }
#endif

#endif // _DEV_HD44780_H_
