
#include<iostream>
using namespace std;
int main() {
    /******************************************  BAI_1 ***************************************************/
    /*
    int n;
    cout << "Nhap n: ";
    cin >> n;
    int giai_thua = 1;
    int i = 1;
    while (i <= n) {
        giai_thua *= i;
        i++;
    }
    cout << "Gia tri n!= " << giai_thua << endl;
    */
    /*******************************************  BAI_2 ****************************************************/
    /*
    int n, x;
    cout << "nhap vao x: ";
    cin >> x;
    cout << "nhap vao n: ";
    cin >> n;
    if (x == 0 && n == 0) {
        cout << "khong tinh duoc";
        return 0;
    }
    double luy_thua = 1;
    if (n > 0) {
        for (int i = 1; i <= n; i++) {
            luy_thua *= x;
        }
    }
    if (n < 0) {
        for (int i = 1; i <= -n; i++) {
            luy_thua *= x;
        }
        luy_thua = 1.0 / luy_thua;
    }
    cout << "gia tri x^n: " << luy_thua;
    */
    /***********************************************BAI_3***************************************************/
    /*
    double n;
    double s = 1;
    cout << "nhap vao n: ";
    cin >> n;
    // Kiểm tra n có phải là số nguyên dương và không có phần thập phân
    if (n > 0 && n == (int)n) {
        for (double i = 1.0; i <= n; i++) {
            s += 1.0 / (2 * i);
        }
        cout << "gia tri cua s: " << s << endl;
    }
    else {
        cout << "n khong hop le!" << endl;
    }
    */
    /************************************************BAI_4*******************************************************/
    /*
    int x;
    cout << "Nhap x: ";
    cin >> x;
    int count = true;  // Ban đầu giả định x là số nguyên tố
    if (x <= 1) {
        count = false;  // Nếu x <= 1, thì không phải số nguyên tố
    }
    else {
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                count = false;  // Nếu x chia hết cho một số khác 1 và chính nó, thì không phải số nguyên tố
                break;
            }
        }
    }
    cout << x;
    if (count == false) {
        cout << " khong";
    }
    cout << " la so nguyen to";
    */
    /***************************************************BAI_5******************************************************/
    /*
    int n, k;
    int gt_n = 1;
    int gt_k = 1;
    int gt_n_k = 1;
    while (true) {
        cout << "nhap vao n: ";
        cin >> n;
        cout << "nhap vao k: ";
        cin >> k;
        if (k <= n) {
            break;
        }
        cout << "du lieu dau vao khong hop le, vui long nhap lai!" << endl;
    }
    //lấy các giá trị cần tính 
    for (int i = 1; i <= n; i++) {
        gt_n *= i;
        if (i == k) {
            gt_k = gt_n;
        }
        if (i == n - k) {
            gt_n_k = gt_n;
        }
    }
    // Tính C(n, k) = n! / (k! * (n - k)!)
    int c_n_k = gt_n / (gt_k * gt_n_k);
    cout << k << "C" << n << " = " << c_n_k << endl;
    */
    
    /*****************************************************BAI_6****************************************************/
    /*
    int x;
    cout << "nhap vao x: ";
    cin >> x;
    cout << x << "(10)=";
    //dùng vòng lặp để hiển thị từ trái qua phải
    for (int a = 0x80; a > 0; a >>= 1) {
        cout << (a & x ? '1' : '0');
    }
    cout << "(2)\n";
    */
    /****************************************************BAI_7****************************************************/
    /*
    int max = 0x80000000; // Khởi tạo giá trị max là giá trị nhỏ nhất của kiểu int 
    int min = 0x7FFFFFFF; // Khởi tạo giá trị min là giá trị lớn nhất của kiểu int
    int a;
    cout << "Nhap day so (nhap 0 de ket thuc): ";
    while (true) {
        cin >> a;
        if (a == 0) {
            break;
        }
        if (a > max) {
            max = a;
        }
        if (a < min) {
            min = a;
        }
    }
    cout << "So nho nhat trong day la: " << min << endl;
    cout << "So lon nhat trong day la: " << max << endl;
    */
    /****************************************************BAI_8*************************************************/
    /*
    int count = 0;
    int dem2 = 0; // Số lượng số chẵn
    int dem3 = 0; // Số lượng số chia hết cho 8
    int a;
    cout << "Nhap day so (nhap 0 de ket thuc): ";
    while (true) {
        cin >> a;
        if (a == 0) {
            break;
        }
        if (a % 2 == 0) {
            dem2++;
            if (a % 8 == 0) dem3++;
        }
        count++;
    }
    cout << "So so le: " << count - dem2 << endl;
    cout << "So so chan: " << dem2 << endl;
    cout << "So so chia het cho 8: " << dem3 << endl;
    */
    /***********************************************BAI_9**********************************************************/
    /*
    int a = 1; // Số Fibonacci hiện tại
    int b = 0; // Số Fibonacci trước đó
    int c = 0; // Biến trung gian
    int n;
    cout << "Nhap vao n: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << b << "; "; // In số Fibonacci trước đó
        // Tính số Fibonacci tiếp theo và cập nhật các biến
        c = a;
        a = b + a;
        b = c;
    }
    */
    /******************************************BAI_10***********************************************************/
    /*
    int n;
    int a = 1;
    int b = 0;
    int c = 0;
    int kt = 0; // Biến kiểm tra
    cout << "Nhap vao n: ";
    cin >> n;
    // Sử dụng vòng lặp để kiểm tra xem n có phải là số Fibonacci hay không
    while (b <= n) {
        if (n == b) {
            kt = 1; // Đánh dấu n là số Fibonacci
        }
        c = a;
        a = b + a;
        b = c;
    }
    cout << n;
    if (kt == 0) {
        cout << " khong";
    }
    cout << " la so Fibonacci";
    */
    /***************************************************BAI_12*****************************************************/
    /*
    const int n = 4;
    int x = 0;
    for (int i = 0; i < n; i++) {
        int y;
        cin >> y;
        x = x * 10 + y;
    }
    /*******************************************BAI_11*********************************************************/
    /*
    double sai_so = 1E-8;
    double a = x / 2.0; // Khởi tạo một ước đoán ban đầu
    while ((a * a - x) > sai_so || (a * a - x) < -sai_so) { // Kiểm tra điều kiện dừng
        a = 0.5 * (a + x / a); // Cập nhật ước đoán
    }
    cout << a;
    */
    /***************************************************BAI_13*****************************************************/
    /*
    int M, N;
    int value = 1; // Giá trị khởi đầu từ 1
    cout << "Nhap so M (so hang): ";
    cin >> M;
    cout << "Nhap so N (so cot): ";
    cin >> N;
    cout << "MA TRAN " << M << "x" << N << " :" << endl;
    for (int i = 0, k = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << ++k << '\t';
        }
        cout << endl;
    }
    */
    /************************************************BAI_14******************************************************/
    /*
    int a, b, c;
    int x, y, z;
    cout << "nhap vao binh phuong 3 canh AB,AC,BC: ";
    cin >> a >> b >> c;
    cout << "tam giac ";
    if (a == b && b == c) {
        cout << " deu!";
    }
    else {
        int vuong = (a + b == c) + (a + c == b) * 2 + (b + c == a) * 4;
        int can = (a == b) + (a == c) * 2 + (b == c) * 4;
        int k = vuong | can;
        if (k == 0) {
            cout << "thuong!";
            return 0;
        }
        if (vuong != 0) {
            cout << "vuong ";
        }
        if (can != 0) {
            cout << "can ";
        }
        cout << "tai ";
        switch (k) {
        case 1:
            cout << "A";
            break;
        case 2:
            cout << "B";
            break;
        case 4:
            cout << "C";
            break;
        }
    }
    */
/**************************************************************BAI_15******************************************/
    /*
    for (char i = 'a', j = '0'; i <= 'z'; i++) {
        if (j <= '9') {
            cout << j << ": " << (int)j;
            j++;
        }
        cout << '\t' << (char)(i - ' ') << ": " << (int)(i - ' ') << '\t' << i << ": " << (int)i << endl;
    }
    */
    return 0;
}