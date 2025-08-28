// Data Handling Library, for processing data
// Implementation file
// by Ambesiwe Sonka and Neo Vorsatz
// Last updated: 28 August 2025

#include <math.h>
#include "DataHandling.h"

/* USER MAY EDIT ================================*/

#include "../C ComplexNumbers/ComplexNumbers.h"

/*================================*/
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

//Returns the standard deviance of an array of data values, assuming the data represents the population
double dhStdDev(double data[], char length) {
  //The standard deviance is the square-root of the variance
  return sqrt(dhVar(data, length));
}

/*================================*/
/* ELECTRICITY ================================*/

//Returns the Direct-Current component of a signal
double dhDC(double signal[], char length) {
  //Call the dhMean function
  return dhMean(signal, length);
}

//Removes the Direct-Current offset from a signal
void dhAC(double write[], double signal[], char length) {
  //Get the DC component
  double dc = dhMean(signal, length);
  //For each data point
  for (char i=0; i<length; i++) {
    //Subtract the DC offset
    write[i] = signal[i]-dc;
  }
}

//Gets the power of the signal at each time step
void dhPower(double write[], double signal[], char length) {
  //For each data point
  for (char i=0; i<length; i++) {
    //Calculate the power
    write[i] = signal[i]*signal[i];
  }
}

//Returns the total energy of a signal
double dhEnergy(double signal[], char length) {
  //Create an array for the power of the signal
  double power[length];
  //Get the power of the signal
  dhPower(power, signal, length);
  //Return the sum of the power
  return dhSum(power, length);
}

//Gets the cumulative sum of energy of a signal
void dhCumSumEnergy(double write[], double signal[], char length) {
  //Create an array for the power of the signal
  double power[length];
  //Get the power of the signal
  dhPower(power, signal, length);
  //Get the cumulative sum of the power
  dhCumSum(write, power, length);
}

//Returns the average power of a signal
double dhAvgPower(double signal[], char length) {
  //Create an array for the power of the signal
  double power[length];
  //Get the power of the signal
  dhPower(power, signal, length);
  //Return the mean/average/expected value of the power
  return dhMean(power, length);
}

//Returns the Alternating-Current Root-Mean-Square of a signal
double dhACRMS(double signal[], char length) {
  //Call the dhStdDev function
  return dhStdDev(signal, length);
}

//Returns the Root-Mean-Square of a signal
double dhRMS(double signal[], char length) {
  //The RMS is the square-root of the average power
  return sqrt(dhAvgPower(signal, length));
}

//Returns the Direct-Current power of a signal
double dhDCPower(double signal[], char length) {
  //Get the DC component
  double dc = dhMean(signal, length);
  //Return the power of the DC component
  return dc*dc;
}

//Returns the Alternating-Current power of a signal
double dhACPower(double signal[], char length) {
  //Call the dhVar function
  return dhVar(signal, length);
}

/*================================*/
/* FOURIER ================================*/



/*================================*/