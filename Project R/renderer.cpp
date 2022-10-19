#include "renderer.h"
#include "render.h"
Renderer::Renderer(Transform * t,char *s,int x,int y, int d)
{
	transform = t;
	Shape = s;
	Center.x = x;
	Center.y = y;
	depth = d;
}

void Renderer::Draw()
{
	Render::Instance()->Write(transform->position.x, transform->position.y, BACKGROUND_INTENSITY, Shape, depth);
}

void Renderer::Update()
{
	Draw();
}