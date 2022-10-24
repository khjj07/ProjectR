#include "component.h"
#include "playerScript.h"
#include "renderer.h"

#include <conio.h>
#include<windows.h>


PlayerScript::PlayerScript(Transform* t,Aim* a,GamePad *pad)
{
	transform = t;
	velocity = Vector2<float>(0, 0);
	aim = a;
	controller = pad;
}
void PlayerScript::Start()
{

}
void PlayerScript::Move()
{
	velocity.x = direction.x *speed;
}
void PlayerScript::Jump()
{
	velocity.y = -jumpforce;
	jumpable = false;
}
void PlayerScript::Input()
{
	if (controller->result == ERROR_SUCCESS)
	{
		
		XINPUT_STATE state= controller->state;
		if (state.Gamepad.sThumbLX <= -32768)
		{ // аб
			direction.x = -1;
			Move();
		}
		if (state.Gamepad.sThumbLX >= 32767)
		{ // ©Л
			direction.x = 1;
			Move();
		}
		if (jumpable && state.Gamepad.wButtons & XINPUT_GAMEPAD_A)
		{ // ©Л
			Jump();
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
			if (jumpable && velocity.y == 0 && GetAsyncKeyState(VK_SPACE) & 0x8000)
			{
				Jump();
			}

			if (GetAsyncKeyState('J') & 0x8001)
			{
				aim->direction.x = -0.001;
				aim->Move();
			}
			if (GetAsyncKeyState('L') & 0x8001)
			{
				aim->direction.x = 0.001;
				aim->Move();
			}
			if (GetAsyncKeyState('I') & 0x8001)
			{
				aim->direction.y = -0.001;
				aim->Move();
			}
			if (GetAsyncKeyState('K') & 0x8001)
			{
				aim->direction.y = 0.001;
				aim->Move();
			}
		}
	}
	
	
}

void PlayerScript::Update(double dt)
{
	Input();
	transform->position = transform->position + velocity * dt;
	velocity = velocity + gravity;
	velocity.x = velocity.x + velocity.x* (-fraction);

	aim->position = aim->direction.Normalize() * aim->range;
	aim->transform->position = transform->position + aim->position;
	aim->velocity = aim->velocity + aim->velocity * -(aim->fraction);
}

void PlayerScript::OnCollisionEnter(Collision* other)
{
	transform->GetComponent<Renderer>()->SetTextColor(10);
}

void PlayerScript::OnCollisionStay(Collision* other)
{
	if (other->tag == FloorTag)
	{
		direction.y = velocity.y >= -1 ? 1 : -1;
		transform->position.y = transform->position.y - direction.y;
		if (direction.y == 1)
			jumpable = true;
		velocity.y = 0;
	}
}

void PlayerScript::OnCollisionExit(Collision* other)
{
	transform->GetComponent<Renderer>()->SetBackgroundColor(BACKGROUND_INTENSITY);
	
}
