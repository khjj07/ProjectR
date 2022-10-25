#pragma once
#include "transform.h"
#include "gamePad.h"
#include "collision.h"
#include "aim.h"
#include "hp.h"
class Component;
class PlayerScript:public Component
{
public:
	PlayerScript(Transform *t, GameObject* go, Aim *a,HP* h,GamePad* pad, int i);
	~PlayerScript();
	virtual void Update(float  dt);
	virtual void Start();
	void Input();
	void Move();
	void Jump();
	virtual void OnDestroy();
	virtual void  OnCollisionStay(Collision* other);
	Vector2<float> direction;
	Vector2<float> velocity;
	Vector2<float> gravity = Vector2<float>(0,1);
	Vector2<int> contactDirection;
	float fraction =0.05;
	float speed = 75;
	float jumpforce = 75;
	bool attackable = true;
	bool jumpable = false;
	int id;
	HP *hp;
	GamePad* controller;
	Aim * aim;
private:
	Transform* transform;
};
