#include "roundUICollection.h"
#include "roundScript.h"


RoundUICollection::RoundUICollection()
{
	Box* round = new Box(Vector2<float>(Screen::Width / 2 -  60/ 2, Screen::Height / 2 - 7/2), Vector2<int>(0, 0), string("round1.txt"), Meterial(Color::WHITE, Color::BLACK, 0));
	round->AddComponent(new RoundScript(round->transform, round));
	Push(round);
}