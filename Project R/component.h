#pragma once
#include "define.h"
using namespace std;
class Collision;

class Component
{
public:
	Component();
	void Awake();
	virtual void Start();
	virtual void Update(double  dt);
	virtual void OnDisable();
	virtual void OnEnable();
	void Disable();
	void Enable();

	void OnDestroy();
	virtual void OnCollisionEnter(Collision* other);
	virtual void OnCollisionStay(Collision* other);
	virtual void OnCollisionExit(Collision* other);
	bool isEnabled = false;
protected:
private:
};