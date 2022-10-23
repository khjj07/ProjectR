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
	Stop
};
class GameObject;
class Engine : public Singleton<Engine>
{
public:
	Engine();
	void Run();
	void Start();
	void Update(double dt);
	void AddObject(GameObject *newObject);
	void AddCollision(Collision *newCollision);
	enum EngineState state= Running;
	Render* render;
	Screen* screen;
private:
	vector<GameObject *> gameObjectList;
	vector<Collision *> collisionList;
	
};