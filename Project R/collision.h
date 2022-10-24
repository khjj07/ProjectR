#pragma once

#include "component.h"
#include "transform.h"
#include <vector>

class Collision :public Component
{
public:
	Collision(Transform* t, Rectangle2D *s, enum CollisionTag id);
	bool CollisionEnter(Collision* other);
	bool CollisionStay(Collision* other);
	bool CollisionExit(Collision* other);
	Transform* transform;
	Rectangle2D *shape;
	enum CollisionTag tag;
	bool entered = false;
private:
};