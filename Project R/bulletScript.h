#pragma once
#include "transform.h"
#include "gamePad.h"
#include "collision.h"
#include "renderer.h"
#include "event.h"
class Component;
class BulletScript :public Component
{
public:
	BulletScript();
	BulletScript(Transform* t, GameObject *go,Vector2<float> g, float f, float spd, float lt, int i, int dmg);
	virtual void Update(float  dt);
	virtual void Start();
	virtual void Shoot(Vector2<float> dir);
	virtual void OnCollisionStay(Collision *other);
	Transform* transform;
	Vector2<float> gravity;
	Vector2<float> velocity;
	Vector2<float> direction;
	float speed;
	float fraction;
	float damage;
	float lifetime;
	int id;
private:

};
