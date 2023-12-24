#include<iostream>
using namespace std;
template<class T>
class Array {
	T* data;
	int length;
	void delete_data(){ if (data) delete[]data; }
public:
	Array() : length(0), data(0) { cout << "ham tao mac dinh \n"; }
	Array(int size) : length(size) {
		data = new T[size];
		cout << "ham tao " << data << endl;
	}
	Array(const Array& s) :data(0) {
		*this = s;
	}
	~Array() {
		cout << "ham huy " << data << endl; delete_data();
	}
public:
	int Length() const { return length; }
	T& ElementAt(int index)
	{
		return data[index];
	}
public:
	T& operator[](int index) {
		return data[index];
	}
	Array& operator=(const Array& s) {
		delete_data();
		data = new T[length = s.length];
		for (int i = 0; i < length; i++)
			data[i] = s.data[i];
		return *this;
	 }
public:
	 class Interator {
		T* pointer;
	public:
		Interator(T*p):pointer(p){}
		Interator& operator++() {
			++pointer;
			return *this;
		}
		T* operator*() { return *pointer; }
		friend bool operator != (const Interator& other,const Interator& b) {
			return pointer != other.pointer;

		}
		friend Interator begin(const Array& s) {
			return Iterator(s.data);
		}
		friend Interator end(const Array& s) {
			return Interator(s.data + s.length);
		}
		
	};
	
};
int main() {
	Array<int> A(10),B(A);
	//B = A; //loi 1 vung nho bi xoa 2 lan
	for (int i = 0; i < A.Length(); i++) {
		A[i] = i;
	}
	for (int i = 0; i < A.Length(); i++) {
		cout << A[i];
	}
	cout << endl;
}