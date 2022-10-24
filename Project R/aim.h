#pragma once
#include "engine.h"
#include "shape.h"
#include "gamePad.h"
class Aim :public GameObject
{
public:
	Aim(int size_x, int size_y, string filename, Meterial meterial);
	Vector2<float> direction;
	Vector2<float> velocity;
	Vector2<float> position;
	float fraction=0.5;
	float speed = 50;
	float range = 50;
	void Move();
private:

};