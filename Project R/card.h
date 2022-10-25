#pragma once
#include "engine.h"
#include "shape.h"
#include "player.h"
class Card :public GameObject
{
public:
	Card(Vector2<float> p, Vector2<int> s, string filename1, Meterial meterial);
	void Select();
	void UnSelect();
	void Apply(GameObject *target);
private:

};