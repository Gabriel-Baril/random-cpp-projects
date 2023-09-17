#pragma once
#include <stdio.h>
#include <stdint.h>

namespace hedron
{
	class BinaryWriter
	{
	public:
		BinaryWriter(const char* filename);

		template<typename T>
		inline void Write(const T& value)
		{
			fwrite(&value, sizeof(T), 1, m_FileHandle);
		}

		template<typename T>
		inline void Write(T* values, uint32_t count)
		{
			fwrite(values, sizeof(T), count, m_FileHandle);
		}

		~BinaryWriter();
	private:
		FILE* m_FileHandle = nullptr;
	};


}