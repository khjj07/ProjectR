#pragma once
#include "engine.h"
#include "cardSelectorScript.h"
#include "card.h"
class  CardSelector: public GameObject
{
public:
	CardSelector();
	CardSelectorScript* script;
private:

};
