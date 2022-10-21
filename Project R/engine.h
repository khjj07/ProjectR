#pragma once
#include "singleton.h"
#include "gameObject.h"
#include "render.h"
#include "screen.h"
#include<vector>
#include "collision.h"
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