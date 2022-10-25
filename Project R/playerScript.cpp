#include "component.h"
#include "playerScript.h"
#include "renderer.h"
#include <conio.h>
#include<windows.h>
#include "defaultBullet.h"
#include "cardSelector.h"
#include "timer.h"
#include "gameManager.h"
#include "bulletScript.h"

PlayerScript::PlayerScript(Transform* t, Player* go, Aim* a,HP *h, GamePad* pad, int i)
{
	transform = t;
	velocity = Vector2<float>(0, 0);
	aim = a;
	controller = pad;
	hp = h;
	id = i;
	gameObject = go;
}
void PlayerScript::Start()
{

}
void PlayerScript::OnEnable()
{
	hp->Reset();
	aim->Reset();
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
		{ // 谅
			direction.x = -1;
			Move();
		}
		if (state.Gamepad.sThumbLX >= 32767)
		{ // 快
			direction.x = 1;
			Move();
		}

		if (state.Gamepad.sThumbRX <= -aim->response)
		{ 
			aim->direction.x -= aim->speed;
			aim->Move();
		}
		if (state.Gamepad.sThumbRX >= aim->response)
		{
			aim->direction.x += aim->speed;
			aim->Move();
		}
		if (state.Gamepad.sThumbRY <= -aim->response)
		{ // 谅
			aim->direction.y += aim->speed;
			aim->Move();
		}
		if (state.Gamepad.sThumbRY >= aim->response)
		{ // 快
			aim->direction.y -= aim->speed;
			aim->Move();
		}

		if (jumpable && state.Gamepad.wButtons & XINPUT_GAMEPAD_A)
		{ // 快
			Jump();
		}

		if (attackable && state.Gamepad.wButtons == XINPUT_GAMEPAD_RIGHT_SHOULDER)
		{ // 快
			Engine::Instance()->Instantiate(new DefaultBullet(transform->position, aim->position.Normalize(), id));
			attackable = false;
			Timer::Delay(attackDelay, false, [this]() {
				attackable = true;
				});
		}
	}
	else
	{
		if (_kbhit())
		{
			if (GetAsyncKeyState('A') & 0x8001 )
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
			if (attackable && GetAsyncKeyState('F') & 0x8000)
			{
				Engine::Instance()->Instantiate(new DefaultBullet(transform->position, aim->direction, id));
				attackable = false;
				Timer::Delay(1, false, [this]() {
					attackable = true;
					});
			}

			if (GetAsyncKeyState('J') & 0x8001)
			{
				aim->direction.x -= aim->speed;
				aim->Move();
			}
			if (GetAsyncKeyState('L') & 0x8001)
			{
				aim->direction.x += aim->speed;
				aim->Move();
			}
			if (GetAsyncKeyState('I') & 0x8001)
			{
				aim->direction.y -= aim->speed;
				aim->Move();
			}
			if (GetAsyncKeyState('K') & 0x8001)
			{
				aim->direction.y += aim->speed;
				aim->Move();
			}
		}
	}
	
	
}
void PlayerScript::OnDestroy()
{

}

void PlayerScript::Update(float dt)
{
	Input();
	transform->position = transform->position + velocity * dt;

	aim->direction = aim->direction.Normalize();
	aim->position.x =  aim->direction.x*aim->range*2;
	aim->position.y = aim->direction.y * aim->range;
	aim->transform->position = transform->position + aim->position;
	
	int hp_center =  transform->size.x / 2- hp->Get();
	hp->transform->position = transform->position + Vector2<float>(hp_center,-3);

	velocity = velocity + gravity;
	velocity.x = velocity.x + velocity.x * (-fraction);
	
}

void PlayerScript::OnCollisionStay(Collision* other)
{
	
	if (other->tag == FloorTag)
	{
		if (transform->position.y - other->transform->position.y < 0)
		{
			jumpable = true;
		}
		transform->position.y = transform->position.y +(transform->position - other->transform->position).Normalize().y;
		velocity.y = 0;
	}
	if (other->tag == WallTag)
	{
		transform->position.x = transform->position.x + Sign(transform->position.x - other->transform->position.x);
		velocity.x =  0;
	}
	if (other->tag == BulletTag)
	{
		BulletScript* bullet = other->transform->GetComponent<BulletScript>();
		if (bullet->id != id)
		{
			if (hp->Decrease(bullet->damage))
			{
				other->Destory();
				auto gamepadManager = GamePadManager::Instance();
				GameManager::Instance()->selector = this->gameObject;
				gamepadManager->mainController = gamepadManager->p[id];
				DeadEvent();
			}
		}
	}
}