#pragma once
#include "define.h"
#include "component.h"
#include "transform.h"
#include "renderer.h"
#include "collision.h"

using namespace std;

class Transform;
class Renderer;
class Collision;

class GameObject
{
public:
	GameObject();
	~GameObject();
	void Awake();
	void Start();
	void Update(float  dt);
	void OnDestroy();
	void Destory();
	void OnEnable();
	void OnDisable();
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


