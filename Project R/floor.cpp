#include "gameObject.h"
#include "component.h"
#include "collision.h"
#include "floor.h"
#include "engine.h"
#include <string>

Floor::Floor(int pos_x,int pos_y)
{
	//transform에 들어갈 변수
	Vector2<int> pos(pos_x, pos_y);
	Vector2<int> size(100, 2); //collision에도 사용

	//render shape
	string shape("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\nAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");

	//collision
	Rectangle2D* collisionShape = new Rectangle2D(size);

	//선언  및 addComponent
	transform = new Transform(pos, size, &componentList);
	renderer = new Renderer(transform, shape, BACKGROUND_INTENSITY, 0);
	collision = new Collision(transform, collisionShape, FloorTag);
	AddComponent(renderer);
	AddComponent(transform);
	AddComponent(collision);
	Engine::Instance()->AddObject(this);
}