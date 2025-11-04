// Data Handling Library, for processing data
// Header file
// by Neo Vorsatz
// Last updated: 4 November 2025

#ifndef DATAHANDLING_H
#define DATAHANDLING_H

/* SUMMING ================================*/

//Returns the sum of an array of data values
double dhSum(double data[], char length);

//Gets the cumulative sum of an array of data values
void dhCumSum(double write[], double data[], char length);

/*================================*/
/* STATISTICS ================================*/

//Returns the mean/average/expected value of an array of data values
double dhMean(double data[], char length);

//Returns the mean/average/expected value of an array of data values
double dhAvg(double data[], char length);

//Returns the mean/average/expected value of an array of data values
double dhExpectedValue(double data[], char length);

//Returns the varience of an array of data values
double dhVar(double data[], char length);

//Returns the standard deviance of an array of data values
double dhStdDev(double data[], char length);

/*================================*/
/* SORTING ================================*/

//Copies an array of data into another array
void dhCopy(double write[], double data[], char length);

//Sorts an array of data in ascending order using the Quick Sort algorithm
void dhQuickSort(double write[], double data[], char length);

/*================================*/

#endif