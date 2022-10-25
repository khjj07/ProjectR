#pragma once
#include "engine.h"
#include "shape.h"
class HP : public GameObject
{
public:
	HP();
	HP(int max, Meterial meterial);
	int Get();
	void Decrease(int val);
	void Increase(int val);
private:
	int maxhp;
	int hp;
};