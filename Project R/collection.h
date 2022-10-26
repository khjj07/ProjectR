#pragma once
#include "define.h"
#include "gameObject.h"
class GameObject;
class Collection
{
public:
	Collection();
	
	void Push(GameObject* newObject);
	void Pop(GameObject* newObject);
	virtual vector<GameObject*> *GetObjectList();
	virtual vector<Collision*> *GetCollisionList();
	virtual void OnEnable();
	virtual void OnDisable();
	vector<GameObject*> gameObjectList;
	vector<Collision*> collisionList;
};


