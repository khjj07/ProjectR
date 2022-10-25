#include "component.h"
#include "bulletScript.h"
#include "gameStateManager.h"


BulletScript::BulletScript(Transform* t, GameObject* go, Vector2<float> g, float f, float spd, float lt, int i, int dmg)
{
	transform = t;
	gravity = g;
	fraction = f;
	speed = spd;
	damage = dmg;
	lifetime = lt;
	id = i;
	gameObject = go;
}


void BulletScript::Start()
{

}
void BulletScript::Update(float dt)
{
	transform->position = transform->position + velocity * dt;
	velocity = velocity + gravity;
	velocity = velocity - velocity * fraction;
}

void BulletScript::Shoot(Vector2<float> dir)
{
	velocity=dir* speed;
}

void BulletScript::OnCollisionStay(Collision* other)
{
	if (other->tag == WallTag || other->tag == FloorTag)
	{
		Destory();
	}
}
