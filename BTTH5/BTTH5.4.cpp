// bai 4: bai toan doi tien
#include<bits/stdc++.h>
using namespace std;

// ham qhd doi tien
void coin_changing(int c[], int n, int m, int f[], int s[]){
	f[0] = 0;
	
	for(int i=1; i<=m; i++){
		int Min = INT_MAX;
		
		for(int j=0; j<n; j++){
			// kiem tra menh gia co the su dung dc hay khong
			if(c[j] <= i && f[i-c[j]] + 1 < Min){
				Min = f[i-c[j]] + 1;
				s[i] = j; // danh dau luu vet
			}
		}
		f[i] = Min;
	}
}

// ham truy vet cac to tien da dung
void truyvet(int c[], int s[], int m, int dem[]){
	while(m > 0){
		dem[s[m]]++; // tang so luong to tien
		m -= c[s[m]];
	}
}

// ham in ket qua
void xuat(int c[], int dem[], int n, int f[], int m){
	cout << "\nSo to tien it nhat phai tra: " << f[m] << endl;
	
	cout << "\nPhuong an doi tien cu the:\n";
	for(int i=0; i<n; i++){
		if(dem[i] > 0){
			cout << c[i] << " : " << dem[i] << " to" << endl;
		}
	}
}

int main(){
	// mang menh gia tien (VD: 1, 2, 5, 10, 20)
	int c[] = {1, 2, 5, 10, 20};
	int n = 5; 
	
	int m;
	cout << "Nhap so tien can doi (m): ";
	cin >> m;
	
	int f[10000];
	int s[10000];
	int dem[100];
	
	for(int i=0; i<100; i++){
		dem[i] = 0;
	}
	
	// goi cac ham theo thu tu
	coin_changing(c, n, m, f, s);
	truyvet(c, s, m, dem);
	xuat(c, dem, n, f, m);
	
	return 0;
}
