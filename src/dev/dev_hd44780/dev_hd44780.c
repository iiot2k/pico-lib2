// Copyright 2021 Ocean (iiot2k@gmail.com) 
// All rights reserved.

#include <stdlib.h>
#include <string.h>

#include "sys_time.h"

#include "dev_hd44780.h"

#define LCD_CS  0x4
#define LCD_LED 0x8

// write to hd44780 module
static void hd44780_write(i2c_inst_t* i2c, uint8_t addr, uint8_t data, uint8_t rs)
{
    uint8_t data_h = (data & 0xF0) | LCD_LED | rs;
    uint8_t data_l = (data << 4) | LCD_LED | rs;

    // write high byte and pulse CD with negative edge
    sys_i2c_wbyte(i2c, addr, data_h | LCD_CS);
    sys_delay_us(100); // cs setup time
    sys_i2c_wbyte(i2c, addr, data_h); 
    sys_delay_us(200); // data hold time

    // write low byte and pulse CD with negative edge
    sys_i2c_wbyte(i2c, addr, data_l | LCD_CS);
    sys_delay_us(100); // cs setup time
    sys_i2c_wbyte(i2c, addr, data_l);
    sys_delay_us(200); // data hold time
}

// write commend
static void inline hd44780_cmd(i2c_inst_t* i2c, uint8_t addr, uint8_t data)
{
    hd44780_write(i2c, addr, data, 0);
}

// write data
static void inline hd44780_data(i2c_inst_t* i2c, uint8_t addr, uint8_t data)
{
    hd44780_write(i2c, addr, data, 1);
}

void dev_hd44780_init(i2c_inst_t* i2c, uint8_t addr)
{
    // set interface to 4 bit
    sys_delay_ms(50);
    hd44780_cmd(i2c, addr, 0x03);
    hd44780_cmd(i2c, addr, 0x03);
    hd44780_cmd(i2c, addr, 0x03);
    hd44780_cmd(i2c, addr, 0x02);

    // set lcd register
    hd44780_cmd(i2c, addr, 0x04 | 0x02); // increment DDRAM
    hd44780_cmd(i2c, addr, 0x08 | 0x04); // display on
    hd44780_cmd(i2c, addr, 0x20 | 0x08); // 4bit, 2 lines, 5x8 dots

    // clear display
    hd44780_cmd(i2c, addr, 0x01); 
    sys_delay_ms(20);
}

static uint8_t row_offsets[] = { 0x00, 0x40, 0x14, 0x54 };

void dev_hd44780_text(i2c_inst_t* i2c, uint8_t addr, uint8_t line, bool is4line, uint8_t* txt)
{
     // 1602 has only two lines
    if (!is4line && (line > 1))
        return;

    // 2004 has only four lines
    if (is4line && (line > 3))
        return;

   // find separator
    uint8_t* ptr = strchr(txt, ';');
    uint8_t col = 0;
    uint8_t maxcol = is4line ? 20 : 16;

    // separator ?
    if (ptr != NULL)
    {
        col = atoi(txt); // get column number
        ptr++; // skip separator
    }
    else
        ptr = txt;

    // check column
    if (col >= maxcol)
        col = 0;

    // set cursor
    hd44780_cmd(i2c, addr, 0x80 | (col + row_offsets[line]));

    uint8_t i;

    // send string to lcd
    for(i = col; (i < maxcol) && *ptr; i++, ptr++)
        hd44780_data(i2c, addr, *ptr);
}

void dev_hd44780_bargraph(i2c_inst_t* i2c, uint8_t addr, uint8_t line, bool is4line, uint8_t data)
{
    // 1602 has only two lines
    if (!is4line && (line > 1))
        return;

    // 2004 has only four lines
    if (is4line && (line > 3))
        return;

    // clamp num
    if (data > 100)
        data = 100;

    // set cursor to col 0
    hd44780_cmd(i2c, addr, 0x80 | row_offsets[line]);

    uint8_t maxcol = is4line ? 20 : 16;
    uint8_t steps = is4line ? 5 : 6;
    uint8_t i;

    // print bargraph
    for(i = 0; i < maxcol; i++)
    {
        if (data > (i*steps))
            hd44780_data(i2c, addr, 0xFF);
        else
            hd44780_data(i2c, addr, ' ');
    }
}