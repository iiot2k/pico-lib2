if (NOT TARGET dev_ads1x15)
    add_library(dev_ads1x15 INTERFACE)
    target_include_directories(dev_ads1x15 INTERFACE ${CMAKE_CURRENT_LIST_DIR})
    target_sources(dev_ads1x15 INTERFACE 
        ${CMAKE_CURRENT_LIST_DIR}/dev_ads1115.c
        ${CMAKE_CURRENT_LIST_DIR}/dev_ads1015.c
        )
    target_link_libraries(dev_ads1x15 INTERFACE lib2_sys)
endif()