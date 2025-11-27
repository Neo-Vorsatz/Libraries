// Programme to test the data handling library; DataHandling
// by Neo Vorsatz
// Last updated: 27 November 2025

#include "DataHandling.c"
#include <stdio.h>

void printData(double data[], int length) {
    printf("{");
    for (int i=0; i<length-1; i++) {
        printf("%.3f, ", data[i]);
    }
    printf("%.3f}", data[length-1]);
}

int main() {
  double testData[] = {1.0, 5.2, 7.3, 0.0, 2.9, 5.2, 13.4};
  int length = sizeof(testData)/sizeof(testData[0]);
  printf("Test data: ");
  printData(testData, length);
  printf("\n");
  double temp[length];

  printf("=== Summing ===\n");

  //Testing summation
  printf("Sum of values: %.3f | expected: 35\n", dhSum(testData, length));

  //Testing cumulative summation
  dhCumSum(temp, testData, length);
  printf("Cumulative sum: ");
  printData(temp, length);
  printf("\n");

  printf("=== Statistics ===\n");

  //Testing mean/average/expected value
  printf("Mean/average/expected value: %.3f, %.3f, %.3f | expected: 5\n",
    dhMean(testData, length), dhAvg(testData, length), dhExpectedValue(testData, length));

  //Testing variance
  printf("Variance: %.3f | expected: 17.334\n", dhVar(testData, length));

  //Testing standard deviation
  printf("Standard deviation: %.3f | expected: 4.163\n", dhStdDev(testData, length)); 

  printf("=== Sorting ===\n");

  //Testing copying
  dhCopy(temp, testData, length);
  printf("Copy of data: ");
  printData(temp, length);
  printf("\n");

  //Testing quick sort
  dhQuickSort(temp, testData, length);
  printf("Quick sort: ");
  printData(temp, length);
  printf("\n");

  //Testing merge sort
  dhMergeSort(temp, testData, length);
  printf("Merge sort: ");
  printData(temp, length);
  printf("\n");

  //Testing reversing
  dhReverse(temp, testData, length);
  printf("Reversed: ");
  printData(temp, length);
  printf("\n");

}