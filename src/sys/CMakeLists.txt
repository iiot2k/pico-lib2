if (NOT TARGET lib2_sys)
    add_library(lib2_sys INTERFACE)

    target_include_directories(lib2_sys INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)
    
    target_sources(lib2_sys INTERFACE 
        ${CMAKE_CURRENT_LIST_DIR}/sys_adc.c
        ${CMAKE_CURRENT_LIST_DIR}/sys_fn.c
        ${CMAKE_CURRENT_LIST_DIR}/sys_util.c
        ${CMAKE_CURRENT_LIST_DIR}/sys_i2c.c
        ${CMAKE_CURRENT_LIST_DIR}/sys_spi.c
        ${CMAKE_CURRENT_LIST_DIR}/sys_time.c
    )

    target_link_libraries(lib2_sys INTERFACE
        pico_stdlib
        pico_unique_id
        hardware_rtc
        hardware_adc
        hardware_spi
        hardware_i2c
        hardware_gpio
    )
endif()