#include "map1Collection.h"
#include "floor.h"
#include "fps.h"
#include "player.h"
#include "aim.h"
#include "gamePadManager.h"
Map1Collection::Map1Collection()
{
	Aim* aim1 = new Aim(3, 3, "cursor.txt", Meterial(Color::BLACK, Color::CYAN, 3));
	Player* player1 = new Player(5, 10, 7, 7, "player.txt", Meterial(Color::BLACK, Color::CYAN, 2), aim1,GamePadManager::Instance()->p[0]);
	Floor* obj2 = new Floor(1, 80,100,3, "floor1.txt", Meterial(Color::GREEN, Color::YELLOW,1));
	Floor* obj3 = new Floor(60, 70, 100, 3, "floor1.txt",Meterial(Color::GREEN, Color::YELLOW,1));
	FPS* fps = new FPS(10,10);
	
	Push(obj2);
	Push(obj3);
	Push(fps);
	Push(player1);
	Push(aim1);
}