#include "Renderer.h"


Renderer::Renderer()
{

}

Renderer::~Renderer()
{

}

void* LoadFile(const char* i_pFilename, size_t& o_sizeFile);
GLib::Sprite* CreateSprite(const char* i_pFilename);


void Renderer::Run(std::vector<std::shared_ptr<GameObject>> io_Objects)
{
	// IMPORTANT: Tell GLib that we want to start rendering
	GLib::BeginRendering(DirectX::Colors::Red);
	// Tell GLib that we want to render some sprites
	GLib::Sprites::BeginRendering();

	for (const auto& io_Object : io_Objects)
	{
		if (io_Object->once == false)
		{
			if (io_Object->ball)
			{
				io_Object->velocityX = 50;
				io_Object->velocityY = -50;
			}
			io_Object->pGoodGuy = CreateSprite(io_Object->spriteFile);
			io_Object->once = true;
		}

		if (io_Object->pGoodGuy)
		{
			renderSprite(io_Object->pGoodGuy, io_Object->m_Position.x(), io_Object->m_Position.y());

		}	
	}

	// Tell GLib we're done rendering sprites
	GLib::Sprites::EndRendering();

	// IMPORTANT: Tell GLib we're done rendering
	GLib::EndRendering();

}

void Renderer::releaseSprite(GLib::Sprite* spr)
{
	if (spr)
		GLib::Release(spr);
}

void Renderer::renderSprite(GLib::Sprite* spr, float _x, float _y)
{
	
	GLib::Point2D	Offset = { _x, _y };

	// Tell GLib to render this sprite at our calculated location
	GLib::Render(*spr, Offset, 0.0f, 0.0f);
}

GLib::Sprite* CreateSprite(const char* i_pFilename)
{
	assert(i_pFilename);

	size_t sizeTextureFile = 0;

	// Load the source file (texture data)
	void* pTextureFile = LoadFile(i_pFilename, sizeTextureFile);

	// Ask GLib to create a texture out of the data (assuming it was loaded successfully)
	GLib::Texture* pTexture = pTextureFile ? GLib::CreateTexture(pTextureFile, sizeTextureFile) : nullptr;

	// exit if something didn't work
	// probably need some debug logging in here!!!!
	if (pTextureFile)
		delete[] pTextureFile;

	if (pTexture == nullptr)
		return nullptr;

	unsigned int width = 0;
	unsigned int height = 0;
	unsigned int depth = 0;

	// Get the dimensions of the texture. We'll use this to determine how big it is on screen
	bool result = GLib::GetDimensions(*pTexture, width, height, depth);
	assert(result == true);
	assert((width > 0) && (height > 0));

	// Define the sprite edges
	GLib::SpriteEdges	Edges = { -float(width / 2.0f), float(height), float(width / 2.0f), 0.0f };
	GLib::SpriteUVs	UVs = { { 0.0f, 0.0f }, { 1.0f, 0.0f }, { 0.0f, 1.0f }, { 1.0f, 1.0f } };
	GLib::RGBA							Color = { 255, 255, 255, 255 };

	// Create the sprite
	GLib::Sprite* pSprite = GLib::CreateSprite(Edges, 0.1f, Color, UVs, pTexture);

	// release our reference on the Texture
	GLib::Release(pTexture);

	return pSprite;
}

void* LoadFile(const char* i_pFilename, size_t& o_sizeFile)
{
	assert(i_pFilename != NULL);

	FILE* pFile = NULL;

	errno_t fopenError = fopen_s(&pFile, i_pFilename, "rb");
	if (fopenError != 0)
		return NULL;

	assert(pFile != NULL);

	int FileIOError = fseek(pFile, 0, SEEK_END);
	assert(FileIOError == 0);

	long FileSize = ftell(pFile);
	assert(FileSize >= 0);

	FileIOError = fseek(pFile, 0, SEEK_SET);
	assert(FileIOError == 0);

	uint8_t* pBuffer = new uint8_t[FileSize];
	assert(pBuffer);

	size_t FileRead = fread(pBuffer, 1, FileSize, pFile);
	assert(FileRead == FileSize);

	fclose(pFile);

	o_sizeFile = FileSize;

	return pBuffer;
}

