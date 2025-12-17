// Digial Signal Processing Library, for processing signals
// Header file
// by Ambesiwe Sonka and Neo Vorsatz
// Last updated: 17 December 2025

#ifndef DIGITALSIGNALPROCESSING_H
#define DIGITALSIGNALPROCESSING_H

/* ELECTRICITY ================================*/

/**
 * @param signal A pointer to the array of the signal
 * @param length The number of samples
 * 
 * @return The Direct-Current component of a signal
 */
double dsDC(double signal[], int length);

/**
 * @brief Removes the Direct-Current offset from a signal
 * 
 * @param write A pointer to where the modified signal will be written
 * @param signal A pointer to the array of the signal
 * @param length The number of samples
 */
void dsAC(double write[], double signal[], int length);

/**
 * @brief Gets the power of the signal at each time step
 * 
 * @param write A pointer to where the power of the signal will be written
 * @param signal A pointer to the array of the signal
 * @param length The number of samples
 */
void dsPower(double write[], double signal[], int length);

/**
 * @param signal A pointer to the array of the signal
 * @param length The number of samples
 * 
 * @return The total energy of a signal
 */
double dsEnergy(double signal[], int length);

/**
 * @brief Gets the cumulative sum of energy of a signal
 * 
 * @param write A pointer to where the cumulative sum of energy will be written
 * @param signal A pointer to the array of the signal
 * @param length The number of samples
 */
void dsCumSumEnergy(double write[], double signal[], int length);

/**
 * @param signal A pointer to the array of the signal
 * @param length The number of samples
 * 
 * @return The average power of a signal
 */
double dsAvgPower(double signal[], int length);

/**
 * @param signal A pointer to the array of the signal
 * @param length The number of samples
 * 
 * @return The Alternating-Current Root-Mean-Square of a signal
 */
double dsACRMS(double signal[], int length);

/**
 * @param signal A pointer to the array of the signal
 * @param length The number of samples
 * 
 * @return The Root-Mean-Square of a signal
 */
double dsRMS(double signal[], int length);

/**
 * @param signal A pointer to the array of the signal
 * @param length The number of samples
 * 
 * @return The Direct-Current power of a signal
 */
double dsDCPower(double signal[], int length);

/**
 * @param signal A pointer to the array of the signal
 * @param length The number of samples
 * 
 * @return The Alternating-Current power of a signal
 */
double dsACPower(double signal[], int length);

/*================================*/
/* FOURIER ================================*/



/*================================*/

#endif