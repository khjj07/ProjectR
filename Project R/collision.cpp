#include "collision.h"
#include "transform.h"
#include "screen.h"
template<typename T>
Collision<T>::Collision(Transform *t,int width,int height,int id)
{
	size.x = width;
	size.y = height;
	transform = t;
}

template<typename T>
bool Collision<T>::OnCollisionEnter(Collision other)
{
	int x = transform->position.x, y = transform->position.y;
	int distance = Vector2<int>::distance(transform->position,other.transform->position);
	int range_between = size.x / 2 + other.size.x / 2;
	if (range_between > distance)
		return true;
	else
		return false;
}
template<typename T>
bool Collision<T>::OnCollisionStay(Collision other);
template<typename T>
bool Collision<T>::OnCollisionExit(Collision other);
