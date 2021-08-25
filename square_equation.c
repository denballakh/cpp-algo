/**
 * @file square_equation.c
 * 
 * @author Баллах Денис
 */
 #include "square_equation.h"

PSolution Solution_New() {
    return calloc(1, sizeof(struct Solution)); 
}

void Solution_Free(PSolution sol) {
    free(sol); 
}

void SolveLinear(PSolution sol, PCoeffs coeffs) {
    if (abs(coeffs->data[1]) < eps) {
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

int RunTests() {
    {
        struct Coeffs coeffs;
        coeffs.data[2] = 0.0;
        coeffs.data[1] = 0.0;
        coeffs.data[0] = 0.0;

        struct Solution sol;
        SolveQuadratic(&sol, &coeffs);

        if (sol.cnt != INF_SOL_CNT) return 1;
    }
    {
        struct Coeffs coeffs;
        coeffs.data[2] = 1.0;
        coeffs.data[1] = 2.0;
        coeffs.data[0] = 1.0;

        struct Solution sol;
        SolveQuadratic(&sol, &coeffs);

        if (sol.cnt != 1) return 1;
        if ((sol.roots[0] - (-1.0)) > eps) return 1;
    }
    {
        struct Coeffs coeffs;
        coeffs.data[2] = 1.0;
        coeffs.data[1] = 2.0;
        coeffs.data[0] = 3.0;

        struct Solution sol;
        SolveQuadratic(&sol, &coeffs);

        if (sol.cnt != 0) return 1;
    }
    {
        struct Coeffs coeffs;
        coeffs.data[2] = 1.0;
        coeffs.data[1] = -5.0;
        coeffs.data[0] = 6.0;

        struct Solution sol;
        SolveQuadratic(&sol, &coeffs);

        if (sol.cnt != 2) return 1;
        double x1 = sol.roots[0];
        double x2 = sol.roots[1];
        if ((abs(x1 - 2.0) + abs(x2 - 3.0) > 2 * eps) && (abs(x2 - 2.0) + abs(x1 - 3.0) > 2 * eps)) return 1;
    }

    return 0;
}

/**
 * @brief Main function. Reads coeffs and prints solution.
 */
int main() {
    assert(!RunTests());

    struct Solution sol;
    struct Coeffs coeffs;

    ReadCoeffs(&coeffs);
    SolveQuadratic(&sol, &coeffs);
    Solution_Print(&sol);

    return 0;
}
