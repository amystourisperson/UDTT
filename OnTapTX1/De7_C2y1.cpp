#include <iostream>
using namespace std;

// Tinh tong cac so le bang de quy
double DQ(double A[], int n, int i){
    // Dieu kien dung
    if(i>=n || i<0){
        return 0;
    }

    // Neu A[i] la so nguyen le
    if((int)A[i] % 2 != 0){
        return A[i] + DQ(A, n, i + 1);
    }

    // Neu khong phai so nguyen le
    return DQ(A, n, i + 1);
}

int main(){
    int n;
    double A[100];

    cout << "Nhap n: ";
    cin >> n;

    cout << "Nhap mang A:\n";
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    cout << "Tong cac so le: " << DQ(A, n, 0);

    return 0;
}
