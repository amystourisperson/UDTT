/*
Bai 1: Cai dat chuong trinh sinh cac chuoi nhi phan do dai n
*/
#include <iostream>
using namespace std;

void show(int *x, int n) {
    for (int i = 1; i <= n; i++) {
        cout << x[i];
    }
    cout << endl;
}

//k: vi tri dang can dien
//x: mang luu chuoi
//n: do dai chuoi

void Try(int k, int *x, int n) {  
    for (int i = 0; i <= 1; i++) {  
        x[k] = i;  //gan gia tri vua chon vao vi tri k

        if (k == n) {   //kiem tra chuoi da du n ptu chua
            show(x, n);
        }
        else {
            Try(k + 1, x, n);
        }
    }
}

int main() {
    int n;

    cout << "Nhap n: ";
    cin >> n;

    int *x = new int[n + 1];

    Try(1, x, n);  //Chay tu 1 cho no du n phan tu 

    delete[] x;

    return 0;
}
