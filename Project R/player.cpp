#include "gameObject.h"
#include "component.h"
#include "collision.h"
#include "player.h"
#include "playerScript.h"
#include "engine.h"
#include <string>

Player::Player(int pos_x,int pos_y, GamePad* pad)
{
	//transform에 들어갈 변수
	Vector2<int> pos(pos_x, pos_y);
	Vector2<int> size(4, 3); //collision에도 사용
	
	//render shape
	string shape("AAAA\nAAAA\nAAAA");
	
	//collision
	
	Rectangle2D *collisionShape = new Rectangle2D(size);

	//선언  및 addComponent
	transform = new Transform(pos,size,&componentList);
	renderer = new Renderer(transform,shape,BACKGROUND_INTENSITY, 1);
	collision = new Collision(transform, collisionShape, PlayerTag);
	PlayerScript* script = new PlayerScript(transform, pad);
	AddComponent(renderer);
	AddComponent(transform);
	AddComponent(collision);
	AddComponent(script);

	Engine::Instance()->AddObject(this);
}