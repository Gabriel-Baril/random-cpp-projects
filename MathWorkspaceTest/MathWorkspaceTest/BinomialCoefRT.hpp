#pragma once
#include <memory>

unsigned long long fact(unsigned N)
{
	int result = 1;
	for (unsigned i = 2;i < N;i++)
		result *= N;
	return result;
}

class BinomialCoef
{
	unsigned int m_n;
	unsigned int m_k;
	unsigned long long m_permutation_count;
	std::unique_ptr<unsigned int[]> m_current_permutation;

public:
	BinomialCoef(unsigned int n, unsigned int k) : m_n{ n }, m_k{k}, m_permutation_count{fact(n)/(fact(k) * fact(n - k))}, m_current_permutation{ std::make_unique<unsigned int[]>(n)  }
	{
		for (unsigned i = 0; i < n; i++)
			m_current_permutation.get()[i] = i;
	}

	unsigned int* next_permutation()
	{
		for (unsigned i = 0; i < m_k; i++)
		{
			if (m_current_permutation.get()[m_k - (i + 1)] < (m_n - i - 1))
			{
				m_current_permutation.get()[m_k - (i + 1)] += 1;
				for (unsigned j = i; j >= 1; j--)
					m_current_permutation.get()[m_k - j] = m_current_permutation.get()[m_k - (j + 1)] + 1;
				break;
			}
		}
		return m_current_permutation.get();
	}

	unsigned long long get_permutation_count() { return m_permutation_count; }
	unsigned int* get_current_permutation() { return m_current_permutation.get(); }
};