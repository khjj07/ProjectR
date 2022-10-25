#pragma once
#include "engine.h"
#include "shape.h"
#include "gamePad.h"
class Aim :public GameObject
{
public:
	Aim(Vector2<int> s, string filename, Meterial meterial);
	Vector2<float> direction=Vector2<float>(1,1);
	Vector2<float> velocity;
	Vector2<float> position;
	float fraction=0.5;
	float speed = 0.05;
	float range = 15;
	float response = 32000;
	void Move();
private:

};