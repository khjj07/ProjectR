#include "cardSelectorScript.h"
#include "gamepadManager.h"
#include "gameStateManager.h"
#include "gameManager.h"
#include "timer.h"
#include <random>
CardSelectorScript::CardSelectorScript()
{

}
void CardSelectorScript::OnEnable()
{
	index = 1;
	applier = GameManager::Instance()->selector;
}
void CardSelectorScript::Input()
{
	XINPUT_STATE state = GamePadManager::Instance()->mainController->state;
	if (movable && state.Gamepad.sThumbLX <= -32768)
	{ 
		index = 0 == index ? cardList.size()-1 : index-1;
		movable=false;
		Timer::Delay(moveDelay, false, [this]() {
			movable = true;
		});
	}
	if (movable && state.Gamepad.sThumbLX >= 32767)
	{ 
		index= cardList.size()-1 == index ? 0 : index + 1;
		movable = false;
		Timer::Delay(moveDelay, false, [this]() {
			movable = true;
		});
	}

	if( state.Gamepad.wButtons == XINPUT_GAMEPAD_X)
	{
		cardList[index]->Apply(applier);
		
		GameStateManager<MainState>::Instance()->Next();
	}
}

void CardSelectorScript::Push(Card *card)
{
	cardList.push_back(card);
}



void CardSelectorScript::Update(float dt)
{
	Input();
	for (int i=0; i < cardList.size(); i++)
	{
		if (i == index)
			cardList[i]->Select();
		else
			cardList[i]->UnSelect();
	}

}
