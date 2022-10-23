#include "gamePadManager.h"


GamePadManager::GamePadManager()
{

}

void GamePadManager::Update()
{
	for (int i = 0; i < count; i++)
	{
		p[i]->Update();
	}
}

void GamePadManager::AddPad(int id)
{
	GamePad* Pad = new GamePad(id);
	p[id] = Pad;
	count++;
}