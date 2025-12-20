# C ComplexNumbers [Warning: Untested]
## Credits
This module was made with the help of [Ambesiwe Sonka](https://github.com/Ambesiwe).

## Overview
This module is for complex number operations in C.<br>
With it, you can create, edit, and do computations with complex numbers, including but not limited to:
- Getting the magnitude of a complex number
- Complex number multiplication
- Getting the conjugate of a complex number
- Euler's formula

Note: All angles are measured in radians.

In this folder, test.c was made to test the module.<br>
It can also be used as a reference to see how the module was intended to be used.

## How To Use
Copy the header and implementation files anywhere where your C-compiler can find it (usually at the standard directory or in the same directory as your main file). Then import the module like you would any other module, using `#include`.

## Data Structures
### Complex Number
This is a struct containing two variables that determine the value the complex number, as well as whether these variables represents rectangular or polar form. Create a complex number like you would any other struct:<br>
`complex myComplexNum;`<br>
then myComplexNum will be a complex struct.

## Functions
### Creating
`complex cnRect(double real, double imag);`<br>
Takes the real part of the complex number, and the imaginary part of the complex number.<br>
Returns a complex number in rectangular form.

`complex cnPolar(double mag, double phase);`<br>
Takes the magnitude of the complex number, and the phase of the complex number.<br>
Returns a complex number in polar form.

`complex cnR(double real);`<br>
Takes the real part of the complex number.<br>
Returns a complex number in rectangular form, with only a real component.

`complex cnI(double imag);`<br>
Takes the imaginary part of the complex number.<br>
Returns a complex number in rectangular form, with only an imaginary component.

`complex cnA(double arg);`<br>
Takes the argument of the complex number.<br>
Returns a complex number in polar form, with magnitude 1.

### Reading
`double cnReal(complex complexNum);`<br>
Takes a complex number.<br>
Returns the real component of a complex number.

`double cnImag(complex complexNum);`<br>
Takes a complex number.<br>
Returns the imaginary component of a complex number.

`double cnMod(complex complexNum);`<br>
Takes a complex number.<br>
Returns the magnitude of a complex number.

`double cnArg(complex complexNum);`<br>
Takes a complex number.<br>
Returns the argument of a complex number.

`cnBoolean_t cnIsRect(complex complexNum);`<br>
Takes a complex number.<br>
Returns whether or not a complex number is in rectangular form.

`cnBoolean_t cnIsPolar(complex complexNum);`<br>
Takes a complex number.<br>
Returns whether or not a complex number is in polar form.

### Updating
`void cnSetReal(complex* complexNum, double real);`<br>
Sets the real component of a complex number.<br>
Takes a complex number, and the new real component of the complex number.

`void cnSetImag(complex* complexNum, double imag);`<br>
Sets the imaginary component of a complex number.<br>
Takes a complex number, and the new imaginary component of the complex number.

`void cnSetMag(complex* complexNum, double mag);`<br>
Sets the magnitude of a complex number.<br>
Takes a complex number, and the new magnitude of the complex number.

`void cnSetArg(complex* complexNum, double arg);`<br>
Sets the argument of a complex number.<br>
Takes a complex number, and the new argument of the complex number.

`void cnSetForm(complex* complexNum, cnBoolean_t rect);`<br>
Sets whether or not a complex number is in rectangular form.<br>
Warning: This changes the value of the complex number.<br>
Takes a complex number, and whether or not the complex number is set to rectangular form, else polar form.

### Operations
`complex cnRectForm(complex complexNum);`<br>
Takes a complex number.<br>
Returns the complex number in rectangular form.

`complex cnPolarForm(complex complexNum);`<br>
Takes a complex number.<br>
Returns the complex number in polar form.

`complex cnAdd(complex complexNum1, complex complexNum2);`<br>
Takes a complex number, and another complex number.<br>
Returns the sum of two complex numbers.

`complex cnSub(complex complexNum1, complex complexNum2);`<br>
Takes a complex number, and another complex number.<br>
Returns the difference of two complex numbers.

`complex cnScale(complex complexNum, double scalar);`<br>
Takes a complex number, and a real scalar.<br>
Returns the complex number multiplied by a scalar.

`complex cnMultiply(complex complexNum1, complex complexNum2);`<br>
Takes a complex number, and another complex number.<br>
Returns the product of two complex numbers.

`complex cnDivide(complex complexNum1, complex complexNum2);`<br>
Takes a complex number, and another complex number.<br>
Returns the quotient of two complex numbers.

`complex cnConjugate(complex complexNum);`<br>
Takes a complex number.<br>
Returns the conjugate of the complex number.

`complex cnExp(complex complexNum);`<br>
Takes a complex number.<br>
Returns e raised to the power of a complex number (Euler's formula).

`double cnPrincipleArg(double angle);`<br>
Takes an angle.<br>
Returns the principle argument of an angle.