#pragma once
#include "define.h"
#include "gamePad.h"
#pragma comment(lib, "xinput.lib")
class Player;
class GamePadManager :public Singleton<GamePadManager>
{
public:
	GamePadManager();
	void AddPad(int id);
	void Update();
	GamePad* p[4];
	GamePad* mainController;
private:
	int count = 0;


};