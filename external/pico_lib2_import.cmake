# This is a copy of <PICO_LIB2_PATH>/external/pico_lib2_import.cmake

# This can be dropped into an external project to help locate pico-lib2
# It should be include()ed prior to project()

if (DEFINED ENV{PICO_LIB2_PATH} AND (NOT PICO_LIB2_PATH))
    set(PICO_LIB2_PATH $ENV{PICO_LIB2_PATH})
    message("Using PICO_LIB2_PATH from environment ('${PICO_LIB2_PATH}')")
endif ()

if (DEFINED ENV{PICO_LIB2_FETCH_FROM_GIT} AND (NOT PICO_LIB2_FETCH_FROM_GIT))
    set(PICO_LIB2_FETCH_FROM_GIT $ENV{PICO_LIB2_FETCH_FROM_GIT})
    message("Using PICO_LIB2_FETCH_FROM_GIT from environment ('${PICO_LIB2_FETCH_FROM_GIT}')")
endif ()

if (DEFINED ENV{PICO_LIB2_FETCH_FROM_GIT_PATH} AND (NOT PICO_LIB2_FETCH_FROM_GIT_PATH))
    set(PICO_LIB2_FETCH_FROM_GIT_PATH $ENV{PICO_LIB2_FETCH_FROM_GIT_PATH})
    message("Using PICO_LIB2_FETCH_FROM_GIT_PATH from environment ('${PICO_LIB2_FETCH_FROM_GIT_PATH}')")
endif ()

if (NOT PICO_LIB2_PATH)
    if (PICO_LIB2_FETCH_FROM_GIT)
        include(FetchContent)
        set(FETCHCONTENT_BASE_DIR_SAVE ${FETCHCONTENT_BASE_DIR})
        if (PICO_LIB2_FETCH_FROM_GIT_PATH)
            get_filename_component(FETCHCONTENT_BASE_DIR "${PICO_LIB2_FETCH_FROM_GIT_PATH}" REALPATH BASE_DIR "${CMAKE_SOURCE_DIR}")
        endif ()
        FetchContent_Declare(
                PICO_LIB2
                GIT_REPOSITORY https://github.com/iiot2k/pico-lib2
                GIT_TAG master
        )
        if (NOT PICO_LIB2)
            message("Downloading PICO LIB2")
            FetchContent_Populate(PICO_LIB2)
            set(PICO_LIB2_PATH ${PICO_LIB2_SOURCE_DIR})
        endif ()
        set(FETCHCONTENT_BASE_DIR ${FETCHCONTENT_BASE_DIR_SAVE})
    else ()
        if (PICO_SDK_PATH AND EXISTS "${PICO_SDK_PATH}/../pico-lib2")
            set(PICO_LIB2_PATH ${PICO_SDK_PATH}/../pico-lib2)
            message("Defaulting PICO_LIB2_PATH as sibling of PICO_SDK_PATH: ${PICO_LIB2_PATH}")
        else()
            message(FATAL_ERROR
                    "PICO LIB2 location was not specified. Please set PICO_LIB2_PATH or set PICO_LIB2_FETCH_FROM_GIT to on to fetch from git."
                    )
        endif()
    endif ()
endif ()

set(PICO_LIB2_PATH "${PICO_LIB2_PATH}" CACHE PATH "Path to the PICO LIB2")
set(PICO_LIB2_FETCH_FROM_GIT "${PICO_LIB2_FETCH_FROM_GIT}" CACHE BOOL "Set to ON to fetch copy of PICO LIB2 from git if not otherwise locatable")
set(PICO_LIB2_FETCH_FROM_GIT_PATH "${PICO_LIB2_FETCH_FROM_GIT_PATH}" CACHE FILEPATH "location to download LIB2")

get_filename_component(PICO_LIB2_PATH "${PICO_LIB2_PATH}" REALPATH BASE_DIR "${CMAKE_BINARY_DIR}")
if (NOT EXISTS ${PICO_LIB2_PATH})
    message(FATAL_ERROR "Directory '${PICO_LIB2_PATH}' not found")
endif ()

set(PICO_LIB2_PATH ${PICO_LIB2_PATH} CACHE PATH "Path to the PICO LIB2" FORCE)

add_subdirectory(${PICO_LIB2_PATH} pico_lib2)