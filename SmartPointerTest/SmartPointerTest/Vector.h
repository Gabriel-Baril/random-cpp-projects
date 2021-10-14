class Vector
{
public:
	Vector(size_t capacity = s_defaultCapacity)
	{
		m_capacity = capacity;
		m_size = 0;
		m_data = new int[m_capacity];
	}

	~Vector()
	{
		delete[] m_data;
	}

	int& operator[](size_t index) { return m_data[index]; }
	const int& operator[](size_t index) const { return m_data[index]; }

	size_t size() { return m_size; }
	size_t capacity() { return m_capacity; }
	int* get_data() { return m_data; }

	void push_back(int val)
	{
		if (m_size >= m_capacity)
			resize(m_capacity + s_defaultBufferJump);
		m_data[m_size] = val;
		m_size++;
	}

	void resize(int newCapacity)
	{
		if (newCapacity > m_capacity)
		{
			int* newBuffer = new int[newCapacity];
			for (int i = 0; i < m_size; i++)
			{
				newBuffer[i] = m_data[i];
			}
			delete[] m_data;
			m_data = newBuffer;
			m_capacity = newCapacity;
		}
	}

	void fill(int filler)
	{
		for (unsigned int i = 0; i < m_size; i++)
		{
			m_data[i] = filler;
		}
	}

	void clear()
	{
		delete[] m_data;
		m_data = nullptr;
		m_size = 0;
	}

private:
	inline static size_t s_defaultCapacity = 16;
	inline static size_t s_defaultBufferJump = 16;
	int* m_data;
	size_t m_size;
	size_t m_capacity;
};