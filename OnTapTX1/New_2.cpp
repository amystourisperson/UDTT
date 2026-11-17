#include <iostream>
#include <string>
using namespace std;

string tv[] = {"", "Tung", "Cuc", "Truc", "Mai"};
string dd[] = {"", "Da Nang", "Phu Quoc", "Ha Long"};

int x[5];      
int dem = 0;  

void view_config(int x[], int n) {
    dem++;
    cout << "Cach " << dem << ": ";
    for (int i = 1; i <= n; i++) {
        cout << "[" << tv[i] << " -> " << dd[x[i]] << "]   ";
    }
    cout << endl;
}

// ==========================================
// 1.
// ==========================================
void next_config(int x[], int n, int i) {
    x[i] += 1;
    i++;
    while (i <= n) {
        x[i] = 1;
        i++;
    }
}

void listing_configs(int n) {
    int i;
    
    for (int j = 1; j <= n; j++) {
        x[j] = 1;
    }

    do {
        view_config(x, n);

        i = n;
        while (i > 0 && x[i] == 3) {
            i--;
        }

        if (i > 0) {
            next_config(x, n, i);
        }

    } while (i > 0);
}

// ==========================================
// 2.
// ==========================================
void Try(int i, int n) {
    for (int j = 1; j <= 3; j++) {
        x[i] = j; 
        
        if (i == n) {
            view_config(x, n);
        } else {
            Try(i + 1, n);
        }
    }
}

// ==========================================
// HÀM MAIN
// ==========================================
int main() {
    int n = 4; // Có 4 thành viên

    cout << "============== CACH 1: PHUONG PHAP SINH ==============" << endl;
    dem = 0; 
    listing_configs(n);
    cout << "=> Tong so cach phan cong (Sinh): " << dem << "\n\n";

    cout << "============== CACH 2: THUAT TOAN QUAY LUI ==============" << endl;
    dem = 0; 
    Try(1, n);
    cout << "=> Tong so cach phan cong (Quay lui): " << dem << endl;

    return 0;
}
