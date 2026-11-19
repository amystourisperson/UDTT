#include <bits/stdc++.h>
using namespace std;

struct Xe{
	char ma[30];
	int kl;
	int gt;
};

// sua lai vong lap de khong bi tran mang (j+1)
void sortgiam_KL(Xe B[], int n){
	for(int i=0; i<n-1; i++){
		for(int j=n-1; j>i; j--){
			if(B[j-1].kl < B[j].kl){
				Xe tmp = B[j-1];
				B[j-1] = B[j];
				B[j] = tmp;
			}
		}
	}
}

// F2
void sortgiam_GiaTri(Xe B[], int n){
	for(int i=0; i<n-1; i++){
		for(int j=n-1; j>i; j--){
			if(B[j-1].gt < B[j].gt){
				Xe tmp = B[j-1];
				B[j-1] = B[j];
				B[j] = tmp;
			}
		}
	}
}

int ThamLam(Xe B[], int n, int m, Xe res[]){
	int i = 0;
	int dem = 0;
	int p = 0;
	// sua dieu kien i < m thanh i < n vi n la so luong phan tu
	while(i < n && p <= m){
		res[dem++] = B[i];
		p += B[i].gt;
		i++;
	}
	cout << "\n[F2] Tong gia tri hang p: " << p << " (muc tieu m = " << m << ")" << endl;
	return dem;
}

// F3
void QHD(Xe B[], int n, int K, int F[][100]){
	for(int i=0; i<=n; i++){
		F[i][0] = 0;
	}
	for(int j=0; j<=K; j++){
		F[0][j] = 0;
	}
	
	// sua lai vong lap: i chay theo so do vat (n), j chay theo suc chua (K)
	for(int i=1; i<=n; i++){
		for(int j=1; j<=K; j++){
			F[i][j] = F[i-1][j];
			if(B[i-1].kl <= j){
				F[i][j] = max(F[i][j], F[i-1][j - B[i-1].kl] + B[i-1].gt);
			}
		}
	}
}

int TruyVet(Xe B[], int n, int K, int F[][100], int x[]){
	int i = n;
	int j = K;
	int dem = 0;
	while(i > 0 && j > 0){
		if(F[i][j] != F[i-1][j]){
			x[dem++] = i-1;
			j -= B[i-1].kl;
		}
		i--;
	}
	return dem; // bo sung return dem;
}

void Xuat(Xe B[], int x[], int dem, int gtmax){
	int tongKL = 0;
	// sua i++ thanh i-- de khong bi lap vo han
	for(int i = dem-1; i>=0; i--){
		// in ra chi tiet tung container da lay
		cout << "- Ma: " << B[x[i]].ma << " | Khoi luong: " << B[x[i]].kl << " | Gia tri: " << B[x[i]].gt << endl;
		tongKL += B[x[i]].kl;
	}
	cout << "[F3] Tong gia tri hang t lon nhat: " << gtmax << " tram trieu VND" << endl;
	cout << "[F3] Tong khoi luong thuc te: " << tongKL << " tan" << endl;
}

int main(){
	// CAU a: Khoi tao n >= 7, m va K
	int n = 7;
	int m = 400; // Muc tieu m tram trieu VND
	int K = 120; // Tai trong con lai K tan
	
	Xe B[7] = {
		{"CONT_01", 30, 150},
		{"CONT_02", 15, 80},
		{"CONT_03", 40, 200},
		{"CONT_04", 25, 120},
		{"CONT_05", 20, 90},
		{"CONT_06", 35, 180},
		{"CONT_07", 10, 50}
	};
	
	// Sap xep va hien thi danh sach giam dan theo khoi luong
	sortgiam_KL(B, n);
	cout << "============= DANH SACH B (Giam dan theo khoi luong) =============" << endl;
	for(int i = 0; i < n; i++){
		cout << i+1 << ". " << B[i].ma << " | KL: " << B[i].kl << " | Gia tri: " << B[i].gt << endl;
	}
	
	// CAU b: Thuat toan F2 (Tham lam)
	cout << "\n============= CAU b: THUAT TOAN F2 (THAM LAM) =============" << endl;
	Xe B_copy[10];
	for(int i=0; i<n; i++) B_copy[i] = B[i]; // tao ban sao de khong anh huong cau c
	
	sortgiam_GiaTri(B_copy, n); // Sap xep giam dan theo gia tri de chon it nhat
	Xe res[10];
	int soLuongF2 = ThamLam(B_copy, n, m, res);
	
	cout << "So container it nhat can xuat (F2): " << soLuongF2 << endl;
	cout << "Cac container duoc chon (F2):" << endl;
	for(int i = 0; i < soLuongF2; i++){
		cout << "- " << res[i].ma << " | KL: " << res[i].kl << " | Gia tri: " << res[i].gt << endl;
	}
	
	// CAU c: Thuat toan F3 (Quy hoach dong)
	cout << "\n============= CAU c: THUAT TOAN F3 (QUY HOACH DONG) =============" << endl;
	int F[15][100]; // 15 la so vat, 100 la gioi han suc chua K
	int x[15];
	
	QHD(B, n, K, F);
	int demF3 = TruyVet(B, n, K, F, x);
	
	cout << "Cac container can xep len tau (F3):" << endl;
	Xuat(B, x, demF3, F[n][K]);
	
	return 0;
}
