#pragma once
#include <iostream>

class DMat
{
	double** m_data;
	unsigned m_row_size;
	unsigned m_column_size;
public:
	void reset()
	{
		if (m_data != nullptr)
		{
			for (unsigned i = 0; i < m_row_size; i++)
			{
				delete[] m_data[i];
			}
			delete[] m_data;
		}
	}

	void init(double** data, unsigned row_size, unsigned column_size)
	{
		if (m_data == nullptr || row_size != m_row_size || column_size != m_column_size)
		{
			m_row_size = row_size;
			m_column_size = column_size;
			this->reset();
			m_data = new double* [m_row_size];
			for (unsigned i = 0; i < m_row_size; i++)
			{
				m_data[i] = new double[m_column_size];
				for (unsigned j = 0; j < m_column_size; j++)
				{
					m_data[i][j] = data[i][j];
				}
			}
		}
		else
		{
			for (unsigned i = 0; i < m_row_size; i++)
			{
				for (unsigned j = 0; j < m_column_size; j++)
				{
					m_data[i][j] = data[i][j];
				}
			}
		}
	}

	DMat(double** data,unsigned row_size, unsigned column_size) : m_row_size{ row_size }, m_column_size{ column_size }
	{
		init(data, m_row_size, m_column_size);
	}

	DMat(unsigned row_size, unsigned column_size) : m_row_size{ row_size }, m_column_size{ column_size }
	{
		m_data = new double*[m_row_size];
		for (unsigned i = 0; i < m_row_size; i++)
		{
			m_data[i] = new double[m_column_size];
			for (unsigned j = 0; j < m_column_size; j++)
			{
				m_data[i][j] = 0;
			}
		}
	}

	DMat(DMat&& mat) noexcept
	{
		this->m_row_size = mat.m_row_size;
		this->m_column_size = mat.m_column_size;
		this->m_data = mat.m_data;
		mat.m_row_size = 0;
		mat.m_column_size = 0;
		mat.m_data = nullptr;
	}

	void set(double val, unsigned i, unsigned j)
	{
		this->m_data[i][j] = val;
	}

	DMat sub_mat(unsigned row_to_exclude, unsigned column_to_exclude)
	{
		DMat sub_mat = DMat(m_row_size - 1, m_column_size - 1);

		unsigned current_row_index_sub_mat = 0;
		unsigned current_column_index_sub_mat = 0;

		for (unsigned i = 0; i < m_row_size; i++)
		{
			if (i != row_to_exclude)
			{
				for (unsigned j = 0; j < m_column_size; j++)
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

	DMat comat()
	{
		DMat cmt = DMat(m_row_size, m_column_size);
		for (unsigned i = 0; i < m_row_size; i++)
		{
			for (unsigned j = 0; j < m_column_size; j++)
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
		if (m_row_size == 1) return m_data[0][0];
		else if (m_row_size == 2) return m_data[0][0] * m_data[1][1] - m_data[1][0] * m_data[0][1];
		else
		{
			double current_det = 0;
			for (unsigned i = 0; i < m_row_size; i++)
			{
				if (i % 2)
					current_det -= this->m_data[0][i] * this->sub_mat(0, i).det();
				else
					current_det += this->m_data[0][i] * this->sub_mat(0, i).det();
			}
			return current_det;
		}
	}

	DMat transpose()
	{
		DMat new_mat = DMat(m_column_size, m_row_size);

		for (unsigned i = 0; i < m_row_size; i++)
		{
			for (unsigned j = 0; j < m_column_size; j++)
			{
				new_mat.m_data[j][i] = m_data[i][j];
			}
		}
		return new_mat;
	}

	DMat adjugate()
	{
		return comat().transpose();
	}

	DMat inverse()
	{
		return scal_mul(adjugate(), (float)1 / (float)det<float>());
	}


	static DMat scal_mul(const DMat& mat, double lambda)
	{
		DMat new_mat = DMat(mat.m_row_size, mat.m_column_size);
		for (unsigned i = 0; i < new_mat.m_row_size; i++)
		{
			for (unsigned j = 0; j < new_mat.m_column_size; j++)
			{
				new_mat.m_data[i][j] = mat.m_data[i][j] * lambda;
			}
		}
		return new_mat;
	}

	static DMat gauss_elim(const DMat& coefs, const DMat& bs)
	{
		if (coefs.m_row_size != bs.m_row_size && coefs.m_row_size != coefs.m_column_size)
		{
			std::runtime_error("Error");
		}
		DMat advanced_mat = DMat(coefs.m_row_size, coefs.m_column_size + 1);
		for (unsigned i = 0;i < coefs.m_row_size;i++)
		{
			for (unsigned j = 0; j < coefs.m_column_size; j++)
			{
				advanced_mat.m_data[i][j] = coefs.m_data[i][j];
			}
		}
		for (unsigned i = 0; i < coefs.m_row_size; i++)
		{
			advanced_mat.m_data[i][coefs.m_column_size] = bs.m_data[i][0];
		}
		for (unsigned i = 0;i < advanced_mat.m_row_size-1;i++)
		{
			double pivot = advanced_mat.m_data[i][i];
			for (unsigned j = i + 1; j < advanced_mat.m_row_size; j++)
			{
				double fact = advanced_mat.m_data[j][i] / pivot;
				for (unsigned k = i; k < advanced_mat.m_column_size; k++)
				{
					advanced_mat.m_data[j][k] -= fact * advanced_mat.m_data[i][k];
				}
			}
		}
		return advanced_mat;
	}

	static DMat mul(const DMat& m1, const DMat& m2)
	{
		if (m1.m_column_size != m2.m_row_size)
		{
			std::runtime_error("Fail");
		}
		DMat new_mat = DMat(m1.m_row_size, m2.m_column_size);
		for (unsigned i = 0; i < m1.m_row_size; i++)
		{
			for (unsigned k = 0; k < m2.m_column_size; k++)
			{
				for (unsigned j = 0; j < m1.m_column_size; j++)
				{
					new_mat.m_data[i][k] += m1.m_data[i][j] * m2.m_data[j][k];
				}
			}
		}

		return new_mat;
	}

	friend std::ostream& operator<<(std::ostream& os, const DMat& mat)
	{
		//os << "[";
		for (unsigned i = 0; i < mat.m_row_size; i++)
		{
			os << "[";
			for (unsigned j = 0; j < mat.m_column_size; j++)
			{
				os << mat.m_data[i][j] << ( (j == mat.m_column_size - 1) ? "" : ",");
			}
			os << "]\n";
		}
		//os << "]\n";
		return os;
	}

	~DMat() noexcept
	{
		if (m_data != nullptr)
		{
			for (unsigned i = 0; i < m_row_size; i++)
			{
				delete[] m_data[i];
			}
			delete[] m_data;
		}
	}
};