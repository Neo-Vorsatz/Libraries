# C DataHandling
## Credits
This module was made with the help of Ambesiwe Sonka.

## Overview
Some functionality this module offers is:
- Getting the mean, variance and standard deviation of a set of data
- Getting the cumulative sum of data

In this folder, test.c was made to test the module.<br>
It can also be used as a reference to see how the module was intended to be used.

## How To Use
Copy the header and implementation files anywhere where your C-compiler can find it (usually at the standard directory or in the same directory as your main file). Then import the module like you would any other module, using `#include`.

## Functions
### Statistics
`double dhSum(double data[], char length);`<br>
Takes a pointer to the array of data values, and the number of the data values.<br>
Returns the sum of an array of data values.

`double dhMean(double data[], char length);`<br>
Takes a pointer to the array of data values, and the number of the data values.<br>
Returns the mean/average/expected value of an array of data values.

`double dhAvg(double data[], char length);`<br>
Does the same thing as the `dhMean` function.<br>
Takes a pointer to the array of data values, and the number of the data values.<br>
Returns the mean/average/expected value of an array of data values.

`double dhExpectedValue(double data[], char length);`<br>
Does the same thing as the `dhMean` function.<br>
Takes a pointer to the array of data values, and the number of the data values.<br>
Returns the mean/average/expected value of an array of data values.

`void dhCumSum(double write[], double data[], char length);`<br>
Gets the cumulative sum of an array of data values.<br>
Takes a pointer to where the cumulative sum will be written, a pointer to the array of data values, and the number of the data values.

`double dhVar(double data[], char length);`<br>
Takes a pointer to the array of data values, and the number of the data values.<br>
Returns the varience of an array of data values.

`double dhSqrt(double value);`
Takes the value that must be square-rooted.<br>
Returns the square-root of a value.

`double dhStdDev(double data[], char length);`<br>
Takes a pointer to the array of data values, and the number of the data values.<br>
Returns the standard deviance of an array of data values.

### Fourier