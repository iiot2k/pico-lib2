// Copyright 2021 Ocean (iiot2k@gmail.com) 
// All rights reserved.

/*!
    @mainpage ../README.md
    @name sys_util - Utility Functions
    @file sys_util.h
    @lib lib2_sys
    @n
*/

#ifndef  _SYS_UTIL_H_
#define  _SYS_UTIL_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

/*! $## **Functions:**
    @--
*/

/*! @brief - Convert double to string
    @param val Value to convert
    @param prec Precision after decimal point (0..)
    @param buf String buffer
    @param buflen String buffer length
    @return buf parameter
*/
int8_t* sys_dbl_str(double val, int32_t prec, int8_t* buf, size_t buflen);

/*! @brief - Convert int to string
    @param val Value to convert
    @param buf String buffer
    @param buflen String buffer length
    @return buf parameter
*/
int8_t* sys_int_str(int32_t val, int8_t* buf, size_t buflen);

/*! @brief - Get system unique id in hex string form
    @param buf String buffer
    @param buflen String buffer length
    @return buf parameter
*/
int8_t* sys_uid_str(int8_t* buf, size_t buflen);

/*! @brief - Get mac address in hex string form
    @brief The mac address is get from system unique id
    @param buf String buffer
    @param buflen String buffer length
    @return buf parameter
*/
int8_t* sys_mac_str(int8_t* buf, size_t buflen);

/*! @brief - Swaps bytes in word
    @param val Word value to swap
    @return swapped word
*/
static inline uint16_t sys_swap_word(uint16_t val)
{
    return (val<<8 & 0xFF00) | (val>>8 & 0x00FF);
}

#ifdef __cplusplus
}
#endif

#endif   // _SYS_UTIL_H_
