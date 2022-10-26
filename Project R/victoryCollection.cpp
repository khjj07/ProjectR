#include "victoryCollection.h"
#include "cursor.h"
#include "button.h"
#include "box.h"
#include "buttonScript.h"
#include "gamePadManager.h"
#include "engine.h"
#include "gameStateManager.h"
#include "victoryScript.h"
#include "player.h"
#include "gameManager.h"

VictoryCollection::VictoryCollection()
{
	Box* victory = new Box(Vector2<float>(Screen::Width / 2 - 60 / 2, Screen::Height / 2 - 7 / 2), Vector2<int>(0, 0), string("victory0.txt"), Meterial(Color::WHITE, Color::BLACK, 0));
	victory->AddComponent(new VictoryScript(victory->transform, victory));
	Push(victory);
}