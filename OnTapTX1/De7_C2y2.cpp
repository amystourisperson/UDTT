#include <iostream>
using namespace std;

// Dem so phan tu khong lon hon k bang chia de tri
int Dem(double A[], int l, int r, double k){
    // Dieu kien dung
    if(l > r){
        return 0;
    }

    // Neu chi con mot phan tu
    if(l == r){
        if(A[l] <= k){
            return 1;
        }
        return 0;
    }

    // Chia mang thanh hai nua
    int m = (l + r) / 2;

    // Dem ben trai
    int trai = Dem(A, l, m, k);

    // Dem ben phai
    int phai = Dem(A, m + 1, r, k);

    // Cong ket qua hai nua
    return trai + phai;
}

int main(){
    int n;
    double A[100];
    double k;

    cout << "Nhap n: ";
    cin >> n;

    cout << "Nhap mang A:\n";
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    cout << "Nhap k: ";
    cin >> k;

    cout << "So phan tu khong lon hon k: "
         << Dem(A, 0, n - 1, k);

    return 0;
}
