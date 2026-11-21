#include <bits/stdc++.h>
using namespace std;
//Cau 2.1
// ==========================================
// 1. THUAT TOAN THAM LAM
// ==========================================
// Tinh D la so luong phan tu nhieu nhat lay trong a de tong M <= C
int greedy(float a[], int n, float C, int s[], float &M) {
    // Khoi tao mang danh dau s[] bang 0
    int i = 0;
    while (i < n) {
        s[i] = 0;
        i++;
    }
    
    M = 0;     // Tong gia tri thuc te lay duoc
    int D = 0; // So luong phan tu lay duoc
    i = 0;
    
    // Vi mang a da sap xep tang dan, ta uu tien lay tu so nho nhat
    while (i < n && M + a[i] <= C) {
        M += a[i];
        s[i] = 1; // Danh dau da chon phan tu thu i
        D++;
        i++;
    }
    
    return D;
}

// ==========================================
// 2. THUAT TOAN BOYER-MOORE-HORSPOOL (BMH)
// ==========================================
// Ham tim vi tri ky tu a trong chuoi s
int char_in_string(char a, const char *s) {
    int x = 0;
    while (s[x] != '\0') {
        if (s[x] == a) {
            return x;
        }
        x++;
    }
    return -1;
}

// Kiem tra chuoi Q (Pattern) co la chuoi con cua P (Text) hay khong
bool BMH(const char *P, const char *Q) {
    int v = strlen(Q);
    int i = v - 1;
    
    while (i < strlen(P)) {
        int k = v - 1;
        while (k > -1 && P[i] == Q[k]) {
            i--;
            k--;
        }
        if (k < 0) {
            return true; // Tim thay Q trong P
        } else {
            int x = char_in_string(P[i], Q);
            if (x < 0) {
                i = i + v;
            } else {
                i = i + v - x - 1;
            }
        }
    }
    return false;
}

int main() {
    // Khoi tao n >= 8, mang a tang dan va so thuc C
    int n = 8;
    float a[8] = {1.2, 2.5, 3.0, 4.5, 5.8, 7.1, 9.0, 12.5};
    float C = 15.0;
    
    int s[100];
    float M = 0;
    
    // Goi thuat toan tham lam
    int D = greedy(a, n, C, s, M);
    
    cout << "============= KET QUA THAM LAM =============" << endl;
    if (D > 0) {
        cout << "So luong phan tu nhieu nhat co the lay (D): " << D << endl;
        cout << "Tong gia tri dat duoc (M): " << M << " (khong vuot qua C = " << C << ")" << endl;
        cout << "Cac gia tri da lay trong mang a: ";
        for (int i = 0; i < n; i++) {
            if (s[i] > 0) {
                cout << a[i] << "  ";
            }
        }
        cout << endl;
    } else {
        cout << "Khong co phuong an nao thoa man (D = 0, M = 0)!" << endl;
    }
    
    // Khoi tao 2 chuoi P va Q (khong qua 255 ky tu)
    char P[256] = "Dai hoc Cong nghiep Ha Noi 2026";
    char Q[256] = "Cong nghiep";
    
    cout << "\n============= KET QUA BOYER-MOORE-HORSPOOL =============" << endl;
    cout << "Chuoi P: " << P << endl;
    cout << "Chuoi Q: " << Q << endl;
    
    if (BMH(P, Q)) {
        cout << "=> Ket luan: Q LA chuoi con cua P." << endl;
    } else {
        cout << "=> Ket luan: Q KHONG LA chuoi con cua P." << endl;
    }
    
    return 0;
}
