#include "hp.h"

HP::HP()
{

}
HP::HP(int max,Meterial meterial)
{
	maxhp = max;
	hp = max;	
	//¼±¾ð  ¹× addComponent
	transform = new Transform(Vector2<float>(0,0), Vector2<int>(0, 0), this, &componentList);
	renderer = new Renderer(transform, string(""), meterial);
	AddComponent(renderer);
	AddComponent(transform);
	Increase(0);

}

int HP::Get()
{
	return hp;
}
void HP::Increase(int val)
{
	hp = hp + val > maxhp ? maxhp : hp + val;
	string shape("");
	for (int i = 0; i < hp; i++)
		shape.append("¡á");
	renderer->shape = shape;
}


void HP::Decrease(int val)
{
	hp = hp -val <0 ? 0 : hp - val;
	string shape("");
	for (int i = 0; i < hp; i++)
		shape.append("¡á");
	renderer->shape = shape;
}