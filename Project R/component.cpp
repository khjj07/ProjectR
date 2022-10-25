#include "component.h"
#include "collision.h"
#include "engine.h"
#include "gameObject.h"
Component::Component()
{
	Awake();
}
void Component::Awake() {

}

void Component::Start() {

}
void Component::Destory()
{
	Engine::Instance()->Destroy(this->gameObject);
}
void Component::Update(float dt)
{

}

void Component::OnDestroy() 
{

}

void Component::OnCollisionEnter(Collision* other) 
{

}

void Component::OnCollisionStay(Collision* other)
{

}

void Component::OnCollisionExit(Collision* other) 
{

}