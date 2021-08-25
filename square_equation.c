/**
 * @defgroup   SQUARE_EQUATION square equation
 *
 * @brief      This file implements square equation.
 *
 * @author     Denba
 * @date       2021
 */

#include "square_equation.h"

/**
 * @brief      function docstring
 *
 * @return     The p solution.
 */
PSolution Solution_New() {
    return calloc(1, sizeof(struct Solution)); 
}

void Solution_Free(PSolution sol) {
    free(sol); 
}


void SolveLinear(PSolution sol, PCoeffs coeffs) {
    if (abs(coeffs) < eps) {
        if (abs(coeffs->data[0]) < eps) {
            sol->cnt = INF_SOL_CNT;
        } else {
            sol->cnt = 0;
        }
    } else {
        sol->cnt = 1;
        sol->roots[0] = -coeffs->data[0] / coeffs->data[1];
    }
}

void SolveQuadratic(PSolution sol, PCoeffs coeffs) {
    if (abs(coeffs->data[2]) < eps) {
        SolveLinear(sol, coeffs);
    } else {
        double a = coeffs->data[2];
        double b = coeffs->data[1];
        double c = coeffs->data[0];
        double D = b * b - 4 * a * c;

        if (abs(D) < eps) {
            sol->cnt = 1;
            sol->roots[0] = -b / (2 * a);
        } else if (D < 0.0) {
            sol->cnt = 0;
        } else {
            sol->cnt = 2;
            sol->roots[0] = (-b - sqrt(D)) / (2 * a);
            sol->roots[1] = (-b + sqrt(D)) / (2 * a);
        }
    }
}

void Solution_Print(PSolution sol) {
    switch (sol->cnt) {
        case INF_SOL_CNT:
            printf("x in (-inf, +inf)\n");
            break;
        case 0:
            printf("x in {}\n");
            break;
        case 1:
            printf("x in {%f}\n", sol->roots[0]);
            break;
        case 2:
            printf("x in {%f, %f}\n", sol->roots[0], sol->roots[1]);
            break;
    }
}


void ReadCoeffs(PCoeffs coeffs) {
    int res;
    do {
        printf("Enter three equation coefficients: \n");
        res = scanf("%lf %lf %lf", &coeffs->data[2], &coeffs->data[1], &coeffs->data[0]);
        fflush(stdin);
    } while (res != 3);
}

int main() {
    struct Solution sol;
    struct Coeffs coeffs;

    ReadCoeffs(&coeffs);
    SolveQuadratic(&sol, &coeffs);
    Solution_Print(&sol);

    return 0;
}
