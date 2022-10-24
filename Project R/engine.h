#pragma once
#include "define.h"
#include "gameObject.h"
#include "component.h"
#include "collection.h"
#include "meterial.h"
#include "render.h"
#include "screen.h"


enum EngineState
{
	Running,
	Stop,
	Restart
};
class GameObject;
class Engine : public Singleton<Engine>
{
public:
	Engine();
	void Run();
	void Start();
	void Update(double dt);
	void SetCollection(Collection* newList);
	enum EngineState state= Running;
	Render* render;
	Screen* screen;
private:
	Collection* currentCollection;
	Collection* nextCollection;
};