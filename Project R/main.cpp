#include<iostream>
#include"engine.h"
#include "Example.h"
int main()
{
	Engine *engine = Engine::Instance();
	Example* obj = new Example();
	engine->Run();


	return 0;
}