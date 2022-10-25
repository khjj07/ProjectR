#include "wall.h"

Wall::Wall(Vector2<float> p, Vector2<int>s, string filename, Meterial meterial)
{
	//transform�� �� ����
	Vector2<float> pos(p.x, p.y);
	Vector2<int> size(s.x, s.y);


	//collision
	Rectangle2D* collisionShape = new Rectangle2D(size);
	//����  �� addComponent
	transform = new Transform(pos, size, this, &componentList);
	renderer = new Renderer(transform, Shape::Load(filename), meterial);
	collision = new Collision(transform, this, collisionShape, WallTag);
	AddComponent(renderer);
	AddComponent(transform);
	AddComponent(collision);
}
Wall::Wall(Vector2<float> p, Vector2<int>s, string filename, Meterial meterial, enum CollisionTag tag)
{
	//transform�� �� ����
	Vector2<float> pos(p.x, p.y);
	Vector2<int> size(s.x, s.y);


	//collision
	Rectangle2D* collisionShape = new Rectangle2D(size);
	//����  �� addComponent
	transform = new Transform(pos, size, this, &componentList);
	renderer = new Renderer(transform, Shape::Load(filename), meterial);
	collision = new Collision(transform, this, collisionShape, tag);
	AddComponent(renderer);
	AddComponent(transform);
	AddComponent(collision);
}