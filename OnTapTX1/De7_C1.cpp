#include <bits/stdc++.h>
using namespace std;

int A[100], B[100];

// Hien thi cau hinh
void view_config(int x[]){
    int a = A[x[1]];
    int b = B[x[2]];

    if(pow(a, b) > pow(b, a)){
        cout << "(" << a << ", " << b << ") ";
    }
}

// Sinh cau hinh tiep theo
void next_config(int x[], int n, int m, int i){
    x[i]++;

    if(x[i] > (i == 1 ? n : m)){
        x[i] = 1;
        if(i == 2){
            next_config(x, n, m, 1);
        }
    }
}

// Liet ke cac cau hinh
void listing_configs(int n, int m){
    int x[3] = {0, 1, 1};

    while(x[1] <= n){
        view_config(x);

        x[2]++;

        if(x[2] > m){
            x[2] = 1;
            x[1]++;
        }
    }
}

int main(){
    int n, m;

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> A[i];
    }

    cin >> m;
    for(int i = 1; i <= m; i++){
        cin >> B[i];
    }

    listing_configs(n, m);

    return 0;
}
