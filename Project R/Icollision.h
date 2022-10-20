#pragma once
#include "collision.h"
#define interface class

__interface ICollisionEnter
{
public: 
	virtual void OnCollisionEnter(Collision other);
};	
__interface ICollisionStay
{
public:
	virtual void OnCollisionStay(Collision other);
};
__interface ICollisionExit
{
public:
	virtual void CollisionExit(Collision other);
};

