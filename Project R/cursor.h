#pragma once
#include "gameObject.h"
#include "GamePad.h"
#include "cursorScript.h"
#include "engine.h"
#include "shape.h"
class Cursor :public GameObject
{
public:
	Cursor(int pos_x, int pos_y, int size_x, int size_y, string shape, Meterial meterial, GamePad* pad);
private:

};