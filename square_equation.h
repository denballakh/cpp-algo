/**
 * @file square_equation.h
 *
 * @author Баллах Денис
 */
#ifndef SQUARE_EQUATION_H_
#define SQUARE_EQUATION_H_

#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "assert.h"

#define INF_SOL_CNT -1                  ///< Const for infinite count of solutions
#define PSolution struct Solution*      ///< Pointer to Solution struct
#define PCoeffs struct Coeffs*          ///< Pointer to Coeffs struct

const double eps = 1e-5;                ///< Espilon for comparation with 0.0

/**
 * @brief           Struct for equation solution.
 */
struct Solution {
    int cnt;            ///< Number of solution. -1 for infinite count of solutions.
    double roots[2];    ///< Array of roots.
};

/**
 * @brief           Allocates memory for solution struct.
 *
 * @return          Solution*
 */
PSolution Solution_New();

/**
 * @brief           Frees memory for solution struct.
 *
 * @param[in]       sol     Solution*
 */
void Solution_Free(PSolution);

/**
 * @brief           Prints solution.
 *
 * @param[in]       sol     Solution*
 */
void Solution_Print(PSolution);

/**
 * @brief           Struct for equation coefficients.
 */
struct Coeffs {
    double data[3]; ///< Array of coefficients.
};

/**
 * @brief           Reads coefficients from stdin.
 *
 * @param[out]      coeffs  Coeffs*
 */
void ReadCoeffs(PCoeffs);


/**
 * @brief           Solves linear equation.
 *
 * @param[out]      sol     Solution*
 * @param[in]       coeffs  Coeffs*
 */
void SolveLinear(PSolution, PCoeffs);

/**
 * @brief           Solves quadratic equation.
 *
 * @param[out]      sol     Solution*
 * @param[in]       coeffs  Coeffs*
 */
void SolveQuadratic(PSolution, PCoeffs);

/**
 * @brief Runs tests.
 *
 * @return 0 - OK. 1 - Error
 */
int RunTests();

#endif  // SQUARE_EQUATION_H_
