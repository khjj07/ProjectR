#include "map1Collection.h"
#include "floor.h"
Map1Collection::Map1Collection()
{
	Floor* obj2 = new Floor(1, 80,100,3, "floor1.txt", Meterial(Color::GREEN, Color::YELLOW));
	Floor* obj3 = new Floor(60, 70, 100, 3, "floor1.txt",Meterial(Color::GREEN, Color::YELLOW));
	Push(obj2);
	Push(obj3);
}