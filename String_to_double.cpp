

#include <iostream>
using namespace std;
double Parse_double(char* s) {
    char* p = s;
    long long a = 0, b = 0;
    bool neg = (*p == '-');
    if (neg) ++p;
    while (char c = *p++) {
        if (c == '.') {
            b = 1;
            continue;
        }
        if (c < '0' || c>'9') break;
        a = (a << 1) + (a << 3) + (c & 0x0F);
        if (b) b = (b << 1) + (b << 3);
    }
    if (neg) a = -a;
    return b > 1 ? double(a) / b : a;
}
int main() {
    char a[] = {'-', '1', '2', '.', '3', '\0' }; 
    cout << Parse_double(a);
    return 0; 
}

