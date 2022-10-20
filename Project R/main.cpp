#include<iostream>
#include"component.h"
#include"engine.h"
#include "Example.h"
#include "Example2.h"
int main()
{
	Engine *engine = Engine::Instance();

	Example* obj = new Example();
	Example2* obj2 = new Example2();

	engine->Run();


	return 0;
}