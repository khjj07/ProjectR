#include "roundScript.h"
#include "gameManager.h"
#include "gameStateManager.h"
#include "ingameCollection.h"
#include "timer.h"
RoundScript::RoundScript()
{

}
RoundScript::RoundScript(Transform* t, GameObject* go)
{
	transform = t;
	gameObject = go;
}

void RoundScript::OnEnable()
{
	char str[20];
	sprintf_s(str, "round%d.txt", GameManager::Instance()->round);
	transform->GetComponent<Renderer>()->shape = Shape::Load(string(str));
	Timer::Delay(1.5, false, []() {
		GameStateManager<MainState>::Instance()->Next();

	});
}