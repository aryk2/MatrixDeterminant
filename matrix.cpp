//functions for inputing a new matrix
#include "determinant.h"

//test functions prototype
//this function allows for the input of matrices and will
//hopefully (eventually) test the edge cases automatically
float ** user_input_matrix(int & rows);
void test_display(float ** matrix, int rows);
void free_mem(float ** matrix, int rows);

//main calls the user input function, displays the input matrix, calls
//the rref function and then displays the result 
int main() {
    int rows;
    float ** new_matrix = user_input_matrix(rows);
    if(new_matrix)
	test_display(new_matrix, rows);
    float result = determinant(new_matrix, rows);
    cout << "\n\nRESULT: " << result << endl;
    free_mem(new_matrix, rows);
    return 0;
}

//function that allows user to enter a matrix of any dimension
float ** user_input_matrix(int & rows) {
    cout << "\nthis function tests the determinant"
         << "\nplease enter how many rows are in the square matrix: ";
    rows = 0;
    cin >> rows;
    
    char col = 'a';
    cout << "\n\n";
    for(int k = 0; k < rows; ++k) 
	cout << "   " << k + 1;
    cout << endl;
    for(int i = 0; i < rows; ++i) {
	cout << char(col+i) << " ";
	for(int k = 0; k < rows; ++k) 
	    cout << "[" << char(col+i) << k+1 << "]";
	cout << endl;
    }
  
    float** matrix = new float*[rows];
    for(int i = 0; i < rows; ++i)
        matrix[i] = new float[rows];

    cout << "\n";
    for(int i = 0; i < rows; ++i) {
        for(int k = 0; k < rows; ++k) {
	    cout << char(col+i) << k+1 << ":";
            cin >> matrix[i][k];
        }  
        cout << endl;
    }
    return matrix;
}

//displays matrix passed as arg
void test_display(float ** matrix, int rows) {
    for(int i = 0; i < rows; ++i) {
	for(int k = 0; k < rows; ++k) 
	    cout << "[" << matrix[i][k] << "]";
	cout << endl;
    }
}

//frees dynamic memory created when new matrix is made
void free_mem(float ** matrix, int rows) {
    if(matrix) {
	for(int i = 0; i < rows; ++i) {
	    delete matrix[i];
   	    matrix[i] = NULL;
	}
	delete matrix;
	matrix = NULL;
    }
}
