#pragma once
#include "fps.h"
#include "engine.h"
#include<stdio.h>
#include<time.h>
#include<conio.h>

clock_t FPSCurTime, FPSOldTime;
int FrameCnt;
char* FPSTextBuffer;

class FPSScript : public Component
{
public:
	Renderer* renderer;
	FPSScript(Renderer* r);
	virtual void Update(double dt);
private:

};

FPSScript::FPSScript(Renderer* r)
{
	renderer = r;
}

void FPSScript::Update(double dt)
{

	char FPSTextBuffer[30];
	FrameCnt++;
	FPSCurTime = clock();
	if (FPSCurTime - FPSOldTime >= 1000)
	{
		sprintf_s(FPSTextBuffer, "FPS:%d", FrameCnt);
		renderer->shape = string(FPSTextBuffer);
		FPSOldTime = clock();
		FrameCnt = 0;
	}
}


FPS::FPS(int x, int y)
{
	//transform에 들어갈 변수
	Vector2<int> pos(x, y);



	//선언  및 addComponent
	transform = new Transform(pos, Vector2<int>(0,0), &componentList);
	renderer = new Renderer(transform, string(""), Meterial(Color::WHITE,Color::BLACK,3));
	FPSScript *script=new FPSScript(renderer);
	AddComponent(renderer);
	AddComponent(transform);
	AddComponent(script);
}

