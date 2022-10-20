#include "gameState.h"


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
void  GameState<T>::AddObject(GameObject object)
{
	gameObjectList.push_back(object);
}
