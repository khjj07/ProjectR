#include "component.h"
#include "cursorScript.h"
#include "renderer.h"

#include <conio.h>
#include<windows.h>


CursorScript::CursorScript(Transform* t, GameObject* go, GamePad* pad)
{
	transform = t;
	velocity = Vector2<float>(0, 0);
	controller = pad;
	gameObject = go;
}
void CursorScript::Start()
{

}
void CursorScript::Move()
{
	velocity = direction * speed;
}

void CursorScript::Input()
{
	if (controller->result == ERROR_SUCCESS)
	{

		XINPUT_STATE state = controller->state;
		if (state.Gamepad.sThumbLX <= -32768)
		{ // 谅
			direction.x = -1;
			Move();
		}
		if (state.Gamepad.sThumbLX >= 32767)
		{ // 快
			direction.x = 1;
			Move();
		}
		if (state.Gamepad.sThumbLY <= -32768)
		{ // 快
			direction.y = 1;
			Move();
		}
		if (state.Gamepad.sThumbLY >= 32767)
		{ // 快
			direction.y = -1;
			Move();
		}
		if (state.Gamepad.wButtons == XINPUT_GAMEPAD_X && EnterTarget)
		{
			EnterTarget->OnClick();
		}
	}
	else
	{
		if (_kbhit())
		{
			if (GetAsyncKeyState('A') & 0x8001)
			{
				direction.x = -1;
				Move();
			}
			if (GetAsyncKeyState('D') & 0x8001)
			{
				direction.x = 1;
				Move();
			}
			if (GetAsyncKeyState('W') & 0x8001)
			{ // 快
				direction.y = -1;
				Move();
			}
			if (GetAsyncKeyState('S') & 0x8001)
			{ // 快
				direction.y = 1;
				Move();
			}
			if (GetAsyncKeyState('E') & 0x8001 &&EnterTarget)
			{
				EnterTarget->OnClick();
			}
		}
	}


}

void CursorScript::Update(float dt)
{
	Input();
	transform->position = transform->position + velocity * dt;
	velocity = velocity + velocity * (-fraction);
	direction.x = 0;
	direction.y = 0;
	EnterTarget = nullptr;
}

void CursorScript::OnCollisionEnter(Collision* other)
{

}

void CursorScript::OnCollisionStay(Collision* other)
{
	if (other->tag == ButtonTag)
	{
		EnterTarget = other->transform->GetComponent<ButtonScript>();
		transform->GetComponent<Renderer>()->SetBackgroundColor(Color::RED);
	}
}

void CursorScript::OnCollisionExit(Collision* other)
{
		
}
