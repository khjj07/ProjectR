#include "engine.h"
#include "gamePadManager.h"
#include <iostream>
#include <thread>
using std::thread;

Engine::Engine()
{
	screen = Screen::Instance();
	render = Render::Instance();
}

void Engine::Run()
{
	double dt = 0;
	__int64  s, e, periodFrequency;
	QueryPerformanceFrequency((LARGE_INTEGER*)&periodFrequency);
	double timeScale = 1.0 / (double)periodFrequency;

	while (state == Running)
	{
		static double elapsed = 0;
		if (elapsed < 30)
			elapsed = 0;
		else
			elapsed -= 30;
		currentCollection = nextCollection;
		Start();
		QueryPerformanceCounter((LARGE_INTEGER*)&s);
		Update(dt);
		if (elapsed < 30)
		{
			screen->Update();
			render->Update();
		}
		QueryPerformanceCounter((LARGE_INTEGER*)&e);
		dt =(double)(e - s)*timeScale;
		elapsed += dt;
	}
}


void Engine::Start()
{
	vector<GameObject*>::iterator object = currentCollection->gameObjectList.begin();
	for (; object < currentCollection->gameObjectList.end(); object++)
	{
			(*object)->Start();
			(*object)->started = true;
	}
}

void Engine::Update(double dt) {
	
	GamePadManager::Instance()->Update();

	vector<GameObject *>::iterator object = currentCollection->gameObjectList.begin();
	
	for (; object < currentCollection->gameObjectList.end(); object++)
	{
		(*object)->Update(dt);
	}

	object = currentCollection->gameObjectList.begin();
	for (; object < currentCollection->gameObjectList.end(); object++)
	{
		vector<Collision*>::iterator other = currentCollection->collisionList.begin();
		if ((*object)->collision)
		{
			for (; other < currentCollection->collisionList.end(); other++)
			{
				if ((*other)->transform != (*object)->transform)
				{
					if ((*object)->collision->CollisionStay((*other)))
					{
						(*object)->OnCollisionStay(*other);
					}
				}
			}
		}
	}
}

void Engine::SetCollection(Collection *col)
{
	nextCollection = col;
}