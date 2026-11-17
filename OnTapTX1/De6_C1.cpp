#include <bits/stdc++.h>
using namespace std;

// Ham in va tinh tong cua cau hinh hien tai
//x[]: mang cau hinh nhi phan
//A[]: mang chua cac ptu ban dau
void view_config(int x[], int A[], int n, int tong[], int &dem){
    int s = 0;  //luu tong cac ptu duoc chon
    bool chon = false;

    for(int i = 1; i <= n; i++){
        if(x[i] == 1){
            s += A[i];
            chon = true;
        }
    }

    // Bo qua tap con rong
    if(chon){
        for(int i = 0; i < dem; i++){
            if(tong[i] == s)  //ktra tong da xh chua
                break;
        }

        // Neu tong chua xuat hien thi luu lai
        if(i == dem){ //tong s chua xhien trong tong[]
            tong[dem] = s; //luu tong moi vao vi tri tiep theo
            dem++;
        }
    }
}

// Ham sinh cau hinh nhi phan tiep theo
void next_config(int x[], int n, int i){
    x[i] = 1;
    i++;

    while(i <= n){
        x[i] = 0;
        i++;
    }
}

// Ham liet ke cac tong khac nhau
void listing_configs(int A[], int n){
    int i;
    int x[n+1] = {0};
    int tong[10000];
    int dem = 0;

    do{
        view_config(x, A, n, tong, dem);

        i = n;
        while(i > 0 && x[i] == 1){
            i--;
        }

        if(i > 0){
            next_config(x, n, i);
        }

    }while(i > 0);

    cout << "Cac tong khac nhau: ";
    for(int i = 0; i < dem; i++){
        cout << tong[i] << " ";
    }
    cout << endl;
}

int main(){
    int n;

    cout << "\nNhap n: ";
    cin >> n;

    int A[n+1];

    for(int i = 1; i <= n; i++){
        cout << "A[" << i << "] = ";
        cin >> A[i];
    }

    listing_configs(A, n);

    return 0;
}

