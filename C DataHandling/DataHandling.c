// Data Handling Library, for processing data
// Implementation file
// by Ambesiwe Sonka and Neo Vorsatz
// Last updated: 24 June 2025

#include "DataHandling.h"
#include <math.h>
/* STATISTICS ================================*/

//Returns the sum of an array of data values
double dhSum(double data[], char length) {
  //Initialise the sum
  double sum = 0.0;
  //For each data point
  for (char i=0; i<length; i++) {
    //Add the data point to the sum
    sum += data[i];
  }
  //Return the sum
  return sum;
}

//Returns the mean/average/expected value of an array of data values
double dhMean(double data[], char length) {
  //Get the sum
  double sum = dhSum(data, length);
  //Return the average
  return sum/length;
}

//Returns the mean/average/expected value of an array of data values
double dhAvg(double data[], char length) {
  //Call the dhMean function
  return dhMean(data, length);
}

//Returns the mean/average/expected value of an array of data values
double dhExpectedValue(double data[], char length) {
  //Call the dhMean function
  return dhMean(data, length);
}

//Gets the cumulative sum of an array of data values
void dhCumSum(double write[], double data[], char length) {
  //Initialise the sum
  double sum = 0.0;
  //For each data point
  for (char i=0; i<length; i++) {
    //Add the data point to the sum
    sum += data[i];
    //Write the cumulative sum to the corresponding index
    write[i] = sum;
  }
}

//Returns the varience of an array of data values, assuming the data represents the population
double dhVar(double data[], char length) {
  //Initialise an array of square-differences
  double sqrDiff[length];
  //Get the mean/average/expected value
  double mean = dhMean(data, length);
  //For each data point
  for (char i=0; i<length; i++) {
    //Get the difference
    double diff = data[i]-mean;
    //Save the squared difference
    sqrDiff[i] = diff*diff;
  }
  //Return the mean/average/expected value of the squared difference
  return dhMean(sqrDiff, length);
}

//Returns the square-root of a value
double dhSqrt(double value) {
  //If the value is negative
  if (value<0) {return 0.0;}
  //If the value is zero
  if (value==0) {return 0.0;}

  //Initialise the number of multiples of 2
  char multiplesOf2 = 0;
  //Extract the multiples of 2
  while (value>2) {
    //Increment the number of multiples
    multiplesOf2++;
    //Reduce the value remaining
    value /= 2.0;
  }

  //Create an x variable that's 1 less than the given value, and will be raised to an increasing exponent
  double x = value-1;
  //Apply a 5th order taylor polynomial ofr sqrt(x) at x=1
  double taylor = 1.0; //zero-th order
  taylor += 0.5*x; //first order
  x *= x; //increment the power of x
  taylor -= 0.125*x; //second order
  x *= x; //increment the power of x
  taylor += 0.0625*x; //third order
  x *= x; //increment the power of x
  taylor -= (5.0/128.0)*x; //fourth order
  x *= x; //increment the power of x
  taylor += (7.0/256.0)*x; //fifth order

  //Initialise the result
  double result = taylor;
  //Bring back the multiples of 2
  for (char i=0; i<multiplesOf2; i++) {
    //Multiply by sqrt(2)
    result *= 1.414213562;
  }

  //Return the result
  return result;
}

//Returns the standard deviance of an array of data values, assuming the data represents the population
double dhStdDev(double data[], char length) {
  //The standard deviance is the square-root of the variance
  return dhSqrt(dhVar(data, length));
}

/*================================*/
/* COMPLEX ================================*/

typedef struct{
  double real;   
  double imag;   
} dhComplex;

// OPERATIONS OF COMPLEX NUMBERS

dhComplex dhComplexAdd(dhComplex firstNum, dhComplex secondNum) {
  dhComplex result;
  //Add the real parts
  result.real = firstNum.real + secondNum.real;
  //Add the imaginary parts
  result.imag = firstNum.imag + secondNum.imag;
  //Return the result
  return result;
}
dhComplex dhComplexSub(dhComplex firstNum, dhComplex secondNum) {
  dhComplex result;
  //Subtract the real parts
  result.real = firstNum.real - secondNum.real;
  //Subtract the imaginary parts
  result.imag = firstNum.imag - secondNum.imag;
  //Return the result
  return result;
}
dhComplex dhComplexConjugate(dhComplex num) {
  dhComplex result;
  //The conjugate is the same real part, but the opposite imaginary part
  result.real = num.real;
  result.imag = -num.imag;
  //Return the result
  return result;
}

dhComplex dhComplexMul(dhComplex firstNum, dhComplex secondNum) {
  dhComplex result;
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

dhComplex dhComplexDiv(dhComplex numerator, dhComplex denomenator){

  dhComplex result;

  dhComplex denomConjugate = dhComplexConjugate(denomenator); // convert the denominator to its conjugate term

  // changing the denomenator to a REAL number that can divide both the real part and imaginary parts of the result
  double divider = denomConjugate.real*denomConjugate.real + denomConjugate.imag*denomConjugate.imag; 

  result.real = (numerator.real* denomConjugate.real + numerator.imag*denomConjugate.imag )/ divider;
  result.imag = (numerator.real*denomConjugate.imag + numerator.imag* denomConjugate.real)/divider;
  return result;
}

// POLAR FORM

// Modulus of a complex number
double dhModulus( dhComplex complexNum){
  double result;
  result = sqrt(pow(complexNum.real,2)+ pow(complexNum.imag,2));
  return result;
}

// Argument of a complex number

double dhArgument(dhComplex complexNum){
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

/*================================*/
/* FOURIER ================================*/



/*================================*/