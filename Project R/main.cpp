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
	//gamepadManager->AddPad(1);
	Engine *engine = Engine::Instance();

	//오브젝트 선언
	Player* player1 = new Player(5, 10, 7, 7,"player.txt",Meterial(Color::BLACK, Color::CYAN), gamepadManager->p[0]);
	//Player* player2 = new Player(20, 10, gamepadManager->p[1]);

	//Collection 선언
	Map1Collection map1;
	TitleUICollection titleUI;


	GameState<MainState> title;
	GameState<MainState> ingame;
	title.nextState = &ingame;
	//MainState-title
	title.AddCollection(titleUI);
	//MainState-ingame
	ingame.AddObject(player1);
	//ingame.AddObject(player2);
	ingame.AddCollection(map1);

	GameStateManager<MainState> mainStateManager(&title);
	engine->Run();

	return 0;
}