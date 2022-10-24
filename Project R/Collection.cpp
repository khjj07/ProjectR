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

}