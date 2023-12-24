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
class Date {
public:
	int year;
	int month;
	int day;
	day_of_week day_week;
public:
	Date() {
		year = 2000;
		month = 1;
		day = 1;
	}
	Date(int year, int month, int day) {
		this->year = year;
		this->month = month;
		this->day = day;

	}
public:
	int Year() const { return year; }
	int Month() const { return month; }
	int Day() const { return day; }

	/*
	Date(int year, int month, int day)
	:year(year),month(month),day(day){}
	*/

	/*
	Date(int year = 2000,month = 1,day=1):year(year),month(month),day(day){}
	*/
	day_of_week Get_day_of_week() {
		int sum_day = 0;
		for (int i = 1; i < month; i++) {
			sum_day += getDayofMonth(year, i);
		}
		int d = year - 2000;


		return day_of_week((d + (d - 1) / 4 + sum_day + day - 1) % 7);
	}
	string dayToString() {
		switch (Get_day_of_week()) {
		case sun: return "Sunday";
		case mon: return "Monday";
		case tue: return "Tuesday";
		case wed: return "Wednesday";
		case thu: return "Thursday";
		case fri: return "Friday";
		case sat: return "Saturday";
		}
	}
	static int getDayofMonth(int y, int m) {
		if (m == 2) return y & 3 ? 28 : 29;
		switch (m) {
		case 4: case 6:
		case 9: case 11:
			return 30;
		}
		return 31;
	}
public:
	Date& operater() {
		if (day > getDayofMonth(year, month)) {
			day = 1;
			month++;
		}
		if (month > 12) {
			month = 1;
			year++;
		}
		return *this;
	}
};
int main() {
	GotoXY(0, 5);
	TextColor(0x4e);
	ShowCursor(false);


	Date today(2023, 12, 32);
	today.operater();
	cout << today.Year() << '/' << today.Month() << '/' << today.Day() << " la: " << today.dayToString();
	return 0;
}