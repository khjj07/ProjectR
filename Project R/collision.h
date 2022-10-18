#pragma once
#include "component.h"
#include "transform.h"

struct Static{

};
template<typename T>
class Collision :public Component
{
public:
	Collision(Transform* t, int width, int height, int id);
	Transform *transform;
	bool OnCollisionEnter(Collision other);
	bool OnCollisionStay(Collision other);
	bool OnCollisionExit(Collision other);
	T type;
	int* Shape;
protected:
private:
};