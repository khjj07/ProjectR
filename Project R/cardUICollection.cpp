#include "cardUICollection.h"
#include "cursor.h"
#include "button.h"
#include "box.h"
#include "buttonScript.h"
#include "gamePadManager.h"
#include "engine.h"
#include "fps.h"
#include "gameStateManager.h"




CardUICollection::CardUICollection()
{
	Button* card1 = new Button(Vector2<float>(Screen::Width / 2 - 50 / 2, Screen::Height / 2 - 20), Vector2<int>(50, 80), "button_frame1.txt", Meterial(Color::GREEN, Color::WHITE, 0));
	card1->AddComponent(new ButtonScript(card1->transform, card1));
	Button* card2 = new Button(Vector2<float>(Screen::Width / 2 - 20 / 2, Screen::Height / 2 - 20), Vector2<int>(50, 80), "button_frame1.txt", Meterial(Color::GREEN, Color::WHITE, 0));
	card2->AddComponent(new ButtonScript(card2->transform, card2));
	Button* card3 = new Button(Vector2<float>(Screen::Width / 2 + 30 / 2, Screen::Height / 2 - 20), Vector2<int>(50, 80), "button_frame1.txt", Meterial(Color::GREEN, Color::WHITE, 0));
	card3->AddComponent(new ButtonScript(card3->transform, card3));
	Push(card1);
	Push(card2);
	Push(card3);
}