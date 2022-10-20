#pragma once
#include "define.h"
#include "gameObject.h"

template <typename T>
class GameState
{
public:
	GameState();
	GameState<T> *nextState;
	GameState<T> *previousState;
	vector<GameObject> gameObjectList;
	void OnEnable();
	void OnDisable();
	void AddObject(GameObject object);

private:

};