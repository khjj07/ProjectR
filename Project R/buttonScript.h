#pragma once
#include "transform.h"
#include "gamePad.h"
#include "collision.h"
#include "renderer.h"
#include "event.h"
class Component;
class ButtonScript :public Component
{
public:
	ButtonScript(Transform* t);
	void OnClick();
	virtual void Update(double  dt);
	virtual void Start();
	virtual void  OnCollisionEnter(Collision* other);
	virtual void  OnCollisionStay(Collision* other);
	virtual void  OnCollisionExit(Collision* other);
	Transform* transform;
	Event OnClickEvent{};
	bool entered = false;
private:

};
