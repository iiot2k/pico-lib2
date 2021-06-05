// Copyright 2021 Ocean (iiot2k@gmail.com) 
// All rights reserved.

/*!
    @mainpage ../README.md
    @name dev_mcp4725 - MCP4725 One Channel 12-bit ADC
    @file dev_mcp4725.h
    @lib dev_mcp472x
    @n
*/

/*! $## **Description:**
    The MCP4725 is a 12-bit digital to analog converter with one output.
    The chip can connected direct to Pico with supply voltage 3.3V.
    Maximum output voltage is VDD (3.3V).
    @n
*/

/*! $### MCP4725 DAC Module
    @image images\mcp4725.png
    @n
*/

#ifndef _DEV_MCP4725_H_
#define _DEV_MCP4725_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

#include "sys_i2c.h"

/*! MCP4725 IC2 address:
    @enum MCP4725_ADDR0 I2C address (0x61) A0 to GND or open
    @enum MCP4725_ADDR1 I2C address (0x62) A0 to VDD
    @n
 */
#define MCP4725_ADDR0 0x61
#define MCP4725_ADDR1 0x62

/*! MCP4725 Power Down:
    @enum MCP4725_PD_OFF Power down off
    @enum MCP4725_PD_1 Power down with 1k resistor
    @enum MCP4725_PD_100 Power down with 100k resistor
    @enum MCP4725_PD_500 Power down with 500k resistor
    @n
 */
enum
{
    MCP4725_PD_OFF = 0,
    MCP4725_PD_1,
    MCP4725_PD_100,
    MCP4725_PD_500,
};

/*! $## **Functions:**
    @--
*/
/*! @brief - Sets power down for channel (active on set or save to dac)
    @brief Default power down is MCP4725_PD_OFF
    @param pd Power down settings MCP4725_PD_xxx
*/
void dev_mcp4725_pd(uint8_t pd);

/*! @brief - Sets adc output
    @param i2c I2C channel i2c0 or i2c1
    @param addr I2C address MCP4725_ADDRn
    @param value Output value for for channnel (0..4095)
    @return true
    @return[error] false
*/
bool dev_mcp4725_set(i2c_inst_t* i2c, uint8_t addr, uint16_t value);

/*! @brief - Sets adc output and save settings to EEPROM (50ms)
    @param i2c I2C channel i2c0 or i2c1
    @param addr I2C address MCP4725_ADDRn
    @param value Output value for for channnel (0..4095)
    @return true
    @return[error] false
*/
bool dev_mcp4725_save(i2c_inst_t* i2c, uint8_t addr, uint16_t value);

#ifdef __cplusplus
 }
#endif

#endif // _DEV_MCP4725_H_
