#pragma once
#include "gameState.h"
#include "singleton.h"
template<typename T>
class GameStateManager :Singleton<GameStateManager<T> > {
	public:
		GameStateManager(GameState<T> *cur);
		GameState<T> *currentState;
		void Change(GameState<T>*state);
		void Next();
		void Previous();

};

template<typename T>
GameStateManager<T>::GameStateManager(GameState<T>* cur)
{
	currentState = cur;
	vector<GameObject *>::iterator object = currentState->gameObjectList.begin();
	for (; object < currentState->gameObjectList.end(); object++)
	{
		(*object)->Enable();
	}
}
template<typename T>
void GameStateManager<T>::Next()
{
	Change(currentState->nextState);
}
template<typename T>
void GameStateManager<T>::Previous()
{
	Change(currentState->previousState);
}
template<typename T>
void GameStateManager<T>::Change(GameState<T>* state)
{
	vector<GameObject *>::iterator object = currentState->gameObjectList.begin();
	for (; object < currentState->gameObjectList.end(); object++)
	{
		(*object)->Disable();
	}
	currentState = state;
	vector<GameObject *>::iterator object = currentState->gameObjectList.begin();
	for (; object < currentState->gameObjectList.end(); object++)
	{
		(*object)->Enable();
	}
}