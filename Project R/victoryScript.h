#pragma once
#include "transform.h"
#include "gamePad.h"
#include "collision.h"
#include "renderer.h"
#include "event.h"

class VictoryScript : public Component
{
public:
	VictoryScript();
	VictoryScript(Transform* t, GameObject* go);
	virtual void OnEnable();
	Transform* transform;

};