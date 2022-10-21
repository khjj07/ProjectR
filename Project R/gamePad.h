#pragma once
#include <iostream>
#include <windows.h>
#include <Xinput.h>
#include <Xinput.h>
#pragma comment(lib, "xinput.lib")

class GamePad
{
public:
	GamePad(int x);
	void Update();
	void GetState();
	DWORD result;
	XINPUT_STATE state;
	int id;
};