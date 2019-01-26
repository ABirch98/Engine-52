//Engine52 V1.08 Graphics Handler
//Grahics.h contains the functions and member variables for the Graphics handler
#pragma once
#include <HAPI_lib.h>
#include "Rectangle.h"
#include <unordered_map>
using namespace HAPISPACE;



class Texture; // forward declaration

class Graphics
{
	
	
private:
	int  mScreenHeight{ 600 };
	int  mScreenWidth{ 800 };//screen dimensions...

	unsigned int mOffset{ 0 };
	int XOffset{ 0 };//offset integers 
	int YOffset{ 0 };

	BYTE *mScreen{ nullptr };// pointer to screen buffer position 
	BYTE *mPointer{ nullptr };

	const Rectangle mScreenrect{ mScreenWidth, mScreenHeight };// Creates a rectangle using screen dimensions
	

	std::unordered_map<std::string, Texture*> mTextureMap; //map to store textures 
	

	HAPI_TColour mBackground{ HAPI_TColour::BLACK };

public:
	Graphics();
	~Graphics();

	bool Initialise();
	bool CreateSprite(const std::string& rFilename, const std::string& rName);

	void FastBlit(const std::string& rName, int posX, int posY) const;
	void AlphaBlit(const std::string& rName, int posX, int posY) const;

	void ClipBlit(const std::string& rName, int posX, int posY, int& rFrameNumber, int frameWidth, int frameHeight, int frameSize)const;
	
	Rectangle GetRect(const std::string& rName,int frameCount);
	

	void ClearToColour();
	void ClearToGreyscale(int greyscaleColour);
};

