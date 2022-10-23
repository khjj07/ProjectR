#include "player.h"
#include "shape.h"

Player::Player(int pos_x,int pos_y, int size_x,int size_y,string filename, Meterial meterial, GamePad* pad)
{
	//transform�� �� ����
	Vector2<int> pos(pos_x, pos_y);
	Vector2<int> size(size_x, size_y); //collision���� ���
	
	//collision
	Rectangle2D *collisionShape = new Rectangle2D(size);
	//����  �� addComponent
	transform = new Transform(pos,size,&componentList);
	renderer = new Renderer(transform, Shape::Load(filename) , meterial, 1);
	collision = new Collision(transform, collisionShape, PlayerTag);
	PlayerScript* script = new PlayerScript(transform, pad);
	AddComponent(renderer);
	AddComponent(transform);
	AddComponent(collision);
	AddComponent(script);

	Engine::Instance()->AddObject(this);
}