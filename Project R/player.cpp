#include "player.h"
#include "shape.h"
#include "hp.h"
Player::Player(Vector2<float> p, Vector2<int> s, string filename, Meterial meterial, Aim* aim, HP* hp, GamePad* pad, int i)
{
	//transform에 들어갈 변수
	Vector2<float> pos(p.x, p.y);
	Vector2<int> size(s.x, s.y); //collision에도 사용
	
	//collision
	Rectangle2D *collisionShape = new Rectangle2D(size);
	//선언  및 addComponent

	gamepad = pad;
	transform = new Transform(pos,size, this, &componentList);
	renderer = new Renderer(transform, Shape::Load(filename) , meterial);
	collision = new Collision(transform, this, collisionShape, PlayerTag);
	script = new PlayerScript(transform,this, aim,hp,pad, i);
	AddComponent(renderer);
	AddComponent(transform);
	AddComponent(collision);
	AddComponent(script);
}