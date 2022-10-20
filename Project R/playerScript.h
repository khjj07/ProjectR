#pragma once
#include "transform.h"
#include "Icollision.h"
class Component;
class PlayerScript:public Component
{
public:
	PlayerScript(Transform *t);
	~PlayerScript();
	void Update(double  dt);
	void Start();
	void Input();
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
	
private:
	Transform* transform;
};
