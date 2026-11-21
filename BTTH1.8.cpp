/*
Bai8: Cai dat chuong trinh cho bai toan tim mien lien thong
*/
#include <iostream>
using namespace std;

void loang(int **O, bool **flag, int i, int j, int m, int n) {
    flag[i][j] = true;

    // Sang trai
    if (j > 0) {
        if ((O[i][j - 1] == O[i][j]) && (!flag[i][j - 1])) {
            loang(O, flag, i, j - 1, m, n);
        }
    }

    // Len tren
    if (i > 0) {
        if ((O[i - 1][j] == O[i][j]) && (!flag[i - 1][j])) {
            loang(O, flag, i - 1, j, m, n);
        }
    }

    // Sang phai
    if (j < n - 1) {
        if ((O[i][j + 1] == O[i][j]) && (!flag[i][j + 1])) {
            loang(O, flag, i, j + 1, m, n);
        }
    }

    // Xuong duoi
    if (i < m - 1) {
        if ((O[i + 1][j] == O[i][j]) && (!flag[i + 1][j])) {
            loang(O, flag, i + 1, j, m, n);
        }
    }
}

int dem_so_mien_lien_thong(int **O, int m, int n) {

    bool **flag = new bool*[m];

    for (int i = 0; i < m; i++) {
        flag[i] = new bool[n];

        for (int j = 0; j < n; j++) {
            flag[i][j] = false;
        }
    }

    int dem = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if (!flag[i][j]) {
                dem++;

                loang(O, flag, i, j, m, n);
            }
        }
    }

    for (int i = 0; i < m; i++) {
        delete[] flag[i];
    }

    delete[] flag;

    return dem;
}

int main() {
    int m, n;

    cout << "Nhap so hang: ";
    cin >> m;

    cout << "Nhap so cot: ";
    cin >> n;

    int **O = new int*[m];

    for (int i = 0; i < m; i++) {
        O[i] = new int[n];

        for (int j = 0; j < n; j++) {
            cin >> O[i][j];
        }
    }

    cout << "Ma tran:" << endl;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << O[i][j] << " ";
        }
        cout << endl;
    }

    int dem = dem_so_mien_lien_thong(O, m, n);

    cout << "So mien lien thong: " << dem << endl;

    for (int i = 0; i < m; i++) {
        delete[] O[i];
    }

    delete[] O;

    return 0;
}
