#include <iostream>
using namespace std;

double b[100];

// Sap xep tron tang dan
void Merge_Sort(double A[], int l, int r){
    if(l < r){
        int m = (l + r) / 2;

        Merge_Sort(A, l, m);
        Merge_Sort(A, m + 1, r);

        // Sao chep nua dau
        for(int i = l; i <= m; i++){
            b[i] = A[i];
        }

        // Sao chep nua sau theo thu tu nguoc
        for(int j = m + 1; j <= r; j++){
            b[r - j + m + 1] = A[j];
        }

        // Gop mang
        int i = l;
        int j = r;

        for(int k = l; k <= r; k++){
            if(b[i] < b[j]){
                A[k] = b[i];
                i++;
            }else{
                A[k] = b[j];
                j--;
            }
        }
    }
}

// Tim kiem nhi phan bang chia de tri
int timKiem(double A[], int l, int r, double k){
    // Khong tim thay
    if(l > r){
        return -1;
    }

    int m = (l + r) / 2;

    // Tim thay k
    if(A[m] == k){
        return m;
    }

    // Tim ben phai
    if(A[m] < k){
        return timKiem(A, m + 1, r, k);
    }

    // Tim ben trai
    return timKiem(A, l, m - 1, k);
}

int main(){
    int n;
    double A[100];
    double k;

    cout << "Nhap n: ";
    cin >> n;

    cout << "Nhap mang A:\n";
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    cout << "Nhap k: ";
    cin >> k;

    // Sap xep mang truoc khi tim kiem
    Merge_Sort(A, 0, n - 1);

    cout << "Mang sau khi sap xep: ";
    for(int i = 0; i < n; i++){
        cout << A[i] << " ";
    }

    int vt = timKiem(A, 0, n - 1, k);

    if(vt != -1){
        cout << "\nVi tri cua k trong mang da sap xep: " << vt;
    }else{
        cout << "\nKhong tim thay k trong mang.";
    }

    return 0;
}
