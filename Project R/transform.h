#pragma once
#include "component.h"
#include "define.h"
class Transform : public Component 
{
public:
	Transform(int x,int y);
	Vector2<int> position;
private:

};