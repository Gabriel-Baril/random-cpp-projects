#include <iostream>

/*
* STD140 rules : https://www.oreilly.com/library/view/opengl-programming-guide/9780132748445/app09lev1sec2.html
* N = 4 bytes
* Scalar types = N
* Vec2 = 2N
* Vec3 = 4N
* Vec4 = 4N
* MAT4 = 4N x 4
*/

enum class ShaderDataType
{
	BOOL, 
	INT,
	FLOAT,
	VEC2,
	VEC3,
	VEC4,
	MAT2,
	MAT3,
	MAT4,
	COUNT
};

#define N 4 * sizeof(char)
int ShaderDataType_Alignment[] =
{
	N, // BOOL
	N, // INT
	N, // FLOAT
	2 * N, // VEC2
	4 * N, // VEC3
	4 * N, // VEC4
	4 * N, // MAT2
	4 * N, // MAT3
	4 * N, // MAT4
};

int ShaderDataType_ComponentCount[] =
{
	1, // BOOL
	1, // INT
	1, // FLOAT
	1, // VEC2
	1, // VEC3
	1, // VEC4
	2, // MAT2
	3, // MAT3
	4, // MAT4
};

struct UniformBufferEntry
{
	ShaderDataType Type;
	int Count = 1;
	const char* DebugName = "__unknown";
};

UniformBufferEntry SimpleMeshMaterialLayout[] =
{
	{ ShaderDataType::INT, 1, "AlbedoMapID" },
	{ ShaderDataType::INT, 1, "NormalMapID" },
	{ ShaderDataType::INT, 1, "RoughnessMapID" },
	{ ShaderDataType::INT, 1, "MetalnessMapID" },
	{ ShaderDataType::INT, 1, "SpecularMapID" },
};

struct SimpleMeshMaterialData
{
	int AlbedoMap;
	int NormalMap;
	int RoughnessMap;
	int MetalnessMap;
	int SpecularMap;
};

void CreateLayoutData(char* out, void** payload, int* payloadSizes, UniformBufferEntry* layout, int size)
{
	int cursor = 0;
	for (int i = 0; i < size; i++)
	{
		const UniformBufferEntry currentEntry = layout[i];
		const int rawType = static_cast<int>(currentEntry.Type);
		int typeAlignement = ShaderDataType_Alignment[rawType];
		if (currentEntry.Count > 1)
		{
			typeAlignement = 16;
		}
		
		for (int j = 0; j < currentEntry.Count; j++)
		{
			for (int k = 0; k < ShaderDataType_ComponentCount[rawType]; k++)
			{
				memcpy(&out[cursor], payload[i], payloadSizes[i]);
				cursor += typeAlignement;
			}
		}
	}
}

int main()
{
	char buffer[4096];
	memset(buffer, 0, 4096);

	SimpleMeshMaterialData data;
	data.AlbedoMap = 0;
	data.NormalMap = 1;
	data.RoughnessMap = 2;
	data.MetalnessMap = 3;
	data.SpecularMap = 4;

	void* materialData[] =
	{
		&data.AlbedoMap,
		&data.NormalMap,
		&data.RoughnessMap,
		&data.MetalnessMap,
		&data.SpecularMap,
	};

	int materialDataSizes[] =
	{
		sizeof(int),
		sizeof(int),
		sizeof(int),
		sizeof(int),
		sizeof(int)
	};

	CreateLayoutData(buffer, materialData, materialDataSizes, SimpleMeshMaterialLayout, 5);

	int a = 5;
}