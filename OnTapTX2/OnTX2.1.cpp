#include<bits/stdc++.h>
using namespace std;
struct Fan{
	char ten[30];
	char mau[30];
	int gia;
};
const int MAX=12;

void sort(Fan d[], int n){
	for(int i=0;i<n-1;i++){
		for(int j=n-1;j>i;j--){
			if(d[j-1].gia>d[j].gia){
				Fan temp=d[j-1];
				d[j-1]=d[j];
				d[j]=temp;
			}
		}
	}
}
//void show(Fan d[], int n){
//	cout<<"\nTen"<<setw(10)<<"Gia"<<endl;
//	for(int i=0;i<n;i++){
//		cout<<d[i].ten<<setw(10)<<d[i].gia<<endl;
//	}
//}
int greedy(Fan d[], int n, int s[], int p) {
    // Sap xep danh sach quat (thuong la tang dan theo gia)
    sort(d, n);

    // 1. Khoi tao cac phan tu mang s[] bang 0 dung while
    int i = 0;
    while (i < n) {
        s[i] = 0;
        i++;
    }

    int tong = 0;
    int dem = 0;
    i = 0; // Reset lai chi so duyet
//i<n: Van con quat de xet
    // 2. Vong lap tham lam duyet qua tung chiec quat
	while (i < n && d[i].gia <= p) {
	    p -= d[i].gia;
	    s[i]++;  //Danh dau da chon quat
	    tong += d[i].gia;
	    dem++;
	    i++;
	}

    cout << "\nSo tien da dung: " << tong;
    return dem;
}

//void Check(Fan d[], int n, int d, int s){
//	for(int i)
//}
int main(){
	int n=7;
	Fan d[n]={
	{"Senko", "Xanh", 250000},
        {"Asia", "Ðen", 350000},
        {"Panasonic", "Trang", 850000},
        {"Kangaroo", "Ðen", 450000},
        {"Vinawind", "Xám", 300000},
        {"Midea", "Trang", 400000},
        {"Sunhouse", "Vang", 280000}
	};
	int s[100];
	int p=2500000;
	int y=greedy(d,n,s,p);
	if(y>0){
		cout<<"\nMua duoc!!!"<<endl;
		
		for(int i=0;i<n;i++){
			cout<<d[i].ten<<" "<<d[i].gia<<" "<<s[i]<<endl;	
		}
	}else{
			cout<<"\nKhong mua duoc quat nao!!";
		}
	cout<<"\nSo luong quat mua:"<<y<<endl;
	return 0;
}
