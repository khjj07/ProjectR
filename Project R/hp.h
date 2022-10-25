#pragma once
#include "engine.h"
#include "shape.h"
#include "event.h"
class HP : public GameObject
{
public:
	HP();
	HP(int max, Meterial meterial);
	int Get();
	void Decrease(int val);
	void Increase(int val);
	Event DeadEvent{};
private:
	int maxhp;
	int hp;
};