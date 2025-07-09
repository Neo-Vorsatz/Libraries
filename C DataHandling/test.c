// Programme to test the data handling library; DataHandling
// by Ambesiwe Sonka and Neo Vorsatz
// Last updated: 9 July 2025

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

  //Testing standard deviation
  printf("Standard deviation: %.3f\n", dhStdDev(testData, length)); 

  printf("=== Fourier ===");
}