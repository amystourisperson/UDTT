#include <bits/stdc++.h>
using namespace std;

struct Hang{
	char ten[30];
	int kl;
	int gt;
	float donGia; // them don gia (gt/kl) de phuc vu rieng cho F2
};

// ==========================================
// CAU a: KHOI TAO VA SAP XEP 
// ==========================================
// dung lai vong lap chuan khong bi tran mang
void sortgiam_KL(Hang B[], int n){
	for(int i=0; i<n-1; i++){
		for(int j=n-1; j>i; j--){
			if(B[j-1].kl < B[j].kl){
				Hang tmp = B[j-1];
				B[j-1] = B[j];
				B[j] = tmp;
			}
		}
	}
}

// ==========================================
// CAU b: F2 (THAM LAM - CAI TUI PHAN SO)
// ==========================================
// sap xep giam dan theo don gia (gt/kl) de uu tien mon ngon nhat
void sortgiam_DonGia(Hang B[], int n){
	for(int i=0; i<n-1; i++){
		for(int j=n-1; j>i; j--){
			if(B[j-1].donGia < B[j].donGia){
				Hang tmp = B[j-1];
				B[j-1] = B[j];
				B[j] = tmp;
			}
		}
	}
}

// vi F2 cho phep lay mot phan nen khong dung mang res[] nhu bai truoc, ma in truc tiep
void ThamLam(Hang B[], int n, int C){
	int i = 0;
	float p = 0; // tong gia tri p
	float C_con = C; // suc cho con lai cua xe
	
	cout << "\n[F2] Khoi luong lay cua tung mat hang (Tham lam):" << endl;
	
	while(i < n && C_con > 0){
		// neu xe du cho chua toan bo kien hang nay
		if(B[i].kl <= C_con){
			cout << "- " << B[i].ten << " : lay toan bo " << B[i].kl << " ta" << endl;
			p += B[i].gt;
			C_con -= B[i].kl;
		} 
		// neu xe khong du cho, phai xe le kien hang de lay 1 phan
		else {
			float lay = C_con;
			float giatri_lay = lay * B[i].donGia;
			cout << "- " << B[i].ten << " : lay mot phan " << lay << " ta" << endl;
			p += giatri_lay;
			C_con = 0; // xe da day
		}
		i++;
	}
	cout << "[F2] Tong gia tri p lon nhat xe cho duoc: " << p << " trieu VND" << endl;
}

// ==========================================
// CAU c: F3 (QUY HOACH DONG - 0/1)
// ==========================================
void QHD(Hang B[], int n, int C, int F[][500]){ // dung mang rong hon (500) de du cho muc C
	for(int i=0; i<=n; i++){
		F[i][0] = 0;
	}
	for(int j=0; j<=C; j++){
		F[0][j] = 0;
	}
	
	// i chay theo so do vat (n), j chay theo suc chua (C)
	for(int i=1; i<=n; i++){
		for(int j=1; j<=C; j++){
			F[i][j] = F[i-1][j];
			if(B[i-1].kl <= j){
				F[i][j] = max(F[i][j], F[i-1][j - B[i-1].kl] + B[i-1].gt);
			}
		}
	}
}

int TruyVet(Hang B[], int n, int C, int F[][500], int x[]){
	int i = n;
	int j = C;
	int dem = 0;
	while(i > 0 && j > 0){
		if(F[i][j] != F[i-1][j]){
			x[dem++] = i-1;
			j -= B[i-1].kl;
		}
		i--;
	}
	return dem; // luon co return dem
}

void Xuat(Hang B[], int x[], int dem, int gtmax){
	int tongKL = 0;
	// dung for lap giam dan de in dung thu tu tu tren xuong
	for(int i = dem-1; i>=0; i--){
		cout << "- Ten hang: " << B[x[i]].ten << " | KL: " << B[x[i]].kl << " | Gia tri: " << B[x[i]].gt << endl;
		tongKL += B[x[i]].kl;
	}
	cout << "[F3] Tong gia tri hang t lon nhat: " << gtmax << " trieu VND" << endl;
	cout << "[F3] Tong khoi luong thuc te: " << tongKL << " ta" << endl;
}

int main(){
	// CAU a: Khoi tao n >= 7, danh sach B va C
	int n = 7;
	int C = 100; // Suc cho toi da C (ta)
	
	Hang B[7] = {
		{"Gao", 30, 45},
		{"Mi tom", 15, 30},
		{"Sua", 20, 60},
		{"Thit hop", 10, 40},
		{"Nuoc sach", 40, 20},
		{"Quoc xeng", 25, 50},
		{"Thuoc men", 5, 25}
	};
	
	// Tinh san don gia (gt/kl) cho vao truong donGia de xai cho F2
	for(int i=0; i<n; i++){
		B[i].donGia = (float)B[i].gt / B[i].kl;
	}
	
	// Sap xep va hien thi danh sach giam dan theo khoi luong
	sortgiam_KL(B, n);
	cout << "============= DANH SACH B (Giam dan theo khoi luong) =============" << endl;
	for(int i = 0; i < n; i++){
		cout << i+1 << ". " << B[i].ten << " | KL: " << B[i].kl << " | Gia tri: " << B[i].gt << endl;
	}
	
	// CAU b: Thuat toan F2 (Tham lam)
	cout << "\n============= CAU b: THUAT TOAN F2 (THAM LAM) =============" << endl;
	Hang B_copy[10];
	for(int i=0; i<n; i++) B_copy[i] = B[i]; // tao ban sao de khong lam hong vi tri array cho cau c
	
	sortgiam_DonGia(B_copy, n); // Sap xep giam dan theo don gia truoc khi tham lam
	ThamLam(B_copy, n, C);
	
	// CAU c: Thuat toan F3 (Quy hoach dong)
	cout << "\n============= CAU c: THUAT TOAN F3 (QUY HOACH DONG) =============" << endl;
	int F[20][500]; // 20 la max so vat, 500 la max suc chua C
	int x[20];
	
	QHD(B, n, C, F);
	int demF3 = TruyVet(B, n, C, F, x);
	
	cout << "Cac kien can xep len xe cho (F3):" << endl;
	Xuat(B, x, demF3, F[n][C]);
	
	return 0;
}
