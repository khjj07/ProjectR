#pragma once
#include "define.h"
#include "gameObject.h"
#include "collection.h"
class MainState;

template <typename T>
class GameState
{
public:
	GameState();
	GameState<T> *nextState;
	GameState<T> *previousState;
	vector<GameObject *> gameObjectList;
	void OnEnable();
	void OnDisable();
	void AddObject(GameObject* object);
	void AddCollection(Collection collection);
private:

};

template <typename T>
GameState<T>::GameState()
{

}

template <typename T>
void GameState<T>::OnEnable()
{

}
template <typename T>
void GameState<T>::OnDisable()
{

}
template <typename T>
void GameState<T>::AddObject(GameObject* object)
{
	gameObjectList.push_back(object);
}

template <typename T>
void GameState<T>::AddCollection(Collection collection)
{
	vector<GameObject*>::iterator object = collection.gameObjectList.begin();
	for (; object < collection.gameObjectList.end(); object++)
	{
		gameObjectList.push_back(*object);
	}
}