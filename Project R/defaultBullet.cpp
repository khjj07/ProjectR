#include "defaultBullet.h"
#include "timer.h"
DefaultBullet::DefaultBullet(Vector2<float> p, Vector2<float> direction, int i)
{
	//transform에 들어갈 변수
	Vector2<float> pos(p.x, p.y);
	Vector2<int> size(2,2);
	//collision
	Rectangle2D* collisionShape = new Rectangle2D(size);
	//선언  및 addComponent
	transform = new Transform(pos, size,this, &componentList);
	renderer = new Renderer(transform, Shape::Load("defaultBullet.txt"), Meterial(Color::LIGHTRED, Color::LIGHTRED,2));
	collision = new Collision(transform, this, collisionShape, BulletTag);
	script = new BulletScript(transform, this, Vector2<float>(0,1), 0, 200, 3, i, 1);
	AddComponent(script);
	AddComponent(renderer);
	AddComponent(transform);
	AddComponent(collision);
	Shoot(direction);
}