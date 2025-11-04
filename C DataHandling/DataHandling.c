// Data Handling Library, for processing data
// Implementation file
// by Ambesiwe Sonka and Neo Vorsatz
// Last updated: 4 November 2025

#include <math.h>
#include "DataHandling.h"

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