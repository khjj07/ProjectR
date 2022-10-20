#pragma once
#include <vector>
#include "component.h"
#include "transform.h"
#include "renderer.h"
#include "collision.h"
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
	void OnDestroy();
	void OnCollisionEnter(Collision* other);
	void OnCollisionStay(Collision* other);
	void OnCollisionExit(Collision* other);
	void AddComponent(Component *);
	void RemoveComponent(Component *);
	Component * GetComponent();
	vector<Component*> componentList;
	Transform *transform;
	Renderer* renderer;
	Collision* collision;
private:

};


