#include "titleUICollection.h"
#include "cursor.h"
#include "button.h"
#include "box.h"
#include "buttonScript.h"
#include "gamePadManager.h"
#include "engine.h"
#include "gameStateManager.h"
#include "player.h"
#include "gameManager.h"

TitleUICollection::TitleUICollection()
{
	GamePadManager* gamepadManager = GamePadManager::Instance();
	gamepadManager->mainController = gamepadManager->p[0];
	Box* title = new Box(Vector2<float>(Screen::Width / 2 - 35, Screen::Height / 2 - 30), Vector2<int>(40, 4), "title.txt", Meterial(Color::WHITE, Color::BLACK, 0));

	Button* startbutton = new Button(Vector2<float>(Screen::Width / 2 - 300 / 2, Screen::Height / 2 - 10), Vector2<int>(300, 15), "button_frame1.txt", Meterial(Color::GREEN, Color::WHITE, 0));
	startbutton->AddComponent(new ButtonScript(startbutton->transform, startbutton));
	EventHandler start([]() {
		GameManager::Instance()->round = 1;
		GameManager::Instance()->score[0] = 0;
		GameManager::Instance()->score[1] = 0;
		GameStateManager<MainState>::Instance()->Next();
		});
	startbutton->transform->GetComponent<ButtonScript>()->OnClickEvent.addHandler(start);


	Button * quitbutton = new Button(Vector2<float>(Screen::Width / 2 - 300 / 2, Screen::Height / 2 + 10), Vector2<int>(300, 15), "button_frame2.txt", Meterial(Color::GREEN, Color::WHITE, 0));
	quitbutton->AddComponent(new ButtonScript(quitbutton->transform, startbutton));
	EventHandler quit([]() {
		GameStateManager<MainState>::Instance()->Next();
		});
	quitbutton->transform->GetComponent<ButtonScript>()->OnClickEvent.addHandler(quit);

	Cursor * cursor = new Cursor(Vector2<float>(1, 80), Vector2<int>(3, 4), "cursor.txt", Meterial(Color::BLUE, Color::BLUE, 1), GamePadManager::Instance()->mainController);

	Push(title);
	Push(cursor);
	Push(startbutton);
	Push(quitbutton);
}