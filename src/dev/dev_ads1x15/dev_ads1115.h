// Copyright 2021 Ocean (iiot2k@gmail.com) 
// All rights reserved.

/*!
    @mainpage ../README.md
    @name dev_ads1115 - ADS1115 Four Channel 16-bit ADC
    @file dev_ads1115.h
    @lib dev_ads1x15
    @n
*/

/*! $## **Description:**
    The ADS1115 is a 16-bit analog to digital converter with four inputs.
    Supports single end or two differential input modes.
    The conversion time is 10ms/channel.
    The chip can connected direct to Pico with supply voltage 3.3V.
    Max. adc input voltage is 3.3V.
    I2C address is selectable with ADDR input.
    @n
*/

/*! $### ADS1115 ADC Module
    @image images\ads1115.png
    @n
*/

#ifndef _DEV_ADS1115_H_
#define _DEV_ADS1115_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

#include "sys_i2c.h"

/*! $## **Constants:**
    @--
*/

/*! ADS1115 Address:
    @enum ADS1115_ADDR0 Address 0 (0x48) ADDR - GND or open
    @enum ADS1115_ADDR1 Address 1 (0x49) ADDR - VDD
    @enum ADS1115_ADDR2 Address 2 (0x4A) ADDR - SDA
    @enum ADS1115_ADDR3 Address 3 (0x4B) ADDR - SCL
    @n
 */
enum
{
    ADS1115_ADDR0 = 0x48,
    ADS1115_ADDR1,
    ADS1115_ADDR2,
    ADS1115_ADDR3,
};

/*! ADS1115 Channel:
    @enum ADS1115_CH0 Channel 0
    @enum ADS1115_CH1 Channel 1
    @enum ADS1115_CH2 Channel 2
    @enum ADS1115_CH3 Channel 3
    @n
 */
enum
{
    ADS1115_CH0 = 0,
    ADS1115_CH1,
    ADS1115_CH2,
    ADS1115_CH3,
    ADS1115_CH_NUM,
};

/*! ADS1115 Input Range:
    @enum ADS1115_GAIN_6114 Max. input voltage 6.114V (interpolated)
    @enum ADS1115_GAIN_4096 Max. input voltage 4.096V (interpolated)
    @enum ADS1115_GAIN_2048 Max. input voltage 2.048V (default)
    @enum ADS1115_GAIN_1024 Max. input voltage 1.024V
    @enum ADS1115_GAIN_0512 Max. input voltage 0.512V
    @enum ADS1115_GAIN_0256 Max. input voltage 0.256V
    @n
 */
enum
{
    ADS1115_GAIN_6114 = 0,
    ADS1115_GAIN_4096,
    ADS1115_GAIN_2048,
    ADS1115_GAIN_1024,
    ADS1115_GAIN_0512,
    ADS1115_GAIN_0256,
    ADS1115_GAIN_NUM
};

/*! ADS1115 Input-0 Settings:
    @enum ADS1115_AI0_AI1 Differential input
    @enum ADS1115_AI3_AI0 Differential input
    @enum ADS1115_AI1_AI3 Differential input
    @enum ADS1115_AI2_AI3 Differential input
    @enum ADS1115_AI0_GND Single end Input
    @enum ADS1115_AI1_GND Single end Input
    @enum ADS1115_AI2_GND Single end Input
    @enum ADS1115_AI3_GND Single end Input
    @n
 */
enum
{
    ADS1115_AI0_AI1 = 0,
    ADS1115_AI3_AI0,
    ADS1115_AI1_AI3,
    ADS1115_AI2_AI3,
    ADS1115_AI0_GND,
    ADS1115_AI1_GND,
    ADS1115_AI2_GND,
    ADS1115_AI3_GND,
    ADS1115_MUX_NUM
};

/*! $## **Functions:**
    @--
*/

/*! @brief - Read extended ads1115 channel
    @param i2c I2C channel i2c0 or i2c1
    @param addr I2C address ADS1115_ADDRn
    @param channel Channel number ADS1115_CHn
    @param mux Input mode ADS1115_AIx_xx
    @param gain Input range ADS1115_GAIN_xxxx
    @param value Channel adc value 
    @return true
    @return[error] false
*/
bool dev_ads1115_read_ex(i2c_inst_t* i2c, uint8_t addr, uint8_t channel, uint8_t mux, uint8_t gain, double *value);

/*! @brief - Read ads1115 channel with single-end
    @param i2c I2C channel i2c0 or i2c1
    @param addr I2C address ADS1115_ADDRn
    @param channel Channel number ADS1115_CHn
    @param gain Input range ADS1115_GAIN_xxxx
    @param value Channel adc value 
    @return true
    @return[error] false
*/
static inline bool dev_ads1115_read(i2c_inst_t* i2c, uint8_t addr, uint8_t channel, uint8_t gain, double *value)
{
    return dev_ads1115_read_ex(i2c, addr, channel, channel + ADS1115_AI0_GND, gain, value);
}

#ifdef __cplusplus
 }
#endif

#endif // _DEV_ADS1115_H_
