#include <iostream>
#include <string_view>
#include <vector>
#include <fstream>
#include <stdio.h>

#include "BinaryReader.h"
#include "BinaryWriter.h"
#include "BufferReader.h"
#include "main.h"

enum class AssetType : uint16_t
{
	TEXTURE,
	LIGHT_PRESET
};

struct Asset
{
	AssetType type;
	uint64_t byteSize;
	uint8_t* data = nullptr;
};

struct TextureData
{
	static constexpr AssetType type = AssetType::TEXTURE;
	uint32_t width;
	uint32_t height;
	uint8_t* pixels;

	Asset CreateAsset()
	{
		uint64_t byteSize = sizeof(width) + sizeof(height) + width * height * sizeof(uint8_t); // Evaluate Byte Size Callback ?
		return { AssetType::TEXTURE, byteSize, (uint8_t*)this};
	}

	~TextureData()
	{
		delete[] pixels;
	}
};

struct vec3f
{
	float x, y, z;
};

struct LightPresetData
{
	static constexpr AssetType type = AssetType::LIGHT_PRESET;

	vec3f color;
	float diffuseFactor;
	float ambientLightFactor;
	float specularLightFactor;

	Asset CreateAsset()
	{
		return { AssetType::LIGHT_PRESET, sizeof(LightPresetData), (uint8_t*)this};
	}
};

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))
void CreateFastFile(const char* filename, uint16_t majorVersion, uint16_t minorVersion, const std::vector<Asset>& assets)
{
	hedron::BinaryWriter writer(filename);

	writer.Write<uint16_t>(majorVersion);
	writer.Write<uint16_t>(minorVersion);
	writer.Write<uint64_t>(assets.size());
	uint64_t totalAssetByteSize = 0;
	for (const auto& asset : assets)
	{
		totalAssetByteSize += asset.byteSize;
	}
	writer.Write<uint64_t>(totalAssetByteSize);

	for (const auto& asset : assets)
	{
		writer.Write<uint16_t>(static_cast<uint16_t>(asset.type));
		writer.Write<uint64_t>(static_cast<uint64_t>(asset.byteSize));
		if (asset.byteSize > 0)
		{
			writer.Write<uint8_t>(asset.data, asset.byteSize);
		}
	}
}

// Use this in the binaryReader class

void ReadFastFile(const char* filename, std::vector<Asset>& outAssets)
{
	char buffer[4096];
	hedron::BinaryReader reader(filename, buffer, 200);

	std::cout << "Major version: " << reader.Read<uint16_t>() << std::endl;
	std::cout << "Minor version: " << reader.Read<uint16_t>() << std::endl;
	std::cout << "Asset Count: " << reader.Read<uint64_t>() << std::endl;
	std::cout << "Total Asset Byte Size: " << reader.Read<uint64_t>() << std::endl;

	while(!reader.Finished())
	{
		AssetType assetType = (AssetType)reader.Read<uint16_t>();
		uint64_t assetByteSize = reader.Read<uint64_t>();
		std::cout << "Asset Type: " << (uint16_t)assetType << std::endl;
		std::cout << "Asset Byte Size: " << assetByteSize << std::endl;
		if (assetByteSize > 0)
		{
			uint8_t* assetData = reader.Read<uint8_t>(assetByteSize);
			hedron::BufferReader assetDataReader(assetData, assetByteSize);
			switch (assetType)
			{
			case AssetType::TEXTURE:
			{
				TextureData texture;
				texture.width = assetDataReader.Read<uint32_t>();
				texture.height = assetDataReader.Read<uint32_t>();
				texture.pixels = new uint8_t[texture.width * texture.height];
				for (int i = 0; i < texture.width * texture.height; i++)
				{
					texture.pixels[i] = assetDataReader.Read<uint8_t>();
				}

				std::cout << "Texture Asset" << std::endl;
				std::cout << "	Width: " << texture.width << std::endl;
				std::cout << "	Height: " << texture.height << std::endl;
				std::cout << "	Pixels:\n";
				for (int i = 0; i < texture.width * texture.height; i++)
				{
					std::cout << (uint32_t)texture.pixels[i] << std::endl;
				}
				break;
			}
			case AssetType::LIGHT_PRESET:
			{
				LightPresetData lightPreset = *reinterpret_cast<LightPresetData*>(assetData);
				std::cout << "Light Preset Asset" << std::endl;
				std::cout << "	Color: " << "[" << lightPreset.color.x << "," << lightPreset.color.y << "," << lightPreset.color.z << "]" << std::endl;
				std::cout << "	Diffuse Factor: " << lightPreset.diffuseFactor << std::endl;
				std::cout << "	Ambient Light Factor: " << lightPreset.ambientLightFactor << std::endl;
				std::cout << "	Specular Light Factor: " << lightPreset.specularLightFactor << std::endl;
				break;
			}
			}
		}
	}
}

void Pack()
{
	TextureData texture;
	texture.width = 2;
	texture.height = 2;
	texture.pixels = new uint8_t[texture.width * texture.height];
	texture.pixels[0] = 0;
	texture.pixels[1] = 100;
	texture.pixels[2] = 50;
	texture.pixels[3] = 145;

	LightPresetData light;
	light.color = { 0.2f, 0.8f, 0.6f };
	light.ambientLightFactor = 23.2f;
	light.diffuseFactor = 12.56f;
	light.specularLightFactor = 2.9f;

	std::vector<Asset> assetsToPack = { texture.CreateAsset(), light.CreateAsset() };
	CreateFastFile("packed_file.ff", 2, 1, assetsToPack);
}

void Unpack()
{
	std::vector<Asset> assetToUnpack;
	ReadFastFile("packed_file.ff", assetToUnpack);
}

int main()
{
	// Pack();
	// Unpack();

	auto v1 = std::hash<std::string_view>()("Bonjour");
	auto v2 = std::hash<std::string_view>()("Bonjour");
	auto v3 = std::hash<std::string_view>()("Alkjwhoijhlkdsfg");
	auto v4 = std::hash<std::string_view>()("B");
	auto v5 = std::hash<std::string_view>()("C");
	std::cout << v1 << std::endl;
	std::cout << v2 << std::endl;
	std::cout << v3 << std::endl;
	std::cout << v4 << std::endl;
	std::cout << v5 << std::endl;
}