#include <iostream>
#include <string>
using namespace std;

// Khai bao cau truc du lieu QuatBan
struct QuatBan {
    string tenHang;
    string mauSac;
    int gia;
};

// Ham sap xep danh sach quat giam dan theo gia ban
void sortGiamDan(QuatBan d[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            // Neu quat dung truoc re hon quat dung sau thi hoan doi
            if (d[j - 1].gia < d[j].gia) {
                QuatBan tmp = d[j - 1];
                d[j - 1] = d[j];
                d[j] = tmp;
            }
        }
    }
}

// Thuat toan tham lam chon it quat nhat de thu duoc so tien lon hon p
int greedyBanQuat(QuatBan d[], int n, int p, QuatBan res[]) {
    // Buoc 1: Sap xep quat giam dan theo gia de uu tien ban quat dat nhat
    sortGiamDan(d, n);

    int dem = 0;       // So luong quat duoc chon
    int tongTien = 0;  // Tong tien thu duoc
    int i = 0;         // Chi so duyet mang

    // Buoc 2: Duyet vong lap den khi tong tien > p hoac het quat
    while (i < n && tongTien <= p) {
        res[dem] = d[i];       // Luu chiec quat vao mang ket qua
        tongTien += d[i].gia;  // Cong don so tien
        dem++;                 // Tang so luong quat da chon
        i++;
    }

    // Buoc 3: Kiem tra xem da dat duoc muc tieu lon hon p chua
    if (tongTien > p) {
        return dem;
    }

    // Tra ve -1 neu ban het quat ma van khong vuot qua duoc p
    return -1;
}

int main() {
    // Khoi tao so luong quat n (5 < n < 12)
    int n = 7;

    // Khoi tao danh sach d gom n chiec quat
    QuatBan d[12] = {
        {"Senko", "Xanh duong", 220000},
        {"Panasonic", "Xam", 550000},
        {"Asia", "Trang", 350000},
        {"Mitsubishi", "Den", 450000},
        {"Vinawind", "Xanh la", 180000},
        {"Toshiba", "Trang sua", 400000},
        {"Kangaroo", "Do", 280000}
    };

    // Khoi tao so tien p (0 < p < 1200000)
    int p = 1000000;

    cout << "--- DANH SACH QUAT BAN DAU ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". Hang: " << d[i].tenHang 
             << " | Mau: " << d[i].mauSac 
             << " | Gia: " << d[i].gia << " VND" << endl;
    }
    cout << "\nMuc tieu thu duoc so tien > " << p << " VND" << endl;

    QuatBan res[12]; // Mang luu ket qua
    int soLuong = greedyBanQuat(d, n, p, res);

    cout << "\n--- KET QUA ---" << endl;
    if (soLuong != -1) {
        cout << "Can ban it nhat " << soLuong << " chiec quat de vuot muc " << p << " VND." << endl;
        cout << "Danh sach cac quat duoc ban:" << endl;
        
        int tongThu = 0;
        for (int i = 0; i < soLuong; i++) {
            // Yeu cau chi hien thi ten hang san xuat va gia ban
            cout << "- Hang san xuat: " << res[i].tenHang 
                 << " | Gia ban: " << res[i].gia << " VND" << endl;
            tongThu += res[i].gia;
        }
        cout << "Tong so tien thuc te thu duoc: " << tongThu << " VND" << endl;
    } else {
        cout << "Tong gia tri tat ca quat hien co khong vuot qua duoc muc tien " << p << " VND." << endl;
    }

    return 0;
}
