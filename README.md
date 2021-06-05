# **Lib2** - Additional Library for Raspberry Pi Pico SDK
[![platform](https://img.shields.io/badge/Raspberry--Pico-Pico)](https://www.raspberrypi.org/products/raspberry-pi-pico/)
[![Donate](https://img.shields.io/badge/Donate-PayPal-green.svg)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=ZDRCZBQFWV3A6)

## Description:
Lib2 implements additional wrapper functions and device driver based on<br>
Raspberry Pi Pico SDK.<br>
With lib2 it is more easy to write applications for Pico.<br>

See [Getting Started with the Raspberry Pi Pico](https://rptl.io/pico-get-started)
for information on getting up and running.

## Using:
⚠️Set environment variables ***PICO_SDK_PATH*** and ***PICO_LIB2_PATH***.<br>
Lib2 is stuctured same as Pico SDK.<br>
Add the file ***pico_lib2_import.cmake*** in folder ***external***<br>
to your application and add to your ***CMakeLists.txt***.<br>

Example ***CMakeLists.txt*** file entry:
```cmake
...
# Pull in PICO SDK (must be before project)
include(pico_sdk_import.cmake)

# We also need LIB2
include(pico_lib2_import.cmake)
...
```
## Examples:
On https://github.com/iiot2k/pico-lib2-examples are examples.

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
