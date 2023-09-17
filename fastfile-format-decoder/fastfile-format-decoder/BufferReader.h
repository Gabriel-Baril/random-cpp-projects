#pragma once

#include <stdio.h>
#include <stdint.h>

namespace hedron
{
	class BufferReader
	{
	public:
		BufferReader(uint8_t* buffer, uint64_t size)
			: m_Size{ size }, m_BufferBase{ buffer }, m_BufferCurr{ buffer }
		{}

		template<typename T>
		inline T Read()
		{
			T value = *(T*)m_BufferCurr;
			m_BufferCurr += sizeof(T);
			return value;
		}

		template<typename T>
		inline T* Read(uint32_t count)
		{
			T* value = (T*)m_BufferCurr;
			m_BufferCurr += sizeof(T) * count;
			return value;
		}

	private:
		uint64_t m_Size;
		uint8_t* m_BufferBase;
		uint8_t* m_BufferCurr;
	};
}