#include "collection.h"

Collection::Collection()
{

}

void Collection::Push(GameObject* newObject)
{
	gameObjectList.push_back(newObject);
	if (newObject->collision)
	{
		collisionList.push_back(newObject->collision);
	}
}

void Collection::Pop(GameObject* newObject)
{
	gameObjectList.erase(std::remove_if(gameObjectList.begin(), gameObjectList.end(), [newObject](GameObject *x) { return x == newObject; }), gameObjectList.end());
	collisionList.erase(std::remove_if(collisionList.begin(), collisionList.end(), [newObject](Collision* x) { return x == newObject->collision; }), collisionList.end());
}