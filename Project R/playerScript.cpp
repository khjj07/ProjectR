#include "component.h"
#include "playerScript.h"
#include "renderer.h"
#include <conio.h>
#include<windows.h>
PlayerScript::PlayerScript(Transform* t)
{
	transform = t;
	velocity = Vector2<float>(0, 0);
}

void PlayerScript::Start()
{

}
void PlayerScript::Input()
{
	if (_kbhit())
	{
		if (GetAsyncKeyState('A') & 0x8001)
		{
			direction.x = -1;
			velocity.x = direction.x*speed;
		}
		if (GetAsyncKeyState('D') & 0x8001)
		{
			direction.x = 1;
			velocity.x = direction.x * speed;
		}
		if (jumpable && velocity.y == 0 && GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			velocity.y = -jumpforce;
			jumpable = false;
		}
	}
}

void PlayerScript::Update(double dt)
{
	Input();
	transform->position = transform->position + velocity * dt;
	velocity = velocity + gravity;
	velocity.x = velocity.x + velocity.x* (-fraction);
	
}

void PlayerScript::OnCollisionEnter(Collision* other)
{

	transform->GetComponent<Renderer>()->SetColor(BACKGROUND_RED);

}

void PlayerScript::OnCollisionStay(Collision* other)
{
	if (other->tag == FloorTag)
	{
		direction.y = velocity.y > 0 ? 1 : -1;
		transform->position.y = transform->position.y - direction.y;
		if (velocity.y > 1)
			jumpable = true;
		velocity.y = 0;
	}

}

void PlayerScript::OnCollisionExit(Collision* other)
{
	transform->GetComponent<Renderer>()->SetColor(BACKGROUND_INTENSITY);
	
}
