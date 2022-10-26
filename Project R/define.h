#pragma once
#include <math.h>
#include <string>
#include <vector>
#include <windows.h>
#include <Xinput.h>
#include <Xinput.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include "color.h"
#include "singleton.h"
#ifndef Sign 
#define Sign(x) (x > 0 ? 1 : -1)
#endif // !1

 


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
	Vector2<T> operator *(float f)
	{
		Vector2<T> result;
		result.x = x * f;
		result.y = y * f;
		return result;
	}

	Vector2<T> operator +(Vector2<T> B)
	{
		Vector2<T> result;
		result.x = x + B.x;
		result.y = y + B.y;
		return result;
	}
	Vector2<T> operator -(Vector2<T> B)
	{
		Vector2<T> result;
		result.x = x - B.x;
		result.y = y - B.y;
		return result;
	}

	Vector2<float> Normalize()
	{
		Vector2<float> result;
		result = (* this) * (1 / pow(pow(x, 2) + pow(y, 2), 0.5));
		return result;
	}


	Vector2<int> toInt()
	{
		Vector2<int> result;
		result.x = x;
		result.y = y;
		return result;
	}

	T distance(Vector2 a, Vector2 b)
	{
		return (T)pow(pow(a.x - b.x, 2) + pow(a.y - b.y, 2), 0.5);
	}
};

enum CollisionTag
{
	PlayerTag,
	FloorTag,
	EnemyTag,
	CursorTag,
	ButtonTag,
	BulletTag,
	WallTag,
	BedRock,
	MoteTag
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
