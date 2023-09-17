#include "BinaryReader.h"

namespace hedron
{
	BinaryReader::BinaryReader(const char* filename, char* buffer, uint64_t bufferSize)
	{
		fopen_s(&m_FileHandle, filename, "rb"); // read binary
		//fseek(m_FileHandle, 2, SEEK_SET);
		fread(buffer, sizeof(char), bufferSize, m_FileHandle);

		fseek(m_FileHandle, 0L, SEEK_END);
		m_FileSizeByte = ftell(m_FileHandle);
		fseek(m_FileHandle, 0L, SEEK_SET);

		m_BufferBase = buffer;
		m_BufferPtr = m_BufferBase;
		m_BufferEnd = m_BufferBase + m_FileSizeByte;
	}
	
	BinaryReader::~BinaryReader()
	{
		fclose(m_FileHandle);
	}
}
