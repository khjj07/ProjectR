#pragma once
#include "define.h"
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
	void Start();
	void Update(double  dt);
	void OnEnable();
	void OnDisable();
	void Enable();
	void Disable();
	void OnDestroy();
	void OnCollisionEnter(Collision* other);
	void OnCollisionStay(Collision* other);
	void OnCollisionExit(Collision* other);
	void AddComponent(Component *);
	void RemoveComponent(Component *);
	Component * GetComponent();
	vector<Component*> componentList;
	Transform *transform;
	Renderer *renderer;
	Collision* collision;
	bool isEnabled = false;
	bool started = false;
private:
	
};


