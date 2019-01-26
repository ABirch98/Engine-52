//Vector2 V2.0
//Vector2.h
#pragma once

#include <cmath>
#include <iostream>


class Vector2
{
public:
	Vector2();
	Vector2(float xpos, float ypos);
	~Vector2();

	float mX{ 0 };
	float mY{ 0 };

	float Length();
	float LengthSquared();
	float DotProduct(const Vector2& rRhs);
	float CrossProduct(const Vector2& rRhs);

	Vector2 Normalise();
	Vector2 operator +(const Vector2& rRhs) const;
	Vector2 operator -(const Vector2& rRhs) const;
	Vector2 operator *(float rRhs) const;
	Vector2 operator /(const Vector2& rRhs) const;
};

