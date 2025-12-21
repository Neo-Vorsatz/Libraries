// Programme to test the complex numbers library; ComplexNumbers
// by Neo Vorsatz
// Last updated: 21 December 2025

#include "complexnumbers.c"
#include <stdio.h>

void printComplex(complex complexNum) {
  if (complexNum.rect_form) {
    if (complexNum.imag_arg < 0) {
      printf("%.3f%.3fi", complexNum.real_mod, complexNum.imag_arg); //Print without adding a '+'
    } else {
      printf("%.3f+%.3fi", complexNum.real_mod, complexNum.imag_arg); //Print while adding a '+'
    }
    
  } else {
    printf("%.3f<%.3f", complexNum.real_mod, complexNum.imag_arg);
  }
}

int main() {
  complex c0;
  complex c1;
  complex c2;

  printf("=== Creating ===\n");

  //Testing creating rectangular complex numbers
  c1 = cnRect(1, 2);
  printf("Rectangular complex number: ");
  printComplex(c1);
  printf(" | expected: 1+2i\n");

  //Testing creating polar complex numbers
  c2 = cnPolar(3, 4);
  printf("Polar complex number: ");
  printComplex(c2);
  printf(" | expected: 3<-2.283\n");

  //Testing creating purely real numbers
  c0 = cnR(5);
  printf("Purely real number: ");
  printComplex(c0);
  printf(" | expected: 5+0i\n");

  //Testing creating purely imaginary numbers
  c0 = cnI(6);
  printf("Purely imaginary number: ");
  printComplex(c0);
  printf(" | expected: 0+6i\n");

  //Testing creating imagninary numbers with magnitude 1
  c0 = cnA(-3.14159265358979323846); //-PI or -180 degrees
  printf("Complex number with magnitude 1: ");
  printComplex(c0);
  printf(" | expected: 1<3.142\n");

  printf("=== Reading ===\n");

  //Testing getting real component
  printf("Real component: %.3f | expected: -1.961\n", cnReal(c2));

  //Testing getting imaginary component
  printf("Imaginary component: %.3f | expected: -2.270\n", cnImag(c2));

  //Testing getting magnitude/modulus
  printf("Magnitude/Modulus: %.3f | expected: 2.236\n", cnMag(c1));

  //Testing getting argument
  printf("Argument: %.3f | expected: 1.107\n", cnArg(c1));

  //Testing getting form
  if (cnIsRect(c1)) {
    printf("Determined rectangular form as rectangular. (Yay)\n");
  }
  if (cnIsPolar(c1)) {
    printf("Determined rectangular form as polar. (Oops)\n");
  }
  if (cnIsRect(c2)) {
    printf("Determined polar form as rectangular. (Oops)\n");
  }
  if (cnIsPolar(c2)) {
    printf("Determined polar form as polar. (Yay)\n");
  }

  printf("=== Updating ===\n");

  //Testing setting real and imaginary components
  cnSetReal(&c2, -2);
  cnSetImag(&c2, 2);
  printf("Setting rectangular: ");
  printComplex(c2);
  printf(" | expected: 2.828<2.356\n");

  //Testing setting magnitude and argument
  cnSetMag(&c1, 2);
  cnSetArg(&c1, -0.5235987756); //-PI/6 or -30 degrees
  printf("Setting polar: ");
  printComplex(c1);
  printf(" | expected: 1.732-1i\n");

  //Testing setting form
  cnSetForm(&c2, 1);
  printf("Forced rectangular: ");
  printComplex(c2);
  printf(" | expected: 2.828+2.356i\n");
  cnSetForm(&c1, 0);
  printf("Forced polar: ");
  printComplex(c1);
  printf(" | expected: 1.732<-1\n");

  printf("=== Operations ===\n");

  c1 = cnPolar(5, 0.927295218); //3+4i
  c2 = cnRect(1, 2);
  
  //Testing converting to rectangular form
  c1 = cnRectForm(c1);
  printf("Rectangular form: ");
  printComplex(c1);
  printf(" | expected: 3+4i\n");

  //Testing converting to polar form
  c2 = cnPolarForm(c2);
  printf("Polar form: ");
  printComplex(c2);
  printf(" | expected: 2.236<1.107\n");
  
  //Testing addition
  c0 = cnAdd(c1, c2);
  printf("Addition: ");
  printComplex(c0);
  printf(" | expected: 4+6i\n");

  //Testing subtraction
  c0 = cnSub(c1, c2);
  printf("Subtraction: ");
  printComplex(c0);
  printf(" | expected: 2+2i\n");

  //Testing scaling
  c0 = cnScale(c1, 3);
  printf("Scaling: ");
  printComplex(c0);
  printf(" | expected: 9+12i\n");

  //Testing multiplication
  c0 = cnMultiply(c1, c2);
  printf("Rect multiplication: ");
  printComplex(c0);
  printf(" | expected: -5+10i\n");
  c0 = cnMultiply(c2, c1);
  printf("Polar multiplication: ");
  printComplex(c0);
  printf(" | expected: 11.180<2.034\n");

  //Testing division
  c0 = cnDivide(c1, c2);
  printf("Division: ");
  printComplex(c0);
  printf(" | expected: 2.2-0.4i\n");

  //Testing real power
  c0 = cnPow(c1, 2.5);
  printf("Real power: ");
  printComplex(c0);
  printf(" | expected: -38+41i\n");

  //Testing complex power
  c0 = cnPowComplex(c1, c2);
  printf("Complex power: ");
  printComplex(c0);
  printf(" | expected: -0.420-0.660i\n");

  //Testing conjugate
  c0 = cnConjugate(c1);
  printf("Rect conjugate: ");
  printComplex(c0);
  printf(" | expected: 3-4i\n");
  c0 = cnConjugate(c2);
  printf("Polar conjugate: ");
  printComplex(c0);
  printf(" | expected: 2.236<-1.107\n");

  //Testing exponential
  c0 = cnRect(cnMag(c2), cnArg(c2));
  c0 = cnExp(c0);
  printf("Exponential: ");
  printComplex(c0);
  printf(" | expected: 9.356<1.107\n"); //Same argument as c2

  //Testing natural logarithm
  c0 = cnLog(cnR(-1)); //Euler's identity
  printf("Natural logarithm: ");
  printComplex(c0);
  printf(" | expected: 0+3.142i\n"); //0+PIi

  //Testing principle argument
  printf("Principle argument: %.3f | expected: -1\n", cnPrincipleArg(5.283185307)); //-1+2*PI
}