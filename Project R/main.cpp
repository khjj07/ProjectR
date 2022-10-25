#include<iostream>
#include "engine.h"
#include "player.h"
#include "gameManager.h"
#include "component.h"
#include "gameState.h"
#include "gameStateManager.h"
#include "gamePadManager.h"
#include "map1Collection.h"
#include "titleUICollection.h"
#include "cardUICollection.h"
#include "shape.h"

int EventHandler::counter = 0;
int main()
{
	GamePadManager *gamepadManager = GamePadManager::Instance();
	GameManager* gameManager = GameManager::Instance();
	gamepadManager->AddPad(0);
	gamepadManager->AddPad(1);
	Engine *engine = Engine::Instance();

	//오브젝트 선언
	
	//Collection 선언
	Map1Collection *map1 = new Map1Collection();
	TitleUICollection* titleUI = new TitleUICollection();
	CardUICollection* cardUI = new CardUICollection();

	GameState<MainState> title;
	GameState<MainState> ingame;
	GameState<MainState> card;
	title.nextState = &ingame;
	ingame.nextState = &card;
	card.nextState = &ingame;
	//MainState-title
	title.SetCollection(*titleUI);
	ingame.SetCollection(*map1);
	card.SetCollection(*cardUI);
	

	GameStateManager<MainState>* mainStateManager = GameStateManager<MainState>::Instance();
	mainStateManager->Change(&title);
	engine->Run();

	return 0;
}