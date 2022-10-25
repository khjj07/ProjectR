#pragma once
#include "define.h"
using namespace std;
class Collision;
class GameObject;

class Component
{
public:
	Component();
	void Awake();
	virtual void Start();
	virtual void Update(float  dt);
	void Destory();
	virtual void OnDestroy();
	virtual void OnEnable();
	virtual void OnDisable();
	virtual void OnCollisionEnter(Collision* other);
	virtual void OnCollisionStay(Collision* other);
	virtual void OnCollisionExit(Collision* other);
	bool isEnabled = false;
	GameObject *gameObject;
protected:
private:
};