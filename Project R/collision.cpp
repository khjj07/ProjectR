#include "component.h"
#include "collision.h"
#include "transform.h"
#include "screen.h"
#include "engine.h"

Collision::Collision(Transform *t, Rectangle2D* s,enum CollisionTag id)
{

	shape = s;
	transform = t;
	tag = id;
	Engine::Instance()->AddCollision(this);
}

bool Collision::CollisionEnter(Collision* other)
{
	bool check = true;
	Vector2<int>A1 =other->shape->A + other->transform->position.toInt();
	Vector2<int>B1 = other->shape->B + other->transform->position.toInt();

	Vector2<int>A2 = shape->A + transform->position.toInt();
	Vector2<int>B2 = shape->B +transform->position.toInt();
	if (!entered)
	{
		 check=!((A1.x <= A2.x && B1.x<=A2.x) || (A1.y <= A2.y && B1.y <= A2.y) || (A1.x >= B2.x && B1.x >= B2.x) || (A1.y >= B2.y && B1.y >= B2.y));


		if (check)
		{
			entered = true;
			return true;
		}
		else
			return false;
	}
}

bool Collision::CollisionStay(Collision* other)
{
	bool check = true;
	Vector2<int>A1 = other->shape->A + other->transform->position.toInt();
	Vector2<int>B1 = other->shape->B + other->transform->position.toInt();

	Vector2<int>A2 = shape->A + transform->position.toInt();
	Vector2<int>B2 = shape->B + transform->position.toInt();
	check = !((A1.x <= A2.x && B1.x <= A2.x) || (A1.y <= A2.y && B1.y <= A2.y) || (A1.x >= B2.x && B1.x >= B2.x) || (A1.y >= B2.y && B1.y >= B2.y));
	return check;
}

bool Collision::CollisionExit(Collision* other)
{
	if (entered)
	{
		if (Collision::CollisionStay(other))
		{
			return false;
		}
		else
		{
			entered = false;
			return true;
		}
	}
	
}
