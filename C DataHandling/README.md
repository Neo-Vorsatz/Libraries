# C DataHandling [Warning: In Production]
## Overview
Some functionality this module offers is:
- Getting the mean, variance and standard deviation of a set of data
- Getting the cumulative sum of data
- Sorting data in ascending order, or reversing the order

In this folder, test.c was made to test the module.<br>
It can also be used as a reference to see how the module was intended to be used.

## How To Use
Copy the header and implementation files anywhere where your C-compiler can find it (usually at the standard directory or in the same directory as your main file). Then import the module like you would any other module, using `#include`.<br>

## Functions
### Summing
`double dhSum(double data[], int length);`<br>
Takes a pointer to the array of data values, and the number of the data values.<br>
Returns the sum of an array of data values.

`void dhCumSum(double write[], double data[], int length);`<br>
Gets the cumulative sum of an array of data values.<br>
Takes a pointer to where the cumulative sum will be written, a pointer to the array of data values, and the number of data values.

### Statistics
`double dhMean(double data[], int length);`<br>
Takes a pointer to the array of data values, and the number of the data values.<br>
Returns the mean/average/expected value of an array of data values.

`double dhAvg(double data[], int length);`<br>
Does the same thing as the `dhMean` function.<br>
Takes a pointer to the array of data values, and the number of the data values.<br>
Returns the mean/average/expected value of an array of data values.

`double dhExpectedValue(double data[], int length);`<br>
Does the same thing as the `dhMean` function.<br>
Takes a pointer to the array of data values, and the number of the data values.<br>
Returns the mean/average/expected value of an array of data values.

`double dhVar(double data[], int length);`<br>
Takes a pointer to the array of data values, and the number of the data values.<br>
Returns the varience of an array of data values.

`double dhStdDev(double data[], int length);`<br>
Takes a pointer to the array of data values, and the number of the data values.<br>
Returns the standard deviance of an array of data values.

### Sorting
`void dhCopy(double write[], double data[], int length);`<br>
Copies an array of data into another array.<br>
Takes a pointer to where the copy will be written, a pointer to the array of data values, and the number of data values.

`void dhQuickSort(double write[], double data[], int length);`<br>
Sorts an array of data in ascending order using the Quick Sort algorithm.<br>
Takes a pointer to where the sorted data will be written, a pointer to the array of data values, and the number of data values.

`void dhMergeSort(double write[], double data[], int length);`<br>
Sorts the data in ascending order using the Merge Sort algorithm.<br>
Takes a pointer to where the sorted data will be written, a pointer to the array of data values, and the number of data values.

`void dhReverse(double write[], double data[], int length);`<br>
Reverses the elements in an array.<br>
Takes a pointer to where the reversed array will be written, a pointer to the array of data values, and the number of data values.