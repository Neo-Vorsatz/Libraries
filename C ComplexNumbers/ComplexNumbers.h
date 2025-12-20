// Complex Numbers Library, for complex number operations
// Header file
// by Ambesiwe Sonka and Neo Vorsatz
// Last updated: 20 December 2025

#ifndef COMPLEXNUMBERS_H
#define COMPLEXNUMBERS_H

/* TYPE DEFINITIONS ================================*/

//Boolean
typedef int cnBoolean_t;

//Structure for complex numbers
typedef struct{
  double real_mod; //real component or magnitude
  double imag_arg; //imaginary component or phase
  cnBoolean_t rect_form; //whether the complex number is in rectangular form or not (otherwise in polar form)
} complex;

/*================================*/
/* CREATING ================================*/

/**
 * @param real The real part of the complex number
 * @param imag The imaginary part of the complex number
 * 
 * @return A complex number in rectangular form
 */
complex cnRect(double real, double imag);

/**
 * @param mag The magnitude of the complex number
 * @param phase The phase of the complex number
 * 
 * @return A complex number in polar form
 */
complex cnPolar(double mag, double phase);

/**
 * @param real The real part of the complex number
 * 
 * @return A complex number in rectangular form, with only a real component
 */
complex cnR(double real);

/**
 * @param imag The imaginary part of the complex number
 * 
 * @return A complex number in rectangular form, with only an imaginary component
 */
complex cnI(double imag);

/**
 * @param arg The argument of the complex number
 * 
 * @return A complex number in polar form, with magnitude 1
 */
complex cnA(double arg);

/*================================*/
/* READING ================================*/

/**
 * @param complexNum A complex number
 * 
 * @return The real component of a complex number
 */
double cnReal(complex complexNum);

/**
 * @param complexNum A complex number
 * 
 * @return The imaginary component of a complex number
 */
double cnImag(complex complexNum);

/**
 * @param complexNum A complex number
 * 
 * @return The magnitude of a complex number
 */
double cnMod(complex complexNum);

/**
 * @param complexNum A complex number
 * 
 * @return The argument of a complex number
 */
double cnArg(complex complexNum);

/**
 * @param complexNum A complex number
 * 
 * @return Whether or not a complex number is in rectangular form
 */
cnBoolean_t cnIsRect(complex complexNum);

/**
 * @param complexNum A complex number
 * 
 * @return Whether or not a complex number is in polar form
 */
cnBoolean_t cnIsPolar(complex complexNum);

/*================================*/
/* UPDATING ================================*/

/**
 * @brief Sets the real component of a complex number
 * 
 * @param complexNum A complex number
 * @param real The new real component of the complex number
 */
void cnSetReal(complex* complexNum, double real);

/**
 * @brief Sets the imaginary component of a complex number
 * 
 * @param complexNum A complex number
 * @param imag The new imaginary component of the complex number
 */
void cnSetImag(complex* complexNum, double imag);

/**
 * @brief Sets the magnitude of a complex number
 * 
 * @param complexNum A complex number
 * @param mag The new magnitude of the complex number
 */
void cnSetMag(complex* complexNum, double mag);

/**
 * @brief Sets the argument of a complex number
 * 
 * @param complexNum A complex number
 * @param arg The new argument of the complex number
 */
void cnSetArg(complex* complexNum, double arg);

/**
 * @brief Sets whether or not a complex number is in rectangular form
 * Warning: This changes the value of the complex number
 * 
 * @param complexNum A complex number
 * @param rect Whether or not the complex number is set to rectangular form, else polar form
 */
void cnSetForm(complex* complexNum, cnBoolean_t rect);

/*================================*/
/* OPERATIONS ================================*/

/**
 * @param complexNum A complex number
 * 
 * @return The complex number in rectangular form
 */
complex cnRectForm(complex complexNum);

/**
 * @param complexNum A complex number
 * 
 * @return The complex number in polar form
 */
complex cnPolarForm(complex complexNum);

/**
 * @param complexNum1 A complex number
 * @param complexNum2 Another complex number
 * 
 * @return The sum of two complex numbers
 */
complex cnAdd(complex complexNum1, complex complexNum2);

/**
 * @param complexNum1 A complex number
 * @param complexNum2 Another complex number
 * 
 * @return The difference of two complex numbers
 */
complex cnSub(complex complexNum1, complex complexNum2);

/**
 * @param complexNum A complex number
 * @param scalar A real scalar
 * 
 * @return The complex number multiplied by a scalar
 */
complex cnScale(complex complexNum, double scalar);

/**
 * @param complexNum1 A complex number
 * @param complexNum2 Another complex number
 * 
 * @return The product of two complex numbers
 */
complex cnMultiply(complex complexNum1, complex complexNum2);

/**
 * @param complexNum1 A complex number
 * @param complexNum2 Another complex number
 * 
 * @return The quotient of two complex numbers
 */
complex cnDivide(complex complexNum1, complex complexNum2);

/**
 * @param complexNum A complex number
 * 
 * @return The conjugate of the complex number
 */
complex cnConjugate(complex complexNum);

/**
 * @param complexNum A complex number
 * 
 * @return e raised to the power of a complex number (Euler's formula)
 */
complex cnExp(complex complexNum);

/**
 * @param angle An angle
 * 
 * @return The principle argument of an angle
 */
double cnPrincipleArg(double angle);

/*================================*/

#endif