// Matrices Library, for matrix operations
// Header file
// by Neo Vorsatz
// Last updated: 9 July 2025

#ifndef MATRIX_H
#define MATRIX_H

/* USER MAY EDIT ================================*/

#define SIZE 4 //Change this value to change the maximum size of your matrices
typedef double mxElement_t; //Change the type of "mxElement_t" to change the numerical data type in your matrices

/*================================*/
/* TYPE DEFINITIONS ================================*/

//Boolean
typedef char boolean_t;

//Structure for matrices
typedef struct {
  unsigned char rows;
  unsigned char columns;
  mxElement_t elements[SIZE][SIZE];
} matrix;

/*================================*/
/* WRITING ================================*/

//Sets the given matrix's values to the parameters
boolean_t mxSet(matrix *write, char rows, char columns, mxElement_t elements[SIZE][SIZE]);

//Copies the second matrix's data onto the first
void mxCopy(matrix *write, matrix *read);

//Sets the number of rows and columns of the given matrix
boolean_t mxSetSize(matrix *write, char rows, char columns);

//Writes an entry into the given row and column of the given matrix
boolean_t mxWriteElement(matrix *write, char row, char column, mxElement_t entry);

//Rewrites the content of a row
boolean_t mxWriteRow_len(matrix *write, char index, mxElement_t *row, char arrLength);

//Rewrites the content of a row (assumes the array length is perfectly sized)
boolean_t mxWriteRow(matrix *write, char index, mxElement_t *row);

//Rewrites the content of a column
boolean_t mxWriteColumn_len(matrix *write, char index, mxElement_t *column, char arrLength);

//Rewrites the content of a column (assumes the array length is perfectly sized)
boolean_t mxWriteColumn(matrix *write, char index, mxElement_t *column);

//Inserts a row of entries into the given index
boolean_t mxInsertRow_len(matrix *write, char index, mxElement_t *row, char arrLength);

//Inserts a row of entries into the given index (assumes the array length is perfectly sized)
boolean_t mxInsertRow(matrix *write, char index, mxElement_t *row);

//Appends a row of entries to the end of the matrix
boolean_t mxAppendRow_len(matrix *write, mxElement_t *row, char arrLength);

//Appends a row of entries to the end of the matrix (assumes the array length is perfectly sized)
boolean_t mxAppendRow(matrix *write, mxElement_t *row);

//Inserts a column of entries into the given index
boolean_t mxInsertColumn_len(matrix *write, char index, mxElement_t *column, char arrLength);

//Inserts a column of entries into the given index (assumes the array length is perfectly sized)
boolean_t mxInsertColumn(matrix *write, char index, mxElement_t *column);

//Appends a column of entries to the end of the matrix
boolean_t mxAppendColumn_len(matrix *write, mxElement_t *column, char arrLength);

//Appends a column of entries to the end of the matrix (assumes the array length is perfectly sized)
boolean_t mxAppendColumn(matrix *write, mxElement_t *column);

//Deletes a row from the matrix
boolean_t mxDeleteRow(matrix *write, char index);

//Deletes a column from the matrix
boolean_t mxDeleteColumn(matrix *write, char index);

/*================================*/
/* READING ================================*/

//Returns the number of rows
char mxGetNumRows(matrix *read);

//Returns the number of columns
char mxGetNumColumns(matrix *read);

//Returns the element in the given row and column
mxElement_t mxReadElement(matrix *read, char row, char column);

/*================================*/
/* OPERATIONS ================================*/

//Checks if two matrices are equal
boolean_t mxEqual(matrix *read1, matrix *read2);

//Empties a matrix
void mxZero(matrix *write);

//Turns a matrix into the identity matrix with a particular size
boolean_t mxIdentity(matrix *write, char size);

//Adds the second matrix to the first
boolean_t mxAdd(matrix *write, matrix *read1, matrix *read2);

//Scales/Multiplies the given matrix by a factor
void mxScale(matrix *write, matrix *read, double factor);

//Multiplies the matrices
boolean_t mxMultiply(matrix *write, matrix *read1, matrix *read2);

//Returns the determinant of the given matrix
mxElement_t mxDeterminant(matrix *read);

//Transposes the given matrix
void mxTranspose(matrix *write, matrix *read);

//Gets the adjoint of the given matrix
boolean_t mxAdjoint(matrix *write, matrix *read);

//Inverts the given matrix
boolean_t mxInverse(matrix *write, matrix *read);

//Solves for a particular element within a particular vector using Cramer's rule
mxElement_t mxSolveCramer(matrix *transform, matrix *result, char vector, char index);

//Solves for all vectors using the inverse of the transformation
boolean_t mxSolveInverse(matrix *write, matrix *transform, matrix *result);

//Turns a matrix into Reduced Row Echelon Form, and edits 1 additional matrix as collateral
void mxReducedEchelon_coll(matrix *writeReduce, matrix *writeCollateral, matrix *readReduce, matrix *readCollateral);

//Turns a matrix into Reduced Row Echelon Form
void mxReducedEchelon(matrix *write, matrix *read);

//Solves for all vectors where possible, using Guass reduction
boolean_t mxSolveGauss(matrix *write, matrix *transform, matrix *result);

/*================================*/

#endif