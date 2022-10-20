#pragma once
#include "transform.h"
#include "Icollision.h"
class Component;
class PlayerScript:public Component
{
public:
	PlayerScript(Transform *t);
	~PlayerScript();
	void Update();
	void Move();
	virtual void  OnCollisionEnter(Collision* other);
	virtual void  OnCollisionStay(Collision* other);
	virtual void  OnCollisionExit(Collision* other);
private:
	Transform* transform;
};
