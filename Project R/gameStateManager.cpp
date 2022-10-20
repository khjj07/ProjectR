#include "gameStateManager.h"
#include "gameState.h"


template<typename T>
GameStateManager<T>::GameStateManager(T *cur)
{
	currentState = cur;
	vector<GameObject>::iterator object = currentState->gameObjectList.begin();
	for (; object < currentState->gameObjectList.end(); object++)
	{
		object->Enable();
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
void GameStateManager<T>::Change(T * state)
{
	vector<GameObject>::iterator object = currentState->gameObjectList.begin();
	for (; object < currentState->gameObjectList.end(); object++)
	{
		object->Disable();
	}
	currentState = state;
	vector<GameObject>::iterator object = currentState->gameObjectList.begin();
	for (; object < currentState->gameObjectList.end(); object++)
	{
		object->Enable();
	}
}