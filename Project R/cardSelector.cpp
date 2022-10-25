#include "cardSelector.h"


CardSelector::CardSelector()
{

	script = new CardSelectorScript();
	AddComponent(script);
}