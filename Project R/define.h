#pragma once
#include <math.h>
template<typename T>
struct Vector2
{
	T x;
	T y;
	T distance(Vector2 a, Vector2 b)
	{
		return (T)pow(pow(a.x - b.x, 2) + pow(a.y - b.y, 2), 0.5);
	}
};