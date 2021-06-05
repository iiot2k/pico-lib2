cmake_minimum_required(VERSION 3.13)

if (NOT TARGET _pico_lib2_inclusion_marker)
    add_library(_pico_lib2_inclusion_marker INTERFACE)

    include(pico_sdk_import.cmake)

    project(pico_lib2 C CXX ASM)

    set(CMAKE_C_STANDARD 11)
    set(CMAKE_CXX_STANDARD 17)

    pico_sdk_init()

    pico_is_top_level_project(PICO_LIB2_TOP_LEVEL_PROJECT)

    add_library(pico_lib2_included INTERFACE)

    target_compile_definitions(pico_lib2_included INTERFACE -DPICO_LIB2=1)

    pico_add_platform_library(pico_lib2_included)

    if (NOT PICO_LIB2_PATH)
        set(PICO_LIB2_PATH ${CMAKE_CURRENT_LIST_DIR})
    endif()

    set(PICO_LIB2_PATH "${PICO_LIB2_PATH}" CACHE PATH "Path to Pico Lib2")
   
    add_subdirectory(src)
endif()