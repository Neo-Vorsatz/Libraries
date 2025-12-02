// Data Handling Library, for processing data
// Header file
// by Neo Vorsatz
// Last updated: 2 December 2025

#ifndef DATAHANDLING_H
#define DATAHANDLING_H

/* SUMMING ================================*/

/**
  @brief Returns the sum of an array of data values
  
  @param data A pointer to the array of data values
  @param length The number of data values
*/
double dhSum(double data[], int length);

/**
  @brief Gets the cumulative sum of an array of data values

  @param write A pointer to where the cumulative sum will be written
  @param data A pointer to the array of data values
  @param length The number of data values
*/
void dhCumSum(double write[], double data[], int length);

/*================================*/
/* SORTING ================================*/

/**
  @brief Copies an array of data into another array

  @param write A pointer to where the copy will be written
  @param data A pointer to the array of data values
  @param length The number of data values
*/
void dhCopy(double write[], double data[], int length);

/**
  @brief Sorts an array of data in ascending order using the Quick Sort algorithm

  @param write A pointer to where the sorted data will be written
  @param data A pointer to the array of data values
  @param length The number of data values
*/
void dhQuickSort(double write[], double data[], int length);

/**
  @brief Sorts an array of data in ascending order using the Merge Sort algorithm

  @param write A pointer to where the sorted data will be written
  @param data A pointer to the array of data values
  @param length The number of data values
*/
void dhMergeSort(double write[], double data[], int length);

/**
  @brief Reverses an array of data

  @param write A pointer to where the reversed array will be written
  @param data A pointer to the array of data values
  @param length The number of data values
*/
void dhReverse(double write[], double data[], int length);

/*================================*/
/* STATISTICS ================================*/

/**
  @brief //Returns the smallest value in an array of data values

  @param data A pointer to the array of data values
  @param length The number of data values
*/
double dhMin(double data[], int length);

/**
  @brief //Returns the largest value in an array of data values

  @param data A pointer to the array of data values
  @param length The number of data values
*/
double dhMax(double data[], int length);

/**
  @brief Returns the mean/average/expected value of an array of data values

  @param data A pointer to the array of data values
  @param length The number of data values
*/
double dhMean(double data[], int length);

/**
  @brief Returns the mean/average/expected value of an array of data values

  @param data A pointer to the array of data values
  @param length The number of data values
*/
double dhAvg(double data[], int length);

/**
  @brief Returns the mean/average/expected value of an array of data values

  @param data A pointer to the array of data values
  @param length The number of data values
*/
double dhExpectedValue(double data[], int length);

/**
  @brief Returns the varience of an array of data values, assuming the data represents the population

  @param data A pointer to the array of data values
  @param length The number of data values
*/
double dhVar(double data[], int length);

/**
  @brief Returns the standard deviance of an array of data values, assuming the data represents the population

  @param data A pointer to the array of data values
  @param length The number of data values
*/
double dhStdDev(double data[], int length);

/**
  @brief Returns the median of an array of data values

  @param data A pointer to the array of data values
  @param length The number of data values
*/
double dhMedian(double data[], int length);

/**
  @brief Returns the lower quartile of an array of data values

  @param data A pointer to the array of data values
  @param length The number of data values
*/
double dhLowerQuartile(double data[], int length);

/**
  @brief Returns the upper quartile of an array of data values

  @param data A pointer to the array of data values
  @param length The number of data values
*/
double dhUpperQuartile(double data[], int length);

/*================================*/

#endif