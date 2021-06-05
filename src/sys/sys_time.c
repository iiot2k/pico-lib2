// Copyright 2021 Ocean (iiot2k@gmail.com) 
// All rights reserved.

#include "pico/stdlib.h"
#include "pico/util/datetime.h"
#include "hardware/watchdog.h"
#include "hardware/rtc.h"
#include "sys_time.h"

#include <time.h>
#include <locale.h>
#include <string.h>

bool sys_timeout_ms(uint64_t* tm, uint32_t timeout_ms)
{
    if (*tm == 0) // check for first time
    {
        *tm = time_us_64() + (timeout_ms * 1000);
        return false;
    }
    else if (time_us_64() > *tm) // check for timeout
    {
        *tm = time_us_64() + (timeout_ms * 1000);
        return true;
    }

    return false;
}

void sys_delay_us(uint32_t delay_us)
{
    uint64_t tend = time_us_64() + delay_us;

    while(time_us_64() < tend)
        watchdog_update(); // run from watchdog
}

#define CHECK_DT(tag, min, max)  if ((dt->tag < min) || (dt->tag > max)) return false

bool sys_check_datetime(datetime_t *dt) 
{
    CHECK_DT(year, 0, 4095);
    CHECK_DT(month, 1, 12);
    CHECK_DT(day, 1, 31);
    CHECK_DT(dotw, 0, 6);
    CHECK_DT(hour, 0, 23);
    CHECK_DT(min, 0, 59);
    CHECK_DT(sec, 0, 59);

    return true;
}

bool sys_setrtc(datetime_t *dt)
{
    return rtc_set_datetime(dt);
}

bool sys_getrtc(datetime_t *dt)
{
    return rtc_get_datetime(dt);
}

void sys_getrtc_str(int8_t* buf, size_t buflen)
{
    datetime_t dt;
    sys_getrtc(&dt);

    datetime_to_str(buf, buflen, &dt);
}

void sys_getrtc_format(int8_t* format, int8_t* buf, size_t buflen)
{
    datetime_t dt;
    sys_getrtc(&dt);

    // init c tm struct
    struct tm pico_time = {
        .tm_sec = dt.sec,
        .tm_min = dt.min,
        .tm_hour = dt.hour,
        .tm_mday = dt.day,
        .tm_mon = dt.month - 1,
        .tm_year = dt.year - 1900,
        .tm_wday = dt.dotw,
        .tm_yday = 0,
        .tm_isdst = 0,
    }; 

    // get date time as string
    strftime(buf, buflen, format, &pico_time);
}

uint8_t sys_dayOfWeek(datetime_t *dt)
{
    uint8_t day = dt->day; 
    uint8_t month = dt->month; 
    uint16_t year = dt->year;

    // adjust month year
    if (month < 3) 
    {
        month += 12;
        year -= 1;
    }

    // split year
    uint32_t c = year / 100;
    year = year % 100;

    // Zeller's congruence
    return (c / 4 - 2 * c + year + year / 4 + 13 * (month + 1) / 5 + day - 1) % 7;
}

void sys_secondsToDate(int64_t ts, datetime_t *dt)
{
    // convert seconds to time
    dt->sec = ts % 60;
    ts /= 60;
    dt->min = ts % 60;
    ts /= 60;
    dt->hour = ts % 24;
    ts /= 24;
  
    // convert seconds to date
    uint32_t tmp1 = ((4 * ts + 102032) / 146097 + 15);
    uint32_t tmp2 = (ts + 2442113 + tmp1 - (tmp1 / 4));
    uint32_t year = (20 * tmp2 - 2442) / 7305;
    uint32_t tmp3 = tmp2 - 365 * year - (year / 4);
    uint32_t month = tmp3 * 1000 / 30601;
    uint32_t day = tmp3 - month * 30 - month * 601 / 1000;
  
    // adjust month and year
    if(month <= 13)
    {
       year -= 4716;
       month -= 1;
    }
    else
    {
       year -= 4715;
       month -= 13;
    }
  
    // set date
    dt->year = year;
    dt->month = month;
    dt->day = day;

    // set day of week
    dt->dotw = sys_dayOfWeek(dt);
}
