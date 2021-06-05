🏠 [Main Page](../README.md) <br>
>##  ***sys_gpio*** - GPIO Functions
💾File: **sys_gpio.h** <br>
📦Library: **lib2_sys** <br>
######  <br>
## **Functions:** <br>
--- 
#### 💠Function:  ***sys_gpio_output*** - Init gpio as output
```c 
static inline void sys_gpio_output(uint32_t pin, bool init)
```
- ▶️Param:  ***pin*** GP pin number <br>
- ▶️Param:  ***init*** Init output (true or false) <br>

#### 💠Function:  ***sys_gpio_set*** - Set gpio output
```c 
static inline void sys_gpio_set(uint32_t pin, bool value)
```
- ▶️Param:  ***pin*** GP pin number <br>
- ▶️Param:  ***value*** Set value (true or false) <br>

#### 💠Function:  ***sys_gpio_input*** - Init gpio as input
```c 
static inline void sys_gpio_input(uint32_t pin)
```
- ▶️Param:  ***pin*** GP pin number <br>

#### 💠Function:  ***sys_gpio_setpullup*** - Set gpio input pullup resistor
```c 
static inline void sys_gpio_setpullup(uint32_t pin)
```
- ▶️Param:  ***pin*** GP pin number <br>

#### 💠Function:  ***sys_gpio_setpulldown*** - Set input pulldown resistor
```c 
static inline void sys_gpio_setpulldown(uint32_t pin)
```
- ▶️Param:  ***pin*** GP pin number <br>

#### 💠Function:  ***sys_gpio_pullup*** - Init gpio as input with pullup resistor
```c 
static inline void sys_gpio_pullup(uint32_t pin)
```
- ▶️Param:  ***pin*** GP pin number <br>

#### 💠Function:  ***sys_gpio_pulldown*** - Init gpio as input with pulldown resistor
```c 
static inline void sys_gpio_pulldown(uint32_t pin)
```
- ▶️Param:  ***pin*** GP pin number <br>

#### 💠Function:  ***sys_gpio_get*** - Get input gpio state
```c 
static inline bool sys_gpio_get(uint32_t pin)
```
- ▶️Param:  ***pin*** GP pin number <br>
- ✅Return: true if pullup input connected to ground, else connected to vcc <br>

