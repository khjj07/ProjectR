#pragma once
#include "transform.h"
#include "gamePad.h"
#include "collision.h"
#include "buttonScript.h"
class Component;
class CursorScript :public Component
{
public:
	CursorScript(Transform* t, GameObject* go, GamePad* pad);
	~CursorScript();
	virtual void Update(float  dt);
	virtual void Start();
	void Input();
	void Move();
	virtual void  OnCollisionEnter(Collision* other);
	virtual void  OnCollisionStay(Collision* other);
	virtual void  OnCollisionExit(Collision* other);
	Vector2<float> direction;
	Vector2<float> velocity;
	float fraction = 1;
	float speed = 60;
	GamePad* controller;
	ButtonScript* EnterTarget;
private:
	Transform* transform;
};
