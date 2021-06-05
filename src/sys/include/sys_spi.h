// Copyright 2021 Ocean (iiot2k@gmail.com) 
// All rights reserved.

/*!
    @mainpage ../README.md
    @name sys_spi - SPI Functions
    @file sys_spi.h
    @lib lib2_sys
    @n
*/

/*! $### Default pin assignment for lib2 
    @image images/pico-pinout.png 
*/

#ifndef _SYS_SPI_H_
#define _SYS_SPI_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>
#include "hardware/spi.h"

/*! $## **Constants:**
    @--
*/

/*! **Default spi0 pins:**
    @def SYS_SCK0 sck pin
    @def SYS_TX0 tx pin (mosi)
    @def SYS_RX0 rx pin (miso)
    @def SYS_CS0 cs pin
    @n
*/
#define SYS_SCK0 2
#define SYS_TX0  3
#define SYS_RX0  4
#define SYS_CS0  5

/*! **Default spi1 pins**
    @def SYS_SCK1 sck pin
    @def SYS_TX1 tx pin (mosi)
    @def SYS_RX1 rx pin (miso)
    @def SYS_CS1 cs pin
    @n
*/
#define SYS_SCK1 10
#define SYS_TX1  11
#define SYS_RX1  12
#define SYS_CS1  13

/*! **Extra cs pins**
    @def SYS_CS2 cs pin
    @def SYS_CS3 cs pin
    @n
*/
#define SYS_CS2  14
#define SYS_CS3  15

/*! $## **Chip select pin handling:**
    @--
    @n
*/

/*! @brief - Init cs pin
    @param cs Chip select pin
*/
void sys_spi_cs_init(uint32_t cs);

/*! @brief - Enable cs pin and lock access
    @param cs Chip select pin
*/
void sys_spi_cs_sel(uint32_t cs); 

/*! @brief - Disable cs pin and unlock access
    @param cs Chip select pin
*/
void sys_spi_cs_desel(uint32_t cs); 

/*! $## **SPI Setup:** 
    @--
    @n
*/

/*! @brief - Set spi baudrate
    @param spi Spi channel spi0 or spi1
    @param baudrate Baudrate in Hz
*/
void sys_spi_setbaudrate(spi_inst_t *spi, uint32_t baudrate);

/*! @brief - Init spi with user assignment pins
    @param spi Spi channel spi0 or spi1
    @param tx Spi tx pin (mosi)
    @param rx Spi rx pin (miso)
    @param sck Spi clock pin
    @param baudrate baudrate in Hz
*/
void sys_spi_init(spi_inst_t *spi, uint32_t tx, uint32_t rx, uint32_t sck, uint32_t baudrate);

/*! @brief - Init default spi, init also default cs pin
    @param spi Spi channel spi0 or spi1
    @param baudrate Baudrate in Hz
*/
void sys_spi_init_def(spi_inst_t *spi, uint32_t baudrate);

/*! @brief - Return default cs pin
    @param spi Spi channel spi0 or spi1
    @return Default cs pin
*/
static inline uint32_t sys_spi_def_cs(spi_inst_t *spi)
{
    return (spi == spi0) ? SYS_CS0 : SYS_CS1;
}

/*! $## **Byte functions:**
    @--
    @n
*/

/*! @brief - Read spi byte
    @param spi Spi channel spi0 or spi1
    @param rb Byte to read
    @return Bytes read
    @return[error] Zero
*/
static inline int32_t sys_spi_rbyte(spi_inst_t *spi, uint8_t* rb)
{
    return spi_read_blocking(spi, 0, rb, 1);
}

/*! @brief - Write spi byte
    @param spi Spi channel spi0 or spi1
    @param wb Byte to write
    @return Bytes written
    @return[error] Zero
*/
static inline int32_t sys_spi_wbyte(spi_inst_t *spi, uint8_t wb)
{
    return spi_write_blocking(spi, &wb, 1);
}

/*! $## **Word functions:**
    @--
    @n
*/

/*! @brief - Read spi word
    @param spi Spi channel spi0 or spi1
    @param rw Word to read
    @return Bytes read
    @return[error] Zero
*/
static inline int32_t sys_spi_rword(spi_inst_t *spi, uint16_t* rw)
{
    return spi_read_blocking(spi, 0, (uint8_t*)rw, 2);
}

/*! @brief - Write spi word
    @param spi Spi channel spi0 or spi1
    @param ww Word to write
    @return Bytes written
    @return[error] Zero
*/
static inline int32_t sys_spi_wword(spi_inst_t *spi, uint16_t ww)
{
    return spi_write_blocking(spi, (uint8_t*)&ww, 2);
}

/*! $## **Buffer functions:**
    @--
    @n
*/

/*! @brief - Read spi buffer
    @param spi Spi channel spi0 or spi1
    @param pBuf Buffer to read
    @param len Length to read
    @return Bytes read
    @return[error] Zero
*/
static inline int32_t sys_spi_rbuf(spi_inst_t *spi, uint8_t* pBuf, uint16_t len)
{
    return spi_read_blocking(spi, 0, pBuf, len);
}

/*! @brief - Write spi buffer
    @param spi Spi channel spi0 or spi1
    @param pBuf Buffer to write
    @param len Length to write
    @return Bytes written
    @return[error] Zero
*/
static inline int32_t sys_spi_wbuf(spi_inst_t *spi, uint8_t* pBuf, uint16_t len)
{
    return spi_write_blocking(spi, pBuf, len);
}

#ifdef __cplusplus
}
#endif

#endif // _SYS_SPI_H_
