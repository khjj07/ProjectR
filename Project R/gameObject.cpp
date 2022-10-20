#include "gameObject.h"
#include "engine.h"
GameObject::GameObject()
{
	Engine::Instance()->AddObject(this);
}

GameObject::~GameObject()
{
	OnDestroy();
}

void GameObject::Start() {
	vector<Component*>::iterator component = componentList.begin();
	for (; component < componentList.end(); component++)
	{
		(*component)->Start();
	}
}
void GameObject::OnCollisionEnter(Collision* other) 
{
	vector<Component*>::iterator component = componentList.begin();
	for (; component < componentList.end(); component++)
	{
		(*component)->OnCollisionEnter(other);
	}
}
void GameObject::OnCollisionStay(Collision* other)
{
	vector<Component*>::iterator component = componentList.begin();
	for (; component < componentList.end(); component++)
	{
		(*component)->OnCollisionStay(other);
	}
}
void GameObject::OnCollisionExit(Collision* other)
{
	vector<Component*>::iterator component = componentList.begin();
	for (; component < componentList.end(); component++)
	{
		(*component)->OnCollisionExit(other);
	}
}

void GameObject::Update(double  dt) {
	vector<Component*>::iterator component = componentList.begin();
	for (; component < componentList.end(); component++)
	{
		(* component)->Update(dt);
	}
}
void GameObject::OnEnable() {
	vector<Component*>::iterator component = componentList.begin();
	for (; component < componentList.end(); component++)
	{
		(*component)->OnEnable();
	}
}
void GameObject::OnDisable() {
	vector<Component*>::iterator component = componentList.begin();
	for (; component < componentList.end(); component++)
	{
		(*component)->OnDisable();
	}
}
void GameObject::Enable() {
	isEnabled = true;
	OnEnable();
}

void GameObject::Disable() {
	isEnabled = false;
	OnDisable();
}

void GameObject::OnDestroy() {

}


void GameObject::AddComponent(Component * newComponent) {
	componentList.push_back(newComponent);
}

Component * GameObject::GetComponent() {
	return nullptr;
}