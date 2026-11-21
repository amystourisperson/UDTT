/*
Bai2: Cai dat chuong trinh sinh cac chuoi ky tu do dai chi chua 2 ky tu
'a' va 'b'
*/
#include <iostream>
using namespace std;

void show(char *x, int n) {
    for (int i = 1; i <= n; i++) {
        cout << x[i];
    }
    cout << endl;
}

void Try(int k, char *x, int n) {
    for(int i = 0; i <= 1; i++) {

        if (i == 0)
            x[k] = 'a';
        else
            x[k] = 'b';

        if (k == n) {
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

    char *x = new char[n + 1];

    Try(1, x, n);

    delete[] x;

    return 0;
}

/*
Cach 2:
#include <iostream>
using namespace std;

char C[2] = {'a', 'b'};

void show(char *x, int n) {
    for (int i = 1; i <= n; i++) {
        cout << x[i];
    }
    cout << endl;
}

void Try(int k, char *x, int n) {
    for (int i = 0; i < 2; i++) {
        x[k] = C[i];

        if (k == n) {
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

    char *x = new char[n + 1];

    Try(1, x, n);

    delete[] x;

    return 0;
}
*/
