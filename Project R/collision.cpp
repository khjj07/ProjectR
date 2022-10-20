#include "component.h"
#include "collision.h"
#include "transform.h"
#include "screen.h"
#include "engine.h"

Collision::Collision(Transform *t, Rectangle2D* s,int id)
{
	shape = s;
	transform = t;
	Engine::Instance()->AddCollision(this);
}

bool Collision::CollisionEnter(Collision* other)
{
	bool check = true;
	Vector2<int>A1 = Vector2<int>::add(other->shape->A,other->transform->position);
	Vector2<int>B1 = Vector2<int>::add(other->shape->B, other->transform->position);

	Vector2<int>A2 = Vector2<int>::add(shape->A , transform->position);
	Vector2<int>B2 = Vector2<int>::add(shape->B , transform->position);
	if (!entered)
	{
		check |= (A1.x >= A2.x && A1.x <= B2.x) && (A1.y >= A2.y && A1.y <= B2.y);
		check |= (B1.x >= A2.x && B1.x <= B2.x) && (B1.y >= A2.y && B1.y <= B2.y);
		check |= (A1.x <= B2.x && A1.y <= B2.y) && (B1.x >= A2.x && B1.y <= A2.y);


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
	Vector2<int>A1 = Vector2<int>::add(other->shape->A, other->transform->position);
	Vector2<int>B1 = Vector2<int>::add(other->shape->B, other->transform->position);

	Vector2<int>A2 = Vector2<int>::add(shape->A, transform->position);
	Vector2<int>B2 = Vector2<int>::add(shape->B, transform->position);
	check &= A1.x >= A2.x && A1.x <= B2.x || B1.x >= A2.x && B1.x <= B2.x;
	check &= A1.y >= A2.y && A1.y <= B2.y || B1.y >= A2.y && B1.y <= B2.y;
	check |= A1.x >= A2.x && A1.x <= B2.x && B1.x >= A2.x && B1.x <= B2.x && (A1.y >= A2.y && A1.y <= B2.y || B1.y >= A2.y && B1.y <= B2.y);
	check |= A1.y >= A2.y && A1.y <= B2.y && B1.x >= A2.y && B1.y<= B2.y &&(A1.x >= A2.x && A1.x <= B2.x || B1.x >= A2.x && B1.x <= B2.x);
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
