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

void GameObject::Update() {
	vector<Component>::iterator component = components.begin();
	for (; component < components.end(); component++)
	{
		component->Update();
	}
}

void GameObject::OnDisable() {

}

void GameObject::OnDestroy() {

}

void GameObject::AddComponent(Component * newComponent) {
	components.push_back(*newComponent);
}

Component * GameObject::GetComponent() {
	return nullptr;
}