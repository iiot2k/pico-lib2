🏠 [Main Page](../README.md) <br>
>##  ***sys_fn*** - System Functions
💾File: **sys_fn.h** <br>
📦Library: **lib2_sys** <br>
######  <br>
## **Functions:** <br>
--- 
#### 💠Function:  ***sys_init*** - Init system enviroment
```c 
void sys_init()
```

#### 💠Function:  ***sys_ledon*** - Turn led on (indicate is ok)
```c 
void sys_ledon()
```

#### 💠Function:  ***sys_logmsg*** - Print text to stdout
```c 
void sys_logmsg(const int8_t *msg)
```
- ▶️Param:  ***msg*** Message to write stdout <br>

#### 💠Function:  ***sys_logmsg2*** - Print texts to stdout
```c 
void sys_logmsg2(const int8_t *msg1, const int8_t *msg2)
```
- ▶️Param:  ***msg1*** Message 1 to write stdout <br>
- ▶️Param:  ***msg2*** Message 2 to write stdout <br>

#### 💠Function:  ***sys_outerr*** - Print error, blink led and wait until watchdog bites
```c 
void sys_outerr(const int8_t *msg)
```
- ▶️Param:  ***msg*** Message to write stdout <br>

#### 💠Function:  ***sys_loop*** - System loop (give watchdog a bone)
```c 
void sys_loop()
```

