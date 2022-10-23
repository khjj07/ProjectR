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
	//OnClickEvent();
}

void ButtonScript::OnCollisionEnter(Collision* other)
{
	transform->GetComponent<Renderer>()->SetBackgroundColor(Color::RED);
}

void ButtonScript::OnCollisionStay(Collision* other)
{


}

void ButtonScript::OnCollisionExit(Collision* other)
{
	transform->GetComponent<Renderer>()->SetBackgroundColor(Color::WHITE);
}