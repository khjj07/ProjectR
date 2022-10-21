#pragma once
#include "transform.h"
#include "gamePad.h"
#include "collision.h"
class Component;
class PlayerScript:public Component
{
public:
	PlayerScript(Transform *t,GamePad* pad);
	~PlayerScript();
	void Update(double  dt);
	void Start();
	void Input();
	void Move();
	void Jump();
	virtual void  OnCollisionEnter(Collision* other);
	virtual void  OnCollisionStay(Collision* other);
	virtual void  OnCollisionExit(Collision* other);
	Vector2<float> direction;
	Vector2<float> velocity;
	Vector2<float> gravity = Vector2<float>(0,1);
	float fraction =0.01;
	float speed = 30;
	float jumpforce = 100;
	bool jumpable = false;
	GamePad* controller;
private:
	Transform* transform;
};
