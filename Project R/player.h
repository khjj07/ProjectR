#pragma once
#include "engine.h"
#include "gamePad.h"
#include "playerScript.h"
#include "shape.h"
#include "aim.h"
class Player :public GameObject
{
public:
	Player(Vector2<float> p, Vector2<int> s, string filename, Meterial meterial, Aim *aim, HP* hp, GamePad* pad, int i);
private:

};