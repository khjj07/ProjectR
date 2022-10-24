#include "aim.h"
#include "shape.h"

Aim::Aim(int size_x, int size_y, string filename, Meterial meterial)
{
	//transform�� �� ����
	Vector2<int> size(size_x, size_y); //collision���� ���

	//collision
	Rectangle2D* collisionShape = new Rectangle2D(size);
	//����  �� addComponent
	transform = new Transform(Vector2<int>(0,0), size, &componentList);
	renderer = new Renderer(transform, Shape::Load(filename), meterial);
	AddComponent(renderer);
	AddComponent(transform);
}
void Aim::Move()
{
	velocity = direction * speed;
}