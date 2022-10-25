#include "gameObject.h"
#include "component.h"
#include "collision.h"
#include "cursor.h"


Cursor::Cursor(Vector2<float> p, Vector2<int> s,string filename, Meterial meterial, GamePad* pad)
{
	//transform에 들어갈 변수
	Vector2<float> pos(p.x, p.y);
	Vector2<int> size(s.x, s.y); //collision에도 사용

	//collision
	Rectangle2D* collisionShape = new Rectangle2D(size);
	//선언  및 addComponent
	transform = new Transform(pos, size, this, &componentList);
	renderer = new Renderer(transform, Shape::Load(filename), meterial);
	collision = new Collision(transform, this, collisionShape, CursorTag);
	CursorScript *script = new CursorScript(transform, this, pad);
	AddComponent(renderer);
	AddComponent(transform);
	AddComponent(collision);
	AddComponent(script);
}