#pragma once
#include "transform.h"
#include "gamePad.h"
#include "collision.h"
#include "renderer.h"
#include "event.h"
#include "card.h"
#include "player.h"
class Component;
class CardSelectorScript :public Component
{
public:
	CardSelectorScript();
	void Input();
	virtual void Update(float  dt);
	virtual void OnEnable();
	vector<Card*> cardList;
	int index = 1;
	bool movable = true;
	float moveDelay = 0.001;
	Player* applier;
	void Push(Card* card);

private:

};
