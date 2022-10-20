#pragma once
#include <math.h>
#include <vector>
using namespace std;
template<typename T>
struct Vector2
{
	T x;
	T y;
	Vector2<T>()
	{

	}
	Vector2<T>(T a,T b)
	{
		x = a;
		y = b;
	}
	static Vector2<T> add(Vector2<T>A, Vector2<T>B)
	{
		Vector2<T> result;
		result.x = A.x + B.x;
		result.y = A.y + B.y;
		return result;
	}
	T distance(Vector2 a, Vector2 b)
	{
		return (T)pow(pow(a.x - b.x, 2) + pow(a.y - b.y, 2), 0.5);
	}
};


struct Rectangle2D {
	Vector2<int> A;
	Vector2<int> B;
	Rectangle2D(Vector2<int> size)
	{
		A.x = 0;
		A.y = 0;
		B.x = size.x;
		B.y = size.y;
	}
};
