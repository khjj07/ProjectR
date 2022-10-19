#pragma once

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
protected:
private:
};