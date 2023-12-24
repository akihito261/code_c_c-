#include<iostream>
#include<windows.h>
using namespace std;
void TextColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void GotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);



}
void ShowCursor(bool visible = true) {
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100; // 100%
	info.bVisible = visible;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}
enum day_of_week { sun, mon, tue, wed, thu, fri, sat };

class so_phuc {
public:
	int a;
	int b;
	so_phuc(int a = 0, int b = 0) {
		this->a = a;
		this->b = b;
	}
public:
	friend so_phuc operator+(const so_phuc& a, const so_phuc& b) {
		return so_phuc(
			a.a + b.a,
			a.b + b.b
		);
	}
	friend ostream& operator<<(ostream& os, const so_phuc& ps) {
		return os << ps.a << " + " << ps.b << 'i';
	}
};
class phan_so {


public:
	int a;
	int b;
	phan_so(int a = 0, int b = 1) {
		this->a = a;
		this->b = b;
	}

	phan_so& rut_gon() {
		int x = a, y = b;
		while (y)
		{
			int r = x % y;
			x = y; y = r;
		}
		if (b < 0) {
			a = -a;
			b = -b;
		}
		a /= x;
		b /= x;

		return *this;
	}
	friend phan_so operator+(const phan_so& a, const phan_so& b) {
		return phan_so(
			a.a * b.b + a.b * b.a,
			a.b * b.b
		);
	}
	friend phan_so operator-(const phan_so& a, const phan_so& b) {
		return a + phan_so(-b.a, b.b);

	}
	friend phan_so operator*(const phan_so& a, const phan_so& b) {
		return phan_so(
			a.a * b.a,
			a.b * b.b
		);
	}
	friend phan_so operator/(const phan_so& a, const phan_so& b) {
		return a * phan_so(b.b, b.a);
	}
	friend ostream& operator<<(ostream& os, const phan_so& ps) {
		phan_so p = ps;
		p.rut_gon();

		if (p.a == 0 || p.b == 1) return os << p.a;
		return os << p.a << '/' << p.b;
	}


};
class hon_so :public phan_so {
public:
	hon_so(int n = 0, int a = 0, int b = 1) 
		:phan_so(n * b + a, b) {};

	friend ostream& operator << (ostream& out, const hon_so& h) {
		int a = h.a;
		int b = h.b;
		int n = a / b;
		a = a %= b;
		if (!n) return out << phan_so(a, b);
		a %= b;
		return out << n << '(' << phan_so(a, b) << ')';
	}
	
};

int main() {
	GotoXY(0, 0);
	TextColor(0x4e);
	ShowCursor(false);

	/*phan_so ps1(-10, 2);
	phan_so ps2(-2, -4);

	ps1.rut_gon();
	ps2.rut_gon();
	phan_so ps3(ps1 - ps2);
	ps3.rut_gon();
	cout << ps1 << " - " << ps2 << " = " << ps3 << endl;

	so_phuc sp1(2, 1);
	so_phuc sp2(2, 3);
	cout << sp1 << " + " << sp2 << " = " << sp1 + sp2;*/


	hon_so x(1, 6, 4);
	cout << x + phan_so(1);

	return 0;
}
