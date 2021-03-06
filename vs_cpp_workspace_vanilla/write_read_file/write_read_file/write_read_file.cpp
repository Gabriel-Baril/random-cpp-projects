// write_read_file.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>

using std::cout;
using std::endl;


template <size_t row, size_t col>
struct Matrix {
	double data[(row <= 0) ? 1 : row][(col <= 0) ? 1 : col];
	size_t rows = (row <= 0) ? 1 : row;
	size_t cols = (col <= 0) ? 1 : col;

	void set(const double& nb) {
		for (size_t i = 0; i < rows;i++) {
			for (size_t j = 0; j < cols;j++) {
				data[i][j] = nb;
			}
		}
	}
};

template <size_t row, size_t col>
void logMatrix(Matrix<row,col> matrix)
{
	for (size_t i = 0; i < matrix.rows; i++) {
		for (size_t j = 0; j < matrix.cols; j++) {
			if ((j == 0) && (j == matrix.cols - 1))
				cout << "[" << matrix.data[i][j] << "]";
			else if (j == 0)
				cout << "[" << matrix.data[i][j] << ",";
			else if (j == matrix.cols - 1)
				cout << matrix.data[i][j] << "]";
			else
				cout << matrix.data[i][j] << ",";

		}
		cout << endl;
	}
	cout << endl;
}

template <size_t row_m1, size_t col_m1, size_t row_m2, size_t col_m2>
Matrix<row_m1, col_m2> mult(Matrix<row_m1, col_m1> m1, Matrix<row_m2, col_m2> m2) {
	Matrix<row_m1, col_m2> result;

	for (int i = 0; i < row_m1; i++) {
		for (int j = 0; j < col_m2; j++) {
			double sum = 0;
			for (int k = 0; k < col_m1; k++) {
				 sum += m1.data[i][k] * m2.data[k][j];
			}
			result.data[i][j] = sum;
		}
	}
	return result;
}

template <size_t row, size_t col>
double det(Matrix<row,col> matrix) {
	double result = 0;
	
	Matrix<row - 1, col - 1> temporary;

	if (row == 1) {
		result = matrix.data[0][0];
		return (result);
	}

	if (row == 2) {
		result = ((matrix.data[0][0] * matrix.data[1][1]) - (matrix.data[0][1] * matrix.data[1][0]));
		return (result);
	}


	for (size_t i = 0; i < col; i++) {
		temporary.set(0);
		for (size_t j = 1; j < row; j++) {
			for (size_t k = 0; k < col; k++) {
				if (k < i) {
					temporary.data[j - 1][k] = matrix.data[j][k];
				}
				else if (k > i) {
					temporary.data[j - 1][k - 1] = matrix.data[j][k];
				}
			}
		}
		result += matrix.data[0][i] * pow(-1, (double) i) * det(temporary);
	}
	return (result);
}

int main()
{
	Matrix<3, 3> obj = { {{1,2,3},
						  {4,5,6},
						  {7,8,9}} };
	Matrix<2, 2> m1 = { {{1,2},
						 {3,4}} };

	Matrix<2, 2> m2 = { {{4,3},
						 {2,1}} };
	Matrix<0, 0> m;

	cout << det(obj) << endl;

	std::cin.get();	
	return 0;
}

