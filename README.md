# MatrixDeterminant
Calculate the determinant of an x by x (square) matrix

The determinant of a matrix is a scalar quantity that holds information about the matrix. It helps calculate the 
inverse of the matrix. If the determinant of the matrix is 0, then that matrix is not invertable. A non square matrix does
not have a determinant. 

[a][b]
[c][d]

The algorithm for calculating the determinant of the 2x2 matrix above is a*d-b*c. This rule that give this equation is:

         |det| = (-1^(1+i)) * matrix[0][i] * det|submatrix of rows below the first row and columns other than column i|

The determinant of a 1x1 matrix is the value stored in matrix[0][0] which gives d and c in the 2x2 equation a*d-b*c

Note: the |det| notation does not indicate absolute value, this is the notation for the determinant of a matrix. 

My function can determine the determinant of any sized square matrix by using recursion to reduce such a matrix to a series
of 2x2 matrices and then calculate the appropriate value from those 2x2 matrices. 

This is done for each step by making a matrix of one size smaller than the current matrix for each index i, calculating that
determinant and then multiplying that my the number in matrix[0][i] and its appropriate exponent of -1 which for all even 
numbers i will equal 1 and for all odd number i will equal -1. this follows the pattern for any square matrix: 

[1][-1][1][-1]
[-1][1][-1][1]
[1][-1][1][-1]
[-1][1][-1][1]
