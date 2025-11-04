// Data Handling Library, for processing data
// Implementation file
// by Neo Vorsatz
// Last updated: 4 November 2025

#include <math.h>
#include "DataHandling.h"

/* SUMMING ================================*/

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

/*================================*/
/* STATISTICS ================================*/

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
/* SORTING ================================*/

//Copies an array of data into another array
void dhCopy(double write[], double data[], char length) {
  //If the pointers aren't identical
  if (write!=data) {
    //For each data point
    for (char i=0; i<length; i++) {
      //Copy the data point
      write[i] = data[i];
    }
  } 
}

//Recursive function used in Quick Sort
static void qsort_recursive(double array[], char low, char high) {
  if (low<high) {
    //Choose last element in the range as the pivot
    char pivot = array[high];
    //Index of the new partition
    char part_i = low;
    //For each element within the partition range, except the last element
    for (char i=low; i<high; i++) {
      //If this element is smaller than the pivot
      if (array[i]<pivot) {
        //Place this element left of the new partition, via a swap
        double temp = array[part_i];
        array[part_i] = array[i];
        array[i] = temp;
        //Increment the index of the new partition
        part_i++;
      }
    }
    //Place the pivot at the new partition, via a swap
    array[high] = array[part_i];
    array[part_i] = pivot;
    //Recursively sort the elements before the pivot
    qsort_recursive(array, low, part_i-1);
    //Recursively sort the elements after the pivot
    qsort_recursive(array, part_i+1, high);
  }
}

//Sorts the data in ascending order using the Quick Sort algorithm
void dhQuickSort(double write[], double data[], char length) {
  //Copy the contents from the source to the destination
  dhCopy(write, data, length);
  //Call the recursive function
  qsort_recursive(write, 0, length-1);
}

/*================================*/