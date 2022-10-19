#include "engine.h"
#include <vector>
using namespace std;

Engine::Engine()
{
	render = Render::Instance();
	screen = Screen::Instance();
}

void Engine::Run()
{
	while (state == Running)
	{
		Update();
	}
}

void Engine::Update() {
	render->Update();
	vector<GameObject>::iterator object = gameObjectList.begin();
	for(;  object < gameObjectList.end(); object++)
		object->Update();
}

void Engine::AddObject(GameObject* newObject)
{
	gameObjectList.push_back(*newObject);
}