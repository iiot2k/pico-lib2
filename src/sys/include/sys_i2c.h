// Copyright 2021 Ocean (iiot2k@gmail.com) 
// All rights reserved.

/*!
    @mainpage ../README.md
    @name sys_i2c - I2C Functions
    @file sys_i2c.h
    @lib lib2_sys
    @n
*/

/*! $### Default pin assignment for lib2 
    @image images/pico-pinout.png 
*/

#ifndef _SYS_I2C_H_
#define _SYS_I2C_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include "hardware/i2c.h"

/*! $## **Constants:**
    @--
*/

/*! $**I2C timeout per char**
    @def I2C_TIMEOUT_CHAR timeout (500us)
    @n
*/
#define I2C_TIMEOUT_CHAR 500  

/*! $**Default i2c0 pins**
    @def SYS_SDA0 sda pin
    @def SYS_SCL0 scl pin
    @n
*/
#define SYS_SDA0 8
#define SYS_SCL0 9

/*! $**Default i2c1 pins**
    @def SYS_SDA1 sda pin
    @def SYS_SCL1 scl pin
    @n
*/
#define SYS_SDA1 6
#define SYS_SCL1 7

/*! $## **I2C Setup:** 
    @--
    @n
*/

/*! @brief - Set i2c baudrate
    @param i2c I2C channel i2c0 or i2c1
    @param baudrate Baudrate in Hz
*/
void sys_i2c_setbaudrate(i2c_inst_t* i2c, uint32_t baudrate);

/*! @brief - Init i2c with user assignment pins
    @param i2c I2C channel i2c0 or i2c1
    @param sda Pin number for sda
    @param scl Pin number for scl
    @param baudrate Baudrate in Hz
    @param pullup If true connect internal pullup resistor
*/
void sys_i2c_init(i2c_inst_t* i2c, uint32_t sda, uint32_t scl, uint32_t baudrate, bool pullup);

/*! @brief - Init default i2c
    @param i2c I2C channel i2c0 or i2c1
    @param baudrate Baudrate in Hz
    @param pullup If true connect internal pullup resistor
*/
void sys_i2c_init_def(i2c_inst_t* i2c, uint32_t baudrate, bool pullup);

/*! $## **Byte functions:**
    @--
    @n
*/

/*! @brief - Read i2c byte
    @param i2c I2C channel i2c0 or i2c1
    @param addr I2C address
    @param rb Byte to read
    @return Bytes read
    @return[error] PICO_ERROR_GENERIC On error
    @return[error] PICO_ERROR_TIMEOUT On timeout
*/
static inline int32_t sys_i2c_rbyte(i2c_inst_t* i2c, uint8_t addr, uint8_t* rb)
{
    return i2c_read_timeout_us(i2c, addr, rb, 1, false, I2C_TIMEOUT_CHAR);
}

/*! @brief - Write i2c byte
    @param i2c I2C channel i2c0 or i2c1
    @param addr I2C address
    @param wb Byte to write
    @return Bytes written
    @return[error] PICO_ERROR_GENERIC On error
    @return[error] PICO_ERROR_TIMEOUT On timeout
*/
static inline int32_t sys_i2c_wbyte(i2c_inst_t* i2c, uint8_t addr, uint8_t wb)
{
    return i2c_write_timeout_us(i2c, addr, &wb, 1, false, I2C_TIMEOUT_CHAR);
}

/*! @brief - Read i2c byte register
    @param i2c I2C channel i2c0 or i2c1
    @param addr I2C address
    @param reg Register address
    @param rb Byte to read
    @return Bytes read
    @return[error] PICO_ERROR_GENERIC On error
    @return[error] PICO_ERROR_TIMEOUT On timeout
*/
int32_t sys_i2c_rbyte_reg(i2c_inst_t* i2c, uint8_t addr, uint8_t reg, uint8_t* rb);

/*! @brief - Write i2c byte register
    @param i2c I2C channel i2c0 or i2c1
    @param addr I2C address
    @param reg Register address
    @param wb Byte to write
    @return Bytes written
    @return[error] PICO_ERROR_GENERIC On error
    @return[error] PICO_ERROR_TIMEOUT On timeout
*/
int32_t sys_i2c_wbyte_reg(i2c_inst_t* i2c, uint8_t addr, uint8_t reg, uint8_t wb);

/*! $## **Word functions:**
    @--
    @n
*/

/*! @brief - Read i2c word
    @param i2c I2C channel i2c0 or i2c1
    @param addr I2C address
    @param rw Word to read
    @return Bytes read
    @return[error] PICO_ERROR_GENERIC On error
    @return[error] PICO_ERROR_TIMEOUT On timeout
*/
static inline int32_t sys_i2c_rword(i2c_inst_t* i2c, uint8_t addr, uint16_t* rw)
{
    return i2c_read_timeout_us(i2c, addr, (uint8_t*)rw, 2, false, 2 * I2C_TIMEOUT_CHAR);
}

/*! @brief - Write i2c word
    @param i2c I2C channel i2c0 or i2c1
    @param addr I2C address
    @param ww Word to write
    @return Bytes written
    @return[error] PICO_ERROR_GENERIC On error
    @return[error] PICO_ERROR_TIMEOUT On timeout
*/
static inline int32_t sys_i2c_wword(i2c_inst_t* i2c, uint8_t addr, uint16_t ww)
{
    return i2c_write_timeout_us(i2c, addr, (uint8_t*)&ww, 2, false, 2 * I2C_TIMEOUT_CHAR);
}

/*! @brief - Read i2c word register
    @param i2c I2C channel i2c0 or i2c1
    @param addr I2C address
    @param reg Register address
    @param rw Word to read
    @return Bytes read
    @return[error] PICO_ERROR_GENERIC On error
    @return[error] PICO_ERROR_TIMEOUT On timeout
*/
int32_t sys_i2c_rword_reg(i2c_inst_t* i2c, uint8_t addr, uint8_t reg, uint16_t* rw);

/*! @brief - Write i2c word register
    @param i2c I2C channel i2c0 or i2c1
    @param addr I2C address
    @param reg Register address
    @param ww Word to write
    @return Bytes written
    @return[error] PICO_ERROR_GENERIC On error
    @return[error] PICO_ERROR_TIMEOUT On timeout
*/
int32_t sys_i2c_wword_reg(i2c_inst_t* i2c, uint8_t addr, uint8_t reg, uint16_t ww);

/*! $## **Buffer functions:**
    @--
    @n
*/

/*! @brief - Read i2c buffer
    @param i2c I2C channel i2c0 or i2c1
    @param addr I2C address
    @param pBuf Buffer to read
    @param len Length to read
    @return Bytes read
    @return[error] PICO_ERROR_GENERIC On error
    @return[error] PICO_ERROR_TIMEOUT On timeout
*/
static inline int32_t sys_i2c_rbuf(i2c_inst_t* i2c, uint8_t addr, uint8_t* pBuf, uint32_t len)
{
    return i2c_read_timeout_us(i2c, addr, pBuf, len, false, len * I2C_TIMEOUT_CHAR);
}

/*! @brief - Write i2c buffer
    @param i2c I2C channel i2c0 or i2c1
    @param addr I2C address
    @param pBuf Buffer to write
    @param len Length to write
    @return Bytes written
    @return[error] PICO_ERROR_GENERIC On error
    @return[error] PICO_ERROR_TIMEOUT On timeout
*/
static inline int32_t sys_i2c_wbuf(i2c_inst_t* i2c, uint8_t addr, const uint8_t* pBuf, uint32_t len)
{
    return i2c_write_timeout_us(i2c, addr, pBuf, len, false, len * I2C_TIMEOUT_CHAR);
}

/*! @brief - Read i2c buffer register
    @param i2c I2C channel i2c0 or i2c1
    @param addr I2C address
    @param reg Register address
    @param pBuf Buffer to read
    @param len Length to read
    @return Bytes read
    @return[error] PICO_ERROR_GENERIC On error
    @return[error] PICO_ERROR_TIMEOUT On timeout
*/
int32_t sys_i2c_rbuf_reg(i2c_inst_t* i2c, uint8_t addr, uint8_t reg, uint8_t* pBuf, uint32_t len);

/*! @brief - Write i2c buffer register
    @param i2c I2C channel i2c0 or i2c1
    @param addr I2C address
    @param reg Register address
    @param pBuf Buffer to read
    @param len Length to read
    @return Bytes written
    @return[error] PICO_ERROR_GENERIC On error
    @return[error] PICO_ERROR_TIMEOUT On timeout
*/
int32_t sys_i2c_wbuf_reg(i2c_inst_t* i2c, uint8_t addr, uint8_t reg, uint8_t* pBuf, uint32_t len);

#ifdef __cplusplus
}
#endif

#endif   // _SYS_I2C_H_
