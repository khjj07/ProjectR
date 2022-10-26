#pragma once
#include "transform.h"
#include "gamePad.h"
#include "collision.h"
#include "renderer.h"
#include "event.h"

class RoundScript : public Component
{
public :
	RoundScript();
	RoundScript(Transform* t, GameObject* go);
	virtual void OnEnable();
	Transform* transform;

};