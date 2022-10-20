#include "component.h"
#include "collision.h"
Component::Component()
{
	Awake();
}
void Component::Awake() {

}

void Component::Start() {

}

void Component::Update(double dt)
{

}
void Component::OnEnable() 
{
	
}

void Component::OnDisable() {

}

void Component::OnDestroy() {

}
void Component::OnCollisionEnter(Collision* other) {

}
void Component::OnCollisionStay(Collision* other){

}
void Component::OnCollisionExit(Collision* other) {

}