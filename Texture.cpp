//Engine52 v1.08 Graphics Handler
//Texture.cpp contains implementation of functions of texture class for graphics handler
#include "Texture.h"




Texture::Texture()
{
	
}


Texture::~Texture()
{
	delete[]mpData;
}

bool Texture::LoadTexture(const std::string& rFilename) 
{
	if (!HAPI.LoadTexture(rFilename, &mpData, mWidth, mHeight))
		return false;
	else
		return true;
	
	
}
void Texture::Blit(BYTE *pScreen, int screenWidth, int screenHeight, int posX, int posY)
{
	BYTE *p_screen_pointer = pScreen + (posX + posY * screenWidth) * 4; //sets screen pointer to the start of the texture
	BYTE *p_texture_pointer = mpData; //sets texture pointer to start of texture
	for (int y = 0; y < mHeight; y++) // loops through the lines of the texture
	{
		memcpy(p_screen_pointer, p_texture_pointer, mWidth * 4);
		p_texture_pointer += mWidth * 4;//increases the pointers by 1 line
		p_screen_pointer += screenWidth * 4;
	}
}
void Texture::AlphaBlit(BYTE *pScreen, int screenWidth, int screenHeight, int posX, int posY)
{
	BYTE *p_screen_pointer = pScreen + (posX + posY * screenWidth) * 4;
	BYTE *p_texture_pointer = mpData;
	mScreenIncrement = (screenWidth - mWidth) * 4;
	
	for (int y = posY; y < posY + mHeight; y++) 
	{

		for (int x = posX; x < posX + mWidth; x++)
		{

			BYTE blue = p_texture_pointer[0];//
			BYTE green = p_texture_pointer[1];//gives BYTE values for the 4 texture colour channels 
			BYTE red = p_texture_pointer[2];//
			BYTE alpha = p_texture_pointer[3];//

			if (alpha == 255.0f) //if alpha is maximum draw the texture 
			{
				memcpy(p_screen_pointer, p_texture_pointer, 4);//copies the pixel to the buffer at the position given by the screen buffer
			}
			else if (!alpha == 0.0f)
			{
				p_screen_pointer[0] = p_screen_pointer[0] + ((alpha*(blue - p_screen_pointer[0])) >> 8);//
				p_screen_pointer[1] = p_screen_pointer[1] + ((alpha*(green - p_screen_pointer[1])) >> 8);//
				p_screen_pointer[2] = p_screen_pointer[2] + ((alpha*(red - p_screen_pointer[2])) >> 8);//
			}
			p_texture_pointer += 4;
			p_screen_pointer += 4;
		}

		p_screen_pointer += mScreenIncrement;


	}

}
int Texture::GetWidth(const int& rFrameCount) const
{
	if (rFrameCount != 0)
	{
		return mWidth / rFrameCount;
	}
	else
	{
		return mWidth;
	}
}
int Texture::GetHeight() const
{
	return mHeight;
}
void Texture::ClipBlit(BYTE *pDest, const Rectangle& rDestRect, int posX, int posY, int& rFrameNumber, int frameWidth, int frameHeight,int framesize)
{
	

	Rectangle new_source_rectangle(0, frameWidth, 0, frameHeight);

	if (new_source_rectangle.OutsideOf(rDestRect))
		return;
	if (!rDestRect.Contains(new_source_rectangle))
	{
		new_source_rectangle.Transform(posX, posY);

		new_source_rectangle.ClipTo(rDestRect);

		new_source_rectangle.Transform(-posX, -posY);

		if (posX < 0)
		{
			posX = 0;

		}

		if (posY < 0)
		{
			posY = 0;

		}
	}


	new_source_rectangle.Transform(rFrameNumber*framesize,0);
	


	BYTE *p_screen_pointer = pDest + (posX + posY * rDestRect.Width() ) * 4;
	BYTE *p_texture_pointer = mpData + (new_source_rectangle.mLeft + new_source_rectangle.mTop * mWidth) * 4;
	mScreenIncrement = (rDestRect.Width() - new_source_rectangle.Width()) * 4;
	mTextureIncrement = (mWidth - new_source_rectangle.Width()) * 4;

	for (int y = posY; y < posY + new_source_rectangle.Height(); y++)
	{

		for (int x = posX; x < posX + new_source_rectangle.Width(); x++)
		{

			BYTE blue = p_texture_pointer[0];//
			BYTE green = p_texture_pointer[1];//gives BYTE values for the 4 texture colour channels 
			BYTE red = p_texture_pointer[2];//
			BYTE alpha = p_texture_pointer[3];//

			if (alpha == 255.0f) //if alpha is maximum draw the texture 
			{
				memcpy(p_screen_pointer, p_texture_pointer, 4);//copies the pixel to the buffer at the position given by the screen buffer
			}
			else if (!alpha == 0.0f)
			{
				p_screen_pointer[0] = p_screen_pointer[0] + ((alpha*(blue - p_screen_pointer[0])) >> 8);//
				p_screen_pointer[1] = p_screen_pointer[1] + ((alpha*(green - p_screen_pointer[1])) >> 8);//
				p_screen_pointer[2] = p_screen_pointer[2] + ((alpha*(red - p_screen_pointer[2])) >> 8);//
			}
			p_texture_pointer += 4;
			p_screen_pointer += 4;
		}

		p_screen_pointer += mScreenIncrement;
		p_texture_pointer += mTextureIncrement;


	}
	
}

