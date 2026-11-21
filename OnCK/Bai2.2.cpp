#include <bits/stdc++.h>
using namespace std;

//Cau 2.2
// ==========================================
// 1. THUAT TOAN THAM LAM
// Muc tieu: Chon so luong phan tu IT NHAT (D) de tong M > C
// ==========================================
int greedy(float a[], int n, float C, int s[], float &M) {
    // Buoc 1: Khoi tao tat ca phan tu mang danh dau s[] bang 0
    int i = 0;
    while (i < n) {
        s[i] = 0;
        i++;
    }
    
    M = 0;     // Tong gia tri thuc te lay duoc
    int D = 0; // Dem so luong phan tu da lay
    
    // Buoc 2: Vi mang a da sap xep TANG DAN, de lay IT phan tu nhat
    // ta phai uu tien lay cac so LON NHAT truoc -> duyet nguoc tu cuoi mang (n - 1) ve 0
    i = n - 1;
    while (i >= 0 && M <= C) {
        M += a[i]; // Cong don gia tri phan tu lon nhat hien tai vao M
        s[i] = 1;  // Danh dau phan tu thu i da duoc chon
        D++;       // Tang so luong phan tu da lay
        i--;       // Lui ve phan tu lon tiep theo
    }
    
    // Buoc 3: Kiem tra dieu kien M > C
    if (M > C) {
        return D; // Tra ve so luong phan tu it nhat thoa man
    }
    
    return 0; // Khong co phuong an (lay het mang van khong lon hon C)
}

// ==========================================
// 2. THUAT TOAN BOYER-MOORE-HORSPOOL (BMH)
// Muc tieu: Tim vi tri xuat hien chuoi P trong chuoi Q
// ==========================================

// Ham tim vi tri xuat hien cua ky tu a trong chuoi mau s
int char_in_string(char a, const char *s) {
    int x = 0;
    while (s[x] != '\0') {
        if (s[x] == a) {
            return x; // Tra ve vi tri index neu tim thay
        }
        x++;
    }
    return -1; // Tra ve -1 neu ky tu a khong nam trong s
}

// Ham BMH tim vi tri bat dau cua chuoi P (Pattern) trong chuoi Q (Text)
// Tra ve vi tri index (tinh tu 0) neu tim thay, tra ve -1 neu khong thay
int BMH(const char *Q, const char *P) {
    int v = strlen(P);    // Do dai chuoi mau P
    int lenQ = strlen(Q); // Do dai chuoi van ban Q
    int i = v - 1;        // Bat dau so khop tu vi tri cuoi cua P
    
    while (i < lenQ) {
        int k = v - 1; // Chi so duyet nguoc cua chuoi mau P
        
        // So sanh tung ky tu tu phai sang trai
        while (k > -1 && Q[i] == P[k]) {
            i--;
            k--;
        }
        
        // Neu k < 0 nghia la da khop toan bo chuoi P
        if (k < 0) {
            return i + 1; // Tra ve vi tri bat dau xuat hien cua P trong Q (tinh tu 0)
        } else {
            // Neu khong khop, tim ky tu loi Q[i] trong chuoi mau P de tinh buoc nhay
            int x = char_in_string(Q[i], P);
            if (x < 0) {
                i = i + v;         // Khong co trong P -> nhay coc nguyen do dai v
            } else {
                i = i + v - x - 1; // Co trong P -> nhay de can khop ky tu do
            }
        }
    }
    
    return -1; // Duyet het chuoi Q ma khong tim thay P
}

int main() {
    // --- PHAN 1: KHOI TAO VA CHAY THUAT TOAN THAM LAM ---
    // Khoi tao n >= 8, mang so thuc a tang dan va so thuc C
    int n = 8;
    float a[8] = {1.2, 2.5, 3.0, 4.5, 5.8, 7.1, 9.0, 12.5};
    float C = 20.0;
    
    int s[100]; // Mang danh dau cac phan tu duoc chon
    float M = 0;
    
    // Goi ham tham lam
    int D = greedy(a, n, C, s, M);
    
    cout << "============= KET QUA THAM LAM =============" << endl;
    if (D > 0) {
        cout << "So luong phan tu it nhat can lay (D): " << D << endl;
        cout << "Tong gia tri dat duoc (M): " << M << " (lon hon C = " << C << ")" << endl;
        cout << "Cac gia tri da lay trong mang a: ";
        // Duyet mang danh dau s[] de in ra cac phan tu da chon
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] > 0) {
                cout << a[i] << "  ";
            }
        }
        cout << endl;
    } else {
        cout << "Khong co phuong an nao thoa man de tong lon hon " << C << "!" << endl;
    }
    
    // --- PHAN 2: KHOI TAO VA CHAY THUAT TOAN BMH ---
    // Khoi tao 2 chuoi P va Q (khong qua 255 ky tu)
    // De bai yeu cau tim vi tri cua P trong Q (Q la chuoi lon, P la chuoi con)
    char Q[256] = "Dai hoc Cong nghiep Ha Noi 2026";
    char P[256] = "Cong nghiep";
    
    cout << "\n============= KET QUA BOYER-MOORE-HORSPOOL =============" << endl;
    cout << "Chuoi Q: " << Q << endl;
    cout << "Chuoi P: " << P << endl;
    
    int vt = BMH(Q, P);
    if (vt != -1) {
        cout << "=> Ket luan: Chuoi P xuat hien trong chuoi Q tai vi tri (index tu 0): " << vt << endl;
    } else {
        cout << "=> Ket luan: Chuoi P KHONG xuat hien trong chuoi Q." << endl;
    }
    
    return 0;
}
