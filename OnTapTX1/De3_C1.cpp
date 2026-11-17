#include <bits/stdc++.h>
using namespace std;

int A[100];

// In tam giac
void view_config(int a[], int n){
    for(int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

// Quay lui tao cac hang tiep theo
void Try(int a[], int n){
    // In hang hien tai
    view_config(a, n);

    // Dieu kien dung
    if(n == 1){
        return;
    }

    int b[100];
    // Tao hang tiep theo
    for(int i = 1; i < n; i++){
        b[i] = a[i] + a[i + 1];
    }
    // De quy tao cac hang tiep theo
    Try(b, n - 1);
}

int main(){
	int n; 
    cout << "Nhap n: ";
    cin >> n;

    cout << "Nhap mang A:\n";
    for(int i = 1; i <= n; i++){
        cin >> A[i];
    }

    cout << "Tam giac dac biet:\n";
    Try(A, n);

    return 0;
}
