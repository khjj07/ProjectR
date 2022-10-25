#include "component.h"
#include "collision.h"
#include "transform.h"
#include "screen.h"
#include "engine.h"

Collision::Collision(Transform *t, GameObject* go, Rectangle2D* s,enum CollisionTag id)
{
	gameObject = go;
	shape = s;
	transform = t;
	tag = id;
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
		check = !((A1.x < A2.x && B1.x < A2.x) || (A1.y < A2.y && B1.y < A2.y) || (A1.x > B2.x && B1.x > B2.x) || (A1.y > B2.y && B1.y > B2.y));


		if (check)
		{
			entered = true;
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

bool Collision::CollisionStay(Collision* other)
{
	bool check = true;
	Vector2<int>A1 = other->shape->A + other->transform->position.toInt();
	Vector2<int>B1 = other->shape->B + other->transform->position.toInt();

	Vector2<int>A2 = shape->A + transform->position.toInt();
	Vector2<int>B2 = shape->B + transform->position.toInt();
	check = !((A1.x < A2.x&& B1.x < A2.x) || (A1.y < A2.y&& B1.y < A2.y) || (A1.x > B2.x+1 && B1.x > B2.x + 1) || (A1.y > B2.y + 1 && B1.y > B2.y + 1));
	return check;
}

bool Collision::CollisionExit(Collision* other)
{
	if (entered)
	{
		bool check = false;
		Vector2<int>A1 = other->shape->A + other->transform->position.toInt();
		Vector2<int>B1 = other->shape->B + other->transform->position.toInt();
		Vector2<int>A2 = shape->A + transform->position.toInt();
		Vector2<int>B2 = shape->B + transform->position.toInt();
		check = ((A1.x <= A2.x && B1.x <= A2.x) || (A1.y <= A2.y && B1.y <= A2.y) || (A1.x >= B2.x && B1.x >= B2.x) || (A1.y >= B2.y && B1.y >= B2.y));
		if (check)
		{
			entered = false;
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
	
}
