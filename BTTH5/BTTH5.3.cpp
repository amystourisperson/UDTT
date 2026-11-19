// bai 3: day con don dieu tang dai nhat (kieu so thuc)
#include<bits/stdc++.h>
using namespace std;

// dung kieu float thay cho int
void QHD(float a[], int L[], int T[], int n){
	// linh canh cho kieu so thuc
	a[0] = -10000000.0;
	a[n+1] = 10000000.0;
	L[n+1] = 1;
	
	// duyet nguoc tu cuoi ve dau
	for(int i=n; i>=0; i--){
		int jmax = n+1;
		
		for(int j = i+1; j <= n+1; j++){
			// a[j] phai lon hon a[i]
			if(a[j] > a[i] && L[j] > L[jmax]){
				jmax = j;
			}
		}
		L[i] = L[jmax] + 1;
		T[i] = jmax;
	}
}

void Truyvet(float a[], int T[], int n){
	int k = T[0];
	cout << "\nGia tri cac phan tu cua day con tang:\n";
	
	// duyet cho den khi cham linh canh cuoi cung
	while(k != n+1){
		cout << a[k] << "  ";
		k = T[k];
	}
	cout << endl;
}

int main(){
	int n = 15;
	
	// mang a chua toi thieu 15 so thuc (chua san cho 0 va n+1 lam linh canh)
	float a[20] = {
		0.0, 
		1.5, 3.2, -2.1, 4.6, 5.0, 
		2.9, 6.3, 7.8, 4.2, 8.5, 
		6.1, 9.2, 10.4, 7.5, 11.0, 
		0.0
	};
	int L[100];
	int T[100];
	
	cout << "Danh sach " << n << " so thuc ban dau:\n";
	for(int i=1; i<=n; i++){
		cout << a[i] << "  ";
	}
	cout << endl;
	
	QHD(a, L, T, n);
	
	// do dai thuc te phai tru di 2 phan tu linh canh
	cout << "\nDo dai cua day con tang dai nhat: " << L[0] - 2 << endl;
	
	Truyvet(a, T, n);
	
	return 0;
}
