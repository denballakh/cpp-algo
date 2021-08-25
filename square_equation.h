/**
 * @defgroup   SQUARE_EQUATION square equation
 *
 * @brief      This file implements square equation.
 *
 * @author     Denba
 * @date       2021
 */

#ifndef SQUARE_EQUATION_H_
#define SQUARE_EQUATION_H_

#include "stdlib.h"
#include "stdio.h"
#include "math.h"

#define INF_SOL_CNT -1
#define PSolution struct Solution*
#define PCoeffs struct Coeffs*

const double eps = 1e-5;

/**
 * @brief      { struct_description }
 */
struct Solution {
    int cnt;  // -1 - infinite solution count
    double roots[2];
};


PSolution Solution_New();
/**
 * @brief      short function docstring
 */
void Solution_Free(PSolution);

/**
 * @brief      short function docstring
 */
void Solution_Print(PSolution);

/**
 * @brief      short struct docstring
 */
struct Coeffs {
    double data[3];
};

/**
 * @brief      short function docstring
 */
void ReadCoeffs(PCoeffs);


/**
 * @brief      short function docstring
 */
void SolveLinear(PSolution, PCoeffs);

/**
 * @brief      short function docstring
 */
void SolveQuadratic(PSolution, PCoeffs);

#endif  // SQUARE_EQUATION_H_
