#include "gameObject.h"
#include "engine.h"
GameObject::GameObject()
{
	Awake();
}

GameObject::~GameObject()
{
	OnDestroy();
}

void GameObject::Awake() {

}

void GameObject::OnEnabled() {

}

void GameObject::Start() {

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

void GameObject::Update() {
	vector<Component*>::iterator component = componentList.begin();
	for (; component < componentList.end(); component++)
	{
		(* component)->Update();
	}
}

void GameObject::OnDisable() {

}

void GameObject::OnDestroy() {

}


void GameObject::AddComponent(Component * newComponent) {
	componentList.push_back(newComponent);
}

Component * GameObject::GetComponent() {
	return nullptr;
}