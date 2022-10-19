#pragma once
#include "Define.h"
class GameObject		
{
public:
	GameObject();
	void Awake();
	void Start();
	void OnEnable();
	void Update();
	void OnDisable();
	void OnDestroy();
	bool isActive=true;
	Vector2 Position;


private:


};
