#include "button.h"

Button::Button(int pos_x, int pos_y, int size_x, int size_y,string filename1, string filename2, Meterial meterial)
{
	//transform�� �� ����
	Vector2<int> pos(pos_x, pos_y);
	Vector2<int> size(size_x, size_y); //collision���� ���

	//collision
	Rectangle2D* collisionShape = new Rectangle2D(size);
	//����  �� addComponent
	transform = new Transform(pos, size, &componentList);
	renderer = new Renderer(transform, Shape::Load(filename1), meterial);
	collision = new Collision(transform, collisionShape, ButtonTag);
	content = new Renderer(transform, Shape::Load(filename2), meterial);
	AddComponent(renderer);
	AddComponent(transform);
	AddComponent(collision);
	AddComponent(content);
}