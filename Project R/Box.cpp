#include "box.h"

Box::Box(Vector2<float>p, Vector2<int>s, string filename, Meterial meterial)
{
	//transform�� �� ����
	Vector2<float> pos(p.x, p.y);
	Vector2<int> size(s.x, s.y); //collision���� ���

	//collision
	Rectangle2D* collisionShape = new Rectangle2D(size);
	//����  �� addComponent
	transform = new Transform(pos, size, this, &componentList);
	renderer = new Renderer(transform, Shape::Load(filename), meterial);
	collision = new Collision(transform,this, collisionShape, FloorTag);
	AddComponent(renderer);
	AddComponent(transform);
	AddComponent(collision);
}