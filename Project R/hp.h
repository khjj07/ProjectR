#pragma once
#include "engine.h"
#include "shape.h"
#include "event.h"
#include "gamePadManager.h"
class HP : public GameObject
{
public:
	HP();
	HP(int max,int id, Meterial meterial);
	int Get();
	bool Decrease(int val);
	void Increase(int val);
	void Reset();
	int id;
private:
	int maxhp;
	int hp;
};