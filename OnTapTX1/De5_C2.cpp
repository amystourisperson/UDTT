#include<bits/stdc++.h>
using namespace std;

// Tinh tong cac so le bang de quy
int total_DQ(int A[], int i, int n){
    // Dieu kien dung
    if(i >= n || i < 0){
        return 0;
    }

    // Neu A[i] la so le thi cong vao tong
    if(A[i] % 2 != 0){
        return A[i] + total_DQ(A, i + 1, n);
    }

    // Neu A[i] la so chan thi bo qua
    return total_DQ(A, i + 1, n);
}

// Tim tong lon nhat cua mang con bang chia de tri
int MaxSum(int A[], int l, int r, int &dau, int &cuoi){
    // Dieu kien dung: mang chi con mot phan tu
    if(l == r){
        dau = l;
        cuoi = r;
        return A[l];
    }

    // Chia mang thanh hai nua
    int mid = (l + r) / 2;

    // Tim tong lon nhat o nua ben trai
    int d1, c1;
    int left = MaxSum(A, l, mid, d1, c1);

    // Tim tong lon nhat o nua ben phai
    int d2, c2;
    int right = MaxSum(A, mid + 1, r, d2, c2);

    // Tim tong lon nhat cua mang con cat qua giua
    int tong = 0;
    int maxLeft = INT_MIN;
    int vtDau = mid;

    for(int i = mid; i >= l; i--){
        tong += A[i];

        if(tong > maxLeft){
            maxLeft = tong;
            vtDau = i;
        }
    }

    tong = 0;
    int maxRight = INT_MIN;
    int vtCuoi = mid + 1;

    for(int i = mid + 1; i <= r; i++){
        tong += A[i];

        if(tong > maxRight){
            maxRight = tong;
            vtCuoi = i;
        }
    }

    int middle = maxLeft + maxRight;

    // So sanh ba truong hop de tim tong lon nhat
    if(left >= right && left >= middle){
        dau = d1;
        cuoi = c1;
        return left;
    }

    if(right >= left && right >= middle){
        dau = d2;
        cuoi = c2;
        return right;
    }

    dau = vtDau;
    cuoi = vtCuoi;
    return middle;
}

int main(){
    srand(time(0));

    // Khoi tao mang ngau nhien gom 20 so
    int n = 20;
    int A[100];

    for(int i = 0; i < n; i++){
        A[i] = rand() % 41 - 20;
    }

    // Dam bao mang co ca so am va so duong
    A[0] = -5;
    A[1] = 8;

    // Hien thi mang
    cout << "Mang A: ";
    for(int i = 0; i < n; i++){
        cout << A[i] << " ";
    }

    // Tinh tong cac so le bang de quy
    cout << "\nTong cac so le: ";
    cout << total_DQ(A, 0, n);

    // Tim mang con co tong lon nhat
    int dau, cuoi;
    int maxTong = MaxSum(A, 0, n - 1, dau, cuoi);

    cout << "\nTong lon nhat cua mang con: " << maxTong;

    cout << "\nMang con co tong lon nhat: ";
    for(int i = dau; i <= cuoi; i++){
        cout << A[i] << " ";
    }

    cout << endl;
    return 0;
}
