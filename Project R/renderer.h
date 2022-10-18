#pragma once
#include "transform.h"

class Renderer
{
public:
	Renderer(Transform *t,char *s);
	char* shape;
	Transform* transform;
	void draw();
private:

};
