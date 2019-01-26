//Vector2 V2.0
//Vector2.cpp
#include "Vector2.h"
Vector2::Vector2()
{
	mX = 0;
	mY = 0;
}
Vector2::Vector2(float xpos, float ypos)
{
	mX = xpos;
	mY = ypos;
}
Vector2::~Vector2()
{
}

float Vector2::Length() //this function and one below for return length and legth squared if it wasnt already obvious  
{
	return sqrt(mX * mX + mY * mY); 
}

float Vector2::LengthSquared()
{	 
	return (mX * mX + mY * mY);
}

float Vector2::DotProduct(const Vector2& rRhs) // Function for Dot Product between Vector2 class types 
{
	return mX * rRhs.mX + mY * rRhs.mY;
}

float Vector2::CrossProduct(const Vector2& rRhs) // Function for Cross Prodcut between class types 
{
	return mX * rRhs.mY - mY * rRhs.mX;
}

Vector2 Vector2::Normalise()  // Normalises given rectangle using the length
{
	Vector2 vector;
	float length = this->Length();

	if (!length == 0)
	{
		vector.mX = mX / length;
		vector.mY = mY / length;
	}
	return vector;
}

Vector2 Vector2::operator +(const Vector2 & rhs) const // below here are functions to allow specific operations to be carried out between Vector2 class types
{
	return Vector2(mX + rhs.mX, mY + rhs.mY);
}

Vector2 Vector2::operator-(const Vector2 & rhs) const						
{
	return Vector2(mX - rhs.mX, mY - rhs.mY);
}

Vector2 Vector2::operator*(float rhs)const
{
	return Vector2(mX * rhs, mY * rhs);
}

Vector2 Vector2::operator/(const Vector2 & rhs) const
{
	return Vector2(mX / rhs.mX, mY / rhs.mY);
}




