# C DataHandling [Warning: In Production]
## Credits
This module was made with the help of Ambesiwe Sonka.

## Overview
Some functionality this module offers is:
- Getting the mean, variance and standard deviation of a set of data
- Getting the cumulative sum of data
- Getting the energy and power of a signal

In this folder, test.c was made to test the module.<br>
It can also be used as a reference to see how the module was intended to be used.

## How To Use
Copy the header and implementation files anywhere where your C-compiler can find it (usually at the standard directory or in the same directory as your main file). Then import the module like you would any other module, using `#include`.<br>
This module requires the ComplexNumbers module to work. It's recommended that you edit the include-path in the implementation file to find where you have your copy of the ComplexNumbers module.

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
Takes a pointer to where the cumulative sum will be written, a pointer to the array of data values, and the number of data values.

`double dhVar(double data[], char length);`<br>
Takes a pointer to the array of data values, and the number of the data values.<br>
Returns the varience of an array of data values.

`double dhStdDev(double data[], char length);`<br>
Takes a pointer to the array of data values, and the number of the data values.<br>
Returns the standard deviance of an array of data values.

### Electricity
`double dhDC(double signal[], char length);`<br>
Does the same thing as the `dhMean` function.<br>
Takes a pointer to the array of the signal, and the number of time steps.<br>
Returns the Direct-Current component of a signal.

`void dhAC(double write[], double signal[], char length);`<br>
Removes the Direct-Current offset from a signal.<br>
Takes a pointer to where the modified signal will be written, a pointer to the array of the signal, and the number of time steps.

`void dhPower(double write[], double signal[], char length);`<br>
Gets the power of the signal at each time step.<br>
Takes a pointer to where the power of the signal will be written, a pointer to the array of the signal, and the number of time steps.

`double dhEnergy(double signal[], char length);`<br>
Takes a pointer to the array of the signal, and the number of time steps.<br>
Returns the total energy of a signal.

`void dhCumSumEnergy(double write[], double signal[], char length);`<br>
Gets the cumulative sum of energy of a signal.<br>
Takes a pointer to where the cumulative sum of energy will be written, a pointer to the array of the signal, and the number of time steps.

`double dhAvgPower(double signal[], char length);`<br>
Takes a pointer to the array of the signal, and the number of time steps.<br>
Returns the average power of a signal.

`double dhACRMS(double signal[], char length);`<br>
Does the same thing as the `dhStdDev` function.<br>
Takes a pointer to the array of the signal, and the number of time steps.<br>
Returns the Alternating-Current Root-Mean-Square of a signal.

`double dhRMS(double signal[], double length);`<br>
Takes a pointer to the array of the signal, and the number of time steps.<br>
Returns the Root-Mean-Square of a signal.

`double dhDCPower(double signal[], char length);`<br>
Takes a pointer to the array of the signal, and the number of time steps.<br>
Returns the Direct-Current power of a signal.

`double dhACPower(double signal[], char length);`<br>
Does the same thing as the `dhVar` function.<br>
Takes a pointer to the array of the signal, and the number of time steps.<br>
Returns the Alternating-Current power of a signal.

### Fourier