/*
Bai7: Cai dat chuong trinh tim so Fibonaci thu n bang de quy co nho
Y tuong: 
F(0) = 0
F(1) = 1
F(n) = F(n-1) + F(n-2)
*/
#include <iostream>
using namespace std;

long F[100];

long Fibonacci(int n) {
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    if (F[n] != -1)
        return F[n];

    F[n] = Fibonacci(n - 1) + Fibonacci(n - 2);

    return F[n];
}

int main() {
    int n;

    cout << "Nhap n: ";
    cin >> n;

    for (int i = 0; i <= n; i++) {
        F[i] = -1;
    }

    cout << "Fibonacci thu " << n << " = "
         << Fibonacci(n);

    return 0;
}
