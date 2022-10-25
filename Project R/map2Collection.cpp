#include "map2Collection.h"
#include "floor.h"
#include "wall.h"
#include "player.h"
#include "aim.h"
#include "gamePadManager.h"
Map2Collection::Map2Collection()
{
	HP* hp1 = new HP(10, Meterial(Color::RED, Color::RED, 5));
	Aim* aim1 = new Aim(Vector2<int>(3, 3), "aim.txt", Meterial(Color::BLACK, Color::CYAN, 3));
	Player* player1 = new Player(Vector2<float>(5, 5), Vector2<int>(8, 7), "player.txt", Meterial(Color::BLACK, Color::CYAN, 2), aim1, hp1, GamePadManager::Instance()->p[0], 1);

	HP* hp2 = new HP(10, Meterial(Color::RED, Color::RED, 5));
	Aim* aim2 = new Aim(Vector2<int>(3, 3), "aim.txt", Meterial(Color::BLACK, Color::CYAN, 3));
	Player* player2 = new Player(Vector2<float>(30, 5), Vector2<int>(8, 7), "player.txt", Meterial(Color::BLACK, Color::CYAN, 2), aim2, hp2, GamePadManager::Instance()->p[1], 2);

	//상하좌우 막는 벽
	Floor* obj1 = new Floor(Vector2<float>(1, 99), Vector2<int>(380, 1), "floor2.txt", Meterial(Color::GREEN, Color::YELLOW, 1));
	Floor* obj2 = new Floor(Vector2<float>(1, 1), Vector2<int>(380, 1), "floor2.txt", Meterial(Color::GREEN, Color::YELLOW, 1));
	Floor* obj3 = new Floor(Vector2<float>(1, 100), Vector2<int>(380, 1), "floor2.txt", Meterial(Color::BLACK, Color::BLACK, 1), BedRock);
	Floor* obj4 = new Floor(Vector2<float>(1, 0), Vector2<int>(380, 1), "floor2.txt", Meterial(Color::BLACK, Color::BLACK, 1), BedRock);
	Wall* obj5 = new Wall(Vector2<float>(1, 1), Vector2<int>(1, 100), "wall1.txt", Meterial(Color::GREEN, Color::YELLOW, 1));
	Wall* obj6 = new Wall(Vector2<float>(0, 1), Vector2<int>(1, 100), "wall1.txt", Meterial(Color::BLACK, Color::BLACK, 1), BedRock);
	Wall* obj7 = new Wall(Vector2<float>(370, 1), Vector2<int>(1, 100), "wall1.txt", Meterial(Color::GREEN, Color::YELLOW, 1));
	Wall* obj8 = new Wall(Vector2<float>(372, 1), Vector2<int>(1, 100), "wall1.txt", Meterial(Color::BLACK, Color::BLACK, 1), BedRock);

	//플레이어 시작지점
	Floor* obj9 = new Floor(Vector2<float>(3, 30), Vector2<int>(50, 3), "floor.txt", Meterial(Color::GREEN, Color::YELLOW, 1));
	Floor* obj10 = new Floor(Vector2<float>(319, 30), Vector2<int>(50, 3), "floor.txt", Meterial(Color::GREEN, Color::YELLOW, 1));
	
	Floor* obj11 = new Floor(Vector2<float>(100, 30), Vector2<int>(50, 3), "floor.txt", Meterial(Color::GREEN, Color::YELLOW, 1));
	Floor* obj12 = new Floor(Vector2<float>(225, 30), Vector2<int>(50, 3), "floor.txt", Meterial(Color::GREEN, Color::YELLOW, 1));
	Floor* obj13 = new Floor(Vector2<float>(50, 60), Vector2<int>(100, 3), "floor1.txt", Meterial(Color::GREEN, Color::YELLOW, 1));
	Floor* obj14 = new Floor(Vector2<float>(210, 60), Vector2<int>(100, 3), "floor1.txt", Meterial(Color::GREEN, Color::YELLOW, 1));

	Floor* obj15 = new Floor(Vector2<float>(160, 45), Vector2<int>(50, 3), "floor.txt", Meterial(Color::GREEN, Color::YELLOW, 1));
	Floor* obj16 = new Floor(Vector2<float>(160, 75), Vector2<int>(50, 3), "floor.txt", Meterial(Color::GREEN, Color::YELLOW, 1));
	Floor* obj19 = new Floor(Vector2<float>(160, 20), Vector2<int>(50, 3), "floor.txt", Meterial(Color::GREEN, Color::YELLOW, 1));

	Floor* obj17 = new Floor(Vector2<float>(30, 85), Vector2<int>(100, 3), "floor1.txt", Meterial(Color::GREEN, Color::YELLOW, 1));
	Floor* obj18 = new Floor(Vector2<float>(230, 85), Vector2<int>(100, 3), "floor1.txt", Meterial(Color::GREEN, Color::YELLOW, 1));

	Wall* obj20 = new Wall(Vector2<float>(80, 52), Vector2<int>(3, 10), "wall2.txt", Meterial(Color::GREEN, Color::YELLOW, 1));
	Wall* obj21 = new Wall(Vector2<float>(120, 52), Vector2<int>(3, 10), "wall2.txt", Meterial(Color::GREEN, Color::YELLOW, 1));
	Wall* obj22 = new Wall(Vector2<float>(240, 52), Vector2<int>(3, 10), "wall2.txt", Meterial(Color::GREEN, Color::YELLOW, 1));
	Wall* obj23 = new Wall(Vector2<float>(280, 52), Vector2<int>(3, 10), "wall2.txt", Meterial(Color::GREEN, Color::YELLOW, 1));
	
	Wall* obj24 = new Wall(Vector2<float>(60, 77), Vector2<int>(3, 10), "wall2.txt", Meterial(Color::GREEN, Color::YELLOW, 1));
	Wall* obj25 = new Wall(Vector2<float>(100, 77), Vector2<int>(3, 10), "wall2.txt", Meterial(Color::GREEN, Color::YELLOW, 1));
	Wall* obj26 = new Wall(Vector2<float>(260, 77), Vector2<int>(3, 10), "wall2.txt", Meterial(Color::GREEN, Color::YELLOW, 1));
	Wall* obj27 = new Wall(Vector2<float>(300, 77), Vector2<int>(3, 10), "wall2.txt", Meterial(Color::GREEN, Color::YELLOW, 1));
	
	Wall* obj28 = new Wall(Vector2<float>(185, 37), Vector2<int>(3, 10), "wall2.txt", Meterial(Color::GREEN, Color::YELLOW, 1));
	Wall* obj29 = new Wall(Vector2<float>(185, 13), Vector2<int>(3, 10), "wall2.txt", Meterial(Color::GREEN, Color::YELLOW, 1));
	Push(obj1);
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
	Push(obj21);
	
	Push(obj22);
	Push(obj23);
	
	Push(obj24);
	Push(obj25);
	Push(obj26);
	Push(obj27);
	Push(obj28);
	Push(obj29);


	Push(player1);
	Push(aim1);
	Push(hp1);
	Push(player2);
	Push(aim2);
	Push(hp2);
}