// Digial Signal Processing Library, for processing signals
// Implementation file
// by Ambesiwe Sonka and Neo Vorsatz
// Last updated: 4 November 2025

#include <math.h>
#include "DataHandling.h"

/* USER MAY EDIT ================================*/

#include "../C DataHandling/DataHandling.h"
#include "../C ComplexNumbers/ComplexNumbers.h"

/*================================*/
/* ELECTRICITY ================================*/

//Returns the Direct-Current component of a signal
double dsDC(double signal[], char length) {
  //Call the dhMean function
  return dhMean(signal, length);
}

//Removes the Direct-Current offset from a signal
void dsAC(double write[], double signal[], char length) {
  //Get the DC component
  double dc = dhMean(signal, length);
  //For each data point
  for (char i=0; i<length; i++) {
    //Subtract the DC offset
    write[i] = signal[i]-dc;
  }
}

//Gets the power of the signal at each time step
void dsPower(double write[], double signal[], char length) {
  //For each data point
  for (char i=0; i<length; i++) {
    //Calculate the power
    write[i] = signal[i]*signal[i];
  }
}

//Returns the total energy of a signal
double dsEnergy(double signal[], char length) {
  //Create an array for the power of the signal
  double power[length];
  //Get the power of the signal
  dsPower(power, signal, length);
  //Return the sum of the power
  return dhSum(power, length);
}

//Gets the cumulative sum of energy of a signal
void dsCumSumEnergy(double write[], double signal[], char length) {
  //Create an array for the power of the signal
  double power[length];
  //Get the power of the signal
  dsPower(power, signal, length);
  //Get the cumulative sum of the power
  dhCumSum(write, power, length);
}

//Returns the average power of a signal
double dsAvgPower(double signal[], char length) {
  //Create an array for the power of the signal
  double power[length];
  //Get the power of the signal
  dsPower(power, signal, length);
  //Return the mean/average/expected value of the power
  return dhMean(power, length);
}

//Returns the Alternating-Current Root-Mean-Square of a signal
double dsACRMS(double signal[], char length) {
  //Call the dhStdDev function
  return dhStdDev(signal, length);
}

//Returns the Root-Mean-Square of a signal
double dsRMS(double signal[], char length) {
  //The RMS is the square-root of the average power
  return sqrt(dsAvgPower(signal, length));
}

//Returns the Direct-Current power of a signal
double dsDCPower(double signal[], char length) {
  //Get the DC component
  double dc = dhMean(signal, length);
  //Return the power of the DC component
  return dc*dc;
}

//Returns the Alternating-Current power of a signal
double dsACPower(double signal[], char length) {
  //Call the dhVar function
  return dhVar(signal, length);
}

/*================================*/
/* FOURIER ================================*/



/*================================*/