#include<bits/stdc++.h>
using namespace std;

// cau truc luu tru don dat hang
struct DonHang {
    int id;      // ma khach hang
    int a;       // thoi gian bat dau
    int b;       // thoi gian ket thuc
    long long c; // tien thue may
};

// ham sap xep tang dan theo thoi gian ket thuc b
bool cmp(DonHang x, DonHang y){
    return x.b < y.b;
}

// ==========================================
// 1. CHIEN LUOC QUY HOACH DONG
// ==========================================

// ham tim chi so j lon nhat (j < i) ma don hang j khong giao voi don hang i
int timP(DonHang arr[], int i){
    for(int j = i - 1; j >= 1; j--){
        if(arr[j].b <= arr[i].a){
            return j; // tim thay don hang tuong thich
        }
    }
    return 0;
}

// ham tinh bang quy hoach dong
void QHD(DonHang arr[], int n, long long F[], int p[]){
    F[0] = 0; // bai toan co so
    
    for(int i = 1; i <= n; i++){
        p[i] = timP(arr, i);
        
        // cong thuc: max(khong chon don i, chon don i + loi nhuan toi uu truoc do)
        if(arr[i].c + F[p[i]] > F[i-1]){
            F[i] = arr[i].c + F[p[i]];
        } else {
            F[i] = F[i-1];
        }
    }
}

// ham truy vet de lay ra danh sach cac don hang duoc chon
void TruyVet_QHD(DonHang arr[], int n, long long F[], int p[]){
    int x[1005]; // mang luu vet
    int dem = 0;
    int i = n;
    
    while(i > 0){
        // neu don hang i duoc chon
        if(arr[i].c + F[p[i]] > F[i-1]){
            x[dem++] = arr[i].id; // luu id khach hang
            i = p[i]; // lui ve vi tri don hang tuong thich truoc do
        } else {
            i--; // khong chon i thi xet tiep i-1
        }
    }
    
    cout << "=> Danh sach khach hang duoc chon (QHD): ";
    // in nguoc lai de dung thu tu thoi gian
    for(int j = dem - 1; j >= 0; j--){
        cout << x[j] << " ";
    }
    cout << endl;
}

// ==========================================
// 2. CHIEN LUOC THAM LAM
// ==========================================

// tham lam: uu tien khach hang ket thuc som va khong bi trung gio
void ThamLam(DonHang arr[], int n){
    int x[1005];
    int dem = 0;
    long long tongTien = 0;
    int tgKetThuc = 0; // thoi gian ket thuc cua don hang gan nhat
    
    for(int i = 1; i <= n; i++){
        // neu don hang i co thoi gian bat dau >= thoi gian ket thuc cua don truoc
        if(arr[i].a >= tgKetThuc){
            x[dem++] = arr[i].id;
            tongTien += arr[i].c;
            tgKetThuc = arr[i].b; // cap nhat lai thoi gian ket thuc
        }
    }
    
    cout << "Tong tien thu duoc (Tham lam): " << tongTien << endl;
    cout << "=> Danh sach khach hang duoc chon (Tham lam): ";
    for(int j = 0; j < dem; j++){
        cout << x[j] << " ";
    }
    cout << endl;
}

// ==========================================
// HAM MAIN
// ==========================================
int main(){
    int n = 6;
    
    // khoi tao don hang (bo trong vi tri 0 de mang chay tu chi so 1)
    DonHang arr[7] = {
        {0, 0, 0, 0},
        {1, 1, 4, 5},
        {2, 3, 5, 2},
        {3, 0, 6, 8},
        {4, 4, 7, 4},
        {5, 5, 9, 7},
        {6, 8, 10, 6}
    };
    
    // buoc bat buoc chung: sap xep don hang tang dan theo thoi gian ket thuc b
    sort(arr + 1, arr + n + 1, cmp);
    
    cout << "============= 1. QUY HOACH DONG =============\n";
    long long F[1005]; // mang luu loi nhuan toi uu
    int p[1005];       // mang luu vet vi tri
    
    QHD(arr, n, F, p);
    cout << "Tong tien thu duoc lon nhat (QHD): " << F[n] << endl;
    TruyVet_QHD(arr, n, F, p);
    
    cout << "\n============= 2. THAM LAM =============\n";
    // ghi chu: thuat toan tham lam chi giup chon duoc nhieu don hang nhat
    // chu khong dam bao se thu duoc tong tien max nhu QHD
    ThamLam(arr, n);
    
    return 0;
}
