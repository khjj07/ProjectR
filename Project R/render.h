#pragma once
#include "define.h"
#include "screen.h"
using namespace std;

class Render : public Singleton<Render>
{
public:
	Render();
	~Render();
	void Init();
	void Update();
	void Clear();
	void Write(int x, int y, int textColor,int backGroundColor, string str, int depth = 0);

private:
	HANDLE Buffer[2] = { nullptr };
	CHAR_INFO StringBuffer[Screen::Width*Screen::Height];
	int DepthBuffer[Screen::Width * Screen::Height];
	int BufferIndex = 0;
	void Flip();
};

