if (NOT TARGET dev_ds3231)
    add_library(dev_ds3231 INTERFACE)
    target_include_directories(dev_ds3231 INTERFACE ${CMAKE_CURRENT_LIST_DIR})
    target_sources(dev_ds3231 INTERFACE 
        ${CMAKE_CURRENT_LIST_DIR}/dev_ds3231.c)
    target_link_libraries(dev_ds3231 INTERFACE lib2_sys)
endif()