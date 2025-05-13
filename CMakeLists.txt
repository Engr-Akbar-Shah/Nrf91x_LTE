cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(DEV_HUB_Nrf91_LTE)

# Add the Main source files
target_sources(app
    PRIVATE
    src/main.c
)

# Add the component LTE
target_sources(app PRIVATE
    components/lte/lte.c)
target_include_directories(app
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/components/lte
)
