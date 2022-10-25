#pragma once
#include "singleton.h"
#include "player.h"
class GameManager : public Singleton<GameManager>
{
public:
	GameManager();
	Player* selector;
	static int score[2];

private:

};
