#include<iostream>
#include"screen.h"
#include "render.h"
#include <string>
void OnEnable()
{

}

void Update()
{

}

void render()
{
	Render::Instance()->Update();
}

int main()
{
	//화면 크기 및 타이틀
	string str("AAAA\nAAAAA");

	char title[] = "hello";
	Screen::Instance();
	//라이프 사이클
	while (true)
	{
		Render::Instance()->Write(50, 50, BACKGROUND_INTENSITY, str, 0);
		render();
		OnEnable();
		Update();
	}
	return 0;
}