#pragma once
#include "define.h"
#include "gameState.h"
#include "engine.h"
template<typename T>
class GameStateManager :public Singleton<GameStateManager<T> > {
	public:
		GameStateManager(GameState<T> *cur);
		GameStateManager();
		GameState<T> *currentState;
		void Change(GameState<T>*state);
		void Next();
		void Previous();

};
template<typename T>
GameStateManager<T>::GameStateManager()
{

}

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
	if(currentState->nextState)
		Change(currentState->nextState);
}
template<typename T>
void GameStateManager<T>::Previous()
{
	if (currentState->previousState)
		Change(currentState->previousState);
}
template<typename T>
void GameStateManager<T>::Change(GameState<T>* state)
{
	if(currentState)
		currentState->collection.OnDisable();
	currentState = state;
	Engine::Instance()->SetCollection(&(currentState->collection));
	
}