/*
Bai10: Cai dat chuong trinh tinh tong cac so le trong mot day 
n so nguyen bang de quy
*/
#include <iostream>
using namespace std;

int TongLe(int *a, int n) {
    if (n == 0) {
        return 0;
    }

    if (a[n - 1] % 2 != 0) {
        return a[n - 1] + TongLe(a, n - 1);
    }

    return TongLe(a, n - 1);
}

int main() {
    int n;

    cout << "Nhap n: ";
    cin >> n;

    int *a = new int[n];

    cout << "Nhap day so:" << endl;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Tong cac so le = "
         << TongLe(a, n);

    delete[] a;

    return 0;
}

