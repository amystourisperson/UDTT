#include <bits/stdc++.h>
using namespace std;

//Cau 1.3
// Ham tinh tong tat ca cac so duong trong mang a theo chien luoc chia de tri
// Tham so: mang a[], chi so ben trai l, chi so ben phai r
float tongDuong_CDT(float a[], int l, int r) {
    // 1. Truong hop co so: doan dang xet chi con dung 1 phan tu
    if (l == r) {
        // Neu phan tu do la so duong (> 0) thi tra ve chinh no
        if (a[l] > 0) {
            return a[l];
        } else {
            // Neu la so am hoac bang 0 thi khong cong (tra ve 0)
            return 0;
        }
    }
    
    // 2. Buoc chia: chia doan [l, r] thanh 2 nua bang nhau tai vi tri mid
    int mid = (l + r) / 2;
    
    // 3. Buoc tri: goi de quy tinh tong so duong cua nua trai va nua phai
    float tongTrai = tongDuong_CDT(a, l, mid);
    float tongPhai = tongDuong_CDT(a, mid + 1, r);
    
    // 4. Buoc tong hop: cong ket qua cua 2 nua lai
    return tongTrai + tongPhai;
}

int main() {
    // Khoi tao so nguyen duong n >= 10 va mang a gom n so thuc (co ca so am va so duong)
    int n = 10;
    float a[10] = {1.5, -2.0, 3.5, 0.0, -4.2, 6.0, 2.5, -1.8, 4.0, -5.5};
    
    // Hien thi mang ban dau ra man hinh
    cout << "Mang a gom " << n << " so thuc: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << "  ";
    }
    cout << endl;
    
    // Ung dung thuat toan chia de tri tren toan bo mang (tu chi so 0 den n - 1)
    float kq = tongDuong_CDT(a, 0, n - 1);
    
    // Hien thi ket qua
    cout << "\nTong tat ca cac so duong trong mang a la: " << kq << endl;
    
    return 0;
}
