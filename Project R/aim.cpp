#include "aim.h"
#include "shape.h"

Aim::Aim(Vector2<int> s, string filename, Meterial meterial)
{
	//transform�� �� ����
	Vector2<int> size(s.x, s.y); //collision���� ���

	//collision
	Rectangle2D* collisionShape = new Rectangle2D(size);
	//����  �� addComponent
	transform = new Transform(Vector2<float>(0,0), size, this, &componentList);
	renderer = new Renderer(transform, Shape::Load(filename), meterial);
	AddComponent(renderer);
	AddComponent(transform);
}
void Aim::Move()
{
	velocity.y = direction.y * speed;
	velocity.x = direction.x * speed;
}