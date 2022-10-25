#pragma once
#include "engine.h"
#include "shape.h"
class Wall :public GameObject
{
public:
	Wall(Vector2<float> p, Vector2<int> s, string filename, Meterial meterial);
	Wall(Vector2<float> p, Vector2<int> s, string filename, Meterial meterial,enum CollisionTag tag);
private:

};