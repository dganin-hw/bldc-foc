function(add_foc_test name)
    add_executable(${name} ${name}.c)
    target_link_libraries(${name} PRIVATE foc)
    target_compile_options(${name} PRIVATE -Wall -Wextra)
    if(UNIX)
        target_link_libraries(${name} PRIVATE m)
    endif()
endfunction()

# Харнесс проверяет сам себя: первый запуск обязан пройти,
# второй обязан провалиться.
add_foc_test(test_harness)
add_test(NAME harness_pass             COMMAND test_harness pass)
add_test(NAME harness_detects_failure  COMMAND test_harness fail)
set_tests_properties(harness_detects_failure PROPERTIES WILL_FAIL TRUE)

add_foc_test(test_foc_util)
add_test(NAME foc_util COMMAND test_foc_util)
