#include <bits/stdc++.h>
using namespace std;

//Cau 1.1 
// Ham tinh tong mang so thuc theo chien luoc chia de tri
float tong_CDT(float a[], int l, int r) {
    // Truong hop co so: mang chi con 1 phan tu
    if (l == r) {
        return a[l];
    }
    
    // Chia mang lam 2 nua
    int mid = (l + r) / 2;
    
    // De quy tinh tong nua trai va nua phai
    float tongTrai = tong_CDT(a, l, mid);
    float tongPhai = tong_CDT(a, mid + 1, r);
    
    // Tong hop ket qua
    return tongTrai + tongPhai;
}

int main() {
    // Khoi tao n >= 10 va mang a gom n so thuc
    int n = 10;
    float a[10] = {1.5, 2.3, 4.0, 5.2, 3.1, 6.4, 2.8, 7.5, 1.2, 8.0};
    
    cout << "Mang a gom " << n << " so thuc: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << "  ";
    }
    cout << endl;
    
    // Ung dung thuat toan chia de tri
    float tong = tong_CDT(a, 0, n - 1);
    
    cout << "\nTong tat ca cac so trong mang a la: " << tong << endl;
    
    return 0;
}
