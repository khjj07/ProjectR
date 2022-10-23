#pragma once
#include "define.h"
#include "gameObject.h"
class GameObject;
class Collection
{
public:
	Collection();
	vector<GameObject*> gameObjectList;
	void Push(GameObject* newObject);
	void Pop(GameObject* newObject);
};

