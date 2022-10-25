#include "map1Collection.h"
#include "floor.h"
#include "wall.h"
#include "player.h"
#include "aim.h"
#include "hp.h"
#include "gamePadManager.h"
Map1Collection::Map1Collection()
{
	HP* hp1 = new HP(10, Meterial(Color::RED, Color::RED, 5));
	Aim* aim1 = new Aim(Vector2<int>(3, 3), "aim.txt", Meterial(Color::BLACK, Color::CYAN, 3));
	Player* player1 = new Player(Vector2<float>(5, 5), Vector2<int>(8, 7), "player.txt", Meterial(Color::BLACK, Color::CYAN, 2), aim1, hp1,GamePadManager::Instance()->p[0], 1);

	HP* hp2 = new HP(10, Meterial(Color::RED, Color::RED, 5));
	Aim* aim2 = new Aim(Vector2<int>(3, 3), "aim.txt", Meterial(Color::BLACK, Color::CYAN, 3));
	Player* player2 = new Player(Vector2<float>(30, 5), Vector2<int>(8, 7), "player.txt", Meterial(Color::BLACK, Color::CYAN, 2), aim2, hp2, GamePadManager::Instance()->p[1], 2);
	//상하좌우 막는 벽
	Floor* obj4 = new Floor(Vector2<float>(1, 99), Vector2<int>(380, 1), "floor2.txt", Meterial(Color::GREEN, Color::YELLOW, 1));
	Floor* obj16 = new Floor(Vector2<float>(1, 1), Vector2<int>(380, 1), "floor2.txt", Meterial(Color::GREEN, Color::YELLOW, 1));
	Floor* obj17 = new Floor(Vector2<float>(1, 100), Vector2<int>(380, 1), "floor2.txt", Meterial(Color::BLACK, Color::BLACK, 1), BedRock);
	Floor* obj18 = new Floor(Vector2<float>(1, 0), Vector2<int>(380, 1), "floor2.txt", Meterial(Color::BLACK, Color::BLACK, 1), BedRock);
	Wall* obj19 = new Wall(Vector2<float>(1, 1), Vector2<int>(1, 100), "wall1.txt", Meterial(Color::GREEN, Color::YELLOW, 1));
	Wall* obj20 = new Wall(Vector2<float>(200, 1), Vector2<int>(1, 100), "wall1.txt", Meterial(Color::GREEN, Color::YELLOW, 1));




	Floor* obj2 = new Floor(Vector2<float>(1, 50), Vector2<int>(100, 3), "floor1.txt", Meterial(Color::GREEN, Color::YELLOW, 1));
	Floor* obj3 = new Floor(Vector2<float>(60, 70), Vector2<int>(100, 3), "floor1.txt", Meterial(Color::GREEN, Color::YELLOW, 1));

	Floor* obj5 = new Floor(Vector2<float>(275, 55), Vector2<int>(100, 3), "floor1.txt", Meterial(Color::GREEN, Color::YELLOW, 1));
	Floor* obj6 = new Floor(Vector2<float>(270, 80), Vector2<int>(50, 3), "floor.txt", Meterial(Color::GREEN, Color::YELLOW, 1));
	Floor* obj7 = new Floor(Vector2<float>(70, 30), Vector2<int>(100, 3), "floor1.txt", Meterial(Color::GREEN, Color::YELLOW, 1));
	Floor* obj8 = new Floor(Vector2<float>(1, 80), Vector2<int>(50, 3), "floor.txt", Meterial(Color::GREEN, Color::YELLOW, 1));
	Floor* obj9 = new Floor(Vector2<float>(1, 20), Vector2<int>(50, 3), "floor.txt", Meterial(Color::GREEN, Color::YELLOW, 1));
	Floor* obj10 = new Floor(Vector2<float>(322, 20), Vector2<int>(50, 3), "floor.txt", Meterial(Color::GREEN, Color::YELLOW, 1));
	Floor* obj11 = new Floor(Vector2<float>(200, 38), Vector2<int>(50, 3), "floor.txt", Meterial(Color::GREEN, Color::YELLOW, 1));
	Floor* obj12 = new Floor(Vector2<float>(200, 60), Vector2<int>(50, 3), "floor.txt", Meterial(Color::GREEN, Color::YELLOW, 1));
	Floor* obj13 = new Floor(Vector2<float>(150, 10), Vector2<int>(100, 3), "floor1.txt", Meterial(Color::GREEN, Color::YELLOW, 1));
	Floor* obj14 = new Floor(Vector2<float>(100, 50), Vector2<int>(50, 3), "floor.txt", Meterial(Color::GREEN, Color::YELLOW, 1));
	Floor* obj15 = new Floor(Vector2<float>(150, 90), Vector2<int>(100, 3), "floor1.txt", Meterial(Color::GREEN, Color::YELLOW, 1));
	//Wall* obj16 = new Wall(Vector2<float>(100, 30), Vector2<int>(3, 50), "wall1.txt", Meterial(Color::GREEN, Color::YELLOW, 1));

	Push(obj2);
	Push(obj3);
	Push(obj4);
	Push(obj5);
	Push(obj6);
	Push(obj7);
	Push(obj8);
	Push(obj9);
	Push(obj10);
	Push(obj11);
	Push(obj12);
	Push(obj13);
	Push(obj14);
	Push(obj15);
	Push(obj16);
	Push(obj17);
	Push(obj18);
	Push(obj19);
	Push(obj20);

	Push(player1);
	Push(aim1);
	Push(hp1);
	Push(player2);
	Push(aim2);
	Push(hp2);
}