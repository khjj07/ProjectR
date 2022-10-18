#include "screen.h"
#include <iostream>
#include<windows.h>
#include<stdlib.h>
#include "define.h"
using namespace std;
Screen::Screen()
{
	char cmd[50];
	sprintf_s(cmd, "mode con cols=%d lines=%d | title %s", Width,Height,Title);
}
