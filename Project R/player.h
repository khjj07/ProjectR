#pragma once
#include "engine.h"
#include "gamePad.h"
#include "playerScript.h"
#include "shape.h"
#include "aim.h"
class Player :public GameObject
{
public:
	Player(int pos_x, int pos_y, int size_x, int size_y, string filename,Meterial meterial, Aim *aim, GamePad* pad);
private:

};