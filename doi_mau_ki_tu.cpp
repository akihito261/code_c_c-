#include<iostream>
#include<windows.h>
using namespace std;

const int n = 8;

class screen {
    HANDLE handle;
public:
    screen() { //hamf khoi tao
        handle = GetStdHandle(STD_OUTPUT_HANDLE);
    }
public:
    screen& Set(int color) {//màu
        SetConsoleTextAttribute(handle, color);
        return *this;

    }
    screen& SetCursorPos(int x, int y) {//vị trí
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(handle, coord);
        return *this;
    }
    screen& showCursor(bool visible = true) {//hiển thị hoặc ẩn con trỏ
        CONSOLE_CURSOR_INFO info;
        info.dwSize = 100; // 100%
        info.bVisible = visible;
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
        return *this;
    }

};
int main() {
    screen scr;

    scr.SetCursorPos(0, 0)
        .showCursor(false)
        .Set(0x5f); 
    cout << "x";
}