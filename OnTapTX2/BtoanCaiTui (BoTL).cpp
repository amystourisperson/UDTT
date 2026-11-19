#include<bits/stdc++.h>
using namespace std;

struct Hang{
	int STT;
	int w;
	int v;
};

void QHD(Hang a[],int n,int m, int F[][100]){
	for(int i=0;i<=n;i++){
		F[i][0]=0;
	}
	for(int j=0;j<=m;j++){
		F[0][j]=0;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			F[i][j]=F[i-1][j];
			
			if(a[i-1].w<=j){
				F[i][j]=max(F[i][j],F[i-1][j-a[i-1].w]+a[i-1].v);
			}
		}
	}
}

int Truyvet(Hang a[], int n, int m,int F[][100],int x[]){
	int dem=0;
	int i=n,j=m;
	while(i>0 && j>0){
		if(F[i][j]!=F[i-1][j]){
			x[dem++]=i-1;
			j-=a[i-1].w;
		}
		i--;
	}
	return dem;
}

void Xuat(Hang a[], int x[], int dem, int gtmax){
	cout<<"\nCac goi hang duoc chon:";
	
	for(int i=dem-1;i>=0;i--){
		cout<<"\nSTT:"<<a[x[i]].STT<<"Khoi luong:"<<a[x[i]].w<<"Gia tri:"<<a[x[i]].v<<endl;
	}
	cout<<"\nTong so hang lay duoc:"<<dem<<endl;
	cout<<"\nGia tri lon nhat duoc:"<<gtmax<<endl;
}
const int MAX=12;
int main(){
	int n=6;
	Hang a[n]={
		{1,5,13},
		{2,6,14},
		{3,7,15},
		{4,2,11},
		{5,3,17},
		{6,5,14}
	};
	int m=12;
	int F[100][100];
	QHD(a,n,m,F);
	int x[100];
	int dem=Truyvet(a,n,m,F,x);
	Xuat(a,x,dem,F[n][m]);
}
