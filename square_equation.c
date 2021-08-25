#include "stdio.h"
#include "math.h"

int main() {
    float eps = 1e-5;
    float koeff_a = 0.0, koeff_b = 0.0, koeff_c = 0.0;
    scanf("%f%f%f", &koeff_a, &koeff_b, &koeff_c);

    if (abs(koeff_a) < eps) {  // bx + c == 0
        if (abs(koeff_b) < eps) {  // c == 0
            if (abs(koeff_c) < eps) {  // 0 == 0
                printf("x in (-inf, +inf)\n");
            } else {  // 1 == 0
                printf("x in {}\n");
            }
        } else {  // bx + c == 0
            float x = -koeff_c / koeff_b;
            printf("x in {%f}\n", x);
        }
    } else {  // ax^2 + bx + c
        float d = koeff_b * koeff_b - 4 * koeff_a * koeff_c;

        if (abs(d) < eps) {  // (x - x0)^2 == 0
            float x = -koeff_b / (2 * koeff_a);
            printf("x in {%f}\n", x);
        } else if (d < 0.0) {  // (x - x0)^2 + K == 0
            printf("x in {}\n");
        } else {  // (x - x1) * (x - x2) == 0
            float x1 = (-koeff_b + sqrt(d)) / (2 * koeff_a);
            float x2 = (-koeff_b - sqrt(d)) / (2 * koeff_a);
            printf("x in {%f, %f}\n", x1, x2);
        }
    }
}
