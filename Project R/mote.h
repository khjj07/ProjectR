#pragma once
#include "engine.h"
#include "bullet.h"
#include "moteScript.h"
#include "shape.h"
class Mote :public GameObject
{
public:
	Mote();
	Mote(Vector2<float> p, Vector2<float>direction,int seed);
	MoteScript* script;
private:

};