// Complex Numbers Library, for complex number operations
// Implementation file
// by Ambesiwe Sonka and Neo Vorsatz
// Last updated: 20 December 2025

#include <math.h>
#include "complexnumbers.h"

#define PI 3.14159265358979323846 //Same value in math.h, but defined locally

/* CREATING ================================*/

//Returns a complex number in rectangular form
complex cnRect(double real, double imag) {
  complex complexNum = {real, imag, 1};
  return complexNum;
}

//Returns a complex number in polar form
complex cnPolar(double mag, double arg) {
  complex complexNum = {mag, cnPrincipleArg(arg), 0};
  return complexNum;
}

//Returns a complex number in rectangular form, with only a real component
complex cnR(double real) {
  complex complexNum = {real, 0, 1};
  return complexNum;
}

//Returns a complex number in rectangular form, with only an imaginary component
complex cnI(double imag) {
  complex complexNum = {0, imag, 1};
  return complexNum;
}

//Returns a complex number in polar form, with magnitude 1
complex cnA(double arg) {
  complex complexNum = {1, cnPrincipleArg(arg), 0};
  return complexNum;
}

/*================================*/
/* READING ================================*/

//Returns the real component of a complex number
double cnReal(complex complexNum) {
  //If the complex number is in rectangular form
  if (complexNum.rect_form) {
    return complexNum.real_mod;
  }
  return complexNum.real_mod*cos(complexNum.imag_arg);
}

//Returns the imaginary component of a complex number
double cnImag(complex complexNum) {
  //If the complex number is in rectangular form
  if (complexNum.rect_form) {
    return complexNum.imag_arg;
  }
  return complexNum.real_mod*sin(complexNum.imag_arg);
}

//Returns the magnitude of a complex number
double cnMod( complex complexNum){
  //If the complex number is in rectangular form
  if (complexNum.rect_form) {
    //Use Pythagorean formula
    return sqrt((complexNum.real_mod*complexNum.real_mod)+(complexNum.imag_arg*complexNum.imag_arg));
  }
  return complexNum.real_mod;
}

//Returns the argument of a complex number
double cnArg(complex complexNum){
  //If the complex number is in rectangular form
  if (complexNum.rect_form) {
    return cnPrincipleArg(atan2(complexNum.imag_arg, complexNum.real_mod));
  }
  return complexNum.imag_arg;
}

//Returns whether or not a complex number is in rectangular form
cnBoolean_t cnIsRect(complex complexNum){
  return complexNum.rect_form;
}

//Returns whether or not a complex number is in polar form
cnBoolean_t cnIsPolar(complex complexNum){
  return !complexNum.rect_form;
}

/*================================*/
/* UPDATING ================================*/

//Sets the real component of a complex number
void cnSetReal(complex* complexNum, double real){
  cnBoolean_t rect_form = complexNum->rect_form; //Save the current form
  *complexNum = cnRectForm(*complexNum); //Convert to rectangular form
  complexNum->real_mod = real;
  if (!rect_form) {
    *complexNum = cnPolarForm(*complexNum); //Convert back to polar form
  }
}

//Sets the imaginary component of a complex numbers
void cnSetImag(complex* complexNum, double imag){
  cnBoolean_t rect_form = complexNum->rect_form; //Save the current form
  *complexNum = cnRectForm(*complexNum); //Convert to rectangular form
  complexNum->imag_arg = imag;
  if (!rect_form) {
    *complexNum = cnPolarForm(*complexNum); //Convert back to polar form
  }
}

//Sets the magnitude of a complex number
void cnSetMag(complex* complexNum, double mag){
  cnBoolean_t rect_form = complexNum->rect_form; //Save the current form
  *complexNum = cnPolarForm(*complexNum); //Convert to polar form
  complexNum->real_mod = mag;
  if (rect_form) {
    *complexNum = cnRectForm(*complexNum); //Convert back to polar form
  }
}

//Sets the argument of a complex number
void cnSetArg(complex* complexNum, double arg){
  cnBoolean_t rect_form = complexNum->rect_form; //Save the current form
  *complexNum = cnPolarForm(*complexNum); //Convert to polar form
  complexNum->imag_arg = cnPrincipleArg(arg);
  if (rect_form) {
    *complexNum = cnRectForm(*complexNum); //Convert back to polar form
  }
}

//Sets whether or not a complex number is in rectangular form
void cnSetForm(complex* complexNum, cnBoolean_t rect){
  complexNum->rect_form = rect;
}

/*================================*/
/* OPERATIONS ================================*/

//Returns the complex number in rectangular form
complex cnRectForm(complex complexNum) {
  //If the complex number is already in rectangular form
  if (complexNum.rect_form) {
    //Return the original complex number
    return complexNum;
  }
  return cnRect(cnReal(complexNum), cnImag(complexNum));
}

//Returns the complex number in polar form
complex cnPolarForm(complex complexNum) {
  //If the complex number is in rectangular form
  if (complexNum.rect_form) {
    return cnPolar(cnMod(complexNum), cnArg(complexNum));
  }
  //Return the original complex number
  return complexNum;
}

//Returns the sum of two complex numbers
complex cnAdd(complex complexNum1, complex complexNum2) {
  //Use the form of the first complex number
  cnBoolean_t rect_form = complexNum1.rect_form;

  //Convert complex numbers to rectangular form
  complexNum1 = cnRectForm(complexNum1);
  complexNum2 = cnRectForm(complexNum2);

  //Add the real parts
  double real = complexNum1.real_mod+complexNum2.real_mod;
  //Add the imaginary parts
  double imag = complexNum1.imag_arg+complexNum2.imag_arg;
  //Create the resulting complex number
  complex result = cnRect(real, imag);
  if (!rect_form) {
    result = cnPolarForm(result); //Convert the result to polar form
  }

  //Return the result
  return result;
}

//Returns the difference of two complex numbers
complex cnSub(complex complexNum1, complex complexNum2) {
  complexNum2 = cnScale(complexNum2, -1); //Negate the second complex number
  return cnAdd(complexNum1, complexNum2);
}

//Returns the complex number multiplied by a real scalar
complex cnScale(complex complexNum, double scalar) {
  if (complexNum.rect_form) {
    complexNum.real_mod *= scalar; //Scale the real component
    complexNum.imag_arg *= scalar; //Scale the imaginary component
  } else {
    complexNum.real_mod *= scalar; //Scale the magnitude
  }
  return complexNum;
}

//Returns the product of two complex numbers
complex cnMultiply(complex complexNum1, complex complexNum2) {
  if (complexNum1.rect_form) { //Do calculations in rectangular form
    //Convert the second complex number to rectangular form
    complexNum2 = cnRectForm(complexNum2);

    //Calculate the real component
    double real = complexNum1.real_mod*complexNum2.real_mod-complexNum1.imag_arg*complexNum2.imag_arg;
    //Calculate the imaginary component
    double imag = complexNum1.real_mod*complexNum2.imag_arg+complexNum1.imag_arg*complexNum2.real_mod;

    //Return the resulting complex number
    return cnRect(real, imag);

  } else { //Do calculations in polar form
    //Convert the second complex number to polar form
    complexNum2 = cnPolarForm(complexNum2);

    //Calculate the magnitude
    double mag = complexNum1.real_mod*complexNum2.real_mod;
    //Calculate the argument
    double arg = cnPrincipleArg(complexNum1.imag_arg+complexNum2.imag_arg);

    //Return the resulting complex number
    return cnPolar(mag, arg);
  }
}

//Returns the quotient of two complex numbers
complex cnDivide(complex complexNum1, complex complexNum2) {
  //Use the form of the first complex number
  cnBoolean_t rect_form = complexNum1.rect_form;

  //Convert complex numbers to polar form
  complexNum1 = cnPolarForm(complexNum1);
  complexNum2 = cnPolarForm(complexNum2);

  //Divide magnitudes
  double mag = complexNum1.real_mod/complexNum2.real_mod;
  //Subtract arguments
  double arg = cnPrincipleArg(complexNum1.imag_arg-complexNum2.imag_arg);
  //Create the resulting complex number
  complex result = cnPolar(mag, arg);
  if (rect_form) {
    result = cnRectForm(result); //Convert the result to rectangular form
  }

  //Return the result
  return result;
}

//Returns the conjugate of the complex number
complex cnConjugate(complex complexNum) {
  complexNum.imag_arg *= -1; //Negate the imaginary part or phase
  if (!complexNum.rect_form) { //If the complex number is in polar form
    complexNum.imag_arg = cnPrincipleArg(complexNum.imag_arg); //Get principle argument
  }
  return complexNum;
}

//Returns e raised to the power of a complex number (Euler's formula)
complex cnExp(complex complexNum) {
  //Convert the complex number to rectangular form
  complexNum = cnRectForm(complexNum);
  //Calculate the magnitude
  double mag = exp(complexNum.real_mod);
  //Calculate the argument
  double arg = cnPrincipleArg(complexNum.imag_arg);
  //Return the resulting complex number
  return cnPolar(mag, arg);
}

//Returns the principle argument of an angle
double cnPrincipleArg(double angle) {
  return fmod(angle-PI, 2*PI)+PI;
}

/*================================*/