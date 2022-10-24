#include "floor.h"

Floor::Floor(int pos_x,int pos_y,int size_x,int size_y,string filename,Meterial meterial)
{
	//transform에 들어갈 변수
	Vector2<int> pos(pos_x, pos_y);
	Vector2<int> size(size_x, size_y); 


	//collision
	Rectangle2D* collisionShape = new Rectangle2D(size);
	//선언  및 addComponent
	transform = new Transform(pos, size, &componentList);
	renderer = new Renderer(transform, Shape::Load(filename), meterial);
	collision = new Collision(transform, collisionShape, FloorTag);
	AddComponent(renderer);
	AddComponent(transform);
	AddComponent(collision);
}