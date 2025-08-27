// Complex Numbers Library, for complex number operations
// Implementation file
// by Ambesiwe Sonka and Neo Vorsatz
// Last updated: 27 August 2025

#include <math.h>
#include "complexnumbers.h"

/* WRITING ================================*/

//Create a complex number in rectangular form
cnComplex cnRect(double real, double imag) {
  cnComplex complexNum = {real, imag, 1};
  return complexNum;
}

//Create a complex number in polar form
cnComplex cnPolar(double mag, double phase) {
  cnComplex complexNum = {mag, phase, 0};
  return complexNum;
}

/*================================*/
/* READING ================================*/

//Get the real component of a complex number
double cnReal(cnComplex complexNum) {
  //If the complex number is in rectangular form
  if (complexNum.rect_form) {
    return complexNum.real_mod;
  }
  return complexNum.real_mod*cos(complexNum.imag_arg);
}

//Get the imaginary component of a complex number
double cnImag(cnComplex complexNum) {
  //If the complex number is in rectangular form
  if (complexNum.rect_form) {
    return complexNum.imag_arg;
  }
  return complexNum.real_mod*sin(complexNum.imag_arg);
}

// Modulus of a complex number
double cnModulus( cnComplex complexNum){
  double result;
  result = sqrt(pow(complexNum.real_mod,2)+ pow(complexNum.imag_arg,2));
  return result;
}

// Argument of a complex number

double cnArgument(cnComplex complexNum){
  double result; // the angle

  double number = complexNum.imag_arg/complexNum.real_mod;

  // evaluate arctan(number) using the Taylor series approach
  double firstTerm = number;
  double secondTerm = pow(number,3)/3;
  double thirdTerm = pow(number,5)/5;
  double fourthTerm = pow(number,7)/7;
  double fifthTerm = pow(number,9)/9;

  result = firstTerm - secondTerm + thirdTerm - fourthTerm + fifthTerm; // the result of the taylor series
  return result;
  

}

//Euler's formula

cnComplex eulerIdentity(double cnArgument){

    double cosResult;
    double sinResult;
    cnComplex result;

    // evaluate cos(number) using the Taylor series approach
    double cosFirstTerm = 1.0;
    double cosSecondTerm = pow(cnArgument,2)/2;
    double cosThirdTerm = pow(cnArgument,4)/24;
    double cosFourthTerm = pow(cnArgument,6)/720;

    cosResult = cosFirstTerm - cosSecondTerm + cosThirdTerm - cosFourthTerm; // the result of the taylor series

     // evaluate sin(number) using the Taylor series approach
    double sinFirstTerm = cnArgument;
    double sinSecondTerm = pow(cnArgument,3)/6;
    double sinThirdTerm = pow(cnArgument,5)/120;
    double sinFourthTerm = pow(cnArgument,7)/5040;

    sinResult = sinFirstTerm - sinSecondTerm + sinThirdTerm - sinFourthTerm; // the result of the taylor series

    result.real_mod = cosResult;
    result.imag_arg = sinResult;

    return result;

}

/*================================*/
/* OPERATIONS ================================*/

//Convert a complex number to rectangular form
cnComplex cnRectForm(cnComplex complexNum) {
  //If the complex number is already in rectangular form
  if (complexNum.rect_form) {
    //Return the original complex number
    return complexNum;
  }
  return cnRect(cnReal(complexNum), cnImag(complexNum));
}

//Convert a complex number to polar form
cnComplex cnPolarForm(cnComplex complexNum) {
  //If the complex number is in reactangular form
  if (complexNum.rect_form) {
    return cnPolar(cnModulus(complexNum), cnArgument(complexNum));
  }
  //Return the original complex number
  return complexNum;
}

cnComplex cnComplexAdd(cnComplex firstNum, cnComplex secondNum) {
  cnComplex result;
  //Add the real parts
  result.real_mod = firstNum.real_mod + secondNum.real_mod;
  //Add the imaginary parts
  result.imag_arg = firstNum.imag_arg + secondNum.imag_arg;
  //Return the result
  return result;
}
cnComplex cnComplexSub(cnComplex firstNum, cnComplex secondNum) {
  cnComplex result;
  //Subtract the real parts
  result.real_mod = firstNum.real_mod - secondNum.real_mod;
  //Subtract the imaginary parts
  result.imag_arg = firstNum.imag_arg - secondNum.imag_arg;
  //Return the result
  return result;
}
cnComplex cnComplexConjugate(cnComplex num) {
  cnComplex result;
  //The conjugate is the same real part, but the opposite imaginary part
  result.real_mod = num.real_mod;
  result.imag_arg = -num.imag_arg;
  //Return the result
  return result;
}

cnComplex cnComplexMul(cnComplex firstNum, cnComplex secondNum) {
  cnComplex result;
  double foilTerm1 = firstNum.real_mod * secondNum.real_mod; //First terms of FOIL
  double foilTerm2 = firstNum.imag_arg * secondNum.imag_arg; //Last terms of FOIL
  double foilTerm3 = firstNum.real_mod * secondNum.imag_arg; //Outer terms of FOIL
  double foilTerm4 = firstNum.imag_arg * secondNum.real_mod; //Inner terms of FOIL

  double sumLikeTerms = foilTerm3 + foilTerm4; 
  //The real part is the first and last terms of FOIL
  result.real_mod = foilTerm1 - foilTerm2; // It is +foilTerm2(-1) since i^2 = -1

  //The imaginary part is the sum of the outer and inner terms of FOIL
  result.imag_arg = sumLikeTerms;
 
  return result;
}

cnComplex cnComplexDiv(cnComplex numerator, cnComplex denomenator){

  cnComplex result;

  cnComplex denomConjugate = cnComplexConjugate(denomenator); // convert the denominator to its conjugate term

  // changing the denomenator to a REAL number that can divide both the real part and imaginary parts of the result
  double divider = denomConjugate.real_mod*denomConjugate.real_mod + denomConjugate.imag_arg*denomConjugate.imag_arg; 

  result.real_mod = (numerator.real_mod* denomConjugate.real_mod + numerator.imag_arg*denomConjugate.imag_arg )/ divider;
  result.imag_arg = (numerator.real_mod*denomConjugate.imag_arg + numerator.imag_arg* denomConjugate.real_mod)/divider;
  return result;
}

/*================================*/