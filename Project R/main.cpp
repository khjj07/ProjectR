#include<iostream>
#include"component.h"
#include "gameState.h"
#include "gameStateManager.h"
#include "gamePadManager.h"
#include"engine.h"
#include "player.h"
#include "map1Collection.h"
int main()
{

	GamePadManager *gamepadManager = GamePadManager::Instance();
	gamepadManager->AddPad(0);
	//gamepadManager->AddPad(1);
	Engine *engine = Engine::Instance();

	//오브젝트 선언
	Player* player1 = new Player(5, 10, gamepadManager->p[0]);
	//Player* player2 = new Player(20, 10, gamepadManager->p[1]);
	//Collection 선언
	Map1Collection map1;

	//MainState
	GameState<MainState> title;
	title.AddObject(player1);
	//title.AddObject(player2);
	title.AddCollection(map1);
	GameState<MainState> ingame;
	

	GameStateManager<MainState> mainStateManager(&title);



	engine->Run();

	return 0;
}