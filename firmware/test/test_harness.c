/* Проверка самого харнесса.
 *
 * Тест, который никогда не падает, ничего не доказывает: он одинаково
 * зелёный и когда код верен, и когда сломаны сами проверки. Поэтому этот
 * файл запускается CTest дважды - один раз должен пройти, второй обязан
 * провалиться (свойство WILL_FAIL). Если механика CHECK перестанет
 * работать, покраснеет второй запуск, и это будет видно сразу.
 */

#include "test_util.h"
#include <string.h>

int main(int argc, char **argv)
{
    const int want_fail = (argc > 1 && strcmp(argv[1], "fail") == 0);

    CHECK(1 == 1);
    CHECK_NEAR(1.0f, 1.0f, 1e-6);
    CHECK_NEAR(0.1f + 0.2f, 0.3f, 1e-6);

    if (want_fail) {
        CHECK(1 == 2);
        CHECK_NEAR(1.0f, 2.0f, 1e-6);

        /* Ненулевой код возвращаем, только если харнесс действительно
         * зафиксировал ровно два провала. Если CHECK сломается и промолчит,
         * вернётся ноль - и CTest с WILL_FAIL покажет это как ошибку. */
        printf("harness_detects_failure: зафиксировано провалов %d, ожидалось 2\n",
               test_failures);
        return (test_failures == 2) ? 1 : 0;
    }

    TEST_REPORT("harness_pass");
    return TEST_RESULT();
}
