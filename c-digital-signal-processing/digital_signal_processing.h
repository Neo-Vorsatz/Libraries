// Digial Signal Processing Library, for processing signals
// Header file
// by Neo Vorsatz
// Last updated: 26 December 2025

//Header guard
#ifndef DIGITAL_SIGNAL_PROCESSING_H
#define DIGITAL_SIGNAL_PROCESSING_H

//C++ compatibility
#ifdef __cplusplus
  extern "C" {
#endif

/* TYPE DEFINITIONS ================================*/

//Structure for signals
typedef struct{
  double *samples; //pointer to array of samples
  unsigned int used_len; //number of samples
  unsigned int max_len; //maximum number of samples
} signal;

//Structure for a system
typedef struct{
  signal imp_resp; //impulse response
  signal history; //past inputs
} system;

/*================================*/
/* ELECTRICITY ================================*/

/**
 * @param signal A pointer to the array of the signal
 * @param length The number of samples
 * 
 * @return The Direct-Current component of a signal
 */
double dsDC(double signal[], unsigned int length);

/**
 * @brief Removes the Direct-Current offset from a signal
 * 
 * @param write A pointer to where the modified signal will be written
 * @param signal A pointer to the array of the signal
 * @param length The number of samples
 */
void dsAC(double write[], double signal[], unsigned int length);

/**
 * @brief Gets the power of the signal at each time step
 * 
 * @param write A pointer to where the power of the signal will be written
 * @param signal A pointer to the array of the signal
 * @param length The number of samples
 */
void dsPower(double write[], double signal[], unsigned int length);

/**
 * @param signal A pointer to the array of the signal
 * @param length The number of samples
 * 
 * @return The total energy of a signal
 */
double dsEnergy(double signal[], unsigned int length);

/**
 * @brief Gets the cumulative sum of energy of a signal
 * 
 * @param write A pointer to where the cumulative sum of energy will be written
 * @param signal A pointer to the array of the signal
 * @param length The number of samples
 */
void dsCumSumEnergy(double write[], double signal[], unsigned int length);

/**
 * @param signal A pointer to the array of the signal
 * @param length The number of samples
 * 
 * @return The average power of a signal
 */
double dsAvgPower(double signal[], unsigned int length);

/**
 * @param signal A pointer to the array of the signal
 * @param length The number of samples
 * 
 * @return The Alternating-Current Root-Mean-Square of a signal
 */
double dsACRMS(double signal[], unsigned int length);

/**
 * @param signal A pointer to the array of the signal
 * @param length The number of samples
 * 
 * @return The Root-Mean-Square of a signal
 */
double dsRMS(double signal[], unsigned int length);

/**
 * @param signal A pointer to the array of the signal
 * @param length The number of samples
 * 
 * @return The Direct-Current power of a signal
 */
double dsDCPower(double signal[], unsigned int length);

/**
 * @param signal A pointer to the array of the signal
 * @param length The number of samples
 * 
 * @return The Alternating-Current power of a signal
 */
double dsACPower(double signal[], unsigned int length);

/*================================*/
/* FOURIER ================================*/



/*================================*/

#ifdef __cplusplus
  }
#endif

#endif