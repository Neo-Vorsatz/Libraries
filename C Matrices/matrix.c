// Matrices Library, for matrix operations
// Implementation file
// by Neo Vorsatz
// Last updated: 9 July 2025

#include "matrix.h"

/* WRITING ================================*/

//Sets the given matrix's values to the parameters
mxBoolean_t mxSet(matrix *write, int rows, int columns, mxElement_t elements[SIZE][SIZE]) {
  //If the given rows or columns are too big
  if ((rows>SIZE)||(columns>SIZE)) {return 0;}

  //Set the size
  write->rows = rows;
  write->columns = columns;
  //Repeat for each row
  for (int r=0; r<SIZE; r++) {
    //Repeat for each column
    for (int c=0; c<SIZE; c++) {
      //Replace the element
      write->elements[r][c] = elements[r][c];
    }
  }

  //Indicate that the process was successful
  return 1;
}

//Copies the second matrix's data onto the first
void mxCopy(matrix *write, matrix *read) {
  //Copy the number of rows and columns
  write->rows = read->rows;
  write->columns = read->columns;
  //For each row
  for (int r=0; r<SIZE; r++) {
    //For each column
    for (int c=0; c<SIZE; c++) {
      //Copy the element
      write->elements[r][c] = read->elements[r][c];
    }
  }
}

//Sets the number of rows and columns of the given matrix
mxBoolean_t mxSetSize(matrix *write, int rows, int columns) {
  //If the given rows or columns are too big
  if ((rows>SIZE)||(columns>SIZE)) {return 0;}

  //Setting the size
  write->rows = rows;
  write->columns = columns;

  //Indicate that the process was successful
  return 1;
}

//Writes an entry into the given row and column of the given matrix
mxBoolean_t mxWriteElement(matrix *write, int row, int column, mxElement_t entry) {
  //If the index is out of bounds
  if ((row+1>SIZE)||(column+1>SIZE)) {return 0;}

  //If the row index is beyond the current size
  if (row+1>write->rows) {
    //Expand the matrix
    write->rows = row+1;
  }
  //If the column index is beyond the current size
  if (column+1>write->columns) {
    //Expand the matrix
    write->columns = column+1;
  }
  //Writing the entry
  write->elements[row][column] = entry;

  //Indicate that the process was successful
  return 1;
}

//Rewrites the content of a row
mxBoolean_t mxWriteRow_len(matrix *write, int index, mxElement_t *row, int arrLength) {
  //If the index is out of bounds
  if (index+1>SIZE) {return 0;}

  //If the index is beyond the current size
  if (index+1>write->rows) {
    //Expand the matrix
    write->rows = index+1;
  }
  //Repeat for each element
  for (int c=0; c<SIZE; c++) {
    //If we've passed the end of the array
    if (c+1>arrLength) {
      //Fill the element with 0
      write->elements[index][c] = 0;
    } else {
      //Fill the element with the value from the array
      write->elements[index][c] = row[c];
    }
  }

  //Indicate that the process was successful
  return 1;
}

//Rewrites the content of a row (assumes the array length is perfectly sized)
mxBoolean_t mxWriteRow(matrix *write, int index, mxElement_t *row) {
  return mxWriteRow_len(write, index, row, write->columns);
}

//Rewrites the content of a column
mxBoolean_t mxWriteColumn_len(matrix *write, int index, mxElement_t *column, int arrLength) {
  //If the index is out of bounds
  if (index+1>SIZE) {return 0;}

  //If the index is beyond the current size
  if (index+1>write->columns) {
    //Expand the matrix
    write->columns = index+1;
  }
  //Repeat for each element
  for (int r=0; r<SIZE; r++) {
    //If we've passed the end of the array
    if (r+1>arrLength) {
      //Fill the element with 0
      write->elements[r][index] = 0;
    } else {
      //Fill the element with the value from the array
      write->elements[r][index] = column[r];
    }
  }

  //Indicate that the process was successful
  return 1;
}

//Rewrites the content of a column (assumes the array length is perfectly sized)
mxBoolean_t mxWriteColumn(matrix *write, int index, mxElement_t *column) {
  return mxWriteColumn_len(write, index, column, write->rows);
}

//Inserts a row of entries into the given index
mxBoolean_t mxInsertRow_len(matrix *write, int index, mxElement_t *row, int arrLength) {
  //If the matrix is too large
  if (write->rows==SIZE) {return 0;}
  //If the index is out of bounds
  if (index+1>SIZE) {return 0;}

  //If the index is beyond the current size
  if (index+1>write->rows) {
    //Expand the matrix
    write->rows = index+1;
  } else {
    //Increment the number of rows
    write->rows++;
  }
  //Repeat for each column
  for (int c=0; c<SIZE; c++) {
    //Repeat for each element below the index, bottom to top
    for (int r=SIZE; r>index; r--) {
      //Replace the element with the one above it
      write->elements[r][c] = write->elements[r-1][c];
    }
    //If we've passed the end of the array
    if (c+1>arrLength) {
      //Fill the element with 0
      write->elements[index][c] = 0;
    } else {
      //Fill the element with the value from the array
      write->elements[index][c] = row[c];
    }
  }

  //Indicate that the process was successful
  return 1;
}

//Inserts a row of entries into the given index (assumes the array length is perfectly sized)
mxBoolean_t mxInsertRow(matrix *write, int index, mxElement_t *row) {
  return mxInsertRow_len(write, index, row, write->columns);
}

//Appends a row of entries to the end of the matrix
mxBoolean_t mxAppendRow_len(matrix *write, mxElement_t *row, int arrLength) {
  return mxInsertRow_len(write, write->rows, row, arrLength);
}

//Appends a row of entries to the end of the matrix (assumes the array length is perfectly sized)
mxBoolean_t mxAppendRow(matrix *write, mxElement_t *row) {
  return mxInsertRow_len(write, write->rows, row, write->columns);
}

//Inserts a column of entries into the given index
mxBoolean_t mxInsertColumn_len(matrix *write, int index, mxElement_t *column, int arrLength) {
  //If the matrix is too large
  if (write->columns==SIZE) {return 0;}
  //If the index is out of bounds
  if (index+1>SIZE) {return 0;}

  //If the index is beyond the current size
  if (index+1>write->columns) {
    //Expand the matrix
    write->columns = index+1;
  } else {
    //Increment the number of columns
    write->columns++;
  }
  //Repeat for each column
  for (int r=0; r<SIZE; r++) {
    //Repeat for each element right of the index, right to left
    for (int c=SIZE; c>index; c--) {
      //Replace the element with the one left of it
      write->elements[r][c] = write->elements[r][c-1];
    }
    //If we've passed the end of the array
    if (r+1>arrLength) {
      //Fill the element with 0
      write->elements[r][index] = 0;
    } else {
      //Fill the element with the value from the array
      write->elements[r][index] = column[r];
    }
  }

  //Indicate that the process was successful
  return 1;
}

//Inserts a column of entries into the given index (assumes the array length is perfectly sized)
mxBoolean_t mxInsertColumn(matrix *write, int index, mxElement_t *column) {
  return mxInsertColumn_len(write, index, column, write->rows);
}

//Appends a column of entries to the end of the matrix
mxBoolean_t mxAppendColumn_len(matrix *write, mxElement_t *column, int arrLength) {
  return mxInsertColumn_len(write, write->columns, column, arrLength);
}

//Appends a column of entries to the end of the matrix (assumes the array length is perfectly sized)
mxBoolean_t mxAppendColumn(matrix *write, mxElement_t *column) {
  return mxInsertColumn_len(write, write->columns, column, write->rows);
}

//Deletes a row from the matrix
mxBoolean_t mxDeleteRow(matrix *write, int index) {
  //If the index is out of bounds
  if (index+1>SIZE) {return 0;}

  //If the index is within the current size
  if (index<write->rows) {
    //Decrement the number of rows
    write->rows--;
  }
  //Repeat for each column
  for (int c=0; c<SIZE; c++) {
    //Repeat for each element below (and including) the index, top to bottom
    for (int r=index; r<SIZE; r++) {
      //Replace the element with the one below it
      write->elements[r][c] = write->elements[r+1][c];
    }
  }

  //Indicate that the process was successful
  return 1;
}

//Deletes a column from the matrix
mxBoolean_t mxDeleteColumn(matrix *write, int index) {
  //If the index is out of bounds
  if (index+1>SIZE) {return 0;}

  //If the index is within the current size
  if (index<write->columns) {
    //Decrement the number of columns
    write->columns--;
  }
  //Repeat for each row
  for (int r=0; r<SIZE; r++) {
    //Repeat for each element right of (and including) the index, left to right
    for (int c=index; c<SIZE; c++) {
      //Replace the element with the one right of it
      write->elements[r][c] = write->elements[r][c+1];
    }
  }

  //Indicate that the process was successful
  return 1;
}

/*================================*/
/* READING ================================*/

//Returns the number of rows
int mxGetNumRows(matrix *read) {
  return read->rows;
}

//Returns the number of columns
int mxGetNumColumns(matrix *read) {
  return read->columns;
}

//Returns the element in the given row and column
mxElement_t mxReadElement(matrix *read, int row, int column) {
  //If the index is out of bounds
  if ((read->rows<row)||(read->columns<column)) {return 0;}
  //Returning the element
  return read->elements[row][column];
}

/*================================*/
/* OPERATIONS ================================*/

//Checks if two matrices are equal
mxBoolean_t mxEqual(matrix *read1, matrix *read2) {
  //If the sizes are different
  if (!((read1->rows==read2->rows)&&(read1->columns==read2->columns))) {
    //Then the matrices aren't equal
    return 0;
  }
  //For each row
  for (int r=0; r<read1->rows; r++) {
    //For each column
    for (int c=0; c<read1->columns; c++) {
      //If the entries are not the same
      if (read1->elements[r][c]!=read2->elements[r][c]) {
        //Then the matrices aren't equal
        return 0;
      }
    }
  }
  //If we've reached this step, the matrices are equal
  return 1;
}

//Empties a matrix
void mxZero(matrix *write) {
  //Set the sizze to 0
  write->rows = 0;
  write->columns = 0;
  //For each row
  for (int r=0; r<SIZE; r++) {
    //For each column
    for (int c=0; c<SIZE; c++) {
      //Replace the entry with 0
      write->elements[r][c] = 0;
    }
  }
}

//Turns a matrix into the identity matrix with a particular size
mxBoolean_t mxIdentity(matrix *write, int size) {
  //If the size is too large
  if (size>SIZE) {return 0;}

  //Set the size
  write->rows = size;
  write->columns = size;
  //For each row
  for (int r=0; r<size; r++) {
    //For each column
    for (int c=0; c<size; c++) {
      //If this entry is on the diagonal
      if (r==c) {
        //Replace the entry with 1
        write->elements[r][c] = 1;
      } else {
        //Replace the entry with 0
        write->elements[r][c] = 0;
      }
    }
  }

  //Indicate that the process was successful
  return 1;
}

//Adds the second matrix to the first
mxBoolean_t mxAdd(matrix *write, matrix *read1, matrix *read2) {
  //If the matrices can't be added
  if (!( (read1->rows==read2->rows)&&(read1->columns==read2->columns) )) {return 0;}

  //Temporarily storing the Read matrices
  matrix m1;
  mxCopy(&m1, read1);
  matrix m2;
  mxCopy(&m2, read2);

  //Setting the size
  write->rows = m1.rows;
  write->columns = m1.columns;
  //For each row
  for (int r=0; r<m1.rows; r++) {
    //For each column
    for (int c=0; c<m1.columns; c++) {
      //Write the sum of the two entries
      write->elements[r][c] = m1.elements[r][c] + m2.elements[r][c];
    }
  }

  //Indicate that the process was successful
  return 1;
}

//Scales/Multiplies the given matrix by a factor
void mxScale(matrix *write, matrix *read, double factor) {
  //Setting the size
  write->rows = read->rows;
  write->columns = read->columns;
  //For each row
  for (int r=0; r<read->rows; r++) {
    //For each column
    for (int c=0; c<read->columns; c++) {
      write->elements[r][c] = read->elements[r][c] * factor;
    }
  }
}

//Multiplies the matrices
mxBoolean_t mxMultiply(matrix *write, matrix *read1, matrix *read2) {
  //If the matrices can't be multiplied
  if (read1->columns!=read2->rows) {return 0;}

  //Temporarily storing the Read matrices
  matrix m1;
  mxCopy(&m1, read1);
  matrix m2;
  mxCopy(&m2, read2);

  //Setting the size
  write->rows = m1.rows;
  write->columns = m2.columns;
  //For each row
  for (int r=0; r<write->rows; r++) {
    //For each column
    for (int c=0; c<write->columns; c++) {
      //Set the cumulative sum to 0
      mxElement_t sum = 0;
      //For each term
      for (int i=0; i<m1.columns; i++) {
        //Increase the sum by the product
        sum += m1.elements[r][i] * m2.elements[i][c];
      }
      //Set the entry as the sum
      write->elements[r][c] = sum;
    }
  }

  //Indicate that the process was successful
  return 1;
}

//Returns the determinant of the given matrix
mxElement_t mxDeterminant(matrix *read) {
  //If it's not a square matrix
  if (read->rows!=read->columns) {return 0;}
  //If there is only 1 element, return that element
  if (read->rows==1) {return read->elements[0][0];}

  //Set the determinant to 0 initially
  mxElement_t determinant = 0;
  //Set the sign to positive
  signed int sign = 1;
  //Get memory for the submatrix
  matrix submatrix;

  //For each element in the first row
  for (int c=0; c<read->columns; c++) {
    //Copy the contents to the submatrix
    mxCopy(&submatrix, read);
    //Delete the first row of the submatrix
    mxDeleteRow(&submatrix, 0);
    //Delete the corresponding column of the submatrix
    mxDeleteColumn(&submatrix, c);

    //Add the element multiplied by the cofactor to the determinant
    determinant += (read->elements[0][c])*sign*mxDeterminant(&submatrix);
    //Change the sign for the next cofactor
    sign *= -1;
  }

  //Return the value of the determinant
  return determinant;
}

//Transposes the given matrix
void mxTranspose(matrix *write, matrix *read) {
  //Temporarily storing the Read matrix
  matrix m;
  mxCopy(&m, read);

  //Swap the number of rows and columns
  write->rows = m.columns;
  write->columns = m.rows;
  //For each row
  for (int r=0; r<SIZE; r++) {
    //For each column
    for (int c=0; c<SIZE; c++) {
      //Copy the element into the transposed-position
      write->elements[c][r] = m.elements[r][c];
    }
  }
}

//Gets the adjoint of the given matrix
mxBoolean_t mxAdjoint(matrix *write, matrix *read) {
  //If it's not a square matrix
  if (read->rows!=read->columns) {return 0;}

  //Temporarily storing the Read matrix
  matrix m;
  mxCopy(&m, read);

  //Setting the size
  write->rows = m.rows;
  write->columns = m.columns;

  //Get memory for the submatrix
  matrix submatrix;
  //For each row
  for (int r=0; r<m.rows; r++) {
    //For each column
    for (int c=0; c<m.columns; c++) {
      //Copy the contents to the submatrix
      mxCopy(&submatrix, &m);
      //Delete the corresponding row of the submatrix
      mxDeleteRow(&submatrix, r);
      //Delete the corresponding column of the submatrix
      mxDeleteColumn(&submatrix, c);

      //Set the transposed element of the adjoint matrix
      write->elements[c][r] = (((r+c)%2)? -1:1)*mxDeterminant(&submatrix);
    }
  }

  //Indicate that the process was successful
  return 1;
}

//Inverts the given matrix
mxBoolean_t mxInverse(matrix *write, matrix *read) {
  //If it's not a square matrix
  if (read->rows!=read->columns) {return 0;}
  //Getting the determinant
  mxElement_t det = mxDeterminant(read);
  //If the determinant is zero, the inverse doesn't exist
  if (det==0) {return 0;}

  //Set Write to the adjoint
  mxAdjoint(write, read);
  //Scale Write by dividing by the determinant
  mxScale(write, write, 1/det);

  //Indicate that the process was successful
  return 1;
}

//Solves for a particular element within a particular vector using Cramer's rule
mxElement_t mxSolveCramer(matrix *transform, matrix *result, int vector, int index) {
  //If it's not a square matrix
  if (transform->rows!=transform->columns) {return 0;}
  //If the vector number is out of bounds
  if (vector>=result->columns) {return 0;}
  //If the index is out of bounds
  if (index>=result->rows) {return 0;}
  //If the result is impossible from the transform
  if (transform->rows!=result->rows) {return 0;}

  //Get the determinant of the transform
  mxElement_t det = mxDeterminant(transform);
  //Copy the transform
  matrix m;
  mxCopy(&m, transform);
  //For each index in the resulting vector
  for (int i=0; i<result->rows; i++) {
    //Copy this entry to the new matrix
    m.elements[i][index] = result->elements[i][vector];
  }
  //Get the determinant of the new matrix
  mxElement_t newDet = mxDeterminant(&m);

  //If there are infinite solutions
  if ((det==0)&&(newDet==0)) {return 1;}
  //If there are no solutions
  if ((det==0)&&(newDet!=0)) {return 0;}
  //Otherwise, there is one solution, using Cramer's Rule
  return (newDet/det);
}

//Solves for all vectors using the inverse of the transformation
mxBoolean_t mxSolveInverse(matrix *write, matrix *transform, matrix *result) {
  //Save Write as the inverse of the Transform
  if (!mxInverse(write, transform)) {
    //If this process fails
    return 0;
  }
  //Save Write as the multiplication of the inverse and the result
  mxMultiply(write, write, result);

  //Indicate that the process was successful
  return 1;
}

//Turns a matrix into Reduced Row Echelon Form, and edits 1 additional matrix as collateral
void mxReducedEchelon_coll(matrix *writeReduce, matrix *writeCollateral, matrix *readReduce, matrix *readCollateral) {
  //Copy the matrices
  mxCopy(writeReduce, readReduce);
  mxCopy(writeCollateral, readCollateral);

  /* When a column with no non-zero pivot is found, it introduces a free-variable.
  The row of the next pivot will be the same row there should've been a pivot,
  so the row for any pivot we're looking for is columnNum minus numOfFreeVariables */
  int numFreeVar = 0;
  //For each index along the diagonal
  for (int i=0; (i<writeReduce->columns)&&(i-numFreeVar<writeReduce->rows); i++) {
    //The starting row to consider for a pivot is on the diagonal, minus the free variables found
    int r = i-numFreeVar;
    //Search for a non-zero pivot
    while ((writeReduce->elements[r][i]==0)&&(r+1<writeReduce->rows)) {r++;}

    //If a non-zero was not found
    if (writeReduce->elements[r][i]==0) {
      //Then we've found a free variable
      numFreeVar++;
    } else {
      /* Swap the pivot row and the row with a non-zero pivot */
      //For each column after the completed columns, in the matrix we're reducing
      for (int c=i; c<writeReduce->columns; c++) {
        //Temporarily store the value from the main row
        mxElement_t temp = writeReduce->elements[i-numFreeVar][c];
        //Replace the value in the main row
        writeReduce->elements[i-numFreeVar][c] = writeReduce->elements[r][c];
        //Replace the value in the row that was found
        writeReduce->elements[r][c] = temp;
      }
      //For each column in the collateral matrix
      for (int c=0; c<writeCollateral->columns; c++) {
        //Temporarily store the value from the main row
        mxElement_t temp = writeCollateral->elements[i-numFreeVar][c];
        //Replace the value in the main row
        writeCollateral->elements[i-numFreeVar][c] = writeCollateral->elements[r][c];
        //Replace the value in the row that was found
        writeCollateral->elements[r][c] = temp;
      }

      /* Reduce this column */
      //For each row
      for (int r=0; r<writeReduce->rows; r++) {
        //If this row isn't the pivot
        if (r!=i-numFreeVar) {
          //Set the scalar multiple needed
          double scalar = writeReduce->elements[r][i]/writeReduce->elements[i-numFreeVar][i];
          /* Perform the row operation */
          //For each column after the completed columns, in the matrix we're reducing
          for (int c=i; c<writeReduce->columns; c++) {
            //Decrease each element in the row by the scalar multiple of the pivot row
            writeReduce->elements[r][c] -= scalar*writeReduce->elements[i-numFreeVar][c];
          }
          //For each column in the collateral matrix
          for (int c=0; c<writeCollateral->columns; c++) {
            //Decrease each element in the row by the scalar multiple of the pivot row
            writeCollateral->elements[r][c] -= scalar*writeCollateral->elements[i-numFreeVar][c];
          }
        }
      }
    }
  }
}

//Turns a matrix into Reduced Row Echelon Form
void mxReducedEchelon(matrix *write, matrix *read) {
  //Creating a zero matrix
  matrix zero;
  mxZero(&zero);

  //Turning the matrix into Reduced Row Echelon Form
  mxReducedEchelon_coll(write, &zero, read, &zero);
}

//Solves for all vectors where possible, using Guass reduction
mxBoolean_t mxSolveGauss(matrix *write, matrix *transform, matrix *result) {
  //If the result is impossible from the transform
  if (transform->rows!=result->rows) {return 0;}

  //Set the size
  write->rows = transform->columns;
  write->columns = result->columns;

  //Creating new matrices to do row operations on
  matrix transform0;
  matrix result0;

  //Gauss Reduction
  mxReducedEchelon_coll(&transform0, &result0, transform, result);

  /* To solve for the vectors, we're going to make all free variables equal 0,
  and only pivots will may have a non-zero value */
  //Whether a variable has been solved for or not
  mxBoolean_t solved[transform0.columns];
  //Note that none of the variables have been solved for
  for (int i=0; i<transform0.columns; i++) {solved[i] = 0;}
  //For each row in the transformation
  for (int r=0; r<transform0.rows; r++) {
    //Start with the first column
    int c=0;
    //Search for the pivot, left to right
    while ((transform0.elements[r][c]==0)&&(c+1<transform0.columns)) {c++;}
    //For each output vector
    for (int v=0; v<result0.columns; v++) {
      //If no pivot was found
      if (transform0.elements[r][c]==0) {
        //If the result is non-zero
        if (result0.elements[r][v]!=0) {
          //Then there is no possible solution
          return 0;
        }
      } else {
        //Solve for the pivot-variable
        write->elements[c][v] = result0.elements[r][v]/transform0.elements[r][c];
        //Note that the variable has been solved for
        solved[c] = 1;
      }
    }
  }
  //For each variable
  for (int i=0; i<transform0.columns; i++) {
    //If this variable was not solved for
    if (!solved[i]) {
      //For each vector
      for (int v=0; v<result0.columns; v++) {
        //Set the solution to 0
        write->elements[i][v] = 0;
      }
    }
  }

  //Indicate that the process was successful
  return 1;
}

/*================================*/