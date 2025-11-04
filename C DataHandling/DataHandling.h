// Data Handling Library, for processing data
// Header file
// by Ambesiwe Sonka and Neo Vorsatz
// Last updated: 4 November 2025

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

#endif