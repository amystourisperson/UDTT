#include <bits/stdc++.h>
using namespace std;

//Cau 1.2
// Ham de quy tinh tong tat ca cac so le trong mang a
// Tham so: mang a[], so luong phan tu n dang xet
int tongLe_DeQuy(int a[], int n) {
    // 1. Truong hop co so (dieu kien dung):
    // Khi n == 0 nghia la khong con phan tu nao de xet, tra ve tong bang 0
    if (n == 0) {
        return 0;
    }
    
    // 2. Buoc de quy: xet phan tu cuoi cung cua doan dang xet la a[n - 1]
    // Kiem tra xem a[n - 1] co phai la so le hay khong (chia 2 du khac 0)
    if (a[n - 1] % 2 != 0) {
        // Neu la so le: cong a[n - 1] vao ket qua va goi de quy cho n - 1 phan tu con lai
        return a[n - 1] + tongLe_DeQuy(a, n - 1);
    } else {
        // Neu la so chan: bo qua a[n - 1] va goi de quy cho n - 1 phan tu con lai
        return tongLe_DeQuy(a, n - 1);
    }
}

int main() {
    // Khoi tao so nguyen duong n >= 10 va mang a gom n so nguyen
    int n = 10;
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11};
    
    // Hien thi mang ban dau ra man hinh
    cout << "Mang a gom " << n << " so nguyen: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << "  ";
    }
    cout << endl;
    
    // Goi ham de quy de tinh tong cac so le
    int kq = tongLe_DeQuy(a, n);
    
    // Hien thi ket qua
    cout << "\nTong tat ca cac so le trong mang a la: " << kq << endl;
    
    return 0;
}
