#pragma once
#include <ostream>
#include "RandGen.hpp"


template<typename T, unsigned M, unsigned N>
class Mat
{
	struct Row
	{
		Mat& parent;
		unsigned i;
		T& operator[](unsigned j)
		{
			return parent.m_data[i][j];
		}
	};
public:
	T m_data[M][N];
	//explicit Mat() : m_data{ {} } {}

	Row operator[](unsigned i)
	{
		return {*this, i};
	}
	
	template<unsigned M2, unsigned N2>
	Mat<T, M2, N2> sub_mat_offset(unsigned row_offset, unsigned column_offset)
	{
		static_assert(M2 > 0, "The row dimension must be > 0");
		static_assert(M2 <= M, "The row dimension must be <= M");
		static_assert(N2 > 0, "The column dimension must be > 0");
		static_assert(N2 <= N, "The column dimension must be <= N");
		//static_assert(M2 + row_offset <= M, "Some rows are out of bound");
		//static_assert(N2 + column_offset <= N, "Some columns are out of bound");
		Mat<T, M2, N2> sub_mat;
		for (int i = 0;i < M2;i++)
		{
			for (int j = 0; j < N2; j++)
			{
				sub_mat[i][j] = m_data[row_offset + i][column_offset + j];
			}
		}
		return sub_mat;
	}
	

	template<typename U>
	static Mat<T, M, N> rand_mat(const RandGen<U>& rand_gen)
	{
		Mat<T, M, N> rand_matrix = { };
		for (unsigned i = 0;i < M;i++)
		{
			for (unsigned j = 0; j < N; j++)
			{
				rand_matrix[i][j] = (T)const_cast<RandGen<U>&>(rand_gen).gen();
			}
		}
		return rand_matrix;
	}



	Mat<T, M - 1, N - 1> sub_mat(unsigned row_to_exclude, unsigned column_to_exclude)
	{
		Mat<T, M - 1, N - 1> sub_mat = { };

		unsigned current_row_index_sub_mat = 0;
		unsigned current_column_index_sub_mat = 0;

		for (unsigned i = 0 ;i < M;i++)
		{
			if (i != row_to_exclude)
			{
				for (unsigned j = 0; j < N; j++)
				{
					if (j != column_to_exclude)
					{
						sub_mat.m_data[current_row_index_sub_mat][current_column_index_sub_mat] = this->m_data[i][j];
						current_column_index_sub_mat++;
					}
				}
				current_row_index_sub_mat++;
			}
			current_column_index_sub_mat = 0;
		}

		return sub_mat;
	}


	Mat<T, M, N> comat()
	{
		static_assert(M == N, "The matrix must be square");

		Mat<T, M, N> cmt = {};
		for (unsigned i = 0; i < M; i++)
		{
			for (unsigned j = 0; j < N; j++)
			{
				if (i % 2 == 0)
				{
					if (j % 2 == 0)
					{
						cmt.m_data[i][j] = this->sub_mat(i, j).det<double>();
					}
					else
					{
						cmt.m_data[i][j] = -this->sub_mat(i, j).det<double>();
					}
				}
				else
				{
					if (j % 2 == 0)
					{
						cmt.m_data[i][j] = -this->sub_mat(i, j).det<double>();
					}
					else
					{
						cmt.m_data[i][j] = this->sub_mat(i, j).det<double>();
					}
				}
			}
		}
		return cmt;
	}

	template<typename T2 = double>
	T2 det()
	{
		static_assert(N == M, "The matrix must be square");
		if constexpr (N == 1) return m_data[0][0];
		else if constexpr (N == 2) return m_data[0][0] * m_data[1][1] - m_data[1][0] * m_data[0][1];
		else
		{
			double current_det = 0;
			for (unsigned i = 0; i < M; i++)
			{
				if (i % 2)
					current_det -= this->m_data[0][i] * this->sub_mat(0, i).det();
				else
					current_det += this->m_data[0][i] * this->sub_mat(0, i).det();
			}
			return current_det;
		}
	}

	Mat<T, N, M> transpose()
	{
		Mat<T, N, M> new_mat;
		
		for (unsigned i = 0;i < M;i++)
		{
			for (unsigned j = 0; j < N; j++)
			{
				new_mat[j][i] = m_data[i][j];
			}
		}
		return new_mat;
	}

	Mat<T, N, M> adjugate()
	{
		return comat().transpose();
	}

	Mat<float, N, M> inverse()
	{
		return scal_mul(adjugate(), (float)1 / (float)det<float>());
	}

	template<typename T, unsigned N2, unsigned M2>
	static Mat<T, M2, N2> scal_mul(const Mat<T, M2, N2>& mat, T lambda)
	{
		Mat new_mat = {};
		for (unsigned i = 0; i < M2; i++)
		{
			for (unsigned j = 0; j < N2; j++)
			{
				new_mat.m_data[i][j] = mat.m_data[i][j] * lambda;
			}
		}
		return new_mat;
	}

	inline Mat operator+(const Mat& mat)
	{
		Mat new_mat = {};
		for (unsigned i = 0;i < M;i++)
		{
			for (unsigned j = 0; j < N; j++)
			{
				new_mat.m_data[i][j] = this->m_data[i][j] + mat.m_data[i][j];
			}
		}
		return new_mat;
	}

	inline Mat operator-(const Mat& mat)
	{
		Mat new_mat = {};
		for (unsigned i = 0; i < M; i++)
		{
			for (unsigned j = 0; j < N; j++)
			{
				new_mat.m_data[i][j] = this->m_data[i][j] - mat.m_data[i][j];
			}
		}
		return new_mat;
	}

	friend inline Mat operator*(const Mat& mat, float lambda)
	{
		Mat new_mat = {};
		for (unsigned i = 0; i < M; i++)
		{
			for (unsigned j = 0; j < N; j++)
			{
				new_mat.m_data[i][j] = mat.m_data[i][j] * lambda;
			}
		}
		return new_mat;
	}

	friend inline Mat operator*(float lambda, Mat& mat)
	{
		return mat * lambda;
	}

	template<typename T2, unsigned M2, unsigned N2>
	inline Mat<T2, M, N2> operator*(const Mat<T2, M2, N2>& mat)
	{
		static_assert(N == M2, "Error");
		Mat<T2, M, N2> new_mat = {};
		for (unsigned i = 0; i < M; i++)
		{
			for (unsigned k = 0; k < N2; k++)
			{
				for (unsigned j = 0; j < N; j++)
				{
					new_mat.m_data[i][k] += this->m_data[i][j] * mat.m_data[j][k];
				}
			}
		}
		return new_mat;
	}

	inline Mat& operator^(unsigned lambda)
	{
		static_assert(N == M, "The matrix needs to be square");
		Mat save = *this;
		for (unsigned i = 0;i < lambda - 1;i++)
		{
			*this = *this * save;
		}
		return *this;
	}
};

template<typename T, unsigned M, unsigned N>
std::ostream& operator<<(std::ostream& os, const Mat<T, M, N>& mat)
{
	//os << "[";
	for (unsigned i = 0; i < M; i++)
	{
		os << "[";
		for (unsigned j = 0; j < N; j++)
		{
			os << mat.m_data[i][j] << ((j == N - 1) ? "" : ",");
		}
		os << "]\n";
	}
	//os << "]\n";
	return os;
}

