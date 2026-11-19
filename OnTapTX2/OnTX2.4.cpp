#include<bits/stdc++.h>
using namespace std;

struct phone{
	char ten[30];
	int size;
	int gia;
};
const int MAX=10;

void QHD(phone d[], int n, int s,int F[][100] ){
	for(int i=0;i<=n;i++){
		F[i][0]=0;
	}
	for(int j=0;j<=s;j++){
		F[0][j]=0;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=s;j++){
			F[i][j]=F[i-1][j];
			
			if(d[i-1].size<=j){
				F[i][j]=max(F[i][j],F[i-1][j-d[i-1].size]+d[i-1].gia);
			}
		}
	}
}

int Truyvet(phone d[], int n, int s, int F[][100], int x[]){
	int dem=0;
	int i=n,j=s;
	while(i>0 && j>0){
		if(F[i][j]!=F[i-1][j]){
			x[dem++]=i-1;
			j-=d[i-1].size;
		}
		i--;
	}
	return dem;
}

void Xuat(phone d[],int x[],int dem, int gtmax){
	int tong=0;
	cout<<"\nNhung phonne lay duoc!!"<<endl;
	for(int i=dem-1;i>=0;i--){
		cout<<d[x[i]].ten<<" "<<d[x[i]].gia<<" "<<d[x[i]].size<<endl;
		tong+=d[x[i]].size;
	}
	cout<<"\nSO dien thoai lay duoc:"<<dem<<endl;
	cout<<"\ntong gia lon nhat:"<<gtmax<<endl;
	cout<<tong;
}
int main(){
	int n=5;
//	phone d[]{
//	{"iphone",12,2000000},
//	{"samsung",11,3000000},
//	{"X",9,2500000},
//	{"nokia",15,3200000},
//	{"Y",7,4000000},
//	};

	phone d[MAX];
	for(int i=0;i<n;i++){
		
		cout<<"Nhap d["<<i<<"]"<<endl;
		cout<<"\nNhap ten:"; cin.getline(d[i].ten,30);
		cout<<"\nNhap size:";cin>>d[i].size;
		cout<<"\nNhap gia:";cin>>d[i].gia;
		cin.ignore();	
	}
	int s;
	cout<<"\nNhap size tui:";	cin>>s;
	int F[100][100];
	int x[100];
	
	QHD(d,n,s,F);
	int dem= Truyvet(d,n,s,F,x);
	Xuat(d,x,dem,F[n][s]);
	return 0;
	
	
}

