#include "component.h"
#include "buttonScript.h"
#include "gameStateManager.h"


ButtonScript::ButtonScript(Transform *t)
{
	transform = t;
}

void ButtonScript::OnClick()
{
	transform->GetComponent<Renderer>()->SetBackgroundColor(Color::BROWN);
	OnClickEvent();
}
void ButtonScript::Start()
{

}
void ButtonScript::Update(double dt)
{
	transform->GetComponent<Renderer>()->SetBackgroundColor(Color::WHITE);
}

void ButtonScript::OnCollisionEnter(Collision* other)
{
	if (other->tag == CursorTag)
	{
		transform->GetComponent<Renderer>()->SetBackgroundColor(Color::RED);
	}
}

void ButtonScript::OnCollisionStay(Collision* other)
{

}

void ButtonScript::OnCollisionExit(Collision* other)
{
	
}