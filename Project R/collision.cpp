#include "collision.h"
#include "transform.h"
struct Static
{

};

template<typename T>
Collision<T>::Collision(Transform *t,int width,int height,int id)
{

	transform = t;
}

template<typename T>
bool Collision<T>::OnCollisionEnter(Collision other)
{
	int x, y = transform->position.x, transform->position.y;
	int distance = Vector2<int>::distance(transform->position,other.transform->position);

	for (int i = 0; i < Height; y++)
	{
		for (int j = 0; j < Width; x++)
		{
			x + j + (y + i) * Screen::Width;
		}
	}
	transform->position
}
template<typename T>
bool Collision<T>::OnCollisionStay(Collision other);
template<typename T>
bool Collision<T>::OnCollisionExit(Collision other);
