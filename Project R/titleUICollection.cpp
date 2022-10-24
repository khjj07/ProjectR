#include "titleUICollection.h"
#include "cursor.h"
#include "button.h"
#include "box.h"
#include "buttonScript.h"
#include "gamePadManager.h"
#include "engine.h"
#include "fps.h"
#include "event.h"
#include "gameStateManager.h"

int EventHandler::counter = 0;

TitleUICollection::TitleUICollection()
{
	Box* title = new Box(Screen::Width / 2 - 20 / 2, Screen::Height / 2 - 20, 40, 4, "title.txt", Meterial(Color::WHITE, Color::BLACK, 0));

	Button* startbutton = new Button(Screen::Width/2-300/2, Screen::Height/2-10, 300, 15, "button_frame1.txt","Content.txt", Meterial(Color::GREEN, Color::WHITE,0));
	startbutton->AddComponent(new ButtonScript(startbutton->transform));
	EventHandler start([]() {
		GameStateManager<MainState>::Instance()->Next();
	});
	startbutton->transform->GetComponent<ButtonScript>()->OnClickEvent.addHandler(start);


	Button* quitbutton = new Button(Screen::Width / 2 - 300 / 2, Screen::Height / 2+10, 300, 15, "button_frame1.txt", "Content.txt", Meterial(Color::GREEN, Color::WHITE,0));
	quitbutton->AddComponent(new ButtonScript(quitbutton->transform));
	EventHandler quit([]() {
		GameStateManager<MainState>::Instance()->Next();
	});
	quitbutton->transform->GetComponent<ButtonScript>()->OnClickEvent.addHandler(quit);

	Cursor* cursor = new Cursor(1, 80, 3, 4, "cursor.txt", Meterial(Color::BLUE, Color::BLUE, 1), GamePadManager::Instance()->p[0]);
	FPS* fps = new FPS(10,10);

	Push(fps);
	Push(title);
	Push(cursor);
	Push(startbutton);
	Push(quitbutton);
}