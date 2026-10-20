#ifndef MOTOR_PARAMS_H
#define MOTOR_PARAMS_H

/* Параметры мотора.
 *
 * Один и тот же тип используется симулятором (как объект управления) и
 * прошивкой (для расчёта коэффициентов регуляторов). Держать их в разных
 * местах нельзя: разъедутся, и модель перестанет что-либо доказывать.
 */
typedef struct {
    const char *name;

    int   pole_pairs;   /* пар полюсов */
    float r_phase;      /* Ом,  фазное сопротивление */
    float l_phase;      /* Гн,  фазная индуктивность */
    float lambda_m;     /* Вб,  потокосцепление магнитов */
    float kv;           /* об/мин на вольт - справочно, из него выведено lambda_m */

    float i_max;        /* А,   предел фазного тока */
    float j_rotor;      /* кг*м^2, момент инерции ротора */
    float b_visc;       /* Н*м*с/рад, вязкое трение */
} motor_params_t;

/* Мотор разработки: этапы 2-3, с энкодером на валу. */
extern const motor_params_t MOTOR_GBM2804H_100T;

/* Целевой мотор: этап 3+, бездатчиковый, высокая электрическая частота. */
extern const motor_params_t MOTOR_DRONE_2207_1800KV;

/* Потокосцепление из kV.
 *
 *   w_mech [рад/с] = kV * V * 2*pi/60
 *   w_el            = p * w_mech
 *   V_peak          = w_el * lambda_m
 *   =>  lambda_m    = 60 / (2*pi * kV * p)
 *
 * Момент при этом: T = 1.5 * p * lambda_m * iq.
 */
float motor_lambda_from_kv(float kv, int pole_pairs);

#endif /* MOTOR_PARAMS_H */
