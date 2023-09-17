#include "BinaryWriter.h"

namespace hedron
{
	BinaryWriter::BinaryWriter(const char* filename)
	{
		fopen_s(&m_FileHandle, filename, "wb"); // write binary
	}

	BinaryWriter::~BinaryWriter()
	{
		fclose(m_FileHandle);
	}

}
