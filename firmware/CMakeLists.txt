cmake_minimum_required(VERSION 3.20)
project(bldc_foc C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
endif()

# Ядро FOC собирается всегда: и под хост (для тестов и симулятора),
# и под ARM. Это один и тот же код, в этом весь смысл этапа 0.
add_subdirectory(src/foc)

if(CMAKE_CROSSCOMPILING)
    message(STATUS "Кросс-сборка под ARM: собирается только libfoc")
else()
    message(STATUS "Хостовая сборка: libfoc + тесты")
    enable_testing()
    add_subdirectory(test)
endif()
