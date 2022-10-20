#pragma once
#include "define.h"
using namespace std;
class Collision;

class Component
{
public:
	Component();
	void Awake();
	void OnEnabled();
	void Start();
	virtual void Update();
	void OnDisable();
	void OnDestroy();
	virtual void OnCollisionEnter(Collision* other);
	virtual void OnCollisionStay(Collision* other);
	virtual void OnCollisionExit(Collision* other);
protected:
private:
};