#include "gameObject.h"
#include "engine.h"
#include "transform.h"
#include "renderer.h"
#include "collision.h"
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
void GameObject::Destory()
{
	Engine::Instance()->Destroy(this);
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

void GameObject::Update(float  dt) {
	vector<Component*>::iterator component = componentList.begin();
	for (; component < componentList.end(); component++)
	{
		(* component)->Update(dt);
	}
}

void GameObject::OnDestroy() {
	vector<Component*>::iterator component = componentList.begin();
	for (; component < componentList.end(); component++)
	{
		(*component)->OnDestroy();
	}
}


void GameObject::AddComponent(Component * newComponent) {
	componentList.push_back(newComponent);
}

Component * GameObject::GetComponent() {
	return nullptr;
}