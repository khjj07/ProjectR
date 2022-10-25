#pragma once
#include "define.h"
#include "collection.h"

class MainState;

template <typename T>
class GameState
{
public:
	GameState();
	GameState<T> *nextState;
	GameState<T> *previousState;
	Collection collection;
	void OnEnable();
	void OnDisable();
	void SetCollection(Collection c);
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
void GameState<T>::SetCollection(Collection c)
{
	collection = c;
}