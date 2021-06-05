// Copyright 2021 Ocean (iiot2k@gmail.com) 
// All rights reserved.

/*!
    @mainpage ../README.md
    @name dev_mcp4728 - MCP4728 Four Channel 12-bit DAC
    @file dev_mcp4728.h
    @lib dev_mcp472x
    @n
*/

/*! $## **Description:**
    The MCP4728 is a 12-bit digital to analog converter with four outputs.
    The chip can connected direct to Pico with supply voltage 3.3V.
    Maximum output voltage is 3.3V.
    @n
*/

/*! $### MCP4728 DAC Module
    @image images\mcp4728.png
    @n
*/

#ifndef _DEV_MCP4728_H_
#define _DEV_MCP4728_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

#include "sys_i2c.h"

/*! MCP4728 Channel:
    @enum MCP4728_CHA Channel A
    @enum MCP4728_CHA Channel B
    @enum MCP4728_CHA Channel C
    @enum MCP4728_CHA Channel D
    @n
 */
enum
{
    MCP4728_CHA = 0,
    MCP4728_CHB,
    MCP4728_CHC,
    MCP4728_CHD,
    MCP4728_CH_NUM,
};

/*! MCP4728 Gain:
    @enum MCP4728_GAIN1 Gain x 1
    @enum MCP4728_GAIN2 Gain x 2
    @n
 */
enum
{
    MCP4728_GAIN1 = 0,
    MCP4728_GAIN2,
    MCP4728_GAIN_NUM,
};

/*! MCP4728 VRef:
    @enum MCP4728_VREF_VDD VRef VDD
    @enum MCP4728_VREF_INT VRef Internal
    @n
 */
enum
{
    MCP4728_VREF_VDD = 0,
    MCP4728_VREF_INT,
    MCP4728_VREF_NUM,
};

/*! MCP4728 Power Down:
    @enum MCP4728_PD_OFF Power down off
    @enum MCP4728_PD_1 Power down with 1k resistor
    @enum MCP4728_PD_100 Power down with 100k resistor
    @enum MCP4728_PD_500 Power down with 500k resistor
    @n
 */
enum
{
    MCP4728_PD_OFF = 0,
    MCP4728_PD_1,
    MCP4728_PD_100,
    MCP4728_PD_500,
    MCP4728_PD_NUM,
};

/*! $## **Functions:**
    @--
*/

/*! @brief - Sets power down for channel (active on set or save to dac)
    @brief Default power down is MCP4728_PD_OFF
    @param ch DAC channel MCP4728_CHAx
    @param pd Power down settings MCP4728_PD_xxx
*/
void dev_mcp4728_pd(uint8_t ch, uint8_t pd);

/*! @brief - Sets Vref for channel (active on set or save to dac)
    @brief Default Vref is MCP4728_VREF_INT
    @param ch DAC channel MCP4728_CHAx
    @param vref Vref settings MCP4728_VREF_XX
*/
void dev_mcp4728_vref(uint8_t ch, uint8_t vref);

/*! @brief - Sets gain for channel (active on set or save to dac)
    @brief Default gain is MCP4728_GAIN2
    @param ch DAC channel MCP4728_CHAx
    @param vref Gain settings MCP4728_GAINn
*/
void dev_mcp4728_gain(uint8_t ch, uint8_t gain);

/*! @brief - Sets adc output
    @param i2c I2C channel i2c0 or i2c1
    @param ch DAC channel MCP4728_CHAx
    @param value Output value for for channnel (0..4095)
    @return true
    @return[error] false
*/
bool dev_mcp4728_set(i2c_inst_t* i2c, uint8_t ch, uint16_t value);

/*! @brief - Sets adc output and save settings to EEPROM (50ms)
    @param i2c I2C channel i2c0 or i2c1
    @param ch DAC channel MCP4728_CHAx
    @param value Output value for for channnel (0..4095)
    @return true
    @return[error] false
*/
bool dev_mcp4728_save(i2c_inst_t* i2c, uint8_t ch, uint16_t value);

#ifdef __cplusplus
 }
#endif

#endif // _DEV_MCP4728_H_
