// Data Handling Library, for processing data
// Implementation file
// by Neo Vorsatz
// Last updated: 2 December 2025

#include <math.h>
#include "DataHandling.h"

/* SUMMING ================================*/

//Returns the sum of an array of data values
double dhSum(double data[], int length) {
  //Initialise the sum
  double sum = 0.0;
  //For each data point
  for (int i=0; i<length; i++) {
    //Add the data point to the sum
    sum += data[i];
  }
  //Return the sum
  return sum;
}

//Gets the cumulative sum of an array of data values
void dhCumSum(double write[], double data[], int length) {
  //Initialise the sum
  double sum = 0.0;
  //For each data point
  for (int i=0; i<length; i++) {
    //Add the data point to the sum
    sum += data[i];
    //Write the cumulative sum to the corresponding index
    write[i] = sum;
  }
}

/*================================*/
/* SORTING ================================*/

//Copies an array of data into another array
void dhCopy(double write[], double data[], int length) {
  //If the pointers aren't identical
  if (write!=data) {
    //For each data point
    for (int i=0; i<length; i++) {
      //Copy the data point
      write[i] = data[i];
    }
  } 
}

//Recursive function used in Quick Sort
static void qsort_recursive(double array[], int low, int high) {
  if (low<high) {
    //Choose last element in the range as the pivot
    double pivot = array[high];
    //Index of the new partition
    int part_i = low;
    //For each element within the partition range, except the last element
    for (int i=low; i<high; i++) {
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

//Sorts an array of data in ascending order using the Quick Sort algorithm
void dhQuickSort(double write[], double data[], int length) {
  //Copy the contents from the source to the destination
  dhCopy(write, data, length);
  //Call the recursive function
  qsort_recursive(write, 0, length-1);
}

//Recursive function used in Merge Sort
static void msort_recursive(double array[], double temp[], int low, int high) {
  //If the range is not empty
  if (low<high) {
    //Calculate the midpoint
    int mid = (low+high)/2;
    //Recursively sort the first half of elements
    msort_recursive(array, temp, low, mid);
    //Recursively sort the second half of elements
    msort_recursive(array, temp, mid+1, high);
    
    //Index for the first half
    int i_1st = low;
    //Index fo the second half
    int i_2nd  = mid+1;
    //Index for the merged array
    int i_merge = low;
    //While both first and second arrays have elements left
    while (i_1st<=mid && i_2nd<=high) {
      //If the first half has a smaller element than the second
      if (array[i_1st] < array[i_2nd]) {
        //Add the element from the first half
        temp[i_merge++] = array[i_1st++];
      } else {
        //Add the element from the second half
        temp[i_merge++] = array[i_2nd++];
      }
    }
    //While there are remaining elements from the first half
    while (i_1st<=mid) {
      //Add the element from the first half
      temp[i_merge++] = array[i_1st++];
    }
    //While there are remaining elements from the second half
    while (i_2nd<=high) {
      //Add the element from the second half
      temp[i_merge++] = array[i_2nd++];
    }

    //For each element in the sorted array
    for (int i=low; i<=high; i++) {
      //Copy the element into the original array
      array[i] = temp[i];
    }
  }
}

//Sorts an array of data in ascending order using the Merge Sort algorithm
void dhMergeSort(double write[], double data[], int length) {
  //Copy the contents from the source to the destination
  dhCopy(write, data, length);
  //Create temporary array for merging
  double temp[length];
  //Call the recursive function
  msort_recursive(write, temp, 0, length-1);
}

//Reverses the elements in an array
void dhReverse(double write[], double data[], int length) {
  //Create temporary array for reversing
  double temp[length];
  //For each element in the original array
  for (int i=0; i<length; i++) {
    //Copy the element from the original array to the temporary array
    temp[length-1-i] = data[i];
  }
  //For each element in the temporary array
  for (int i=0; i<length; i++) {
    //Copy the element from the temporary array to the output
    write[i] = temp[i];
  }
}

/*================================*/
/* STATISTICS ================================*/

//Returns the smallest value in an array of data values
double dhMin(double data[], int length) {
  //If there are no elements
  if (length<1) {
    //Return 0 as the minimum
    return 0;
  }

  //Assume the minimum is the first value
  double min = data[0];
  //For each data point other than the first
  for (int i=1; i<length; i++) {
    //If this value is less than the minimum
    if (data[i]<min) {
      //Update the minimum
      min = data[i];
    }
  }
  return min;
}

//Returns the largest value in an array of data values
double dhMax(double data[], int length) {
  //If there are no elements
  if (length<1) {
    //Return 0 as the maximum
    return 0;
  }

  //Assume the maximum is the first value
  double max = data[0];
  //For each data point other than the first
  for (int i=1; i<length; i++) {
    //If this value is more than the maximum
    if (data[i]>max) {
      //Update the maximum
      max = data[i];
    }
  }
  return max;
}

//Returns the mean/average/expected value of an array of data values
double dhMean(double data[], int length) {
  //Get the sum
  double sum = dhSum(data, length);
  //Return the average
  return sum/length;
}

//Returns the mean/average/expected value of an array of data values
double dhAvg(double data[], int length) {
  //Call the dhMean function
  return dhMean(data, length);
}

//Returns the mean/average/expected value of an array of data values
double dhExpectedValue(double data[], int length) {
  //Call the dhMean function
  return dhMean(data, length);
}

//Returns the varience of an array of data values, assuming the data represents the population
double dhVar(double data[], int length) {
  //Initialise an array of square-differences
  double sqrDiff[length];
  //Get the mean/average/expected value
  double mean = dhMean(data, length);
  //For each data point
  for (int i=0; i<length; i++) {
    //Get the difference
    double diff = data[i]-mean;
    //Save the squared difference
    sqrDiff[i] = diff*diff;
  }
  //Return the mean/average/expected value of the squared difference
  return dhMean(sqrDiff, length);
}

//Returns the standard deviance of an array of data values, assuming the data represents the population
double dhStdDev(double data[], int length) {
  //The standard deviance is the square-root of the variance
  return sqrt(dhVar(data, length));
}

//Returns the median of an array of data values
double dhMedian(double data[], int length) {
  //If there are no elements
  if (length<1) {
    //Return 0 as the median
    return 0;
  }

  //Find the middle index
  int middle = length/2;
  //Declare an array for the sorted data
  double sortedData[length];
  //Sort the data
  dhMergeSort(sortedData, data, length);
  //If there are an even number of data values
  if (length%2==0) {
    //Calculate the median
    double median = (sortedData[middle-1]+sortedData[middle])/2;
    //Return the median
    return median;
  }
  //Return the value at the middle index
  return sortedData[middle];
}

//Returns the lower quartile of an array of data values
double dhLowerQuartile(double data[], int length) {
  //If there are no elements
  if (length<1) {
    //Return 0 as the median
    return 0;
  }
  //If there's only 1 element
  if (length<2) {
    //Return the only element
    return data[0];
  }

  //Find the middle index
  int middle = length/2;
  //Declare an array for the sorted data
  double sortedData[length];
  //Sort the data
  dhMergeSort(sortedData, data, length);
  //Return the median of the lower half of data
  return dhMedian(sortedData, middle);
}

//Returns the upper quartile of an array of data values
double dhUpperQuartile(double data[], int length) {
  //If there are no elements
  if (length<1) {
    //Return 0 as the median
    return 0;
  }
  //If there's only 1 element
  if (length<2) {
    //Return the only element
    return data[0];
  }

  //Find the middle index
  int middle = length/2;
  //Declare an array for the sorted data
  double sortedData[length];
  //Sort the data
  dhMergeSort(sortedData, data, length);
  //Find the starting index of the upper half of data
  double* start = sortedData+middle;
  //If there are an odd number of data values
  if (length%2!=0) {
    //Skip over the middle value (median)
    start++;
  }
  //Return the median of the upper half of data
  return dhMedian(start, middle);
}

/*================================*/