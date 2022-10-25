#pragma once
#include "gameObject.h"
#include "GamePad.h"
#include "cursorScript.h"
#include "engine.h"
#include "shape.h"
class Cursor :public GameObject
{
public:
	Cursor(Vector2<float> p, Vector2<int> s, string filename, Meterial meterial, GamePad* pad);
private:

};