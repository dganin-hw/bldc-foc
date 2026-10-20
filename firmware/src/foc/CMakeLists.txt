add_library(foc STATIC
    foc_util.c
    motor_params.c
)

target_include_directories(foc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# -Werror только здесь: это код, который поедет в прошивку.
# -Wdouble-promotion критичен - ловит неявное превращение float в double,
# которое на Cortex-M4F уходит в софтверную библиотеку и стоит сотни тактов.
target_compile_options(foc PRIVATE
    -Wall
    -Wextra
    -Werror
    -Wdouble-promotion
    -Wshadow
)
