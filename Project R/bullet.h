#pragma once
#include "engine.h"
#include "bullet.h"
#include "bulletScript.h"
#include "shape.h"
class Bullet :public GameObject
{
public:
	Bullet();
	Bullet(Vector2<float> p, Vector2<float>direction,int id);
	Bullet(Vector2<float> p, Vector2<int> s, string filename, Meterial meterial,BulletScript* script);
	int damage;
	BulletScript* script;
	void Shoot(Vector2<float> dir);
private:

};