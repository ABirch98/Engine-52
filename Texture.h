//Engine52 v1.08 Graphics Handler 
//Texture.h Functions and member variable for texture class in graphics handler 
#pragma once
#include <String>
#include"HAPI_lib.h"
#include"Rectangle.h"
#include "Graphics.h"


using namespace HAPISPACE;
class Texture
{
public:
	Texture();
	~Texture();


	bool LoadTexture(const std::string& rFilename);
	void Blit(BYTE *pScreen, int screenWidth, int screenHeight, int posX, int posY);
	void ClipBlit(BYTE *pDest, const Rectangle& rDestRect, int posX, int posY, int& rFrameNumber, int frameWidth, int frameHeight, int frameSize);
	void AlphaBlit(BYTE *pScreen, int screenWidth, int screenHeight, int posX, int posY);
	int GetWidth(const int& rFrameCount) const;
	int GetHeight() const;


private:
	int mScreenIncrement{ 0 };
	int mTextureIncrement{ 0 };
	int mWidth{ 0 };
	int mHeight{ 0 };
	int mCounter{ 0 };
	int mLevel = {0};
	BYTE* mpData{ nullptr };

};

