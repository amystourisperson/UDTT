#include <iostream>
#include <string>
using namespace std;

string pb[] = {"", "HR", "Sales", "Tech", "Finance", "R&D"};
string da[] = {"", "Project A", "Project B", "Project C", "Project D"};

int x[6];       
bool dd[6];     
int dem = 0;    


void swap(int &a, int &b) {
    int tg = a;
    a = b;
    b = tg;
}

// ==========================================
// HÀM HI?N TH? CHUNG CHO C? 2 CÁCH
// ==========================================
void view_config(int x[], int k) {
    dem++;
    cout << "Cach " << dem << ": ";
    for (int i = 1; i <= k; i++) {
        cout << "[" << da[i] << " -> " << pb[x[i]] << "]   ";
    }
    cout << endl;
}

// ==========================================
// 1.
// ==========================================
void next_config(int x[], int n, int i) {
    int k = n;
    while (x[k] < x[i]) {
        k--;
    }
    
    swap(x[i], x[k]);

    int j = n;
    i++;
    while (i < j) {
        swap(x[i], x[j]);
        i++;
        j--;
    }
}

void listing_configs(int n, int k) {
    int i;
    
    for (int j = 1; j <= n; j++) {
        x[j] = j;
    }

    do {
        view_config(x, k);

        i = n - 1;
        while (i > 0 && x[i] > x[i + 1]) {
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
void Try(int i, int n, int k) {
    for (int j = 1; j <= n; j++) {
        if (dd[j] == false) {
            x[i] = j;
            dd[j] = true; 
            
            if (i == k) {
                view_config(x, k);
            } else {
                Try(i + 1, n, k);
            }
            
            dd[j] = false; // Quay lui
        }
    }
}

// ==========================================
// HÀM MAIN
// ==========================================
int main() {
    int n = 5; 
    int k = 4; // Can chon ra 4 phong ban de phan cho 4 du an

    cout << "============== CACH 1: PHUONG PHAP SINH ==============" << endl;
    dem = 0; 
    listing_configs(n, k);
    cout << "=> Tong so cach phan cong (Sinh): " << dem << "\n\n";

    cout << "============== CACH 2: THUAT TOAN QUAY LUI ==============" << endl;
    dem = 0; 
    for (int j = 1; j <= n; j++) {
        dd[j] = false;
    }
    Try(1, n, k);
    cout << "=> Tong so cach phan cong (Quay lui): " << dem << endl;

    return 0;
}
