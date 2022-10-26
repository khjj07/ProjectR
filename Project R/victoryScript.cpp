#include "victoryScript.h"
#include "gameManager.h"
#include "gameStateManager.h"
#include "ingameCollection.h"
#include "timer.h"
VictoryScript::VictoryScript()
{

}
VictoryScript::VictoryScript(Transform* t, GameObject* go)
{
	transform = t;
	gameObject = go;
}

void VictoryScript::OnEnable()
{
	char str[20];
	sprintf_s(str, "victory%d.txt", GameManager::Instance()->winner);
	transform->GetComponent<Renderer>()->shape = Shape::Load(string(str));
	transform->GetComponent<Renderer>()->SetBackgroundColor(GameManager::Instance()->winnerColor);
	Timer::Delay(1.5, false, []() {
		GameStateManager<MainState>::Instance()->Next();

	});
}