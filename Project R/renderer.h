#pragma once
#include "transform.h"
#include "define.h"	
#include "component.h"

class Renderer :public Component
{
public:
	Renderer(Transform *t,char *s,int x,int y,int d);
	char* Shape;
	int depth;
	Vector2<int> Center;
	Transform* transform;
	void Draw();
	virtual void Update();
private:

};
