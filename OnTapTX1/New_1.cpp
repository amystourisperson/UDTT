//De7 
#include <bits/stdc++.h>
using namespace std;

struct TaiSan {
    string ten;
    string tinhTrang;
    long long giaTri;
};

int x[25];      
bool dd[25];    
int soPhuongAn = 0; 

void HienThiTaiSan(TaiSan ts) {
    cout << "Ten: " << ts.ten 
         << " | Tinh trang: " << ts.tinhTrang 
         << " | Gia tri: " << ts.giaTri << " VND" << endl;
}

TaiSan TimMax(TaiSan d[], int l, int r) {
    if (l == r) {
        return d[l];
    }
    
    int m = (l + r) / 2;
    
    TaiSan maxTrai = TimMax(d, l, m);
    TaiSan maxPhai = TimMax(d, m + 1, r);
    
    if (maxTrai.giaTri > maxPhai.giaTri) {
        return maxTrai;
    } else {
        return maxPhai;
    }
}

void InPhuongAn(TaiSan d[], int n) {
    cout << "Cach " << soPhuongAn << ": ";
    for (int i = 1; i <= n; i++) {
        cout << "[Phong " << i << ": " << d[x[i]].ten << "]   ";
    }
    cout << endl;
}

void Try(int k, TaiSan d[], int n) {
    for (int j = 1; j <= n; j++) {
        if (dd[j] == false) { 
            x[k] = j;         
            
            if (k == n) {     
                soPhuongAn++;
                InPhuongAn(d, n);
            } else {
                dd[j] = true;      
                Try(k + 1, d, n);  
                dd[j] = false;     
            }
        }
    }
}

int main() {
    int n = 6;
    
    TaiSan d[25] = {
        {"", "", 0},
        {"May chieu", "Moi", 15000000},
        {"Ban ghe", "Cu", 2500000},
        {"Dieu hoa", "Moi", 12000000},
        {"May tinh", "Cu", 8000000},
        {"Tivi", "Hong", 0},
        {"Loa am thanh", "Moi", 20000000}
    };

    cout << "========== DANH SACH TAI SAN ==========" << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << ". ";
        HienThiTaiSan(d[i]);
    }

    cout << "\n========== TAI SAN CO GIA TRI LON NHAT ==========" << endl;
    TaiSan tsMax = TimMax(d, 1, n);
    HienThiTaiSan(tsMax);

    cout << "\n========== DANH SACH CAC PHUONG AN XEP PHONG ==========" << endl;
    for (int i = 1; i <= n; i++) {
        dd[i] = false;
    }
    
    Try(1, d, n);
    
    cout << "\n=> TONG SO PHUONG AN XEP: " << soPhuongAn << " (phuong an)" << endl;

    return 0;
}
