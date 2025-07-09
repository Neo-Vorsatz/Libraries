// Complex Numbers Library, for complex number operations
// Implementation file
// by Ambesiwe Sonka and Neo Vorsatz
// Last updated: 9 July 2025

#include <math.h>
#include "complexnumbers.h"

/* WRITING ================================*/



/*================================*/
/* READING ================================*/

// Modulus of a complex number
double cnModulus( cnComplex complexNum){
  double result;
  result = sqrt(pow(complexNum.real,2)+ pow(complexNum.imag,2));
  return result;
}

// Argument of a complex number

double cnArgument(cnComplex complexNum){
  double result; // the angle

  double number = complexNum.imag/complexNum.real;

  // evaluate arctan(number) using the Taylor series approach
  double firstTerm = number;
  double secondTerm = pow(number,3)/3;
  double thirdTerm = pow(number,5)/5;
  double fourthTerm = pow(number,7)/7;
  double fifthTerm = pow(number,9)/9;

  result = firstTerm - secondTerm + thirdTerm - fourthTerm + fifthTerm; // the result of the taylor series
  return result;
  

}

/*================================*/
/* OPERATIONS ================================*/

cnComplex cnComplexAdd(cnComplex firstNum, cnComplex secondNum) {
  cnComplex result;
  //Add the real parts
  result.real = firstNum.real + secondNum.real;
  //Add the imaginary parts
  result.imag = firstNum.imag + secondNum.imag;
  //Return the result
  return result;
}
cnComplex cnComplexSub(cnComplex firstNum, cnComplex secondNum) {
  cnComplex result;
  //Subtract the real parts
  result.real = firstNum.real - secondNum.real;
  //Subtract the imaginary parts
  result.imag = firstNum.imag - secondNum.imag;
  //Return the result
  return result;
}
cnComplex cnComplexConjugate(cnComplex num) {
  cnComplex result;
  //The conjugate is the same real part, but the opposite imaginary part
  result.real = num.real;
  result.imag = -num.imag;
  //Return the result
  return result;
}

cnComplex cnComplexMul(cnComplex firstNum, cnComplex secondNum) {
  cnComplex result;
  double foilTerm1 = firstNum.real * secondNum.real; //First terms of FOIL
  double foilTerm2 = firstNum.imag * secondNum.imag; //Last terms of FOIL
  double foilTerm3 = firstNum.real * secondNum.imag; //Outer terms of FOIL
  double foilTerm4 = firstNum.imag * secondNum.real; //Inner terms of FOIL

  double sumLikeTerms = foilTerm3 + foilTerm4; 
  //The real part is the first and last terms of FOIL
  result.real = foilTerm1 - foilTerm2; // It is +foilTerm2(-1) since i^2 = -1

  //The imaginary part is the sum of the outer and inner terms of FOIL
  result.imag = sumLikeTerms;
 
  return result;
}

cnComplex cnComplexDiv(cnComplex numerator, cnComplex denomenator){

  cnComplex result;

  cnComplex denomConjugate = cnComplexConjugate(denomenator); // convert the denominator to its conjugate term

  // changing the denomenator to a REAL number that can divide both the real part and imaginary parts of the result
  double divider = denomConjugate.real*denomConjugate.real + denomConjugate.imag*denomConjugate.imag; 

  result.real = (numerator.real* denomConjugate.real + numerator.imag*denomConjugate.imag )/ divider;
  result.imag = (numerator.real*denomConjugate.imag + numerator.imag* denomConjugate.real)/divider;
  return result;
}

/*================================*/