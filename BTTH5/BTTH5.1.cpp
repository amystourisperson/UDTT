// bai 1: bai toan cai tui
#include<bits/stdc++.h>
using namespace std;

// cau truc luu tru thong tin goi hang
struct Hang{
	int STT;
	int w;
	int v;
};

// ham quy hoach dong
void QHD(Hang a[], int n, int m, int F[][100]){
	// khoi tao
	for(int i=0; i<=n; i++){
		F[i][0] = 0;
	}
	for(int j=0; j<=m; j++){
		F[0][j] = 0;
	}
	
	// tinh bang quy hoach dong
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			F[i][j] = F[i-1][j];
			
			// neu co the dua vao tui thi kiem tra de lay max
			if(a[i-1].w <= j){
				F[i][j] = max(F[i][j], F[i-1][j-a[i-1].w] + a[i-1].v);
			}
		}
	}
}

// ham truy vet lay cac mon hang
int Truyvet(Hang a[], int n, int m, int F[][100], int x[]){
	int dem = 0;
	int i = n, j = m;
	
	while(i > 0 && j > 0){
		if(F[i][j] != F[i-1][j]){
			x[dem++] = i-1;
			j -= a[i-1].w; // tru di khoi luong mon do da lay
		}
		i--;
	}
	return dem;
}

// ham xuat thong tin
void Xuat(Hang a[], int x[], int dem, int gtmax){
	cout << "\nCac goi hang duoc chon:" << endl;
	
	// in nguoc de dung thu tu
	for(int i = dem-1; i >= 0; i--){
		cout << "STT: " << a[x[i]].STT << " | Khoi luong: " << a[x[i]].w << " | Gia tri: " << a[x[i]].v << endl;
	}
	cout << "\nTong so hang lay duoc: " << dem << endl;
	cout << "\nGia tri lon nhat dat duoc: " << gtmax << endl;
}

int main(){
	int n = 6;
	Hang a[6] = {
		{1, 5, 13},
		{2, 6, 14},
		{3, 7, 15},
		{4, 2, 11},
		{5, 3, 17},
		{6, 5, 14}
	};
	int m;
	
	cout << "Nhap khoi luong toi da cua tui (m): ";
	cin >> m;
	
	int F[100][100];
	QHD(a, n, m, F);
	
	int x[100];
	int dem = Truyvet(a, n, m, F, x);
	
	Xuat(a, x, dem, F[n][m]);
	
	return 0;
}
