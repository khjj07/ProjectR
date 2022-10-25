#include "card.h"

Card::Card(Vector2<float> p, Vector2<int> s, string filename1, Meterial meterial)
{
	//transform�� �� ����
	Vector2<float> pos(p.x, p.y);
	Vector2<int> size(s.x, s.y); //collision���� ���

	//����  �� addComponent
	transform = new Transform(pos, size, this, &componentList);
	renderer = new Renderer(transform, Shape::Load(filename1), meterial);

	AddComponent(renderer);
	AddComponent(transform);
}

void Card::Select()
{
	renderer->SetBackgroundColor(Color::LIGHTBLUE);
}

void Card::UnSelect()
{
	renderer->SetBackgroundColor(Color::WHITE);
}
void Card::Apply(GameObject* target)
{

}
