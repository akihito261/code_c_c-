#include <iostream>
using namespace std;

class Coord {
public:
	int x;  // hoành độ
	int y;  // tung độ

public:
	Coord() { 
		x = y = 0;
		cout << "Default constructor: " << *this << endl;
	}
	Coord(int x, int y) {
		this->x = x;
		this->y = y;
		cout << "Initial constructor: " << *this << endl;
	}
	Coord(const Coord& coord)
		: x(coord.x)
		, y(coord.y) {
		
		cout << "Copy constructor: " << *this << endl;
	
	}
	~Coord() {
		cout << "Destructor constructor: " << *this << endl;
	}

public:
	void Offset(int d) { this->Offset(d, d); }
	void Offset(int x, int y);
	int Distance2() const { return x * x + y * y; }
		
public:
	friend ostream& operator<<(ostream& out, const Coord& coord) {
		return out << "x = " << coord.x << ", y = " << coord.y;
	}
};

void Coord::Offset(int x, int y) {
	this->x += x;
	this->y += y;
}

int main() {
	Coord p = new Coord();
	Coord p1(10, 10);
	Coord p2 = p1;

	p2.Offset(40);

	delete p;
}