#pragma once
#include "transform.h"
#include "meterial.h"
#include "gameObject.h"
class Renderer :public Component
{
public:
	Renderer(Transform *t,string s, Meterial meterial);
	string shape;
	int depth;
	int backgroundColor;
	int textColor;
	Transform* transform;
	void Draw();
	virtual void Update(float dt);
	void SetBackgroundColor(int color);
	void SetTextColor(int color);
private:

};
