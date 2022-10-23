#pragma once
#include "engine.h"
#include "shape.h"
class Button :public GameObject
{
public:
	Button(int pos_x, int pos_y, int size_x, int size_y, string filename1, string filename2, Meterial meterial);
	Renderer* content;
private:

};