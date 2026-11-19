#include <bits/stdc++.h>
using namespace std;

// Dinh nghia cau truc Nong san
struct NongSan{
	char ten[30];
	int kl;
	int gt;
	float donGia; // them don gia (gt/kl) de dung cho thuat toan tham lam
};

// ==========================================
// CAU a: KHOI TAO VA SAP XEP 
// ==========================================
// Luu y: De bai (cau a) yeu cau sap xep TANG DAN theo khoi luong
void sort_tang_KL(NongSan B[], int n){
	for(int i=0; i<n-1; i++){
		for(int j=n-1; j>i; j--){
			// sap xep tang dan (>) thay vi (<)
			if(B[j-1].kl > B[j].kl){
				NongSan tmp = B[j-1];
				B[j-1] = B[j];
				B[j] = tmp;
			}
		}
	}
}

// ==========================================
// CAU b: F2 (THAM LAM - CAI TUI PHAN SO)
// Nong san ban theo can, CO THE LAY MOT PHAN
// ==========================================
// sap xep giam dan theo don gia (gt/kl) de chon nong san co gia tri cao nhat
void sort_giam_DonGia(NongSan B[], int n){
	for(int i=0; i<n-1; i++){
		for(int j=n-1; j>i; j--){
			if(B[j-1].donGia < B[j].donGia){
				NongSan tmp = B[j-1];
				B[j-1] = B[j];
				B[j] = tmp;
			}
		}
	}
}

void ThamLam(NongSan B[], int n, int C){
	int i = 0;
	float p = 0; // tong gia tri p
	float C_con = C; // suc cho con lai cua xe
	
	cout << "\n[F2] Khoi luong lay cua tung mat hang (Tham lam):" << endl;
	
	while(i < n && C_con > 0){
		// neu xe du cho chua toan bo mat hang nay
		if(B[i].kl <= C_con){
			cout << "- " << B[i].ten << " : lay toan bo " << B[i].kl << " ta" << endl;
			p += B[i].gt;
			C_con -= B[i].kl;
		} 
		// neu xe khong du cho, phai xuc le nong san (lay 1 phan)
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
// Dong thanh 1 lo nguyen, PHAI LAY CA LO HOAC KHONG
// ==========================================
void QHD(NongSan B[], int n, int C, int F[][500]){ // dung mang rong de du suc chua C
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

int TruyVet(NongSan B[], int n, int C, int F[][500], int x[]){
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
	return dem;
}

void Xuat(NongSan B[], int x[], int dem, int gtmax){
	int tongKL = 0;
	for(int i = dem-1; i>=0; i--){
		cout << "- Lo hang: " << B[x[i]].ten << " | KL: " << B[x[i]].kl << " | Gia tri: " << B[x[i]].gt << endl;
		tongKL += B[x[i]].kl;
	}
	cout << "[F3] Tong gia tri cac lo t lon nhat: " << gtmax << " trieu VND" << endl;
	cout << "[F3] Tong khoi luong thuc te: " << tongKL << " ta" << endl;
}

int main(){
	// CAU a: Khoi tao n >= 7, danh sach B va C
	int n = 7;
	int C = 100; // Suc cho toi da C (ta)
	
	NongSan B[7] = {
		{"Gao ST25", 30, 45},
		{"Ca phe do", 15, 30},
		{"Hat dieu", 20, 60},
		{"Tieu den", 10, 40},
		{"Ngo ngot", 40, 20},
		{"Dau tuong", 25, 50},
		{"Che kho", 5, 25}
	};
	
	// Tinh san don gia (gt/kl) luu vao struct cho F2
	for(int i=0; i<n; i++){
		B[i].donGia = (float)B[i].gt / B[i].kl;
	}
	
	// Sap xep va hien thi danh sach TANG DAN theo khoi luong (chu y de bai a)
	sort_tang_KL(B, n);
	cout << "============= DANH SACH B (Tang dan theo khoi luong) =============" << endl;
	for(int i = 0; i < n; i++){
		cout << i+1 << ". " << B[i].ten << " | KL: " << B[i].kl << " | Gia tri: " << B[i].gt << endl;
	}
	
	// CAU b: Thuat toan F2 (Tham lam)
	cout << "\n============= CAU b: THUAT TOAN F2 (THAM LAM) =============" << endl;
	NongSan B_copy[10];
	for(int i=0; i<n; i++) B_copy[i] = B[i]; // tao ban sao de khong lam dao lon thu tu mang cho F3
	
	sort_giam_DonGia(B_copy, n); // Sap xep giam dan theo don gia cho chien luoc tham lam
	ThamLam(B_copy, n, C);
	
	// CAU c: Thuat toan F3 (Quy hoach dong)
	cout << "\n============= CAU c: THUAT TOAN F3 (QUY HOACH DONG) =============" << endl;
	int F[20][500]; // 20 la max so vat, 500 la max suc chua C
	int x[20];
	
	QHD(B, n, C, F);
	int demF3 = TruyVet(B, n, C, F, x);
	
	cout << "Cac lo nong san can cho theo nguyen lo (F3):" << endl;
	Xuat(B, x, demF3, F[n][C]);
	
	return 0;
}
