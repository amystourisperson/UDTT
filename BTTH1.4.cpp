/*
Bai4: Cai dat chuong trinh liet ke cac cach lay 4 sv tu 6 sv gom:
Cong, Trung, Binh, Hoan, Mai
*/
#include <iostream>
using namespace std;

string sv[7] = {
    "",
    "Trang",
    "Cong",
    "Trung",
    "Binh",
    "Hoan",
    "Mai"
};

void show(int *x, int k) {
    for (int i = 1; i <= k; i++) {
        cout << sv[x[i]] << " ";
    }
    cout << endl;
}

void Try(int k, int *x, int n, int m) {
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
    int n = 6;
    int k = 4;

    int *x = new int[k + 1];

    x[0] = 0;

    Try(1, x, n, k);

    delete[] x;

    return 0;
}
