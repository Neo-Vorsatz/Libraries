# C DigitalSignalProcessing [Warning: In Production]
## Credits
This module was made with the help of [Ambesiwe Sonka](https://github.com/Ambesiwe).

## Overview
Some functionality this module offers is:
- Getting the DC or AC components of a signal
- Getting the energy and power of a signal
- Bringing a signal to and from the frequency domain (Fourier)

In this folder, test.c was made to test the module.<br>
It can also be used as a reference to see how the module was intended to be used.

## How To Use
Copy the header and implementation files anywhere where your C-compiler can find it (usually at the standard directory or in the same directory as your main file). Then import the module like you would any other module, using `#include`.<br>
This module requires the DataHandling and ComplexNumbers modules to work. It's recommended that you edit the include-path in the implementation file to find where you have your copy of the DataHandling and ComplexNumbers modules.

## Functions
### Electricity
`double dhDC(double signal[], int length);`<br>
Takes a pointer to the array of the signal, and the number of time steps.<br>
Returns the Direct-Current component of a signal.

`void dhAC(double write[], double signal[], int length);`<br>
Removes the Direct-Current offset from a signal.<br>
Takes a pointer to where the modified signal will be written, a pointer to the array of the signal, and the number of time steps.

`void dhPower(double write[], double signal[], int length);`<br>
Gets the power of the signal at each time step.<br>
Takes a pointer to where the power of the signal will be written, a pointer to the array of the signal, and the number of time steps.

`double dhEnergy(double signal[], int length);`<br>
Takes a pointer to the array of the signal, and the number of time steps.<br>
Returns the total energy of a signal.

`void dhCumSumEnergy(double write[], double signal[], int length);`<br>
Gets the cumulative sum of energy of a signal.<br>
Takes a pointer to where the cumulative sum of energy will be written, a pointer to the array of the signal, and the number of time steps.

`double dhAvgPower(double signal[], int length);`<br>
Takes a pointer to the array of the signal, and the number of time steps.<br>
Returns the average power of a signal.

`double dhACRMS(double signal[], int length);`<br>
Takes a pointer to the array of the signal, and the number of time steps.<br>
Returns the Alternating-Current Root-Mean-Square of a signal.

`double dhRMS(double signal[], double length);`<br>
Takes a pointer to the array of the signal, and the number of time steps.<br>
Returns the Root-Mean-Square of a signal.

`double dhDCPower(double signal[], int length);`<br>
Takes a pointer to the array of the signal, and the number of time steps.<br>
Returns the Direct-Current power of a signal.

`double dhACPower(double signal[], int length);`<br>
Takes a pointer to the array of the signal, and the number of time steps.<br>
Returns the Alternating-Current power of a signal.

### Fourier