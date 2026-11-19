#include <iostream>
#include <string>
using namespace std;

// 1. Khai bao cau truc du lieu QuatBan
struct QuatBan {
    string tenHang; // Ten hang san xuat
    string mauSac;  // Mau sac
    int gia;        // Gia ban
};

// Ham sap xep danh sach quat giam dan theo gia ban
// Chien luoc tham lam: Uu tien ban nhung chiec quat co gia cao nhat truoc de can it quat nhat
void sortGiamDanTheoGia(QuatBan d[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (d[j].gia > d[j - 1].gia) {
                QuatBan tmp = d[j];
                d[j] = d[j - 1];
                d[j - 1] = tmp;
            }
        }
    }
}

// 2. Thuat toan tham lam chon it quat nhat de thu duoc dung so tien p
int greedyBanQuat(QuatBan d[], int n, int p, QuatBan res[]) {
    // Buoc 1: Sap xep quat giam dan theo gia
    sortGiamDanTheoGia(d, n);

    int dem = 0;   // So luong quat duoc chon vao ket qua
    int i = 0;     // Chi so duyet qua danh sach quat

    // Buoc 2: Duyet lan luot tung chiec quat tu gia cao xuong thap
    while (i < n && p > 0) {
        // Neu gia chiec quat nay nho hon hoac bang so tien con thieu
        if (d[i].gia <= p) {
            res[dem++] = d[i]; // Chon chiec quat nay
            p -= d[i].gia;     // Giam so tien con thieu
        }
        i++; // Xet tiep chiec quat tiep theo (moi chiec chi ban 1 lan)
    }

    // Neu sau khi duyet ma p van chua ve 0 thi khong the ban dung bang p
    if (p == 0) {
        return dem; // Tra ve so quat it nhat
    }

    return -1; // Khong tim duoc phuong an co tong dung bang p
}

int main() {
    // Khoi tao so luong quat n thoa man 5 < n < 12 (o day chon n = 8)
    int n = 8;

    // Khoi tao danh sach d gom n chiec quat ban khac nhau ve gia
    QuatBan d[8] = {
        {"Senko", "Xanh duong", 220000},
        {"Panasonic", "Xam", 550000},
        {"Asia", "Trang", 350000},
        {"Mitsubishi", "Den", 450000},
        {"Vinawind", "Xanh la", 180000},
        {"Toshiba", "Trang sua", 400000},
        {"Kangaroo", "Do", 280000},
        {"Midea", "Den nham", 150000}
    };

    // Khoi tao so tien p thoa man 0 < p < 1200000
    int p = 1000000;

    cout << "--- DANH SACH QUAT HIEN CO ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". Hang: " << d[i].tenHang 
             << " | Mau: " << d[i].mauSac 
             << " | Gia: " << d[i].gia << " VND" << endl;
    }
    cout << "\nSo tien can thu ve: " << p << " VND" << endl;

    // Mang chua ket qua cac quat duoc chon
    QuatBan res[12];
    int soLuong = greedyBanQuat(d, n, p, res);

    // 3. Hien thi ket qua
    cout << "\n--- KET QUA ---" << endl;
    if (soLuong != -1) {
        cout << "Can ban IT NHAT: " << soLuong << " chiec quat." << endl;
        cout << "Danh sach quat duoc chon:" << endl;
        int tongTien = 0;
        for (int i = 0; i < soLuong; i++) {
            cout << "- Hang san xuat: " << res[i].tenHang 
                 << " | Gia ban: " << res[i].gia << " VND" << endl;
            tongTien += res[i].gia;
        }
        cout << "Tong so tien thu ve: " << tongTien << " VND (Dung bang p)" << endl;
    } else {
        cout << "Khong co phuong an ban quat de thu duoc so tien dung bang " << p << " VND." << endl;
    }

    return 0;
}
