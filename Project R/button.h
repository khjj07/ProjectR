#pragma once
#include "engine.h"
#include "shape.h"
class Button :public GameObject
{
public:
	Button(Vector2<float> p, Vector2<int> s, string filename1, string filename2, Meterial meterial);
	Renderer* content;
private:

};