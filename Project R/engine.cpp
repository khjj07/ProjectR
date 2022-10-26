#include "engine.h"
#include "gamePadManager.h"
#include <iostream>
#include <thread>
#include <time.h>
using std::thread;


Engine::Engine()
{
	screen = Screen::Instance();
	render = Render::Instance();
}

void Engine::Run()
{
	float dt = 0;
	__int64  s, e, periodFrequency;
	QueryPerformanceFrequency((LARGE_INTEGER*)&periodFrequency);
	float timeScale = 1.0 / (float)periodFrequency;

	while (state == Running)
	{
		static float elapsed = 0;
		if (elapsed < 30)
			elapsed = 0;
		else
			elapsed -= 30;
		if (!objectBuffer.empty())
		{
			currentCollection->Push(objectBuffer[0]);
			objectBuffer.erase(objectBuffer.begin());
		}
		if (!removeObjectBuffer.empty())
		{
			currentCollection->Pop(removeObjectBuffer[0]);
			removeObjectBuffer[0]->OnDestroy();
			delete removeObjectBuffer[0];
			removeObjectBuffer.erase(removeObjectBuffer.begin());
		}
		if (nextCollection)
		{
			currentCollection = nextCollection;
			currentCollection->OnEnable();
		}
		nextCollection = nullptr;
		Start();
		QueryPerformanceCounter((LARGE_INTEGER*)&s);
		Update(dt);
		if (elapsed < 30)
		{
			screen->Update();
			render->Update();
		}
		QueryPerformanceCounter((LARGE_INTEGER*)&e);
		dt =(float)(e - s)*timeScale;
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

void Engine::Instantiate(GameObject* newObject)
{
	objectBuffer.push_back(newObject);
}
void Engine::Destroy(GameObject* obj)
{
	removeObjectBuffer.push_back(obj);
}


void Engine::Update(float dt) {
	
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