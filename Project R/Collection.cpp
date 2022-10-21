#include "collection.h"

Collection::Collection()
{

}

void Collection::Push(GameObject* newObject)
{
	gameObjectList.push_back(newObject);
}

void Collection::Pop(GameObject* newObject)
{

}