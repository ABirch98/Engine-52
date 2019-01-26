//Engine52 Graphics Handler
//Graphics.cpp Implentations of graphics handler functions 
#include "Graphics.h"
#include "Texture.h"



Graphics::Graphics()
{
}


Graphics::~Graphics()
{
	std::unordered_map<std::string, Texture*>::iterator it;

	for (it = mTextureMap.begin(); it != mTextureMap.end(); ++it)// iterator loop to empty texture map //TODO Change this to more efficient deletion 
	{
		delete it->second;
	}
		

}

bool Graphics::Initialise()//opens HAPI screen with set screen dimensions, sets up screen pointer and turns on fps counter for debug 
{
	if (HAPI.Initialise(mScreenWidth, mScreenHeight, "MY HAPI SPACE") == false)
	{
		return false;
	}
	else 
	{
		mScreen = HAPI.GetScreenPointer();
		HAPI.SetShowFPS(true);// , S_Width - 100, 0, HAPI_TColour::HORRID_PINK);//FPS Counter
		return true;
	}

}
void Graphics::ClearToColour()//clears to any given colour (slower)
{

	for (int i = 0; i < mScreenHeight; i++)
	{
		YOffset = i;
		for (int t = 0; t < mScreenWidth; t++)
		{
			XOffset = t;
			mOffset = (XOffset + YOffset * mScreenWidth) * 4;
			mPointer = mScreen + mOffset; // adjusts pointer by 1 offset of 4 bytes of memory 
			memcpy(mPointer, &mBackground, 4);
		}
	}
}

void Graphics::ClearToGreyscale(int greyScaleColour)//clears to a colour fast from white to grey 
{
	memset(mScreen, greyScaleColour, mScreenWidth*mScreenHeight * 4);
}

bool Graphics::CreateSprite(const std::string& rFilename, const std::string& rName)// creates new texture 
{
	Texture *pNewTexture = new Texture; 
	if (!pNewTexture->LoadTexture(rFilename) == true)
	{
		delete pNewTexture;
		HAPI.UserMessage(rFilename+" failed to load", "ERROR", HAPI_ButtonType::eButtonTypeOk, 0);
		return false;
	}
	mTextureMap[rName] = pNewTexture;
	return true;
}
void Graphics::FastBlit(const std::string& rName, int posX, int posY) const // a fast texture drawing option with no alpha handling  
{
	if (mTextureMap.find(rName) == mTextureMap.end())
	{
		HAPI.UserMessage("cant find " + rName +" to fast Blit", "ERROR", HAPI_ButtonType::eButtonTypeOk, 0);
		return;
	}
	

	mTextureMap.at(rName)->Blit(mScreen, mScreenWidth, mScreenHeight, posX, posY);
}
void Graphics::AlphaBlit(const std::string& rName, int posX, int posY) const // slightly slower texture drawing including alpha handling 
{
	if (mTextureMap.find(rName) == mTextureMap.end())
	{
		HAPI.UserMessage("cant find " + rName + " to alpha blit", "ERROR", HAPI_ButtonType::eButtonTypeOk, 0);
		return;
	}
		


	mTextureMap.at(rName)->AlphaBlit(mScreen, mScreenWidth, mScreenHeight, posX, posY);
	
}

void Graphics::ClipBlit(const std::string& rName, int posX, int posY, int& rFrameNumber, int frameWidth, int frameHeight, int frameSize) const // slowest texture drawing however can handle off screen drawing through clipping 
{
	if (mTextureMap.find(rName) == mTextureMap.end())
	{
		HAPI.UserMessage("cant find " + rName + " to clip", "ERROR", HAPI_ButtonType::eButtonTypeOk, 0);
		return;
	}
		
	mTextureMap.at(rName)->ClipBlit(mScreen, mScreenrect, posX, posY, rFrameNumber, frameWidth, frameHeight, frameSize);

}

Rectangle Graphics::GetRect(const std::string& rName,int frameCount)// creates a rectangle using rectangle support class 
{
	if (mTextureMap.find(rName) == mTextureMap.end())
	{
		HAPI.UserMessage("cant find texture " + rName + " to make rectangle", "ERROR", HAPI_ButtonType::eButtonTypeOk, 0);
		HAPI.Close();
	}
	return Rectangle(mTextureMap.at(rName)->GetWidth(frameCount), mTextureMap.at(rName)->GetHeight());
}
