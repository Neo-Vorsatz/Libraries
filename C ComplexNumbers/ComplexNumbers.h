// Complex Numbers Library, for complex number operations
// Header file
// by Ambesiwe Sonka and Neo Vorsatz
// Last updated: 9 July 2025

#ifndef COMPLEXNUMBERS_H
#define COMPLEXNUMBERS_H

/* TYPE DEFINITIONS ================================*/

//Boolean
typedef char cnBoolean_t;

typedef struct{
  double real;
  double imag;
  cnBoolean_t rect_form;
} cnComplex;

//Structure for complex number
// typedef struct {
//   double real_mag; //the real part or magnitude
//   double imag_arg; //the imaginary part of argument
//   cnBoolean_t rect_form; //whether the complex number is in rectangular form or not (otherwise in polar form)
// } complexNum;

/*================================*/
/* WRITING ================================*/



/*================================*/
/* READING ================================*/

// double cnModulus( cnComplex complexNum);
// double cnArgument(cnComplex complexNum);

/*================================*/
/* OPERATIONS ================================*/

// Returns the sum of two complex numbers
cnComplex cnComplexAdd(cnComplex firstNum, cnComplex secondNum);

// cnComplex cnComplexSub(cnComplex firstNum, cnComplex secondNum);
// cnComplex cnComplexConjugate(cnComplex num);
// cnComplex cnComplexMul(cnComplex firstNum, cnComplex secondNum);
// cnComplex cnComplexDiv(cnComplex numerator, cnComplex denomenator);

/*================================*/

#endif