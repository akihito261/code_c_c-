#include<iostream>
#include<windows.h>
using namespace std;

const int n = 8;

void ClearConsoleScreen() {
	system("cls");
}

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

class Process {
protected:

	int value;
	virtual void Init() = 0;
	virtual void Next() = 0;
	virtual bool EOP() = 0;
	void Write() {
		for (int i = 0; i < n; i++) {
			if (value & (1 << i)) {
				screen scr;



				// Đổi màu cho ký tự tiếp theo
				scr.Set(0x0A); // Màu xanh lá cây

				// In ký tự có màu
				cout << (char)254;

				// Trả màu về mặc định sau khi in xong
				scr.Set(0x07); // Màu mặc định (0x07 là màu trắng trên đen)

				// Hiển thị con trỏ
				//cout << '1';
				continue;
			}
			cout << (char)254;
		}

		Sleep(500);
		ClearConsoleScreen();
	}
public:
	void play() {
		Init();
		Write();
		while (!EOP()) {
			Next();

			Write();

		}
	}
};

class SingleL2R : public Process {
protected:
	void Init() override { value = 1; }
	void Next() override { value <<= 1; }
	bool EOP() override { return value >= (1 << n); }
};
class SingleR2L : public Process {
protected:
	void Init() override { value = (1 << n - 1); }
	void Next() override { value >>= 1; }
	bool EOP() override { return value == 0; }
};
class TurnOnL2R : public SingleL2R {
	void Next() override {
		SingleL2R::Next();
		value |= 1;
	}

};
class TurnOffL2R : public SingleR2L {
protected:
	void Init() {
		value = (1 << n) - 1;
	}

};
class TurnOnR2L : public SingleR2L {
protected:
    void Next() override {
        SingleR2L::Next();
        value |= (1 << (n - 1));
    }
	bool EOP() override {
		return value == 255;

	}
   
};
class TurnOffR2L : public SingleL2R {
protected:
    void Init() {
        value = 255;
    }


};

int main() {
	screen src;
	src.showCursor(false);
	SingleL2R().play();
	SingleR2L().play();
	TurnOnL2R().play();
	TurnOffL2R().play();
	TurnOnR2L().play();
	TurnOffL2R().play();
	return 0;
}