#include "component.h"
#include "moteScript.h"
#include "gameStateManager.h"


MoteScript::MoteScript(Transform* t,Vector2<float>d ,Vector2<float> g, float f, float spd)
{
	direction = d;
	speed = spd;
	transform = t;
	gravity = g;
	fraction = f;
	velocity = Vector2<float>(0, -20);
}


void MoteScript::Start()
{

}
void MoteScript::Update(float dt)
{
	transform->position = transform->position + velocity * dt;
	velocity = velocity + gravity;
	velocity = velocity - velocity * fraction;
}

void MoteScript::Shoot(Vector2<float> dir)
{
	
}

void MoteScript::OnCollisionStay(Collision* other)
{
	if (other->tag == WallTag || other->tag == FloorTag)
	{
		Destory();
	}
}
