/*
Bai9: Cai dat chuong trinh tinh tong cac chu so cua mot so 
nguyen duong n bang de quy
*/
#include <iostream>
using namespace std;

int TongChuSo(int n) {
    if (n < 10) {
        return n;
    }

    return n % 10 + TongChuSo(n / 10);
}

int main() {
    int n;

    cout << "Nhap n: ";
    cin >> n;

    cout << "Tong cac chu so cua n = "
         << TongChuSo(n);

    return 0;
}

