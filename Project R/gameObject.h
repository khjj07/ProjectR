#pragma once
#include <vector>
#include "component.h"
#include "transform.h"
#include "renderer.h"
using namespace std;


class GameObject
{
public:
	GameObject();
	~GameObject();
	void Awake();
	void OnEnabled();
	void Start();
	void Update();
	void OnDisable();
	void OnDestory();
	void AddComponent(Component *);
	void RemoveComponent(Component *);
	Component * GetComponent();
	vector<Component*> Components;
	Transform *transform;
	Renderer* renderer;
private:

};


