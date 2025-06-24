//Programme to test the data handling library; DataHandling.c
// by Ambesiwe Sonka and Neo Vorsatz
// Last updated: 24 June 2025

#include "DataHandling.c"
#include <stdio.h>

void printData(double data[], char length) {
    printf("{");
    for (char i=0; i<length-1; i++) {
        printf("%.3f, ", data[i]);
    }
    printf("%.3f}", data[length-1]);
}

int main() {
  printf("=== Statistics ===");
  double testData[] = {1.0, 5.2, 7.3, 0.0, 2.9, 5.2, 13.4};
  char length = sizeof(testData)/sizeof(testData[0]);
  printf("Test data: ");
  printData(testData, length);
  printf("\n");

  //Testing summation
  printf("Sum of values: %.3f\n", dhSum(testData, length));

  //Testing mean/average/expected value
  printf("Mean/average/expected value: %.3f, %.3f, %.3f\n",
    dhMean(testData, length), dhAvg(testData, length), dhExpectedValue(testData, length));

  //Testing cumulative sum
  double cumSum[length];
  dhCumSum(cumSum, testData, length); 
  printf("Cumulative sum: ");
  printData(cumSum, length);
  printf("\n");

  //Testing variance
  printf("Variance: %.3f\n", dhVar(testData, length));

  //Testing square-root
  printf("Square-root of 9, 100, 0, 1, 2: %.3f, %.3f, %.3f, %.3f, %.3f\n",
    dhSqrt(9.0), dhSqrt(100.0), dhSqrt(0.0), dhSqrt(1.0), dhSqrt(2.0));

  //Testing standard deviation
  printf("Standard deviation: %.3f\n", dhStdDev(testData, length));

  printf("=== Fourier ===");
}