#include "aim.h"
#include "shape.h"

Aim::Aim(int size_x, int size_y, string filename, Meterial meterial)
{
	//transform에 들어갈 변수
	Vector2<int> size(size_x, size_y); //collision에도 사용

	//collision
	Rectangle2D* collisionShape = new Rectangle2D(size);
	//선언  및 addComponent
	transform = new Transform(Vector2<int>(0,0), size, &componentList);
	renderer = new Renderer(transform, Shape::Load(filename), meterial);
	AddComponent(renderer);
	AddComponent(transform);
}
void Aim::Move()
{
	velocity = direction * speed;
}