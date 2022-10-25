#include "bullet.h"
#include "bulletScript.h"
Bullet::Bullet()
{

}
Bullet::Bullet(Vector2<float> p, Vector2<float>direction,int i)
{
	Vector2<float> pos(p.x, p.y);
}
Bullet::Bullet(Vector2<float> p, Vector2<int> s , string filename, Meterial meterial, BulletScript* sc)
{
	//transform에 들어갈 변수
	Vector2<float> pos(p.x, p.y);
	Vector2<int> size(s.x, s.y);
	//collision
	Rectangle2D* collisionShape = new Rectangle2D(size);
	//선언  및 addComponent
	transform = new Transform(pos, size, this, &componentList);
	renderer = new Renderer(transform, Shape::Load(filename), meterial);
	collision = new Collision(transform, this, collisionShape, BulletTag);
	script = sc;
	AddComponent(script);
	AddComponent(renderer);
	AddComponent(transform);
	AddComponent(collision);
}

void Bullet::Shoot(Vector2<float> dir)
{
	script->Shoot(dir);
}