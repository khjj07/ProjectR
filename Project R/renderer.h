#pragma once
#include "transform.h"
#include "define.h"	
#include "component.h"
#include <string>
using namespace std;

class Renderer :public Component
{
public:
	Renderer(Transform *t,string s,int c,int d);
	string shape;
	int depth;
	int color;
	Transform* transform;
	void Draw();
	virtual void Update(double dt);
	void SetColor(int c);
private:

};
