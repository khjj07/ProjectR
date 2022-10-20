#include "component.h"
#include "playerScript.h"
#include "renderer.h"
#include <conio.h>
#include<windows.h>
PlayerScript::PlayerScript(Transform* t)
{
	transform = t;
}
void PlayerScript::Update()
{
	if (_kbhit())
	{
		if (GetAsyncKeyState('W') & 0x0001)
		{
			transform->position.y--;
		}
		if (GetAsyncKeyState('S') & 0x0001)
		{
			transform->position.y++;
		}
		if (GetAsyncKeyState('A') & 0x0001)
		{
			transform->position.x--;
		}
		if (GetAsyncKeyState('D') & 0x0001)
		{
			transform->position.x++;
		}
	}
}

void PlayerScript::OnCollisionEnter(Collision* other)
{
	transform->GetComponent<Renderer>()->SetColor(BACKGROUND_RED);

}

void PlayerScript::OnCollisionStay(Collision* other)
{

}

void PlayerScript::OnCollisionExit(Collision* other)
{
	transform->GetComponent<Renderer>()->SetColor(BACKGROUND_INTENSITY);
}
