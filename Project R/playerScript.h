#pragma once
#include "transform.h"
#include "gamePad.h"
#include "collision.h"
#include "aim.h"
class Component;
class PlayerScript:public Component
{
public:
	PlayerScript(Transform *t,Aim *a,GamePad* pad);
	~PlayerScript();
	virtual void Update(double  dt);
	virtual void Start();
	void Input();
	void Move();
	void Jump();
	virtual void  OnCollisionStay(Collision* other);
	Vector2<float> direction;
	Vector2<float> velocity;
	Vector2<float> gravity = Vector2<float>(0,1);
	float fraction =0.01;
	float speed = 50;
	float jumpforce = 100;

	bool jumpable = false;
	GamePad* controller;
	Aim * aim;
private:
	Transform* transform;
};
