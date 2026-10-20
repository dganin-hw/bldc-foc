#ifndef TEST_UTIL_H
#define TEST_UTIL_H

/* Микро-харнесс для тестов.
 *
 * Внешнего фреймворка намеренно нет: каждый тест - отдельный исполняемый
 * файл, запускается через CTest, ненулевой код возврата означает провал.
 * Ноль зависимостей - значит CI собирается из коробки и не ломается от
 * чужих обновлений.
 *
 * Каждый тест - своя единица трансляции, поэтому static-счётчик здесь
 * корректен: у каждого исполняемого файла он свой.
 */

#include <math.h>
#include <stdio.h>

static int test_failures = 0;

#define CHECK(cond)                                                        \
    do {                                                                   \
        if (!(cond)) {                                                     \
            printf("FAIL %s:%d  %s\n", __FILE__, __LINE__, #cond);         \
            test_failures++;                                               \
        }                                                                  \
    } while (0)

#define CHECK_NEAR(actual, expected, tol)                                  \
    do {                                                                   \
        double a_ = (double)(actual);                                      \
        double e_ = (double)(expected);                                    \
        double t_ = (double)(tol);                                         \
        if (!(fabs(a_ - e_) <= t_)) {                                      \
            printf("FAIL %s:%d  %s = %g, ожидалось %g +/- %g\n",           \
                   __FILE__, __LINE__, #actual, a_, e_, t_);               \
            test_failures++;                                               \
        }                                                                  \
    } while (0)

#define TEST_REPORT(name)                                                  \
    do {                                                                   \
        if (test_failures == 0) {                                          \
            printf("OK   %s\n", (name));                                   \
        } else {                                                           \
            printf("FAIL %s: провалов %d\n", (name), test_failures);       \
        }                                                                  \
    } while (0)

#define TEST_RESULT() (test_failures == 0 ? 0 : 1)

#endif /* TEST_UTIL_H */
