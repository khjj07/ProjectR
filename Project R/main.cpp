#include<iostream>
#include "engine.h"
#include "player.h"
#include "component.h"
#include "gameState.h"
#include "gameStateManager.h"
#include "gamePadManager.h"
#include "map1Collection.h"
#include "titleUICollection.h"
#include "shape.h"

int main()
{
	GamePadManager *gamepadManager = GamePadManager::Instance();
	gamepadManager->AddPad(0);
	gamepadManager->AddPad(1);
	Engine *engine = Engine::Instance();

	//오브젝트 선언
	
	//Collection 선언
	Map1Collection *map1 = new Map1Collection();
	TitleUICollection* titleUI = new TitleUICollection();

	GameState<MainState> title;
	GameState<MainState> ingame;
	title.nextState = &ingame;
	ingame.nextState = &title;
	//MainState-title
	title.SetCollection(*titleUI);
	//MainState-ingame
	ingame.SetCollection(*map1);

	GameStateManager<MainState>* mainStateManager = GameStateManager<MainState>::Instance();
	mainStateManager->Change(&title);
	engine->Run();

	return 0;
}