#include "gameObject.h"
#include "component.h"
#include "collision.h"
#include "Example2.h"
#include "playerScript.h"
#include "engine.h"
#include <string>

Example2::Example2()
{
	//transform에 들어갈 변수
	Vector2<int> pos(50, 10);
	Vector2<int> size(6, 3); //collision에도 사용

	//render shape
	string shape("AAAAAA\nAAAAAA\nAAAAAA");

	//collision
	int id = 1;
	Rectangle2D* collisionShape = new Rectangle2D(size);

	//선언  및 addComponent
	transform = new Transform(pos, size, &componentList);
	renderer = new Renderer(transform, shape, BACKGROUND_INTENSITY, 0);
	collision = new Collision(transform, collisionShape, id);
	AddComponent(renderer);
	AddComponent(transform);
	AddComponent(collision);

	Engine::Instance()->AddObject(this);
}