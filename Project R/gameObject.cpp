#include "gameObject.h"
#include "engine.h"
GameObject::GameObject()
{

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
	
}
void GameObject::OnDisable() {

}
void GameObject::Enable() {
	isEnabled = true;
	vector<Component*>::iterator component = componentList.begin();
	for (; component < componentList.end(); component++)
	{
		(* component)->Enable();
	}
	OnEnable();
}

void GameObject::Disable() {
	isEnabled = false;
	vector<Component*>::iterator component = componentList.begin();
	for (; component < componentList.end(); component++)
	{
		(*component)->Disable();
	}
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