// Data Handling Library, for processing data
// Header file
// by Ambesiwe Sonka and Neo Vorsatz
// Last updated: 28 August 2025

#ifndef DATAHANDLING_H
#define DATAHANDLING_H

/* STATISTICS ================================*/

//Returns the sum of an array of data values
double dhSum(double data[], char length);

//Returns the mean/average/expected value of an array of data values
double dhMean(double data[], char length);

//Returns the mean/average/expected value of an array of data values
double dhAvg(double data[], char length);

//Returns the mean/average/expected value of an array of data values
double dhExpectedValue(double data[], char length);

//Gets the cumulative sum of an array of data values
void dhCumSum(double write[], double data[], char length);

//Returns the varience of an array of data values
double dhVar(double data[], char length);

//Returns the standard deviance of an array of data values
double dhStdDev(double data[], char length);

/*================================*/
/* ELECTRICITY ================================*/

//Returns the Direct-Current component of a signal
double dhDC(double signal[], char length);

//Removes the Direct-Current offset from a signal
void dhAC(double write[], double signal[], char length);

//Gets the power of the signal at each time step
void dhPower(double write[], double signal[], char length);

//Returns the total energy of a signal
double dhEnergy(double signal[], char length);

//Gets the cumulative sum of energy of a signal
void dhCumSumEnergy(double write[], double signal[], char length);

//Returns the average power of a signal
double dhAvgPower(double signal[], char length);

//Returns the Alternating-Current Root-Mean-Square of a signal
double dhACRMS(double signal[], char length);

//Returns the Root-Mean-Square of a signal
double dhRMS(double signal[], char length);

//Returns the Direct-Current power of a signal
double dhDCPower(double signal[], char length);

//Returns the Alternating-Current power of a signal
double dhACPower(double signal[], char length);

/*================================*/
/* FOURIER ================================*/



/*================================*/

#endif