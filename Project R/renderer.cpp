#include "component.h"
#include "renderer.h"
#include "render.h"

Renderer::Renderer(Transform * t,string s, int c, int d)
{
	transform = t;
	shape = s;
	depth = d;
	color = c;
}

void Renderer::Draw()
{
	Render::Instance()->Write(transform->position.x, transform->position.y, color, shape, depth);
}

void Renderer::SetColor(int c)
{
	color = c;
}

void Renderer::Update()
{
	Draw();
}