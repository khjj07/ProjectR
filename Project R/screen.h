#pragma once
#include "singleton.h"
class Screen : public Singleton<Screen>
{
public:
	Screen();
	void Update();
	const static int FontSize = 8;
	const static int Width = 3000 / FontSize;
	const static int Height = 800 / FontSize;
	char Title[10] = "Hello";
private:
};