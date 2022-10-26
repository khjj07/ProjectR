#include "mote.h"
#include "moteScript.h"
Mote::Mote()
{

}
Mote::Mote(Vector2<float> p, Vector2<float>direction, int seed)
{
	Vector2<float> pos(p.x, p.y);
	Vector2<int> size(1, 1);
	//collision
	Rectangle2D* collisionShape = new Rectangle2D(size);
	//¼±¾ð  ¹× addComponent
	transform = new Transform(pos, size, this, &componentList);
	renderer = new Renderer(transform, Shape::Load("mote.txt"), Meterial(Color::RED,Color::RED,3));
	collision = new Collision(transform, this, collisionShape, MoteTag);
	script = new MoteScript(transform, direction, Vector2<float>(0,1),  0.001, 10);;
	AddComponent(script);
	AddComponent(renderer);
	AddComponent(transform);
	AddComponent(collision);
	
}