#ifndef FOC_UTIL_H
#define FOC_UTIL_H

/* Константы с суффиксом f обязательны: без него компилятор считает литерал
 * double, и любое выражение с ним тянет за собой софтверную арифметику
 * двойной точности. На Cortex-M4F это сотни тактов вместо единиц. */
#define FOC_PI        3.14159265358979f
#define FOC_2PI       6.28318530717959f
#define FOC_SQRT3     1.73205080756888f
#define FOC_1_SQRT3   0.57735026918963f

/* Приведение угла к диапазону [-pi, pi). */
float foc_wrap_pi(float angle);

/* Ограничение значения снизу и сверху. */
float foc_clampf(float x, float lo, float hi);

#endif /* FOC_UTIL_H */
