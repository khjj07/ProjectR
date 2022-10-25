#pragma once
#include "engine.h"
#include "shape.h"
class Floor :public GameObject
{
public:
	Floor(Vector2<float> p, Vector2<int> s,string filename, Meterial meterial);
	Floor(Vector2<float> p, Vector2<int> s, string filename, Meterial meterial, enum CollisionTag tag);
private:

};