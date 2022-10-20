#include "engine.h"
#include <vector>
#include<time.h>
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
	{
		object->Update();
		vector<Collision*>::iterator other = collisionList.begin();
		for (; other < collisionList.end(); other++)
		{
			if ((* other)->transform != object->transform)
			{
				if (object->collision->CollisionEnter((*other)))
				{
					object->OnCollisionEnter(*other);
				}
				if(object->collision->CollisionStay((*other)))
				{
					object->OnCollisionStay(*other);
				}
				if (object->collision->CollisionExit((*other)))
				{
					object->OnCollisionExit(*other);
				}
			}
				
		}
	}
		

}

void Engine::AddObject(GameObject* newObject)
{
	gameObjectList.push_back(*newObject);
}

void Engine::AddCollision(Collision* newCollision)
{
	collisionList.push_back(newCollision);
}