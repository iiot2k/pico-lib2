🏠 [Main Page](../README.md) <br>
>##  ***sys_util*** - Utility Functions
💾File: **sys_util.h** <br>
📦Library: **lib2_sys** <br>
######  <br>
## **Functions:** <br>
--- 
#### 💠Function:  ***sys_dbl_str*** - Convert double to string
```c 
int8_t* sys_dbl_str(double val, int32_t prec, int8_t* buf, size_t buflen)
```
- ▶️Param:  ***val*** Value to convert <br>
- ▶️Param:  ***prec*** Precision after decimal point (0..) <br>
- ▶️Param:  ***buf*** String buffer <br>
- ▶️Param:  ***buflen*** String buffer length <br>
- ✅Return: buf parameter <br>

#### 💠Function:  ***sys_int_str*** - Convert int to string
```c 
int8_t* sys_int_str(int32_t val, int8_t* buf, size_t buflen)
```
- ▶️Param:  ***val*** Value to convert <br>
- ▶️Param:  ***buf*** String buffer <br>
- ▶️Param:  ***buflen*** String buffer length <br>
- ✅Return: buf parameter <br>

#### 💠Function:  ***sys_uid_str*** - Get system unique id in hex string form
```c 
int8_t* sys_uid_str(int8_t* buf, size_t buflen)
```
- ▶️Param:  ***buf*** String buffer <br>
- ▶️Param:  ***buflen*** String buffer length <br>
- ✅Return: buf parameter <br>

#### 💠Function:  ***sys_mac_str*** - Get mac address in hex string form
#### The mac address is get from system unique id
```c 
int8_t* sys_mac_str(int8_t* buf, size_t buflen)
```
- ▶️Param:  ***buf*** String buffer <br>
- ▶️Param:  ***buflen*** String buffer length <br>
- ✅Return: buf parameter <br>

#### 💠Function:  ***sys_swap_word*** - Swaps bytes in word
```c 
static inline uint16_t sys_swap_word(uint16_t val)
```
- ▶️Param:  ***val*** Word value to swap <br>
- ✅Return: swapped word <br>

