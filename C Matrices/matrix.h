// Matrices Library, for matrix operations
// Header file
// by Neo Vorsatz
// Last updated: 27 November 2025

#ifndef MATRIX_H
#define MATRIX_H

/* USER MAY EDIT ================================*/

#define SIZE 4 //Change this value to change the maximum size of your matrices
typedef double mxElement_t; //Change the type of "mxElement_t" to change the numerical data type in your matrices

/*================================*/
/* TYPE DEFINITIONS ================================*/

//Boolean
typedef int mxBoolean_t;

//Structure for matrices
typedef struct {
  unsigned int rows;
  unsigned int columns;
  mxElement_t elements[SIZE][SIZE];
} matrix;

/*================================*/
/* WRITING ================================*/

/**
  @brief Sets the given matrix's values to the parameters

  Returns 1 (true) if the process was successful, otherwise returns 0 (false).
  
  @param write A pointer to the matrix
  @param rows The number of rows
  @param columns The number of columns
  @param elements A 2D array of the elements
*/
mxBoolean_t mxSet(matrix *write, int rows, int columns, mxElement_t elements[SIZE][SIZE]);

/**
  @brief Copies the second matrix's data onto the first
  
  @param write A pointer to the matrix that is being copied to
  @param read A pointer to the matrix that is being copied from
*/
void mxCopy(matrix *write, matrix *read);

/**
  @brief Sets the number of rows and columns of the given matrix

  Returns 1 (true) if the process was successful, otherwise returns 0 (false).
  
  @param write A pointer to the matrix
  @param rows The number of rows
  @param columns The number of columns
*/
mxBoolean_t mxSetSize(matrix *write, int rows, int columns);

/**
  @brief Writes an entry into the given row and column of the given matrix

  Returns 1 (true) if the process was successful, otherwise returns 0 (false).
  
  @param write A pointer to the matrix
  @param row The index of the row
  @param column The index of the column
  @param entry The value of the entry
*/
mxBoolean_t mxWriteElement(matrix *write, int row, int column, mxElement_t entry);

/**
  @brief Rewrites the content of a row

  Returns 1 (true) if the process was successful, otherwise returns 0 (false).
  
  @param write A pointer to the matrix
  @param index The index of the row
  @param row An array of entries
  @param arrLength The length of that array
*/
mxBoolean_t mxWriteRow_len(matrix *write, int index, mxElement_t *row, int arrLength);

/**
  @brief Rewrites the content of a row (assumes the array length is perfectly sized)

  Returns 1 (true) if the process was successful, otherwise returns 0 (false).
  
  @param write A pointer to the matrix
  @param index The index of the row
  @param row An array of entries
*/
mxBoolean_t mxWriteRow(matrix *write, int index, mxElement_t *row);

/**
  @brief Rewrites the content of a column

  Returns 1 (true) if the process was successful, otherwise returns 0 (false).
  
  @param write A pointer to the matrix
  @param index The index of the column
  @param column An array of entries
  @param arrLength The length of that array
*/
mxBoolean_t mxWriteColumn_len(matrix *write, int index, mxElement_t *column, int arrLength);

/**
  @brief Rewrites the content of a column (assumes the array length is perfectly sized)

  Returns 1 (true) if the process was successful, otherwise returns 0 (false).
  
  @param write A pointer to the matrix
  @param index The index of the column
  @param column An array of entries
*/
mxBoolean_t mxWriteColumn(matrix *write, int index, mxElement_t *column);

/**
  @brief Inserts a row of entries into the given index

  Returns 1 (true) if the process was successful, otherwise returns 0 (false).
  
  @param write A pointer to the matrix
  @param index The index of the row
  @param row An array of entries
  @param arrLength The length of that array
*/
mxBoolean_t mxInsertRow_len(matrix *write, int index, mxElement_t *row, int arrLength);

/**
  @brief Inserts a row of entries into the given index (assumes the array length is perfectly sized)

  Returns 1 (true) if the process was successful, otherwise returns 0 (false).
  
  @param write A pointer to the matrix
  @param index The index of the row
  @param row An array of entries
*/
mxBoolean_t mxInsertRow(matrix *write, int index, mxElement_t *row);

/**
  @brief Appends a row of entries to the end of the matrix

  Returns 1 (true) if the process was successful, otherwise returns 0 (false).
  
  @param write A pointer to the matrix
  @param row An array of entries
  @param arrLength The length of that array
*/
mxBoolean_t mxAppendRow_len(matrix *write, mxElement_t *row, int arrLength);

/**
  @brief Appends a row of entries to the end of the matrix (assumes the array length is perfectly sized)

  Returns 1 (true) if the process was successful, otherwise returns 0 (false).
  
  @param write A pointer to the matrix
  @param row An array of entries
*/
mxBoolean_t mxAppendRow(matrix *write, mxElement_t *row);

/**
  @brief Inserts a column of entries into the given index

  Returns 1 (true) if the process was successful, otherwise returns 0 (false).
  
  @param write A pointer to the matrix
  @param index The index of the column
  @param column An array of entries
  @param arrLength The length of that array
*/
mxBoolean_t mxInsertColumn_len(matrix *write, int index, mxElement_t *column, int arrLength);

/**
  @brief Inserts a column of entries into the given index (assumes the array length is perfectly sized)

  Returns 1 (true) if the process was successful, otherwise returns 0 (false).
  
  @param write A pointer to the matrix
  @param index The index of the column
  @param column An array of entries
*/
mxBoolean_t mxInsertColumn(matrix *write, int index, mxElement_t *column);

/**
  @brief Appends a column of entries to the end of the matrix

  Returns 1 (true) if the process was successful, otherwise returns 0 (false).
  
  @param write A pointer to the matrix
  @param column An array of entries
  @param arrLength The length of that array
*/
mxBoolean_t mxAppendColumn_len(matrix *write, mxElement_t *column, int arrLength);

/**
  @brief Appends a column of entries to the end of the matrix (assumes the array length is perfectly sized)

  Returns 1 (true) if the process was successful, otherwise returns 0 (false).
  
  @param write A pointer to the matrix
  @param column An array of entries
*/
mxBoolean_t mxAppendColumn(matrix *write, mxElement_t *column);

/**
  @brief Deletes a row from the matrix

  Returns 1 (true) if the process was successful, otherwise returns 0 (false).
  
  @param write A pointer to the matrix
  @param index The index of the row
*/
mxBoolean_t mxDeleteRow(matrix *write, int index);

/**
  @brief Deletes a column from the matrix

  Returns 1 (true) if the process was successful, otherwise returns 0 (false).
  
  @param write A pointer to the matrix
  @param index The index of the column
*/
mxBoolean_t mxDeleteColumn(matrix *write, int index);

/*================================*/
/* READING ================================*/

/**
  @brief Returns the number of rows
  
  @param read A pointer to the matrix
*/
int mxGetNumRows(matrix *read);

/**
  @brief Returns the number of columns
  
  @param read A pointer to the matrix
*/
int mxGetNumColumns(matrix *read);

/**
  @brief Returns the element in the given row and column
  
  @param read A pointer to the matrix
  @param row The index of the row
  @param column The index of the column
*/
mxElement_t mxReadElement(matrix *read, int row, int column);

/*================================*/
/* OPERATIONS ================================*/

/**
  @brief Checks if two matrices are equal

  Returns 1 (true) if the two matrices are equal, otherwise returns 0 (false)
  
  @param read1 A pointer to the first matrix
  @param read2 A pointer to the second matrix
*/
mxBoolean_t mxEqual(matrix *read1, matrix *read2);

/**
  @brief Empties a matrix
  
  @param write A pointer to the matrix
*/
void mxZero(matrix *write);

/**
  @brief Turns a matrix into the identity matrix with a particular size

  Returns 1 (true) if the process was successful, otherwise returns 0 (false)
  
  @param write A pointer to the matrix
  @param size The size desired
*/
mxBoolean_t mxIdentity(matrix *write, int size);

/**
  @brief Adds the second matrix to the first

  Returns 1 (true) if the process was successful, otherwise returns 0 (false)
  
  @param write A pointer to where the result will be written
  @param read1 A pointer to the first matrix
  @param read2 A pointer to the second matrix
*/
mxBoolean_t mxAdd(matrix *write, matrix *read1, matrix *read2);

/**
  @brief Scales/Multiplies the given matrix by a factor
  
  @param write A pointer to where the result will be written
  @param read A pointer to the matrix
  @param factor The value of the factor/scalar
*/
void mxScale(matrix *write, matrix *read, double factor);

/**
  @brief Multiplies two matrices

  Returns 1 (true) if the process was successful, otherwise returns 0 (false)
  
  @param write A pointer to where the result will be written
  @param read1 A pointer to the first matrix (transformation)
  @param read2 A pointer to the second matrix (vector)
*/
mxBoolean_t mxMultiply(matrix *write, matrix *read1, matrix *read2);

/**
  @brief Returns the determinant of the given matrix
  
  @param read A pointer to the matrix
*/
mxElement_t mxDeterminant(matrix *read);

/**
  @brief Transposes the given matrix
  
  @param write A pointer to where the result will be written
  @param read A pointer to the matrix
*/
void mxTranspose(matrix *write, matrix *read);

/**
  @brief Gets the adjoint of the given matrix

  Returns 1 (true) if the process was successful, otherwise returns 0 (false)
  
  @param write A pointer to where the result will be written
  @param read A pointer to the matrix
*/
mxBoolean_t mxAdjoint(matrix *write, matrix *read);

/**
  @brief Inverts the given matrix
  
  Returns 1 (true) if the process was successful, otherwise returns 0 (false)
  
  @param write A pointer to where the result will be written
  @param read A pointer to the matrix
*/
mxBoolean_t mxInverse(matrix *write, matrix *read);

/**
  @brief Solves for a particular element within a particular vector using Cramer's rule
  
  Returns the value of the particular element in the particular vector, or returns 0 if there are no solutions, or returns 1 if there are infinite solutions.

  @param transform A pointer to the transformation matrix
  @param result A pointer to the resultant matrix
  @param vector The index of the vector being solved for
  @param index The index of the element of that vector
*/
mxElement_t mxSolveCramer(matrix *transform, matrix *result, int vector, int index);

/**
  @brief Solves for all vectors using the inverse of the transformation
  
  Returns 1 (true) if the process was successful, otherwise returns 0 (false)

  @param write A pointer to where the result will be written
  @param transform A pointer to the transformation matrix
  @param result A pointer to the resultant matrix
*/
mxBoolean_t mxSolveInverse(matrix *write, matrix *transform, matrix *result);

/**
  @brief Turns a matrix into Reduced Row Echelon Form, and edits 1 additional matrix as collateral

  @param writeReduce A pointer to where the result will be written
  @param writeCollateral A pointer to where the collateral result will be written
  @param readReduce A pointer to the matrix
  @param readCollateral A pointer to the collateral matrix
*/
void mxReducedEchelon_coll(matrix *writeReduce, matrix *writeCollateral, matrix *readReduce, matrix *readCollateral);

/**
  @brief Turns a matrix into Reduced Row Echelon Form

  @param write A pointer to where the result will be written
  @param read A pointer to the matrix
*/
void mxReducedEchelon(matrix *write, matrix *read);

/**
  @brief Solves for all vectors where possible, using Guass reduction
  
  All vectors that could not be solved for are written as zero-vectors
  
  Returns 1 (true) if the process was successful, otherwise returns 0 (false)

  @param write A pointer to where the result will be written
  @param transform A pointer to the transformation matrix
  @param result A pointer to the resultant matrix
*/
mxBoolean_t mxSolveGauss(matrix *write, matrix *transform, matrix *result);

/*================================*/

#endif