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
	ButtonScript(Transform* t, GameObject* go);
	void OnClick();
	virtual void Update(float  dt);
	virtual void Start();
	virtual void  OnCollisionStay(Collision* other);

	Transform* transform;
	Event OnClickEvent{};
	bool entered = false;
private:

};
