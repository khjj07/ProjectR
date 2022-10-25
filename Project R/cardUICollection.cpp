#include "cardUICollection.h"



CardUICollection::CardUICollection()
{
	CardSelector* selector = new CardSelector();
	Card* card1 = new Card(Vector2<float>(Screen::Width / 2 - 120, Screen::Height / 2 - 20), Vector2<int>(40, 80), "card.txt", Meterial(Color::GREEN, Color::WHITE, 0));
	//card1->AddComponent(new ButtonScript(card1->transform, card1));
	Card* card2 = new Card(Vector2<float>(Screen::Width / 2 - 20, Screen::Height / 2 - 20), Vector2<int>(40, 80), "card.txt", Meterial(Color::GREEN, Color::WHITE, 0));
	//card2->AddComponent(new ButtonScript(card2->transform, card2));
	Card* card3 = new Card(Vector2<float>(Screen::Width / 2 + 80, Screen::Height / 2 - 20), Vector2<int>(40, 80), "card.txt", Meterial(Color::GREEN, Color::WHITE, 0));
	//card3->AddComponent(new ButtonScript(card3->transform, card3));
	selector->script->Push(card1);
	selector->script->Push(card2);
	selector->script->Push(card3);
	Push(selector);
	Push(card1);
	Push(card2);
	Push(card3);
}