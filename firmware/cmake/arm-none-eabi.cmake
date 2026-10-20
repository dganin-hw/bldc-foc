# Тулчейн для кросс-сборки под STM32G431 (Cortex-M4F).
#
# На этапе 0 сюда ничего не линкуется - цель одна: проверять на каждом коммите,
# что в src/foc не заехало ничего хостового. Если код перестанет собираться
# этим компилятором, CI покраснеет до того, как появится железо.

set(CMAKE_SYSTEM_NAME      Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_C_COMPILER   arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)
set(CMAKE_AR           arm-none-eabi-ar)
set(CMAKE_OBJCOPY      arm-none-eabi-objcopy)
set(CMAKE_SIZE         arm-none-eabi-size)

# Без этого CMake при определении компилятора попытается слинковать
# полноценный исполняемый файл и упадёт - линкер-скрипта ещё нет.
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# Cortex-M4 с аппаратным FPU одинарной точности.
# -mfloat-abi=hard обязателен: иначе float пойдёт через софтверные вызовы,
# и шаг FOC не уложится в 20.8 мкс.
set(MCU_FLAGS "-mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard")

set(CMAKE_C_FLAGS_INIT   "${MCU_FLAGS} -ffunction-sections -fdata-sections")
set(CMAKE_CXX_FLAGS_INIT "${MCU_FLAGS} -ffunction-sections -fdata-sections")
set(CMAKE_ASM_FLAGS_INIT "${MCU_FLAGS}")

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
