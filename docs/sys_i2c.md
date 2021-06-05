🏠 [Main Page](../README.md) <br>
>##  ***sys_i2c*** - I2C Functions
💾File: **sys_i2c.h** <br>
📦Library: **lib2_sys** <br>
######  <br>
### Default pin assignment for lib2 <br>
![image](images/pico-pinout.png) <br>
## **Constants:** <br>
--- 
**I2C timeout per char** <br>
🔟Const:  ***I2C_TIMEOUT_CHAR*** timeout (500us) <br>
######  <br>
**Default i2c0 pins** <br>
🔟Const:  ***SYS_SDA0*** sda pin <br>
🔟Const:  ***SYS_SCL0*** scl pin <br>
######  <br>
**Default i2c1 pins** <br>
🔟Const:  ***SYS_SDA1*** sda pin <br>
🔟Const:  ***SYS_SCL1*** scl pin <br>
######  <br>
## **I2C Setup:** <br>
--- 
######  <br>
#### 💠Function:  ***sys_i2c_setbaudrate*** - Set i2c baudrate
```c 
void sys_i2c_setbaudrate(i2c_inst_t* i2c, uint32_t baudrate)
```
- ▶️Param:  ***i2c*** I2C channel i2c0 or i2c1 <br>
- ▶️Param:  ***baudrate*** Baudrate in Hz <br>

#### 💠Function:  ***sys_i2c_init*** - Init i2c with user assignment pins
```c 
void sys_i2c_init(i2c_inst_t* i2c, uint32_t sda, uint32_t scl, uint32_t baudrate, bool pullup)
```
- ▶️Param:  ***i2c*** I2C channel i2c0 or i2c1 <br>
- ▶️Param:  ***sda*** Pin number for sda <br>
- ▶️Param:  ***scl*** Pin number for scl <br>
- ▶️Param:  ***baudrate*** Baudrate in Hz <br>
- ▶️Param:  ***pullup*** If true connect internal pullup resistor <br>

#### 💠Function:  ***sys_i2c_init_def*** - Init default i2c
```c 
void sys_i2c_init_def(i2c_inst_t* i2c, uint32_t baudrate, bool pullup)
```
- ▶️Param:  ***i2c*** I2C channel i2c0 or i2c1 <br>
- ▶️Param:  ***baudrate*** Baudrate in Hz <br>
- ▶️Param:  ***pullup*** If true connect internal pullup resistor <br>

## **Byte functions:** <br>
--- 
######  <br>
#### 💠Function:  ***sys_i2c_rbyte*** - Read i2c byte
```c 
static inline int32_t sys_i2c_rbyte(i2c_inst_t* i2c, uint8_t addr, uint8_t* rb)
```
- ▶️Param:  ***i2c*** I2C channel i2c0 or i2c1 <br>
- ▶️Param:  ***addr*** I2C address <br>
- ▶️Param:  ***rb*** Byte to read <br>
- ✅Return: Bytes read <br>
- ❌Error Return: PICO_ERROR_GENERIC On error <br>
- ❌Error Return: PICO_ERROR_TIMEOUT On timeout <br>

#### 💠Function:  ***sys_i2c_wbyte*** - Write i2c byte
```c 
static inline int32_t sys_i2c_wbyte(i2c_inst_t* i2c, uint8_t addr, uint8_t wb)
```
- ▶️Param:  ***i2c*** I2C channel i2c0 or i2c1 <br>
- ▶️Param:  ***addr*** I2C address <br>
- ▶️Param:  ***wb*** Byte to write <br>
- ✅Return: Bytes written <br>
- ❌Error Return: PICO_ERROR_GENERIC On error <br>
- ❌Error Return: PICO_ERROR_TIMEOUT On timeout <br>

#### 💠Function:  ***sys_i2c_rbyte_reg*** - Read i2c byte register
```c 
int32_t sys_i2c_rbyte_reg(i2c_inst_t* i2c, uint8_t addr, uint8_t reg, uint8_t* rb)
```
- ▶️Param:  ***i2c*** I2C channel i2c0 or i2c1 <br>
- ▶️Param:  ***addr*** I2C address <br>
- ▶️Param:  ***reg*** Register address <br>
- ▶️Param:  ***rb*** Byte to read <br>
- ✅Return: Bytes read <br>
- ❌Error Return: PICO_ERROR_GENERIC On error <br>
- ❌Error Return: PICO_ERROR_TIMEOUT On timeout <br>

#### 💠Function:  ***sys_i2c_wbyte_reg*** - Write i2c byte register
```c 
int32_t sys_i2c_wbyte_reg(i2c_inst_t* i2c, uint8_t addr, uint8_t reg, uint8_t wb)
```
- ▶️Param:  ***i2c*** I2C channel i2c0 or i2c1 <br>
- ▶️Param:  ***addr*** I2C address <br>
- ▶️Param:  ***reg*** Register address <br>
- ▶️Param:  ***wb*** Byte to write <br>
- ✅Return: Bytes written <br>
- ❌Error Return: PICO_ERROR_GENERIC On error <br>
- ❌Error Return: PICO_ERROR_TIMEOUT On timeout <br>

## **Word functions:** <br>
--- 
######  <br>
#### 💠Function:  ***sys_i2c_rword*** - Read i2c word
```c 
static inline int32_t sys_i2c_rword(i2c_inst_t* i2c, uint8_t addr, uint16_t* rw)
```
- ▶️Param:  ***i2c*** I2C channel i2c0 or i2c1 <br>
- ▶️Param:  ***addr*** I2C address <br>
- ▶️Param:  ***rw*** Word to read <br>
- ✅Return: Bytes read <br>
- ❌Error Return: PICO_ERROR_GENERIC On error <br>
- ❌Error Return: PICO_ERROR_TIMEOUT On timeout <br>

#### 💠Function:  ***sys_i2c_wword*** - Write i2c word
```c 
static inline int32_t sys_i2c_wword(i2c_inst_t* i2c, uint8_t addr, uint16_t ww)
```
- ▶️Param:  ***i2c*** I2C channel i2c0 or i2c1 <br>
- ▶️Param:  ***addr*** I2C address <br>
- ▶️Param:  ***ww*** Word to write <br>
- ✅Return: Bytes written <br>
- ❌Error Return: PICO_ERROR_GENERIC On error <br>
- ❌Error Return: PICO_ERROR_TIMEOUT On timeout <br>

#### 💠Function:  ***sys_i2c_rword_reg*** - Read i2c word register
```c 
int32_t sys_i2c_rword_reg(i2c_inst_t* i2c, uint8_t addr, uint8_t reg, uint16_t* rw)
```
- ▶️Param:  ***i2c*** I2C channel i2c0 or i2c1 <br>
- ▶️Param:  ***addr*** I2C address <br>
- ▶️Param:  ***reg*** Register address <br>
- ▶️Param:  ***rw*** Word to read <br>
- ✅Return: Bytes read <br>
- ❌Error Return: PICO_ERROR_GENERIC On error <br>
- ❌Error Return: PICO_ERROR_TIMEOUT On timeout <br>

#### 💠Function:  ***sys_i2c_wword_reg*** - Write i2c word register
```c 
int32_t sys_i2c_wword_reg(i2c_inst_t* i2c, uint8_t addr, uint8_t reg, uint16_t ww)
```
- ▶️Param:  ***i2c*** I2C channel i2c0 or i2c1 <br>
- ▶️Param:  ***addr*** I2C address <br>
- ▶️Param:  ***reg*** Register address <br>
- ▶️Param:  ***ww*** Word to write <br>
- ✅Return: Bytes written <br>
- ❌Error Return: PICO_ERROR_GENERIC On error <br>
- ❌Error Return: PICO_ERROR_TIMEOUT On timeout <br>

## **Buffer functions:** <br>
--- 
######  <br>
#### 💠Function:  ***sys_i2c_rbuf*** - Read i2c buffer
```c 
static inline int32_t sys_i2c_rbuf(i2c_inst_t* i2c, uint8_t addr, uint8_t* pBuf, uint32_t len)
```
- ▶️Param:  ***i2c*** I2C channel i2c0 or i2c1 <br>
- ▶️Param:  ***addr*** I2C address <br>
- ▶️Param:  ***pBuf*** Buffer to read <br>
- ▶️Param:  ***len*** Length to read <br>
- ✅Return: Bytes read <br>
- ❌Error Return: PICO_ERROR_GENERIC On error <br>
- ❌Error Return: PICO_ERROR_TIMEOUT On timeout <br>

#### 💠Function:  ***sys_i2c_wbuf*** - Write i2c buffer
```c 
static inline int32_t sys_i2c_wbuf(i2c_inst_t* i2c, uint8_t addr, const uint8_t* pBuf, uint32_t len)
```
- ▶️Param:  ***i2c*** I2C channel i2c0 or i2c1 <br>
- ▶️Param:  ***addr*** I2C address <br>
- ▶️Param:  ***pBuf*** Buffer to write <br>
- ▶️Param:  ***len*** Length to write <br>
- ✅Return: Bytes written <br>
- ❌Error Return: PICO_ERROR_GENERIC On error <br>
- ❌Error Return: PICO_ERROR_TIMEOUT On timeout <br>

#### 💠Function:  ***sys_i2c_rbuf_reg*** - Read i2c buffer register
```c 
int32_t sys_i2c_rbuf_reg(i2c_inst_t* i2c, uint8_t addr, uint8_t reg, uint8_t* pBuf, uint32_t len)
```
- ▶️Param:  ***i2c*** I2C channel i2c0 or i2c1 <br>
- ▶️Param:  ***addr*** I2C address <br>
- ▶️Param:  ***reg*** Register address <br>
- ▶️Param:  ***pBuf*** Buffer to read <br>
- ▶️Param:  ***len*** Length to read <br>
- ✅Return: Bytes read <br>
- ❌Error Return: PICO_ERROR_GENERIC On error <br>
- ❌Error Return: PICO_ERROR_TIMEOUT On timeout <br>

#### 💠Function:  ***sys_i2c_wbuf_reg*** - Write i2c buffer register
```c 
int32_t sys_i2c_wbuf_reg(i2c_inst_t* i2c, uint8_t addr, uint8_t reg, uint8_t* pBuf, uint32_t len)
```
- ▶️Param:  ***i2c*** I2C channel i2c0 or i2c1 <br>
- ▶️Param:  ***addr*** I2C address <br>
- ▶️Param:  ***reg*** Register address <br>
- ▶️Param:  ***pBuf*** Buffer to read <br>
- ▶️Param:  ***len*** Length to read <br>
- ✅Return: Bytes written <br>
- ❌Error Return: PICO_ERROR_GENERIC On error <br>
- ❌Error Return: PICO_ERROR_TIMEOUT On timeout <br>

