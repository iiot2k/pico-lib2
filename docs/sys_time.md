🏠 [Main Page](../README.md) <br>
>##  ***sys_time*** - Time Functions
💾File: **sys_time.h** <br>
📦Library: **lib2_sys** <br>
######  <br>
## **Functions:** <br>
--- 
#### 💠Function:  ***sys_timeout_ms*** - Timeout function, call in loop to update timeout
```c 
bool sys_timeout_ms(uint64_t* tm, uint32_t timeout_ms)
```
- ▶️Param:  ***tm*** timer variable, must init with 0 on start <br>
- ▶️Param:  ***timeout_ms*** timeout in ms <br>
- ✅Return: true if timeout <br>

#### 💠Function:  ***sys_delay_us*** - Wait microseconds
```c 
void sys_delay_us(uint32_t delay_us)
```
- ▶️Param:  ***delay_us*** Delay in us <br>

#### 💠Function:  ***sys_delay_ms*** - Wait miliseconds
```c 
static inline void sys_delay_ms(uint32_t delay_ms)
```
- ▶️Param:  ***delay_ms*** Delay in ms <br>

#### 💠Function:  ***sys_delay_s*** - Wait seconds
```c 
static inline void sys_delay_s(uint32_t delay_s)
```
- ▶️Param:  ***delay_us*** Delay in s <br>

#### 💠Function:  ***sys_check_datetime*** - Check datetime_t struct for valid values
```c 
bool sys_check_datetime(datetime_t *dt)
```
- ▶️Param:  ***dt*** datetime_t to check <br>
- ✅Return: true if datetime_t valid <br>

#### 💠Function:  ***sys_setrtc*** - Set system rtc
```c 
bool sys_setrtc(datetime_t *dt)
```
- ▶️Param:  ***dt*** Datetime_t to set <br>
- ✅Return: true if rtc set <br>

#### 💠Function:  ***sys_getrtc*** - Get system rtc
```c 
bool sys_getrtc(datetime_t *dt)
```
- ▶️Param:  ***dt*** Datetime_t to get <br>
- ✅Return: true if rtc get <br>

#### 💠Function:  ***sys_getrtc_str*** - Get system rtc as string
```c 
void sys_getrtc_str(int8_t* buf, size_t buflen)
```
- ▶️Param:  ***buf*** String buffer <br>
- ▶️Param:  ***buflen*** String buffer length <br>

#### 💠Function:  ***sys_getrtc_format*** - Get system rtc as string formated
#### Example format: "%H:%M:%S"
#### For detail format look in C function strftime()
```c 
void sys_getrtc_format(int8_t* format, int8_t* buf, size_t buflen)
```
- ▶️Param:  ***format*** Date time format <br>
- ▶️Param:  ***buf*** String buffer <br>
- ▶️Param:  ***buflen*** String buffer length <br>

#### 💠Function:  ***sys_dayOfWeek*** - Calultate day of week from date
```c 
uint8_t sys_dayOfWeek(datetime_t *dt)
```
- ▶️Param:  ***dt*** Datetime_t to calculate <br>
- ✅Return: Day of week (0=Sunday) <br>

#### 💠Function:  ***sys_secondsToDate*** - Convert unix epoch seconds to date time
```c 
void sys_secondsToDate(int64_t ts, datetime_t *dt)
```
- ▶️Param:  ***ts*** Seconds since unix epoch <br>
- ▶️Param:  ***dt*** Datetime_t to get <br>

