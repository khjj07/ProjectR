#include "gameObject.h"
#include "component.h"
#include "transform.h"

template<typename T>
vector<T> create_copy(std::vector<T> const& vec)
{
	std::vector<T> v(vec);
	return v;
}

Transform::Transform(Vector2<int> p,Vector2<int> s,vector<Component *> *c)
{
	position.x = p.x;
	position.y = p.y;
	size.x = s.x;
	size.y = s.y;
	center.x = size.x / 2;
	center.y = size.y / 2;
	componentList = c;

}

