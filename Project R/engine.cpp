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
		currentCollection = nextCollection;
		Start();
		QueryPerformanceCounter((LARGE_INTEGER*)&s);
		Update(dt);
		QueryPerformanceCounter((LARGE_INTEGER*)&e);
		dt =(double)(e - s)*timeScale;
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
	screen->Update();
	render->Update();
	vector<thread *> t_list;
	vector<GameObject *>::iterator object = currentCollection->gameObjectList.begin();
	vector<Collision*>::iterator other = currentCollection->collisionList.begin();
	for(;  object < currentCollection->gameObjectList.end(); object++)
	{
		thread new_t([object, dt]() {
			(*object)->Update(dt);  
		});
		//스레드로 시도중
		t_list.push_back(&new_t);

		if ((*object)->collision)
		{

			for (; other < currentCollection->collisionList.end(); other++)
			{
				if ((*other)->transform != (*object)->transform)
				{
					if ((*object)->collision->CollisionEnter((*other)))
					{
						(*object)->OnCollisionEnter(*other);
					}
					if ((*object)->collision->CollisionExit((*other)))
					{
						(*object)->OnCollisionExit(*other);
					}
					if ((*object)->collision->CollisionStay((*other)))
					{
						(*object)->OnCollisionStay(*other);
					}
				}
			}
		}

	}
	vector<thread *>::iterator t=t_list.begin();
	for (; t < t_list.end(); t++)
	{
		(* t)->join();
	}
}

void Engine::SetCollection(Collection *col)
{
	nextCollection = col;
}