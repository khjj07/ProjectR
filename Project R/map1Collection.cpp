#include "map1Collection.h"
#include "floor.h"
Map1Collection::Map1Collection()
{
	Floor* obj2 = new Floor(1, 80);
	Floor* obj3 = new Floor(60, 70);
	Push(obj2);
	Push(obj3);
}