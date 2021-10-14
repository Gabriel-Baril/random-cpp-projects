#include <iostream>
#include <string>
#include <vector>
#include "Mat.hpp"
#include "DMat.h"
#include "RandGen.hpp"
#include "vec_type.hpp"

template<typename T>
void render_array(T* arr, size_t array_size)
{
	std::cout << "[";
	for (unsigned i = 0;i < array_size;i++)
	{
		std::cout << arr[i] << ( (i < array_size - 1) ? "," : "" );
	}
	std::cout << "]" << "\n";
}

template<typename T>
T** trans_vec_vector(const std::vector<Vec2<T>>& vecs)
{
	T** output = new T*[vecs.size()];
	for (unsigned i = 0;i < vecs.size();i++)
	{
		output[i] = new T[2];
		output[i][0] = vecs[i].values[0];
		output[i][1] = vecs[i].values[1];
	}
	return output;
}

double pow(double base, unsigned exponent)
{
	double output = base;
	for (unsigned i = 0;i < exponent;i++)
	{
		output *= base;
	}
	return output;
}

DMat polynomial_regression(const std::vector<Vec2<double>>& points, unsigned precision)
{
	std::vector<double> output = std::vector<double>(precision);
	DMat poly_mat(points.size(), precision);
	double value_to_push;
	for (unsigned i = 0;i < points.size();i++)
	{
		value_to_push = 1;
		for (unsigned j = 0;j < precision;j++)
		{
			poly_mat.set(value_to_push, i, j);
			value_to_push *= points[i].values[0];
		}
	}
	//std::cout << poly_mat << '\n';
	DMat trans_poly_mat = poly_mat.transpose();
	DMat ys = DMat(points.size(), 1);
	for (unsigned i = 0;i < points.size();i++)
	{
		ys.set(points[i].values[1], i, 0);
	}
	return DMat::mul(DMat::mul(DMat::mul(trans_poly_mat, poly_mat).inverse(), trans_poly_mat), ys);
}

DMat logarithmic_regression(const std::vector<Vec2<double>>& points)
{
	std::vector<double> output = std::vector<double>(2);
	DMat poly_mat(points.size(), 2);
	for (unsigned i = 0; i < points.size(); i++)
	{
		poly_mat.set(log(points[i].values[0]), i, 0);
		poly_mat.set(1, i, 1);
	}
	//std::cout << poly_mat << '\n';
	DMat trans_poly_mat = poly_mat.transpose();
	DMat ys = DMat(points.size(), 1);
	for (unsigned i = 0; i < points.size(); i++)
	{
		ys.set(points[i].values[1], i, 0);
	}
	return DMat::mul(DMat::mul(DMat::mul(trans_poly_mat, poly_mat).inverse(), trans_poly_mat), ys);
}

DMat rational_regression(const std::vector<Vec2<double>>& points, unsigned num_power, unsigned den_power)
{
	unsigned nb_biases = num_power + den_power + 1;
	std::vector<double> output = std::vector<double>(num_power + den_power + 1);
	DMat poly_mat(points.size(), nb_biases);
	double value_to_push;
	for (unsigned i = 0; i < points.size(); i++)
	{
		value_to_push = 1;
		for (unsigned j = 0;j < num_power + 1;j++)
		{
			poly_mat.set(value_to_push, i, j);
			value_to_push *= points[i].values[0];
		}
		value_to_push = -points[i].values[0];
		for (unsigned j = num_power + 1; j < (num_power + den_power + 1); j++)
		{
			poly_mat.set(value_to_push * points[i].values[1], i, j);
			value_to_push *= points[i].values[0];
		}
	}
	//std::cout << poly_mat << '\n';
	DMat trans_poly_mat = poly_mat.transpose();
	DMat ys = DMat(points.size(), 1);
	for (unsigned i = 0; i < points.size(); i++)
	{
		ys.set(points[i].values[1], i, 0);
	}
	return DMat::mul(DMat::mul(DMat::mul(trans_poly_mat, poly_mat).inverse(), trans_poly_mat), ys);
}

// y = a*e^(bx) => ln(y)=bx+ln(a) => y = e^(bx + ln(a))
DMat exponential_regression(const std::vector<Vec2<double>>& points)
{
	DMat poly_mat(points.size(), 2);
	for (unsigned i = 0; i < points.size(); i++)
	{
		poly_mat.set(points[i].values[0], i, 0);
		poly_mat.set(1, i, 1);
	}
	//std::cout << poly_mat << '\n';
	DMat trans_poly_mat = poly_mat.transpose();
	DMat ys = DMat(points.size(), 1);
	for (unsigned i = 0; i < points.size(); i++)
	{
		ys.set(log(points[i].values[1]), i, 0);
	}
	return DMat::mul(DMat::mul(DMat::mul(trans_poly_mat, poly_mat).inverse(), trans_poly_mat), ys); // b1 = b, b2 = ln(a)
}

// Doesnt works
// y = a/b(x-h) + k => A/(x-h)+k
DMat simple_rational_regression(const std::vector<Vec2<double>>& points)
{
	DMat poly_mat(points.size(), 3);
	for (unsigned i = 0; i < points.size(); i++)
	{
		poly_mat.set(points[i].values[0], i, 0);
		poly_mat.set(points[i].values[0] * points[i].values[1], i, 1);
		poly_mat.set(1, i, 2);
	}
	DMat trans_poly_mat = poly_mat.transpose();
	DMat ys = DMat(points.size(), 1);
	for (unsigned i = 0; i < points.size(); i++)
	{
		ys.set(points[i].values[1], i, 0);
	}
	return DMat::mul(DMat::mul(DMat::mul(trans_poly_mat, poly_mat).inverse(), trans_poly_mat), ys);
}


float f(float x)
{
	return (float)1 / (float)x;
}

int main()
{
	/*
	Vec2<int> v = {3, 4};

	BinomialCoef binomial = BinomialCoef(12, 4);

	unsigned long long perm_count = binomial.get_permutation_count() - 1;
	render_array(binomial.get_current_permutation(), 4);
	for (unsigned i = 0;i < perm_count;i++)
	{
		render_array(binomial.next_permutation(), 4);
	}
	*/
	std::vector<Vec2<double>> points_for_poly = { {0, 0}, {3, 10}, {2, -2}, {5, 5}, {8, 7} };
	//std::cout << polynomial_regression(points_for_poly, 5) << '\n';
	std::vector<Vec2<double>> points_for_log = { {0.5, 1}, {2, 2}, {4, 3}, {6, 3.6}, {8, 4} };
	//std::cout << logarithmic_regression(points_for_log) << '\n';
	std::vector<Vec2<double>> points_for_rat = { {-10, f(-10)}, {-5, f(-5)}, {-4, f(-4)}, {0.5, f(0.5)}, {2, f(2)}, {4, f(4)}, {6, f(6)}, {8, f(8)} };
	//std::cout << rational_regression(points_for_rat, 3, 0) << '\n';
	std::cout << '\n';
	//std::cout << polynomial_regression(points_for_rat, 4) << '\n';

	//std::cout << simple_rational_regression(points_for_rat) << '\n';

	DMat mat = DMat(3, 3);
	mat.set(1, 0, 0);
	mat.set(-2, 0, 1);
	mat.set(1, 0, 2);

	mat.set(2, 1, 0);
	mat.set(1, 1, 1);
	mat.set(-3, 1, 2);

	mat.set(4, 2, 0);
	mat.set(-7, 2, 1);
	mat.set(1, 2, 2);

	DMat mat2 = DMat(3, 1);

	mat2.set(0, 0, 0);
	mat2.set(5, 1, 0);
	mat2.set(-1, 2, 0);

	DMat m = DMat::gauss_elim(mat, mat2);
	std::cout << m << '\n';

	//std::cout << d1 << '\n';
	//std::cout << d2 << '\n';
	//DMat t = DMat::mul(d1, d2);
	//std::cout << t << '\n';

	//std::cout << mat2 * mat2.transpose() << '\n';

	//std::cout << test << '\n';
	//std::cout << mat3.det() << '\n';
	//std::cout << mat3.comat() << '\n';
	//RandGen<int> rand = { 2, 10 };
	//std::cout << Mat<float, 4, 4>::rand_mat<float>({ -100, 100 }) << '\n';
	
	/*
	Mat<float, 3, 3> mat3 = { { {1, 4,  1},
								{4, -7, 0},
								{9, 0, -1} } };

	std::cout << mat3 << '\n';
	std::cout << mat3.inverse() << '\n';
	std::cout << mat3 * mat3.inverse() << '\n';

	*/

	//std::cout << RandNum(2, 13) << '\n';
	//std::cout << Mat<float, 3, 3>::rand_mat(-3, 3) << '\n';

	//mat[0][0] = 3;
	//std::cout << mat2 << '\n';
	//std::cout << mat2.transpose() << '\n';

}