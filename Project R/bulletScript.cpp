#include "component.h"
#include "bulletScript.h"
#include "gameStateManager.h"
#include "Mote.h"

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
	srand(time(NULL));
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

void BulletScript::OnDestory()
{
	
	
}

void BulletScript::OnCollisionStay(Collision* other)
{
	if (other->tag == WallTag || other->tag == FloorTag)
	{
		for (size_t i = 0; i < 1; i++)
		{
			Engine::Instance()->Instantiate(new Mote(transform->position+ direction * -10, direction * -1, rand() % 100));
		}
		Destory();
	}
}
