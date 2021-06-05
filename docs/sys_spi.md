🏠 [Main Page](../README.md) <br>
>##  ***sys_spi*** - SPI Functions
💾File: **sys_spi.h** <br>
📦Library: **lib2_sys** <br>
######  <br>
### Default pin assignment for lib2 <br>
![image](images/pico-pinout.png) <br>
## **Constants:** <br>
--- 
**Default spi0 pins:** <br>
🔟Const:  ***SYS_SCK0*** sck pin <br>
🔟Const:  ***SYS_TX0*** tx pin (mosi) <br>
🔟Const:  ***SYS_RX0*** rx pin (miso) <br>
🔟Const:  ***SYS_CS0*** cs pin <br>
######  <br>
**Default spi1 pins** <br>
🔟Const:  ***SYS_SCK1*** sck pin <br>
🔟Const:  ***SYS_TX1*** tx pin (mosi) <br>
🔟Const:  ***SYS_RX1*** rx pin (miso) <br>
🔟Const:  ***SYS_CS1*** cs pin <br>
######  <br>
**Extra cs pins** <br>
🔟Const:  ***SYS_CS2*** cs pin <br>
🔟Const:  ***SYS_CS3*** cs pin <br>
######  <br>
## **Chip select pin handling:** <br>
--- 
######  <br>
#### 💠Function:  ***sys_spi_cs_init*** - Init cs pin
```c 
void sys_spi_cs_init(uint32_t cs)
```
- ▶️Param:  ***cs*** Chip select pin <br>

#### 💠Function:  ***sys_spi_cs_sel*** - Enable cs pin and lock access
```c 
void sys_spi_cs_sel(uint32_t cs)
```
- ▶️Param:  ***cs*** Chip select pin <br>

#### 💠Function:  ***sys_spi_cs_desel*** - Disable cs pin and unlock access
```c 
void sys_spi_cs_desel(uint32_t cs)
```
- ▶️Param:  ***cs*** Chip select pin <br>

## **SPI Setup:** <br>
--- 
######  <br>
#### 💠Function:  ***sys_spi_setbaudrate*** - Set spi baudrate
```c 
void sys_spi_setbaudrate(spi_inst_t *spi, uint32_t baudrate)
```
- ▶️Param:  ***spi*** Spi channel spi0 or spi1 <br>
- ▶️Param:  ***baudrate*** Baudrate in Hz <br>

#### 💠Function:  ***sys_spi_init*** - Init spi with user assignment pins
```c 
void sys_spi_init(spi_inst_t *spi, uint32_t tx, uint32_t rx, uint32_t sck, uint32_t baudrate)
```
- ▶️Param:  ***spi*** Spi channel spi0 or spi1 <br>
- ▶️Param:  ***tx*** Spi tx pin (mosi) <br>
- ▶️Param:  ***rx*** Spi rx pin (miso) <br>
- ▶️Param:  ***sck*** Spi clock pin <br>
- ▶️Param:  ***baudrate*** baudrate in Hz <br>

#### 💠Function:  ***sys_spi_init_def*** - Init default spi, init also default cs pin
```c 
void sys_spi_init_def(spi_inst_t *spi, uint32_t baudrate)
```
- ▶️Param:  ***spi*** Spi channel spi0 or spi1 <br>
- ▶️Param:  ***baudrate*** Baudrate in Hz <br>

#### 💠Function:  ***sys_spi_def_cs*** - Return default cs pin
```c 
static inline uint32_t sys_spi_def_cs(spi_inst_t *spi)
```
- ▶️Param:  ***spi*** Spi channel spi0 or spi1 <br>
- ✅Return: Default cs pin <br>

## **Byte functions:** <br>
--- 
######  <br>
#### 💠Function:  ***sys_spi_rbyte*** - Read spi byte
```c 
static inline int32_t sys_spi_rbyte(spi_inst_t *spi, uint8_t* rb)
```
- ▶️Param:  ***spi*** Spi channel spi0 or spi1 <br>
- ▶️Param:  ***rb*** Byte to read <br>
- ✅Return: Bytes read <br>
- ❌Error Return: Zero <br>

#### 💠Function:  ***sys_spi_wbyte*** - Write spi byte
```c 
static inline int32_t sys_spi_wbyte(spi_inst_t *spi, uint8_t wb)
```
- ▶️Param:  ***spi*** Spi channel spi0 or spi1 <br>
- ▶️Param:  ***wb*** Byte to write <br>
- ✅Return: Bytes written <br>
- ❌Error Return: Zero <br>

## **Word functions:** <br>
--- 
######  <br>
#### 💠Function:  ***sys_spi_rword*** - Read spi word
```c 
static inline int32_t sys_spi_rword(spi_inst_t *spi, uint16_t* rw)
```
- ▶️Param:  ***spi*** Spi channel spi0 or spi1 <br>
- ▶️Param:  ***rw*** Word to read <br>
- ✅Return: Bytes read <br>
- ❌Error Return: Zero <br>

#### 💠Function:  ***sys_spi_wword*** - Write spi word
```c 
static inline int32_t sys_spi_wword(spi_inst_t *spi, uint16_t ww)
```
- ▶️Param:  ***spi*** Spi channel spi0 or spi1 <br>
- ▶️Param:  ***ww*** Word to write <br>
- ✅Return: Bytes written <br>
- ❌Error Return: Zero <br>

## **Buffer functions:** <br>
--- 
######  <br>
#### 💠Function:  ***sys_spi_rbuf*** - Read spi buffer
```c 
static inline int32_t sys_spi_rbuf(spi_inst_t *spi, uint8_t* pBuf, uint16_t len)
```
- ▶️Param:  ***spi*** Spi channel spi0 or spi1 <br>
- ▶️Param:  ***pBuf*** Buffer to read <br>
- ▶️Param:  ***len*** Length to read <br>
- ✅Return: Bytes read <br>
- ❌Error Return: Zero <br>

#### 💠Function:  ***sys_spi_wbuf*** - Write spi buffer
```c 
static inline int32_t sys_spi_wbuf(spi_inst_t *spi, uint8_t* pBuf, uint16_t len)
```
- ▶️Param:  ***spi*** Spi channel spi0 or spi1 <br>
- ▶️Param:  ***pBuf*** Buffer to write <br>
- ▶️Param:  ***len*** Length to write <br>
- ✅Return: Bytes written <br>
- ❌Error Return: Zero <br>

