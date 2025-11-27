// Digial Signal Processing Library, for processing signals
// Header file
// by Ambesiwe Sonka and Neo Vorsatz
// Last updated: 27 November 2025

#ifndef DIGITALSIGNALPROCESSING_H
#define DIGITALSIGNALPROCESSING_H

/* ELECTRICITY ================================*/

/**
  @brief Returns the Direct-Current component of a signal
  
  @param signal A pointer to the array of the signal
  @param length The number of samples
*/
double dsDC(double signal[], int length);

/**
  @brief Removes the Direct-Current offset from a signal
  
  @param write A pointer to where the modified signal will be written
  @param signal A pointer to the array of the signal
  @param length The number of samples
*/
void dsAC(double write[], double signal[], int length);

/**
  @brief Gets the power of the signal at each time step
  
  @param write A pointer to where the power of the signal will be written
  @param signal A pointer to the array of the signal
  @param length The number of samples
*/
void dsPower(double write[], double signal[], int length);

/**
  @brief Returns the total energy of a signal
  
  @param signal A pointer to the array of the signal
  @param length The number of samples
*/
double dsEnergy(double signal[], int length);

/**
  @brief Gets the cumulative sum of energy of a signal
  
  @param write A pointer to where the cumulative sum of energy will be written
  @param signal A pointer to the array of the signal
  @param length The number of samples
*/
void dsCumSumEnergy(double write[], double signal[], int length);

/**
  @brief Returns the average power of a signal
  
  @param signal A pointer to the array of the signal
  @param length The number of samples
*/
double dsAvgPower(double signal[], int length);

/**
  @brief Returns the Alternating-Current Root-Mean-Square of a signal
  
  @param signal A pointer to the array of the signal
  @param length The number of samples
*/
double dsACRMS(double signal[], int length);

/**
  @brief Returns the Root-Mean-Square of a signal
  
  @param signal A pointer to the array of the signal
  @param length The number of samples
*/
double dsRMS(double signal[], int length);

/**
  @brief Returns the Direct-Current power of a signal
  
  @param signal A pointer to the array of the signal
  @param length The number of samples
*/
double dsDCPower(double signal[], int length);

/**
  @brief Returns the Alternating-Current power of a signal
  
  @param signal A pointer to the array of the signal
  @param length The number of samples
*/
double dsACPower(double signal[], int length);

/*================================*/
/* FOURIER ================================*/



/*================================*/

#endif