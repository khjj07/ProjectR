#include<iostream>
#include"component.h"
#include "gameState.h"
#include "mainState.h"
#include "gameStateManager.h"

#include"engine.h"
#include "player.h"
#include "floor.h"
int main()
{
	Engine *engine = Engine::Instance();// 맨위에 있어야 됨

	//오브젝트 선언
	Player* player = new Player(5, 10);
	Floor* obj2 = new Floor(1, 80);
	Floor* obj3 = new Floor(60, 70);


	//MainState
// 	MainState title;
// 	title.AddObject((GameObject)(* player));
// 	title.AddObject((GameObject)(*obj2));
// 	title.AddObject((GameObject)(*obj3));
// 	MainState ingame();
// 	GameStateManager<MainState> mainStateManager(&title);
// 
// 
// 	
	engine->Run();

	return 0;
}