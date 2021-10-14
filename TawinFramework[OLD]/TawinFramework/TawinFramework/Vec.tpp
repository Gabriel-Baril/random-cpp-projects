namespace tw::math
{
	template<unsigned short N, unsigned short M, typename T>
	inline Vec<max<N, M>(), T> operator+(const Vec<N, T>& v1, const Vec<M, T>& v2)
	{
		constexpr signed max_size = max<N, M>();
		constexpr signed min_size = min<N, M>();
		Vec<max_size, T> out;
		for (unsigned short i = 0; i < max_size; i++)
			if (i < min_size)
				*((T*)& out + i) = *((T*)& v1 + i) + *((T*)& v2 + i);
			else
				if constexpr (N >= M)
					*((T*)& out + i) = *((T*)& v1 + i);
				else
					*((T*)& out + i) = *((T*)& v2 + i);
		return out;
	}

	template<unsigned short N, typename T>
	inline Vec<N, T> operator+(const Vec<N, T>& v1, const Vec<N, T>& v2)
	{
		Vec<N, T> out;
		for (unsigned short i = 0; i < N; i++)
			*((T*)& out + i) = *((T*)& v1 + i) + *((T*)& v2 + i);
		return out;
	}
	
	
	template<unsigned short N, typename T, typename U>
	inline Vec<N, T> operator+(const Vec<N, T>& v1, const Vec<N, U>& v2)
	{
		//decltype(choose_biggest_number_type_hierarchie<float, int>::type) biggest_type;
		Vec<N, T> out;
		for (unsigned short i = 0; i < N; i++)
			*((T*)& out + i) = (T)(*((T*)& v1 + i) + *((U*)& v2 + i));
		return out;
	}
	
	
	template<unsigned short N, typename T>
	inline Vec<N, T> operator-(const Vec<N, T>& v1, const Vec<N, T>& v2)
	{
		Vec<N, T> out;
		for (unsigned short i = 0; i < N; i++)
			*((T*)& out + i) = *((T*)& v1 + i) - *((T*)& v2 + i);
		return out;
	}
	
	template<unsigned short N, unsigned short M, typename T>
	inline Vec<max<N, M>(), T> operator-(const Vec<N, T>& v1, const Vec<M, T>& v2)
	{
		constexpr signed max_size = max<N, M>();
		constexpr signed min_size = min<N, M>();
		Vec<max_size, T> out;
		for (unsigned short i = 0; i < max_size; i++)
			if (i < min_size)
				* ((T*)& out + i) = *((T*)& v1 + i) - *((T*)& v2 + i);
			else
				if constexpr (N >= M)
					* ((T*)& out + i) = *((T*)& v1 + i);
				else
					*((T*)& out + i) = -*((T*)& v2 + i);
		return out;
	}
	
	template<unsigned short N, typename T>
	inline std::ostream& operator<<(std::ostream& os, const Vec<N, T>& vec)
	{
		os << "[";
		for (unsigned short i = 0; i < N; i++)
			os << *((T*)& vec + i) << ((i == N - 1) ? "" : ", ");
		return os << "]";
	}
}