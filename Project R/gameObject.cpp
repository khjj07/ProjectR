#include "gameObject.h"

GameObject::GameObject()
{
	Awake();
}

GameObject::~GameObject()
{
	OnDestory();
}

void GameObject::Awake() {

}

void GameObject::OnEnabled() {

}

void GameObject::Start() {

}

void GameObject::Update() {

}

void GameObject::OnDisable() {

}

void GameObject::AddComponent(Component *) {

}

Component * GameObject::GetComponent() {

}