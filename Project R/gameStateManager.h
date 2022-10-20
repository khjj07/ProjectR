#pragma once
#include "gameState.h"
#include "singleton.h"
template<typename T>
class GameStateManager :Singleton<GameStateManager<T> > {
	public:
		GameStateManager(T *cur);
		T *currentState;
		void Change(T *state);
		void Next();
		void Previous();

};