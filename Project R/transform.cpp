#include "component.h"
#include "transform.h"


template<typename T>
vector<T> create_copy(std::vector<T> const& vec)
{
	std::vector<T> v(vec);
	return v;
}

Transform::Transform(Vector2<float> p, Vector2<int>s, GameObject* go, vector<Component*>* c)
{
	position.x = p.x;
	position.y = p.y;
	size.x = s.x;
	size.y = s.y;
	center.x = size.x / 2;
	center.y = size.y / 2;
	componentList = c;
	gameObject = go;
}

