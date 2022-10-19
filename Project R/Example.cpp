#include "gameObject.h"
#include "component.h"
#include "collision.h"
#include "Example.h"
#include "engine.h"

Example::Example()
{
	char shape[] = "aaaaaa\naaaaaaaaaa\naaaaaa";
	int id = 1;
	transform = new Transform(10,10);
	renderer = new Renderer(transform, shape, 2, 1, 0);
	AddComponent(renderer);
	AddComponent(transform);
	Engine::Instance()->AddObject(this);
	//AddComponent(new Collision<Static>(transform,width,height, id));
}