#pragma once
#include "singleton.h"
#include "player.h"
class GameManager : public Singleton<GameManager>
{
public:
	GameManager();
	Player* selector;
	int score[2];
	int round=0;
	int winner;
	int winnerColor;
private:

};
