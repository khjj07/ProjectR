#include "aim.h"
#include "shape.h"

Aim::Aim(Vector2<int> s, string filename, Meterial meterial)
{
	//transform에 들어갈 변수
	Vector2<int> size(s.x, s.y); //collision에도 사용

	//collision
	Rectangle2D* collisionShape = new Rectangle2D(size);
	//선언  및 addComponent
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