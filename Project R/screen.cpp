#include "screen.h"
#include <iostream>

#include<windows.h>
#include<stdlib.h>
#include "define.h"
using namespace std;
BOOL SetConsoleSize(int cols, int rows) {
    HWND hWnd;
    HANDLE hConOut;
    CONSOLE_FONT_INFO fi;
    CONSOLE_SCREEN_BUFFER_INFO bi;
    int w, h, bw, bh;
    RECT rect = { 0, 0, 0, 0 };
    COORD coord = { 0, 0 };
    hWnd = GetConsoleWindow();
    if (hWnd) {
        hConOut = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hConOut && hConOut != (HANDLE)-1) {
            if (GetCurrentConsoleFont(hConOut, FALSE, &fi)) {
                if (GetClientRect(hWnd, &rect)) {
                    w = rect.right - rect.left;
                    h = rect.bottom - rect.top;
                    if (GetWindowRect(hWnd, &rect)) {
                        bw = rect.right - rect.left - w;
                        bh = rect.bottom - rect.top - h;
                        if (GetConsoleScreenBufferInfo(hConOut, &bi)) {
                            coord.X = bi.dwSize.X;
                            coord.Y = bi.dwSize.Y;
                            if (coord.X < cols || coord.Y < rows) {
                                if (coord.X < cols) {
                                    coord.X = cols;
                                }
                                if (coord.Y < rows) {
                                    coord.Y = rows;
                                }
                                if (!SetConsoleScreenBufferSize(hConOut, coord)) {
                                    return FALSE;
                                }
                            }
                            return SetWindowPos(hWnd, NULL, rect.left, rect.top, cols * fi.dwFontSize.X + bw, rows * fi.dwFontSize.Y + bh, SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOOWNERZORDER | SWP_NOZORDER);
                        }
                    }
                }
            }
        }
    }
    return FALSE;
}


BOOL GetConsoleSize(int* cols, int* rows) {
    HWND hWnd;
    HANDLE hConOut;
    CONSOLE_FONT_INFO fi;
    int w, h;
    RECT rect = { 0, 0, 0, 0 };
    hWnd = GetConsoleWindow();
    if (hWnd) {
        hConOut = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hConOut && hConOut != (HANDLE)-1) {
            if (GetCurrentConsoleFont(hConOut, FALSE, &fi)) {
                if (GetClientRect(hWnd, &rect)) {
                    w = rect.right - rect.left;
                    h = rect.bottom - rect.top;
                    *cols = w / fi.dwFontSize.X;
                    *rows = h / fi.dwFontSize.Y;
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

Screen::Screen()
{
    char cmd[50];
    sprintf_s(cmd, "mode con cols=%d lines=%d | title %s", Width, Height, Title);
    system(cmd);
}
void Screen::Update()
{
    int cols, rows;
    GetConsoleSize(&cols, &rows);
    if (cols != Width || rows != Height)
    {
        SetConsoleSize(Width, Height);
    }
}
