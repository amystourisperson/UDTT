/*
Cai dat chuong trinh sinh cac hoan vi cua tap S={1,2,...,n}
123 -> 321
Ta su dung:
x[k]: phan tu thu k trong hoan vi
dd[i]: danh dau so i da duoc sdung hay chua
*/
#include <iostream>
using namespace std;

void show(int *x, int n) {
    for (int i = 1; i <= n; i++) {
        cout << x[i] << " ";
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
                dd[i] = true;  //Danh dau
                Try(k + 1, x, n, dd); //Dequy
                dd[i] = false; //Quay lui -> De kiem tra so i chua duoc su dung, tranh lap so trong mot hoan vi.
            }
        }
    }
}

int main() {
    int n;

    cout << "Nhap n: ";
    cin >> n;

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

