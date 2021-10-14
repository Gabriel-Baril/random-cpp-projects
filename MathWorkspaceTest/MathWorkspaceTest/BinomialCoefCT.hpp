#pragma once
#include <type_traits>
template<unsigned N> struct Fact { constexpr static unsigned long long value = N * Fact<N - 1>::value; };
template<> struct Fact<0> { constexpr static unsigned long long value = 1; };


template<unsigned N, unsigned K, typename = void> class BinomialCoef;

template<unsigned N, unsigned K>
class BinomialCoef<N, K, std::void_t<std::enable_if_t<N >= K>> >
{
	static constexpr unsigned long m_permutation_count = Fact<N>::value / (Fact<K>::value * Fact<N - K>::value);
	unsigned int m_current_permutation[K];

public:
	BinomialCoef() : m_current_permutation{}
	{
		for (unsigned i = 0;i < K;i++)
			m_current_permutation[i] = i;
	}

	unsigned int* next_permutation()
	{
		for (unsigned i = 0;i < K;i++)
		{
			if (m_current_permutation[K - (i + 1)] < (N - i - 1))
			{
				m_current_permutation[K - (i + 1)] += 1;
				for (unsigned j = i;j >= 1;j--) 
					m_current_permutation[K - j] = m_current_permutation[K - (j + 1)] + 1;
				break;
			}
		}
		return m_current_permutation;
	}

	static constexpr unsigned long get_permutation_count() { return m_permutation_count; }
	unsigned int* get_current_permutation() { return m_current_permutation; }
};