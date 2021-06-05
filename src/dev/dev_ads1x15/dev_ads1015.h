// Copyright 2021 Ocean (iiot2k@gmail.com) 
// All rights reserved.

/*!
    @mainpage ../README.md
    @name dev_ads1015 - ADS1015 Four Channel 12-bit ADC
    @file dev_ads1015.h
    @lib dev_ads1x15
    @n
*/

/*! $## **Description:**
    The ADS1015 is a 12-bit analog to digital converter with four inputs.
    Supports single end or two differential input modes.
    The conversion time is 1ms/channel.
    The chip can connected direct to Pico with supply voltage 3.3V.
    Max. adc input voltage is 3.3V.
    I2C address is selectable with ADDR input.
    @n
*/

/*! $### ADS1015 ADC Module
    @image images\ads1015.png
    @n
*/

#ifndef _DEV_ADS1015_H_
#define _DEV_ADS1015_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

#include "sys_i2c.h"

/*! $## **Constants:**
    @--
*/

/*! ADS1015 Address:
    @enum ADS1015_ADDR0 Address 0 (0x48) ADDR - GND or open
    @enum ADS1015_ADDR1 Address 1 (0x49) ADDR - VDD
    @enum ADS1015_ADDR2 Address 2 (0x4A) ADDR - SDA
    @enum ADS1015_ADDR3 Address 3 (0x4B) ADDR - SCL
    @n
 */
enum
{
    ADS1015_ADDR0 = 0x48,
    ADS1015_ADDR1,
    ADS1015_ADDR2,
    ADS1015_ADDR3,
};

/*! ADS1015 Channel:
    @enum ADS1015_CH0 Channel 0
    @enum ADS1015_CH1 Channel 1
    @enum ADS1015_CH2 Channel 2
    @enum ADS1015_CH3 Channel 3
    @n
 */
enum
{
    ADS1015_CH0 = 0,
    ADS1015_CH1,
    ADS1015_CH2,
    ADS1015_CH3,
    ADS1015_CH_NUM,
};

/*! ADS1015 Input Range:
    @enum ADS1015_GAIN_6114 Max. input voltage 6.114V (interpolated)
    @enum ADS1015_GAIN_4096 Max. input voltage 4.096V (interpolated)
    @enum ADS1015_GAIN_2048 Max. input voltage 2.048V (default)
    @enum ADS1015_GAIN_1024 Max. input voltage 1.024V
    @enum ADS1015_GAIN_0512 Max. input voltage 0.512V
    @enum ADS1015_GAIN_0256 Max. input voltage 0.256V
    @n
 */
enum
{
    ADS1015_GAIN_6114 = 0,
    ADS1015_GAIN_4096,
    ADS1015_GAIN_2048,
    ADS1015_GAIN_1024,
    ADS1015_GAIN_0512,
    ADS1015_GAIN_0256,
    ADS1015_GAIN_NUM
};

/*! ADS1015 Input-0 Settings:
    @enum ADS1015_AI0_AI1 Differential input
    @enum ADS1015_AI3_AI0 Differential input
    @enum ADS1015_AI1_AI3 Differential input
    @enum ADS1015_AI2_AI3 Differential input
    @enum ADS1015_AI0_GND Single end Input
    @enum ADS1015_AI1_GND Single end Input
    @enum ADS1015_AI2_GND Single end Input
    @enum ADS1015_AI3_GND Single end Input
    @n
 */
enum
{
    ADS1015_AI0_AI1 = 0,
    ADS1015_AI3_AI0,
    ADS1015_AI1_AI3,
    ADS1015_AI2_AI3,
    ADS1015_AI0_GND,
    ADS1015_AI1_GND,
    ADS1015_AI2_GND,
    ADS1015_AI3_GND,
    ADS1015_MUX_NUM
};

/*! $## **Functions:**
    @--
*/

/*! @brief - Read extended ads1015 channel
    @param i2c I2C channel i2c0 or i2c1
    @param addr I2C address ADS1015_ADDRn
    @param channel Channel number ADS1015_CHn
    @param mux Input mode ADS1015_AIx_xx
    @param gain Input range ADS1015_GAIN_xxxx
    @param value Channel adc value 
    @return true
    @return[error] false
*/
bool dev_ads1015_read_ex(i2c_inst_t* i2c, uint8_t addr, uint8_t channel, uint8_t mux, uint8_t gain, double *value);

/*! @brief - Read ads1015 channel with single-end
    @param i2c I2C channel i2c0 or i2c1
    @param addr I2C address ADS1015_ADDRn
    @param channel Channel number ADS1015_CHn
    @param gain Input range ADS1015_GAIN_xxxx
    @param value Channel adc value 
    @return true
    @return[error] false
*/
static inline bool dev_ads1015_read(i2c_inst_t* i2c, uint8_t addr, uint8_t channel, uint8_t gain, double *value)
{
    return dev_ads1015_read_ex(i2c, addr, channel, channel + ADS1015_AI0_GND, gain, value);
}

#ifdef __cplusplus
 }
#endif

#endif // _DEV_ADS1015_H_
