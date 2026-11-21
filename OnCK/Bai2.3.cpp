#include <bits/stdc++.h>
using namespace std;

//Cau 2.3
// Dinh nghia cau truc GoiHang
struct GoiHang {
    int stt; // So thu tu goc cua goi hang (tu 1 den n)
    int m;   // Khoi luong goi hang (so nguyen de lam chi so cot trong bang QHD)
    float v; // Gia tri goi hang (so thuc de khop voi so thuc C)
};

// ==========================================
// 1. THUAT TOAN THAM LAM
// Muc tieu: Chon so luong goi hang NHIEU NHAT (D) de tong gia tri BANG DUNG C
// ==========================================

// Ham sap xep danh sach goi hang TANG DAN theo gia tri v (Bubble Sort)
// Chien luoc: De lay duoc NHIEU goi hang nhat, ta uu tien lay cac goi co gia tri NHO NHAT truoc
void sortTang_GiaTri(GoiHang a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (a[j - 1].v > a[j].v) {
                GoiHang tmp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = tmp;
            }
        }
    }
}

// Ham tham lam tra ve so luong goi hang D (tra ve -1 neu khong tim duoc tong dung bang C)
int ThamLam(GoiHang a[], int n, float C, GoiHang res[]) {
    // Buoc 1: Sap xep tang dan theo gia tri
    sortTang_GiaTri(a, n);
    
    int dem = 0;      // Dem so goi hang duoc chon (gia tri D)
    int i = 0;        // Chi so duyet mang
    float C_con = C;  // Gia tri con thieu can bu vao de dat dung C
    
    // Buoc 2: Duyet qua tung goi hang tu gia tri nho den lon
    while (i < n && C_con > 1e-6) {
        // Neu gia tri goi hang nay <= phan gia tri con thieu thi chon
        if (a[i].v <= C_con + 1e-6) {
            res[dem++] = a[i]; // Luu goi hang vao mang ket qua
            C_con -= a[i].v;   // Tru di gia tri da lay
        }
        i++; // Chuyen sang goi hang tiep theo
    }
    
    // Buoc 3: Kiem tra xem tong gia tri da bang DUNG C chua (C_con xap xi 0)
    if (fabs(C_con) < 1e-6) {
        return dem; // Thanh cong, tra ve so luong goi hang D
    }
    
    return -1; // Khong co phuong an bang dung C
}

// ==========================================
// 2. THUAT TOAN QUY HOACH DONG (CAI TUI 0/1)
// Muc tieu: Chon cac goi hang de tong gia tri lon nhat (P) voi tong khoi luong <= M
// ==========================================

// Ham lap bang phuong an quy hoach dong F
void QHD(GoiHang a[], int n, int M, float F[][100]) {
    // Khoi tao hang 0 va cot 0 bang 0 (khong co hang hoac suc chua = 0 thi gia tri = 0)
    for (int i = 0; i <= n; i++) {
        F[i][0] = 0;
    }
    for (int j = 0; j <= M; j++) {
        F[0][j] = 0;
    }
    
    // Tinh bang phuong an: i chay theo so goi hang (1..n), j chay theo khoi luong (1..M)
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= M; j++) {
            // Mac dinh la khong chon goi hang thu i
            F[i][j] = F[i - 1][j];
            
            // Neu goi hang thu i (nam o chi so a[i-1]) nhet vua suc chua j
            if (a[i - 1].m <= j) {
                // Chon phuong an tot hon giua khong lay va lay goi hang thu i
                F[i][j] = max(F[i][j], F[i - 1][j - a[i - 1].m] + a[i - 1].v);
            }
        }
    }
}

// Ham truy vet nguoc tu F[n][M] de tim chi so cac goi hang da chon
int TruyVet(GoiHang a[], int n, int M, float F[][100], int x[]) {
    int i = n;
    int j = M;
    int dem = 0;
    
    while (i > 0 && j > 0) {
        // Neu F[i][j] khac F[i-1][j] nghia la ta da chon goi hang thu i
        if (F[i][j] != F[i - 1][j]) {
            x[dem++] = i - 1; // Luu chi so mang cua goi hang da chon
            j -= a[i - 1].m;  // Giam suc chua con lai di khoi luong cua goi hang do
        }
        i--; // Xet tiep goi hang phia truoc
    }
    return dem;
}

// Ham xuat ket qua quy hoach dong
void Xuat_QHD(GoiHang a[], int x[], int dem, float P) {
    int tongKL = 0;
    cout << "Gia tri lon nhat dat duoc (P): " << P << endl;
    cout << "Danh sach cac goi hang da lay de duoc P:" << endl;
    
    // In nguoc tu dem - 1 ve 0 de hien thi theo dung thu tu ban dau
    for (int i = dem - 1; i >= 0; i--) {
        cout << "- Goi hang STT: " << a[x[i]].stt 
             << " | Khoi luong: " << a[x[i]].m 
             << " | Gia tri: " << a[x[i]].v << endl;
        tongKL += a[x[i]].m;
    }
    cout << "Tong khoi luong thuc te: " << tongKL << endl;
}

// ==========================================
// HAM MAIN
// ==========================================
int main() {
    // Khoi tao n >= 8, danh sach a gom n goi hang, so thuc C va khoi luong toi da M
    int n = 8;
    float C = 15.0; // Gia tri muc tieu can dat dung bang cho Tham lam
    int M = 25;     // Tong khoi luong toi da cho Quy hoach dong
    
    GoiHang a[8] = {
        {1, 6, 8.0},
        {2, 4, 3.0},
        {3, 8, 12.0},
        {4, 3, 2.5},
        {5, 7, 6.5},
        {6, 5, 5.0},
        {7, 9, 10.0},
        {8, 4, 4.5}
    };
    
    // Hien thi danh sach ban dau
    cout << "============= DANH SACH GOI HANG BAN DAU =============" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Goi " << a[i].stt << " | Khoi luong (m): " << a[i].m 
             << " | Gia tri (v): " << a[i].v << endl;
    }
    
    // --- CHAY THUAT TOAN THAM LAM ---
    cout << "\n============= KET QUA THAM LAM (TONG = " << C << ") =============" << endl;
    // Tao mang ban sao de sap xep khong lam thay doi thu tu mang goc a
    GoiHang a_copy[20];
    for (int i = 0; i < n; i++) {
        a_copy[i] = a[i];
    }
    
    GoiHang res[20];
    int D = ThamLam(a_copy, n, C, res);
    
    if (D != -1) {
        cout << "So luong goi hang nhieu nhat lay duoc (D): " << D << endl;
        cout << "So thu tu cac goi hang da lay trong a: ";
        for (int i = 0; i < D; i++) {
            cout << res[i].stt << " ";
        }
        cout << endl;
        cout << "Chi tiet cac goi hang da lay:" << endl;
        for (int i = 0; i < D; i++) {
            cout << "- STT: " << res[i].stt << " | Gia tri: " << res[i].v << endl;
        }
    } else {
        cout << "Khong co phuong an tham lam de tong gia tri bang dung " << C << "!" << endl;
    }
    
    // --- CHAY THUAT TOAN QUY HOACH DONG ---
    cout << "\n============= KET QUA QUY HOACH DONG (KHOI LUONG <= " << M << ") =============" << endl;
    float F[20][100]; // Bang phuong an QHD
    int x[20];        // Mang luu vet chi so goi hang duoc chon
    
    QHD(a, n, M, F);
    int dem = TruyVet(a, n, M, F, x);
    Xuat_QHD(a, x, dem, F[n][M]);
    
    return 0;
}
