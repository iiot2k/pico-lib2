if (NOT TARGET dev_mcp472x)
    add_library(dev_mcp472x INTERFACE)
    target_include_directories(dev_mcp472x INTERFACE ${CMAKE_CURRENT_LIST_DIR})
    target_sources(dev_mcp472x INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/dev_mcp4725.c
        ${CMAKE_CURRENT_LIST_DIR}/dev_mcp4728.c)
    target_link_libraries(dev_mcp472x INTERFACE lib2_sys)
endif()