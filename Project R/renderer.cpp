#include "component.h"
#include "renderer.h"
#include "render.h"


Renderer::Renderer(Transform* t, string s, Meterial meterial)
{
	transform = t;
	shape = s;
	depth = meterial.depth;
	backgroundColor = meterial.backgroundColor;
	textColor = meterial.textColor;
}

void Renderer::Draw()
{
	Render::Instance()->Write(round(transform->position.x), round(transform->position.y), textColor, backgroundColor,shape, depth);
}

void Renderer::SetBackgroundColor(int color)
{
	backgroundColor = color;
}

void Renderer::SetTextColor(int color)
{
	textColor = color;
}


void Renderer::Update(float dt)
{
	Draw();
}