// bai 2: phan tich so thanh tong cac so <= m
#include<bits/stdc++.h>
using namespace std;

int F[100]; // mang quy hoach dong de dem so cach
int x[100]; // mang luu cau hinh cho quay lui

// 1. tinh so cach phan tich bang quy hoach dong
int QHD(int n, int m){
	for(int i=0; i<=n; i++){
		F[i] = 0;
	}
	F[0] = 1;
	
	for(int j=1; j<=m; j++){
		for(int i=j; i<=n; i++){
			F[i] = F[i] + F[i-j];
		}
	}
	return F[n];
}

// in mot cau hinh
void HienThi(int k){
	for(int i=1; i<=k; i++){
		cout << x[i] << " ";
	}
	cout << endl;
}

// 2. dung thuat toan quay lui de liet ke cac cach
// S: tong con lai can phan tich, limit: gia tri toi da, k: vi tri trong mang x
void Try(int S, int limit, int k){
	// neu da dat tong thi in ket qua
	if(S == 0){
		HienThi(k-1);
		return;
	}
	
	// duyet lui de in ra cac so tu lon den be
	for(int j = min(S, limit); j >= 1; j--){
		x[k] = j;
		Try(S - j, j, k + 1);
	}
}

int main(){
	int n, m;
	cout << "Nhap n: ";
	cin >> n;
	cout << "Nhap m (cac so nguyen duong <= m): ";
	cin >> m;
	
	cout << "\nSo cach phan tich (QHD): " << QHD(n, m) << endl;
	
	cout << "\nCac cau hinh cu the (Quay lui):" << endl;
	Try(n, m, 1);
	
	return 0;
}
