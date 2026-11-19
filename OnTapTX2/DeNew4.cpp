#include <bits/stdc++.h>
using namespace std;

// Dinh nghia cau truc Quang cao
struct QuangCao{
	char ten[30];
	int tl; // thoi luong (giay)
	int dt; // doanh thu (trieu VND)
};

// ==========================================
// CAU a: KHOI TAO VA SAP XEP 
// ==========================================
// Sap xep giam dan theo THOI LUONG (nhu yeu cau cau a)
void sortgiam_TL(QuangCao B[], int n){
	for(int i=0; i<n-1; i++){
		for(int j=n-1; j>i; j--){
			if(B[j-1].tl < B[j].tl){
				QuangCao tmp = B[j-1];
				B[j-1] = B[j];
				B[j] = tmp;
			}
		}
	}
}

// ==========================================
// CAU b: F2 (THAM LAM)
// Tim so quang cao it nhat de doanh thu lon hon m
// ==========================================
// Ðe chon it nhat ma thu nhieu tien nhat, ta xep giam dan theo DOANH THU
void sortgiam_DoanhThu(QuangCao B[], int n){
	for(int i=0; i<n-1; i++){
		for(int j=n-1; j>i; j--){
			if(B[j-1].dt < B[j].dt){
				QuangCao tmp = B[j-1];
				B[j-1] = B[j];
				B[j] = tmp;
			}
		}
	}
}

int ThamLam(QuangCao B[], int n, int m, QuangCao res[]){
	int i = 0;
	int dem = 0;
	int p = 0; // tong doanh thu p
	
	// Vong lap chay den khi tong doanh thu > m hoac het quang cao
	while(i < n && p <= m){
		res[dem++] = B[i];
		p += B[i].dt;
		i++;
	}
	
	cout << "\n[F2] Tong doanh thu p: " << p << " (muc tieu m = " << m << ")" << endl;
	return dem;
}

// ==========================================
// CAU c: F3 (QUY HOACH DONG - 0/1)
// Tim doanh thu max ma khong vuot qua khung gio T
// ==========================================
void QHD(QuangCao B[], int n, int T, int F[][500]){ // dung mang rong (500) chong tran khung gio T
	for(int i=0; i<=n; i++){
		F[i][0] = 0;
	}
	for(int j=0; j<=T; j++){
		F[0][j] = 0;
	}
	
	// i chay theo so quang cao (n), j chay theo khung gio (T)
	for(int i=1; i<=n; i++){
		for(int j=1; j<=T; j++){
			F[i][j] = F[i-1][j]; // mac dinh la khong chon quang cao i
			// neu thoi luong cua quang cao i <= thoi gian j con trong
			if(B[i-1].tl <= j){
				F[i][j] = max(F[i][j], F[i-1][j - B[i-1].tl] + B[i-1].dt);
			}
		}
	}
}

int TruyVet(QuangCao B[], int n, int T, int F[][500], int x[]){
	int i = n;
	int j = T;
	int dem = 0;
	while(i > 0 && j > 0){
		if(F[i][j] != F[i-1][j]){ // neu gia tri thay doi tuc la co lay quang cao nay
			x[dem++] = i-1;
			j -= B[i-1].tl; // tru di thoi luong cua no
		}
		i--;
	}
	return dem;
}

void Xuat(QuangCao B[], int x[], int dem, int gtmax){
	int tongTL = 0;
	// In nguoc tu dem-1 de hien thi dung thu tu da chon
	for(int i = dem-1; i>=0; i--){
		cout << "- Nhan hang: " << B[x[i]].ten << " | Thoi luong: " << B[x[i]].tl << "s | Doanh thu: " << B[x[i]].dt << " tr" << endl;
		tongTL += B[x[i]].tl;
	}
	cout << "[F3] Tong doanh thu t lon nhat: " << gtmax << " trieu VND" << endl;
	cout << "[F3] Tong thoi luong thuc te: " << tongTL << " giay" << endl;
}

int main(){
	// CAU a: Khoi tao n >= 7, m va T
	int n = 7;
	int m = 400; // Muc tieu doanh thu (trieu VND)
	int T = 120; // Tong thoi luong khung gio quang cao (giay)
	
	QuangCao B[7] = {
		{"Coca Cola", 30, 150},
		{"Pepsi", 15, 80},
		{"Vinamilk", 40, 200},
		{"TH True Milk", 25, 120},
		{"Omo", 20, 90},
		{"Sunlight", 35, 180},
		{"Honda", 10, 50}
	};
	
	// Sap xep va hien thi danh sach giam dan theo thoi luong
	sortgiam_TL(B, n);
	cout << "============= DANH SACH B (Giam dan theo thoi luong) =============" << endl;
	for(int i = 0; i < n; i++){
		cout << i+1 << ". " << B[i].ten << " | Thoi luong: " << B[i].tl << "s | Doanh thu: " << B[i].dt << " tr" << endl;
	}
	
	// CAU b: Thuat toan F2 (Tham lam)
	cout << "\n============= CAU b: THUAT TOAN F2 (THAM LAM) =============" << endl;
	QuangCao B_copy[10];
	for(int i=0; i<n; i++) B_copy[i] = B[i]; // copy mang de khong lam hong mang cua cau c
	
	sortgiam_DoanhThu(B_copy, n); // Sap xep giam dan theo doanh thu de chon it nhat
	QuangCao res[10];
	int soLuongF2 = ThamLam(B_copy, n, m, res);
	
	cout << "So quang cao it nhat can phat (F2): " << soLuongF2 << endl;
	cout << "Cac quang cao duoc chon phat (F2):" << endl;
	for(int i = 0; i < soLuongF2; i++){
		cout << "- " << res[i].ten << " | Thoi luong: " << res[i].tl << "s | Doanh thu: " << res[i].dt << " tr" << endl;
	}
	
	// CAU c: Thuat toan F3 (Quy hoach dong)
	cout << "\n============= CAU c: THUAT TOAN F3 (QUY HOACH DONG) =============" << endl;
	int F[15][500]; // 15 la max so luong quang cao, 500 la max khung gio T
	int x[15];
	
	QHD(B, n, T, F);
	int demF3 = TruyVet(B, n, T, F, x);
	
	cout << "Cac quang cao can phat trong khung gio T (F3):" << endl;
	Xuat(B, x, demF3, F[n][T]);
	
	return 0;
}
