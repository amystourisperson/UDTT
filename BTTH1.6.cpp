/*
Bai6: Cai dat chuong trinh liet ke tat ca cac cach sx 6 sinh vien gom:
Trang, Cong, Trung, Binh, Hoan, Mai vao 6 chiec ghe duoc danh so tt 1,2,..,6
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

void show(int *x, int n) {
    for (int i = 1; i <= n; i++) {
        cout << "Ghe " << i << ": " << sv[x[i]] << "    ";
    }
    cout << endl;
}

void Try(int k, int *x, int n, bool *dd) {
    for (int i = 1; i <= n; i++) {
        if (dd[i] == false) {
            x[k] = i;

            if (k == n) {
                show(x, n);
            }
            else {
                dd[i] = true;
                Try(k + 1, x, n, dd);
                dd[i] = false;
            }
        }
    }
}

int main() {
    int n = 6;

    int *x = new int[n + 1];
    bool *dd = new bool[n + 1];

    for (int i = 1; i <= n; i++) {
        dd[i] = false;
    }

    Try(1, x, n, dd);

    delete[] x;
    delete[] dd;

    return 0;
}
