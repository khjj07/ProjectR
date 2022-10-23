#include "component.h"
#include "renderer.h"
#include "render.h"

Renderer::Renderer(Transform* t, string s, Meterial meterial, int d)
{
	transform = t;
	shape = s;
	depth = d;
	backgroundColor = meterial.backgroundColor;
	textColor = meterial.textColor;
}

void Renderer::Draw()
{
	Render::Instance()->Write((int)transform->position.x, (int)transform->position.y, textColor, backgroundColor,shape, depth);
}

void Renderer::SetBackgroundColor(int color)
{
	backgroundColor = color;
}

void Renderer::SetTextColor(int color)
{
	textColor = color;
}


void Renderer::Update(double dt)
{
	Draw();
}