#include "box.h"

Box::Box(int pos_x, int pos_y, int size_x, int size_y, string filename, Meterial meterial)
{
	//transform�� �� ����
	Vector2<int> pos(pos_x, pos_y);
	Vector2<int> size(size_x, size_y); //collision���� ���

	//collision
	Rectangle2D* collisionShape = new Rectangle2D(size);
	//����  �� addComponent
	transform = new Transform(pos, size, &componentList);
	renderer = new Renderer(transform, Shape::Load(filename), meterial, 0);
	collision = new Collision(transform, collisionShape, FloorTag);
	AddComponent(renderer);
	AddComponent(transform);
	AddComponent(collision);

	Engine::Instance()->AddObject(this);
}