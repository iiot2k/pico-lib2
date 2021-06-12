# **Lib2** - C/C++ Library for Raspberry Pi Pico
[![platform](https://img.shields.io/badge/Raspberry--Pico-Pico)](https://www.raspberrypi.org/products/raspberry-pi-pico/)
[![Donate](https://img.shields.io/badge/Donate-PayPal-green.svg)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=ZDRCZBQFWV3A6)

## Description:
Lib2 library implements wrapper functions and device driver for Raspberry Pi Pico.<br>
With lib2 it is more easy to write C/C++applications for Pico.<br>

See [Getting Started with the Raspberry Pi Pico](https://rptl.io/pico-get-started)
for information on getting up and running.

## Using:
⚠️Set environment variables ***PICO_SDK_PATH*** and ***PICO_LIB2_PATH***.<br>
Add the file ***pico_lib2_import.cmake*** in folder ***external***<br>
to your application ***CMakeLists.txt***.<br>

Example ***CMakeLists.txt*** file entry:
```cmake
cmake_minimum_required(VERSION 3.12)

# Pull in PICO SDK (must be before project)
include(pico_sdk_import.cmake)

# We also need LIB2
include(pico_lib2_import.cmake)

# Your project
project(myproj C CXX)

# Used compiler 
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

#Your sourfiles
add_executable(myproj main.c)

# Add used libraries
target_link_libraries(myproj
    lib2_sys
    dev_ads1x15
)

# Setup stdio 
pico_enable_stdio_usb(myproj 0)
pico_enable_stdio_uart(myproj 1)

# Create map/bin/hex file etc.
pico_add_extra_outputs(myproj)

```
## Examples:
https://github.com/iiot2k/pico-lib2-examples are examples for using Lib2.

[CHANGELOG](CHANGELOG.md)<br>

## Functions and Device Driver:

### System:
[GPIO Functions](docs/sys_gpio.md)<br>
[I2C Functions](docs/sys_i2c.md)<br>
[SPI Functions](docs/sys_spi.md)<br>
[ADC Functions](docs/sys_adc.md)<br>
[Time Functions](docs/sys_time.md)<br>
[System Functions](docs/sys_fn.md)<br>
[Utility Functions](docs/sys_util.md)<br>

### Device Driver:
[HD44780 LCD Driver with PCF8574](docs/dev_hd44780.md)<br>
[ADS1115 Four Channel 16-bit ADC](docs/dev_ads1115.md)<br>
[ADS1015 Four Channel 12-bit ADC](docs/dev_ads1015.md)<br>
[MCP4728 Four Channel 12-bit DAC](docs/dev_mcp4728.md)<br>
[MCP4725 One Channel 12-bit DAC](docs/dev_mcp4725.md)<br>
[DS3231 Accurate Real-Time-Clock](docs/dev_ds3231.md)<br>
