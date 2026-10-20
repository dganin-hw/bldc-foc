#include "test_util.h"
#include "foc_util.h"
#include "foc_config.h"
#include "motor_params.h"

static void test_wrap_pi(void)
{
    /* Внутри диапазона ничего не меняется. */
    CHECK_NEAR(foc_wrap_pi(0.0f),   0.0f,   1e-6);
    CHECK_NEAR(foc_wrap_pi(1.0f),   1.0f,   1e-6);
    CHECK_NEAR(foc_wrap_pi(-1.0f), -1.0f,   1e-6);

    /* Границы: -pi принадлежит диапазону, +pi нет. */
    CHECK_NEAR(foc_wrap_pi(-FOC_PI), -FOC_PI, 1e-5);
    CHECK_NEAR(foc_wrap_pi(FOC_PI),  -FOC_PI, 1e-5);

    /* Выход за границу на один оборот в обе стороны. */
    CHECK_NEAR(foc_wrap_pi(FOC_PI + 0.5f),  -FOC_PI + 0.5f, 1e-5);
    CHECK_NEAR(foc_wrap_pi(-FOC_PI - 0.5f),  FOC_PI - 0.5f, 1e-5);

    /* Результат всегда в [-pi, pi) - в пределах предусловия |angle| < 3*pi. */
    for (int i = -300; i <= 300; i++) {
        float a = (float)i * 0.03f;
        float w = foc_wrap_pi(a);
        CHECK(w >= -FOC_PI - 1e-5f);
        CHECK(w < FOC_PI + 1e-5f);
    }
}

static void test_clampf(void)
{
    CHECK_NEAR(foc_clampf(0.5f, 0.0f, 1.0f), 0.5f, 1e-6);
    CHECK_NEAR(foc_clampf(-1.0f, 0.0f, 1.0f), 0.0f, 1e-6);
    CHECK_NEAR(foc_clampf(2.0f, 0.0f, 1.0f), 1.0f, 1e-6);

    /* Границы включительно. */
    CHECK_NEAR(foc_clampf(0.0f, 0.0f, 1.0f), 0.0f, 1e-6);
    CHECK_NEAR(foc_clampf(1.0f, 0.0f, 1.0f), 1.0f, 1e-6);
}

static void test_config_consistency(void)
{
    /* Частота ШИМ должна следовать из ARR, а не быть вписана отдельно:
     * при центрированном счёте f = clk / (2 * ARR). Если кто-то поменяет
     * одно и забудет другое, тест поймает это раньше осциллографа. */
    float f_from_arr = FOC_TIM_CLK_HZ / (2.0f * (float)FOC_TIM_ARR);
    CHECK_NEAR(f_from_arr, FOC_PWM_FREQ_HZ, 100.0);

    CHECK_NEAR(FOC_TS, 1.0f / FOC_PWM_FREQ_HZ, 1e-9);
    CHECK(FOC_DUTY_MIN > 0.0f);
    CHECK(FOC_DUTY_MAX < 1.0f);
    CHECK(FOC_DUTY_MIN < FOC_DUTY_MAX);
}

static void test_motor_params(void)
{
    /* lambda_m в таблицах должно соответствовать заявленному kV. */
    CHECK_NEAR(MOTOR_DRONE_2207_1800KV.lambda_m,
               motor_lambda_from_kv(MOTOR_DRONE_2207_1800KV.kv,
                                    MOTOR_DRONE_2207_1800KV.pole_pairs),
               1e-6);

    CHECK_NEAR(MOTOR_GBM2804H_100T.lambda_m,
               motor_lambda_from_kv(MOTOR_GBM2804H_100T.kv,
                                    MOTOR_GBM2804H_100T.pole_pairs),
               1e-5);

    /* Электрическая частота дрон-мотора на 4S - та самая, ради которой
     * выбрана ШИМ 48 кГц. Ожидаем порядка 3.5 кГц. */
    float v_bus     = 16.8f;
    float rpm       = MOTOR_DRONE_2207_1800KV.kv * v_bus;
    float f_el      = (rpm / 60.0f) * (float)MOTOR_DRONE_2207_1800KV.pole_pairs;
    CHECK(f_el > 3000.0f);
    CHECK(f_el < 4000.0f);

    /* И на неё должно приходиться хотя бы десяток периодов ШИМ. */
    CHECK(FOC_PWM_FREQ_HZ / f_el > 10.0f);
}

int main(void)
{
    test_wrap_pi();
    test_clampf();
    test_config_consistency();
    test_motor_params();

    TEST_REPORT("foc_util");
    return TEST_RESULT();
}
