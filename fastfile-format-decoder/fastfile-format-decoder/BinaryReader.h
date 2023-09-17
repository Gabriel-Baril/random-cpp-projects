#pragma once
#include <stdio.h>
#include <stdint.h>

namespace hedron
{
	class BinaryReader
	{
	public:
		BinaryReader(const char* filename, char* buffer, uint64_t bufferSize);

		template<typename T>
		inline T Read()
		{
			T value = *(T*)m_BufferPtr;
			m_BufferPtr += sizeof(T);
			return value;
		}

		template<typename T>
		inline T* Read(uint32_t count)
		{
			T* value = (T*)m_BufferPtr;
			m_BufferPtr += sizeof(T) * count;
			return value;
		}

		bool Finished()
		{
			return m_BufferPtr == m_BufferEnd;
		}

		~BinaryReader();
	private:
		FILE* m_FileHandle = nullptr;
		uint64_t m_FileSizeByte;
		char* m_BufferPtr = nullptr;
		char* m_BufferBase = nullptr;
		char* m_BufferEnd = nullptr;
	};


}