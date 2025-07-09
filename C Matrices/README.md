# C Matrices
## Overview
This module is for matrix operations in C.<br>
With it, you can create, edit, and do computations with matrices, including but not limited to:
- Matrix multiplication
- Getting the determinant of a square matrix
- Getting the inverse of a square matrix
- Guass elimination into Reduced Row Echelon form
- Solving for vectors, using a transformation and matrix of resulting vectors

In this folder, test.c was made to test the module.<br>
It can also be used as a reference to see how the module was intended to be used.

## How To Use
Copy the header and implementation files anywhere where your C-compiler can find it (usually at the standard directory or in the same directory as your main file). Then import the module like you would any other module, using `#include`.<br>
You can make edits to the header file to modify the module to suit your needs:
- You can change the value of SIZE (a char value) to change the maximum size of your matrices. By default SIZE is 4, meaning a 4x4 matrix is the largest that can be used.
- You can change the data type of mxElement_t to change the data type that the matrices use. By default mxElement_t is a double, to allow fractional values.

## Data Structures
### Matrix
This is a struct containing a 2-dimensional array of elements (the matrix) as well as the size of the matrix. Create a matrix like you would any other struct:<br>
`matrix myMatrix;`<br>
then myMatrix will be a matrix struct.

## Functions
### Writing
`boolean_t mxSet(matrix *write, char rows, char columns, mxElement_t elements[SIZE][SIZE]);`<br>
Sets the given matrix's values to the parameters.<br>
Takes a pointer to the matrix, a number of rows, a number of columns, and a 2D array of the elements.<br>
Returns 1 (true) if the process was successful, otherwise returns 0 (false).

`void mxCopy(matrix *write, matrix *read);`<br>
Copies the second matrix's data onto the first.<br>
Takes a pointer to the matrix that is being copied to, and another pointer to the matrix that is being copied from.

`boolean_t mxSetSize(matrix *write, char rows, char columns);`<br>
Sets the number of rows and columns of the given matrix.<br>
Takes a pointer to the matrix, a number of rows, and a number of columns.<br>
Returns 1 (true) if the process was successful, otherwise returns 0 (false).

`boolean_t mxWriteElement(matrix *write, char row, char column, mxElement_t entry);`<br>
Writes an entry into the given row and column of the given matrix.<br>
Takes a pointer to the matrix, the index of the row, the index of the column, and the value of the entry.<br>
Returns 1 (true) if the process was successful, otherwise returns 0 (false).

`boolean_t mxWriteRow_len(matrix *write, char index, mxElement_t *row, char arrLength);`<br>
Rewrites the content of a row.<br>
Takes a pointer to the matix, the index of the row, an array of entries, and the length of that array.<br>
Returns 1 (true) if the process was successful, otherwise returns 0 (false).

`boolean_t mxWriteRow(matrix *write, char index, mxElement_t *row);`<br>
Rewrites the content of a row (assumes the array length is perfectly sized).<br>
Takes a pointer to the matrix, the index of the row, and an array of entries.<br>
Returns 1 (true) if the process was successful, otherwise returns 0 (false).

`boolean_t mxWriteColumn_len(matrix *write, char index, mxElement_t *column, char arrLength);`<br>
Rewrites the content of a column.<br>
Takes a pointer to the matrix, the index of the column, and an array of entries, and the length of that array.<br>
Returns 1 (true) if the process was successful, otherwise returns 0 (false).

`boolean_t mxWriteColumn(matrix *write, char index, mxElement_t *column);`<br>
Rewrites the content of a column (assumes the array length is perfectly sized).<br>
Takes a pointer to the matrix, the index of the row, and an array of entries.<br>
Returns 1 (true) if the process was successful, otherwise returns 0 (false).

`boolean_t mxInsertRow_len(matrix *write, char index, mxElement_t *row, char arrLength);`<br>
Inserts a row of entries into the given index.<br>
Takes a pointer to the matix, the index of the row, an array of entries, and the length of that array.<br>
Returns 1 (true) if the process was successful, otherwise returns 0 (false).

`boolean_t mxInsertRow(matrix *write, char index, mxElement_t *row);`<br>
Inserts a row of entries into the given index (assumes the array length is perfectly sized).<br>
Takes a pointer to the matrix, the index of the row, and an array of entries.<br>
Returns 1 (true) if the process was successful, otherwise returns 0 (false).

`boolean_t mxAppendRow_len(matrix *write, mxElement_t *row, char arrLength);`<br>
Appends a row of entries to the end of the matrix.<br>
Takes a pointer to the matix, an array of entries, and the length of that array.<br>
Returns 1 (true) if the process was successful, otherwise returns 0 (false).

`boolean_t mxAppendRow(matrix *write, mxElement_t *row);`<br>
Appends a row of entries to the end of the matrix (assumes the array length is perfectly sized).<br>
Takes a pointer to the matrix, and an array of entries.<br>
Returns 1 (true) if the process was successful, otherwise returns 0 (false).

`boolean_t mxInsertColumn_len(matrix *write, char index, mxElement_t *column, char arrLength);`<br>
Inserts a column of entries into the given index.<br>
Takes a pointer to the matix, the index of the column, an array of entries, and the length of that array.<br>
Returns 1 (true) if the process was successful, otherwise returns 0 (false).

`boolean_t mxInsertColumn(matrix *write, char index, mxElement_t *column);`<br>
Inserts a column of entries into the given index (assumes the array length is perfectly sized).<br>
Takes a pointer to the matrix, the index of the column, and an array of entries.<br>
Returns 1 (true) if the process was successful, otherwise returns 0 (false).

`boolean_t mxAppendColumn_len(matrix *write, mxElement_t *column, char arrLength);`<br>
Appends a column of entries to the end of the matrix.<br>
Takes a pointer to the matix, an array of entries, and the length of that array.<br>
Returns 1 (true) if the process was successful, otherwise returns 0 (false).

`boolean_t mxAppendColumn(matrix *write, mxElement_t *column);`<br>
Appends a column of entries to the end of the matrix (assumes the array length is perfectly sized).<br>
Takes a pointer to the matrix, and an array of entries.<br>
Returns 1 (true) if the process was successful, otherwise returns 0 (false).

`boolean_t mxDeleteRow(matrix *write, char index);`<br>
Deletes a row from the matrix.<br>
Takes a pointer to the matrix, and the index of the row.<br>
Returns 1 (true) if the process was successful, otherwise returns 0 (false).

`boolean_t mxDeleteColumn(matrix *write, char index);`<br>
Deletes a column from the matrix.<br>
Takes a pointer to the matrix, and the index of the column.<br>
Returns 1 (true) if the process was successful, otherwise returns 0 (false).

### Reading

`char mxGetNumRows(matrix *read);`<br>
Takes a pointer to the matrix.<br>
Returns the number of rows.

`char mxGetNumColumns(matrix *read);`<br>
Takes a pointer to the matrix.<br>
Returns the number of columns.

`mxElement_t mxReadElement(matrix *read, char row, char column);`<br>
Takes a pointer to the matrix, the index of the row, and the index of the column.<br>
Returns the element in the given row and column.

### Operations

`boolean_t mxEqual(matrix *read1, matrix *read2);`<br>
Checks if two matrices are equal.<br>
Takes a pointer to the first matrix, and a pointer to the second matrix.<br>
Returns 1 (true) if the two matrices are equal, otherwise returns 0 (false).

`void mxZero(matrix *write);`<br>
Empties a matrix.<br>
Takes a pointer to the matrix.

`boolean_t mxIdentity(matrix *write, char size);`<br>
Turns a matrix into the identity matrix with a particular size.<br.>
Takes a pointer to the matrix, and the size desired.<br>
Returns 1 (true) if the process was successful, otherwise returns 0 (false).

`boolean_t mxAdd(matrix *write, matrix *read1, matrix *read2);`<br>
Adds the second matrix to the first.<br>
Takes a pointer to where the result will be written, a pointer to the first matrix, and a pointer to the second matrix.<br>
Returns 1 (true) if the process was successful, otherwise returns 0 (false).

`void mxScale(matrix *write, matrix *read, double factor);`<br>
Scales/Multiplies the given matrix by a factor.<br>
Takes a pointer to where the result will be written, a pointer to the matrix, the value of the factor/scalar.<br>

`boolean_t mxMultiply(matrix *write, matrix *read1, matrix *read2);`<br>
Multiplies the matrices.<br>
Takes a pointer to where the result will be written, a pointer to the first matrix (transformation), and a pointer to the second matrix (vector).<br>
Returns 1 (true) if the process was successful, otherwise returns 0 (false).

`mxElement_t mxDeterminant(matrix *read);`<br>
Takes a pointer to the matrix.<br>
Returns the determinant of the given matrix.

`void mxTranspose(matrix *write, matrix *read);`<br>
Transposes the given matrix.<br>
Takes a pointer to where the result will be written, and a pointer to the matrix.

`boolean_t mxAdjoint(matrix *write, matrix *read);`<br>
Gets the adjoint of the given matrix.<br>
Takes a pointer to where the result will be written, and a pointer to the matrix.<br>
Returns 1 (true) if the process was successful, otherwise returns 0 (false).

`boolean_t mxInverse(matrix *write, matrix *read);`<br>
Inverts the given matrix.<br>
Takes a pointer to where the result will be written, and a pointer to the matrix.<br>
Returns 1 (true) if the process was successful, otherwise returns 0 (false).

`mxElement_t mxSolveCramer(matrix *transform, matrix *result, char vector, char index);`<br>
Solves for a particular element within a particular vector using Cramer's rule.<br>
Takes a pointer to the transformation matrix, a pointer to the resultant matrix, the index of the vector being solved for, and the index of the element of that matrix.<br>
Returns the value of the particular element in the particular vector, or returns 0 if there are no solutions, or returns 1 if there are infinite solutions.

`boolean_t mxSolveInverse(matrix *write, matrix *transform, matrix *result);`<br>
Solves for all vectors using the inverse of the transformation.<br>
Takes a pointer to where the result will be written, a pointer to the transformation matrix, and a pointer to the resultant matrix.<br>
Returns 1 (true) if the process was successful, otherwise returns 0 (false).

`void mxReducedEchelon_coll(matrix *writeReduce, matrix *writeCollateral, matrix *readReduce, matrix *readCollateral);`<br>
Turns a matrix into Reduced Row Echelon Form, and edits 1 additional matrix as collateral.<br>
Takes a pointer to where the result will be written, a pointer to where the collateral result will be written, a pointer to the matrix, and a pointer to the collateral matrix.

`void mxReducedEchelon(matrix *write, matrix *read);`<br>
Turns a matrix into Reduced Row Echelon Form.<br>
Takes a pointer to where the result will be written, and a pointer to the matrix.

`boolean_t mxSolveGauss(matrix *write, matrix *transform, matrix *result);`<br>
Solves for all vectors where possible, using Guass reduction. All vectors that could not be solved for are written as zero-vectors.<br>
Takes a pointer to where the result will be written, a pointer to the transformation matrix, and a pointer to the resultant matrix.<br>
Returns 1 (true) if the process was successful, otherwise returns 0 (false).