#include <iostream>
#include <cmath>
const int MAX = 100;
using namespace std;

int menu() {
	cout << "\n----------------bai tap 13.2-------------------" << endl
		<< "b1. Ham mu " << endl
		<< "b2. Ham giai thua " << endl
		<< "b3. Ham fibo " << endl
		<< "b4. Ham giai phuong trinh bac 2 " << endl
		<< "b5. Ham chuyen doi nhiet do " << endl
		<< "b6. Ham in mang so nguyen " << endl
		<< "b7. Ham tinh tong cua mang " << endl
		<< "b8. Ham tinh trung binh cong cua mang " << endl
		<< "b9. Ham tim gia tri da thuc n tai x" << endl
		<< "b10. Ham doi xau ki tu sang dang so " << endl
		<< "b11. Ham chuan hoa ho ten " << endl
		<< "b12. Thuc hien cac bai 6-11 bang phuong phap duyet con tro" << endl
		<< "b13.  Ham cho day n so fibonaci dau tien" << endl
		<< "b14. Ham tao mang n phan tu tu mang so nguyen" << endl
		<< "b15. Ham tao xau moi chuyen cac chu cai thuong thanh chu cai viet hoa tu xau dau vao" << endl
		<< "b16. ham chuyen doi so nguyen thanh xau ki tu nhi phan" << endl
		<< "b17. Ham tim tan suat của cac ki tu trong xau" << endl
		<< "18. Exit" << endl
		<< "<<";


	int a;
	cin >> a;
	return a;

}
double Pow(double x, int n) {
	if (n == 0) {
		return 1;
	}
	if (n < 0) return 1 / Pow(x, -n);
	return x * Pow(x, n - 1);
}
int giai_thua(int x) {
	if (x == 0) {
		return 1;
	}
	if (x < 0) return 0;
	return x * giai_thua(x - 1);
}
int fibo(int t) {
	if (t == 0) {
		return 0;
	}
	else if (t == 1) {
		return 1;
	}
	else {
		return fibo(t - 1) + fibo(t - 2);
	}
}

int find_root(double a, double b, double c, double* x1, double* x2) {
	double d = b * b - 4 * a * c;
	if (d < 0) return 0;
	if (d == 0) {
		*x1 = *x2 = -b / a;
		return 1;
	}
	d = sqrt(d);
	*x1 = (-b - d) / a;
	*x2 = (-b + d) / a;
	return 2;
}
void c_k_f(double c, double* k, double* f) {
	*f = 9.0 / 5.0 * c + 32;
	*k = c + 273;
}
// void hien_thi(int A[], int n) {
// 	cout << "A = {";
// 	for (int i = 0; i < n; i++) { // Duyệt từ 0 đến n-1
// 		cout << A[i]; // Hiển thị phần tử mảng
// 		if (i < n - 1) {
// 			cout << ';'; // Hiển thị dấu ';' nếu không phải phần tử cuối cùng
// 		}
// 	}
// 	cout << '}';
// }
void hien_thi(int A[], int n) {
	cout << "A = {";
	for (int i = 0; i < n; i++) { // Duyệt từ 0 đến n-1
		cout << A[i]; // Hiển thị phần tử mảng
		if (i < n - 1) {
			cout << ';'; // Hiển thị dấu ';' nếu không phải phần tử cuối cùng
		}
	}
	cout << '}';
}

// int Sum(int A[], int n) {
// 	int sum = 0;
// 	for (int i = 0; i < n; i++) {
// 		sum += A[i];
// 	}
// 	return sum;
// }
int Sum_array(int* A, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += A[i];
	}
	return sum;
}
// double calculate_Average(int A[], int n) {
// 	double x = Sum(A, n);
// 	return x / n;
// }
double calculate_Average(int* A, int n) {
	double x = Sum_array(A, n);
	return x / n;
}
// double evaluate_Polynomial(int A[], int  n, double x) {
// 	double f = 0;
// 	for (int i = 0; i < n; i++) {
// 		f += A[i] * Pow(x, n - i - 1);
// 	}
// 	return f;
// }
double evaluate_Polynomial(int* A, int  n, double x) {
	double f = 0;
	for (int i = 0; i < n; i++) {
		f += A[i] * Pow(x, n - i - 1);
	}
	return f;
}
int* convert_string_tolnt(char* str) {
	int* y;
	int x;
	y = &x;
	for (int i = 0; char c = str[i]; i++) {
		x = x << 1 + x << 3 + (c && 15);
	}
	return y;
}
char* correct_full_name(char* S) {
	const char space = 32;
	char last = space;
	int k = 0;
	for (int i = 0; char c = S[i]; i++) {
		if (last == space && c == space) {

			continue;
		}
		if (last == space && c != space) {
			c = toupper(c);

		}
		if (last != space && c != space) {
			c = tolower(c);
		}
		S[k] = c;
		k++;
		last = c;
	}
	S[k] = '\0';
	return S;

}
string chuyen_thuong_hoa(char S[]) {
	char S1[100];
	int k = 0;
	for (int i = 0; char c = S[i]; i++) {
		if (c <= 'z' && c >= 'a') {
			c = c - 'a' + 'A';
		}
		S1[i] = c;
		k++;
	}
	S1[k] = '\0';
	return S1;
}
int* n_fibo(int n) {
	int a = 1;
	int b = 0;
	int c = 0;
	int* A = new int[n];
	for (int i = 0; i < n; i++) {
		A[i] = b;
		c = a;
		a = b + a;
		b = c;
	}
	return A;
}
int main() {
	while (1) {
		int a = menu();
		if (a == 1) {
			int x;
			int n;
			cout << "nhap x: ";
			cin >> x;
			cout << "nhap n: ";
			cin >> n;
			cout << x << "^(" << n << ") = " << pow(x, n) << endl;
			continue;
		}
		if (a == 2) {
			int x;
			cout << "nhap x: ";
			cin >> x;
			cout << x << "! = " << giai_thua(x);
			continue;
		}
		if (a == 3) {
			int n;
			cout << "nhap n: ";
			cin >> n;
			cout << "so fibonaci thu " << n << " la: " << fibo(n) << endl;

		}
		if (a == 4) {
			double x1, x2;
			int a, b, c;
			cout << "nhap a, b, c: ";
			cin >> a >> b >> c;
			if (find_root(a, b, c, &x1, &x2) == 0) {
				cout << "phuong trinh vo nghiem " << endl;
			}
			if (find_root(a, b, c, &x1, &x2) == 1) {
				cout << "phuong trinh co nghiem duy nhat x = " << x1 << endl;
			}
			if (find_root(a, b, c, &x1, &x2) == 2) {
				cout << " phuong trinh co 2 nghiem: " << endl;
				cout << "x1 = " << x1 << endl;
				cout << "x2 = " << x2 << endl;
			}
			continue;
		}
		if (a == 5) {
			double c;
			double k, f;
			cout << "nhap vao do c: ";
			cin >> c;
			c_k_f(c, &k, &f);
			cout << c << "oC = " << k << "oK = " << f << "oF" << endl;
			continue;
		}
		if (a == 6) {
			int n1;
			cout << "nhap so phan tu cua mang: ";
			cin >> n1;
			int* A = new int[n1];
			cout << "nhap mang: ";
			for (int i = 0; i < n1; i++) {
				cin >> A[i];
			}
			hien_thi(A, n1);
			delete[] A;
		}
		if (a == 7) {
			int n1;
			cout << "nhap so phan tu cua mang: ";
			cin >> n1;
			int* A = new int[n1];
			cout << "nhap mang: ";
			for (int i = 0; i < n1; i++) {
				cin >> A[i];
			}
			cout << Sum_array(A, n1);
			delete[] A;
		}
		if (a == 8) {
			int n1;
			cout << "nhap so phan tu cua mang: ";
			cin >> n1;
			int* A = new int[n1];
			cout << "nhap mang: ";
			for (int i = 0; i < n1; i++) {
				cin >> A[i];
			}
			cout << calculate_Average(A, n1);
			delete[] A;
		}
		if (a == 9) {
			int n1;
			double x;
			cout << "nhap bac cua da thuc: ";
			cin >> n1;
			int* A = new int[n1];
			cout << "nhap mang: ";
			for (int i = 0; i <= n1; i++) {
				cin >> A[i];
			}
			cout << "nhap gia tri cua x: ";
			cin >> x;
			cout << evaluate_Polynomial(A, n1, x);
			delete[] A;
		}

		if (a == 10) {

			char* str = new char(MAX);
			cout << "nhap chuoi ki tu: ";
			cin.getline(str, MAX);
			int* x = convert_string_tolnt(str);

			cout << "so chuyen doi tu xau ki tu: " << x;
		}
		if (a == 11) {
			char   S[100] = "  ngUyen     vAn   An";
			char* S1 = correct_full_name(S);
			cout << S1 << endl;
			delete[] S1;
		}
		if (a == 13) {
			int n;
			cout << "nhap vao n: ";
			cin >> n;
			int* A1 = n_fibo(n);
			cout << A1;
			delete[] A1;

		}
		if (a == 14) {

		}
		if (a == 15) {
			char   S[100] = "  ngUyen     vAn   An";
			cout << chuyen_thuong_hoa(S);

		}
		if (a == 18) {
			break;
		}
	}
	return 0;

}
//ctrl k d
//chú ý dấu cách kiểu "x1 = "