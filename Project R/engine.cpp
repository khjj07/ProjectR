#include "engine.h"
#include "gamePadManager.h"
#include <vector>
#include<windows.h>
using namespace std;

Engine::Engine()
{
	render = Render::Instance();
	screen = Screen::Instance();
}

void Engine::Run()
{
	double dt = 0;
	__int64  s, e, periodFrequency;
	QueryPerformanceFrequency((LARGE_INTEGER*)&periodFrequency);
	double timeScale = 1.0 / (double)periodFrequency;
	while (state == Running)
	{
		Start();
		QueryPerformanceCounter((LARGE_INTEGER*)&s);
		Update(dt);
		QueryPerformanceCounter((LARGE_INTEGER*)&e);
		dt =(double)(e - s)*timeScale;
	}
}

void Engine::Start()
{
	vector<GameObject*>::iterator object = gameObjectList.begin();
	for (; object < gameObjectList.end(); object++)
	{
		if ((* object)->isEnabled)
		{
			(*object)->Start();
			(*object)->started = true;
		}
	}
}

void Engine::Update(double dt) {
	GamePadManager::Instance()->Update();
	render->Update();
	vector<GameObject *>::iterator object = gameObjectList.begin();
	for(;  object < gameObjectList.end(); object++)
	{
		if ((*object)->isEnabled)
		{
			(*object)->Update(dt);
			vector<Collision*>::iterator other = collisionList.begin();
			for (; other < collisionList.end(); other++)
			{
				if ((*other)->transform != (*object)->transform)
				{
					if ((*object)->collision->CollisionEnter((*other)))
					{
						(*object)->OnCollisionEnter(*other);
					}
					if ((*object)->collision->CollisionStay((*other)))
					{
						(*object)->OnCollisionStay(*other);
					}
					if ((*object)->collision->CollisionExit((*other)))
					{
						(*object)->OnCollisionExit(*other);
					}
				}

			}
		}
		
	}
		

}

void Engine::AddObject(GameObject* newObject)
{
	gameObjectList.push_back(newObject);
}

void Engine::AddCollision(Collision* newCollision)
{
	collisionList.push_back(newCollision);
}