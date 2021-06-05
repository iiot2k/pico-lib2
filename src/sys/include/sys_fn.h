// Copyright 2021 Ocean (iiot2k@gmail.com) 
// All rights reserved.

/*!
    @mainpage ../README.md
    @name sys_fn - System Functions
    @file sys_fn.h
    @lib lib2_sys
    @n
*/

#ifndef _SYS_FN_H_
#define _SYS_FN_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>

/*! $## **Functions:**
    @--
*/

/*! @brief - Init system enviroment
*/
void sys_init();

/*! @brief - Turn led on (indicate is ok)
*/
void sys_ledon();

/*! @brief - Print text to stdout
    @param msg Message to write stdout 
*/
void sys_logmsg(const int8_t *msg);

/*! @brief - Print texts to stdout
    @param msg1 Message 1 to write stdout 
    @param msg2 Message 2 to write stdout 
*/
void sys_logmsg2(const int8_t *msg1, const int8_t *msg2);

/*! @brief - Print error, blink led and wait until watchdog bites
    @param msg Message to write stdout 
*/
void sys_outerr(const int8_t *msg);

/*! @brief - System loop (give watchdog a bone)
*/
void sys_loop();

#ifdef __cplusplus
 }
#endif

#endif   // _SYS_FN_H_

