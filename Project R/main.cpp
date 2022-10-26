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
#include "roundUICollection.h"
#include "IngameCollection.h"
#include "victoryCollection.h"
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
	RoundUICollection* roundUI = new RoundUICollection();
	TitleUICollection* titleUI = new TitleUICollection();

	IngameCollection* main = IngameCollection::Instance();
	Map1Collection *map1 = new Map1Collection();
	VictoryCollection * victoryUI = new VictoryCollection();


	GameState<MainState> title;
	GameState<MainState> round;
	GameState<MainState> ingame;
	GameState<MainState> victory;
	title.nextState = &round;
	round.nextState = &ingame;
	victory.nextState = &title;
	ingame.nextState = &round;
	ingame.previousState = &victory;


	//MainState-title
	title.SetCollection(*titleUI);
	ingame.SetCollection(*main);
	round.SetCollection(*roundUI);
	victory.SetCollection(*victoryUI);
	GameStateManager<MainState>* mainStateManager = GameStateManager<MainState>::Instance();
	mainStateManager->Change(&title);
	engine->Run();

	return 0;
}