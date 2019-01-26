//Rectangle class v2.0
//Rectangle.cpp 
#include "Rectangle.h"






Rectangle::~Rectangle()
{
}


void Rectangle::ClipTo(const Rectangle& rOtherRectangle)
{
	if (mRight > rOtherRectangle.mRight)
	{
		mRight = rOtherRectangle.mRight;
	}
	if (mBottom > rOtherRectangle.mBottom)
	{
		mBottom = rOtherRectangle.mBottom;
	}
	if (mLeft < rOtherRectangle.mLeft)
	{
		mLeft = rOtherRectangle.mLeft;
	}
	if (mTop < rOtherRectangle.mTop)
	{
		mTop = rOtherRectangle.mTop;
	}
}
	

bool Rectangle::Contains(const Rectangle& rOtherRectangle) const
{
	if (mRight < rOtherRectangle.mRight && mLeft > rOtherRectangle.mLeft && mTop > rOtherRectangle.mTop && mBottom < rOtherRectangle.mBottom)
	{
		return true;
	}
	else
		return false;
}	
bool Rectangle::OutsideOf(const Rectangle& rOtherRectangle) const
{
	if (((mLeft > rOtherRectangle.mRight) || (mRight < rOtherRectangle.mLeft)) || ((mTop > rOtherRectangle.mBottom) || (mBottom < rOtherRectangle.mTop)) )
	{
		return true;
	}	
	else
		return false;
}	
void Rectangle::Transform(int dX, int dY)
{
	mLeft = dX + mLeft;
	mRight = dX + mRight;
	mTop = dY + mTop;
	mBottom = dY + mBottom;
}