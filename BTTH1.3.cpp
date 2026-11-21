/*
Bai3: Cai dat chuong trinh sinh cac tap con k phan tu cua tap S={1,2,..,n}
*/
#include <iostream>
using namespace std;

void show(int *x, int k) {
    for (int i = 1; i <= k; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}

/*
k: vi tri hien tai can chon
n: tap S
m: so phan tu can lay
x: luu tap con
*/
void Try(int k, int *x, int n, int m) {
	//Viec bat dau tu x[k-1]+1 dam bao x[1] <x[2]<..<x[k]
    for (int i = x[k - 1] + 1; i <= n - m + k; i++) {
        x[k] = i;

        if (k == m) {
            show(x, m);
        }
        else {
            Try(k + 1, x, n, m);
        }
    }
}

int main() {
    int n, k;

    cout << "Nhap n: ";
    cin >> n;

    cout << "Nhap k: ";
    cin >> k;

    int *x = new int[k + 1];

    x[0] = 0;  

    Try(1, x, n, k);

    delete[] x;

    return 0;
} 
