//Rectangle class v2.0
//Rectangle.h
#pragma once
#include <iostream>
#include <algorithm>
class Rectangle
{
	
public:
	int mLeft{ 0 }, mRight{ 0 }, mTop{ 0 }, mBottom{ 0 };
	Rectangle()=default;
	Rectangle(int l, int r, int t, int b) : mLeft(l), mRight(r), mTop(t), mBottom(b) {}
	Rectangle(int w, int h) : mLeft(0), mRight(w), mTop(0), mBottom(h){}
	
	~Rectangle();

	int Width() const { return mRight - mLeft; }
	int Height() const { return mBottom - mTop; }

	void ClipTo(const Rectangle& rOtherRectangle);
	bool Contains(const Rectangle& rOtherRectangle) const;
	bool OutsideOf(const Rectangle& rOtherRectangle) const;
	void Transform(int dX, int dY);

};

