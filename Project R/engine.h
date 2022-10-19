#pragma once
#include "singleton.h"
#include "gameObject.h"
#include "render.h"
#include "screen.h"
#include<vector>
using namespace std;

enum EngineState
{
	Running,
	Stop
};

class Engine : public Singleton<Engine>
{
public:
	Engine();
	void Run();
	void Update();
	void AddObject(GameObject *newObject);
	enum EngineState state= Running;
	Render* render;
	Screen* screen;
private:
	vector<GameObject> gameObjectList;

};