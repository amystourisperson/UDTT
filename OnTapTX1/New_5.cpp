#include <iostream>
#include <string>
using namespace std;

struct HocSinh {
    string maHS;
    string ten;
    int namSinh;
};

int x[10];

void HienThiHocSinh(HocSinh hs) {
    cout << "Ma HS: " << hs.maHS 
         << " | Ten: " << hs.ten 
         << " | Nam sinh: " << hs.namSinh << endl;
}

void HienThiToHop(HocSinh d[], int k) {
    cout << "Cach chon: [ ";
    for (int i = 1; i <= k; i++) {
        cout << d[x[i]].maHS << " "; 
    }
    cout << "]" << endl;
}


void Try(int i, int k, int n, HocSinh d[]) {
    for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
        x[i] = j;
        
        if (i == k) {
            HienThiToHop(d, k);
        } else {
            Try(i + 1, k, n, d);
        }
    }
}


int TimKiem(HocSinh d[], int l, int r, string tenCanTim) {
    if (l > r) {
        return -1; 
    }
    
    int m = (l + r) / 2;

    if (d[m].ten == tenCanTim) {
        int vt = TimKiem(d, l, m - 1, tenCanTim);
        if (vt != -1) {
            return vt;
        }
        return m; 
    }

    if (d[m].ten > tenCanTim) {
        return TimKiem(d, l, m - 1, tenCanTim);
    }
    
    return TimKiem(d, m + 1, r, tenCanTim);
}


int main() {
    int n = 6; 
    int k = 4; 

    HocSinh d[20] = {
        {"", "", 0}, 
        {"HS01", "An", 2005},
        {"HS02", "Binh", 2006},
        {"HS03", "Cuong", 2005},
        {"HS04", "Dung", 2006},
        {"HS05", "Hoa", 2005},
        {"HS06", "Hoa", 2006} 
    };

    cout << "============= DANH SACH HOC SINH GOC =============" << endl;
    for(int i = 1; i <= n; i++) {
        HienThiHocSinh(d[i]);
    }

    x[0] = 0;
    
    cout << "\n============= TAT CA CAC PHUONG AN CHON 4 HOC SINH (QUAY LUI) =============" << endl;
    Try(1, k, n, d);

    cout << "\n============= TIM KIEM HOC SINH (CHIA DE TRI) =============" << endl;
    string tenTimKiem;
    cout << "Nhap ten hoc sinh can tim: ";
    cin >> tenTimKiem;

    int viTri = TimKiem(d, 1, n, tenTimKiem);

    if (viTri != -1) {
        cout << "\n=> Tim thay hoc sinh '" << tenTimKiem << "' xuat hien dau tien tai vi tri thu " << viTri << ":" << endl;
        HienThiHocSinh(d[viTri]); 
    } else {
        cout << "\n=> Khong tim thay hoc sinh nao co ten '" << tenTimKiem << "' trong danh sach." << endl;
    }

    return 0;
}
