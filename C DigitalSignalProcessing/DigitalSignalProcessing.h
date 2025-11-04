// Digial Signal Processing Library, for processing signals
// Header file
// by Ambesiwe Sonka and Neo Vorsatz
// Last updated: 28 August 2025

#ifndef DIGITALSIGNALPROCESSING_H
#define DIGITALSIGNALPROCESSING_H

/* ELECTRICITY ================================*/

//Returns the Direct-Current component of a signal
double dsDC(double signal[], char length);

//Removes the Direct-Current offset from a signal
void dsAC(double write[], double signal[], char length);

//Gets the power of the signal at each time step
void dsPower(double write[], double signal[], char length);

//Returns the total energy of a signal
double dsEnergy(double signal[], char length);

//Gets the cumulative sum of energy of a signal
void dsCumSumEnergy(double write[], double signal[], char length);

//Returns the average power of a signal
double dsAvgPower(double signal[], char length);

//Returns the Alternating-Current Root-Mean-Square of a signal
double dsACRMS(double signal[], char length);

//Returns the Root-Mean-Square of a signal
double dsRMS(double signal[], char length);

//Returns the Direct-Current power of a signal
double dsDCPower(double signal[], char length);

//Returns the Alternating-Current power of a signal
double dsACPower(double signal[], char length);

/*================================*/
/* FOURIER ================================*/



/*================================*/

#endif