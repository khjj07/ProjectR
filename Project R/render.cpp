#include "define.h"
#include "render.h"

using namespace std;
Render::Render()
{
	Init();
}

Render::~Render()
{
	
}

void Render::Init()
{
	COORD size = { Screen::Width,Screen::Height };
	for (int i=0;i< Screen::Width * Screen::Height;i++)
	{
		DepthBuffer[i] = 0;
	}
	SMALL_RECT rect;
	rect.Left = 0;
	rect.Top = 0;
	rect.Right = size.X - 1;
	rect.Bottom = size.Y - 1;


	//폰트
	CONSOLE_FONT_INFOEX cfi{ sizeof(CONSOLE_FONT_INFOEX) };
	GetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), false, &cfi);
	cfi.dwFontSize.Y = Screen::FontSize;

	//0번 버퍼 초기화
	Buffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetCurrentConsoleFontEx(Buffer[0], false, &cfi);
	SetConsoleScreenBufferSize(Buffer[0], size);
	SetConsoleWindowInfo(Buffer[0], true, &rect);

	//1번 버퍼 초기화
	Buffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetCurrentConsoleFontEx(Buffer[1], false, &cfi);
	SetConsoleScreenBufferSize(Buffer[1], size);
	SetConsoleWindowInfo(Buffer[1], true, &rect);


	//커서 숨기기
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = false;
	SetConsoleCursorInfo(Buffer[0], &cci);
	SetConsoleCursorInfo(Buffer[1], &cci);

	//0번 버퍼 활성화

}

void Render::Update()
{
	COORD size = { Screen::Width,Screen::Height };

	SMALL_RECT rect;
	rect.Left = 0;
	rect.Top = 0;
	rect.Right = size.X - 1;
	rect.Bottom = size.Y - 1;

	WriteConsoleOutput(Buffer[BufferIndex], StringBuffer, size, { 0, 0 }, &rect);
	Flip();
	Clear();
}

void Render::Clear()
{
	for (int i = 0; i < Screen::Height; i++)
	{
		for (int j = 0; j < Screen::Width; j++)
		{
			StringBuffer[i * Screen::Width + j].Char.UnicodeChar = ' ';
			StringBuffer[i * Screen::Width + j].Attributes = NULL;
			DepthBuffer[i * Screen::Width + j] = -9999;
		}
	}
}

vector<string> split(string input, char delimiter) {
	vector<string> result;
	stringstream ss(input);
	string temp;

	while (getline(ss, temp, delimiter)) {
		result.push_back(temp);
	}

	return result;
}

void Render::Write(int x, int y, int textColor,int backgroundColor, string str, int depth)
{
	DWORD dw;
	COORD CursorPosition = { x, y };
	vector<string> result = split(str, '\n');
	vector<string>::iterator iter;

	int k;
	int color = textColor + backgroundColor * 16;
	SetConsoleTextAttribute(Buffer[BufferIndex], color);
	
	for (iter = result.begin(), k=0;  iter< result.end(); iter++)
	{
		for (int i = 0; i < (* iter).size(); i++)
		{
			if( x+i+(y+k) * Screen::Width > 0 && x + i + (y + k) * Screen::Width < Screen::Width*Screen::Height && x+i>=0 && y+k>=0 && x + i < Screen::Width && y + k < Screen::Height)
			{
				if (DepthBuffer[x + i + (y + k) * Screen::Width] <= depth && ((*iter)[i] != ' '))
				{
					StringBuffer[x + i + (y + k) * Screen::Width].Char.UnicodeChar = (*iter)[i];
					StringBuffer[x + i + (y + k) * Screen::Width].Attributes = color;
					DepthBuffer[x + i + (y + k) * Screen::Width] = depth;
				}
			}
			
		}
		k++;
	}
		
}
void Render::Flip()
{
	SetConsoleActiveScreenBuffer(Buffer[BufferIndex]);
	BufferIndex = !BufferIndex;
}