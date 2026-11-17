//Bai5
#include<bits/stdc++.h>
using namespace std;

struct Job{
	char macv[30];
	char time_start[30];
	char time_do[30];
};

const int MAX=10;

void Out(Job c[], int n){
	for(int i=0;i<n;i++)
	cout<<"Ma job:"<<c[i].macv<<" thoi gian bat dau: "<<c[i].time_start<<" Thoi gian thuc hien:"<<c[i].time_do<<endl;
}

void DQ(Job c[], int n, int i){
	if (i<0)	return;
cout<<"Ma job:"<<c[i].macv<<" thoi gian bat dau: "<<c[i].time_start<<" Thoi gian thuc hien:"<<c[i].time_do<<endl;

	DQ(c,n,i-1);
}

int x[6];
void show(Job c[], int n){
	for(int i=1;i<=5;i++){
		cout<<"Ma job:"<<c[x[i]-1].macv<<" ";
	}
	cout<<endl;
}

int dem=0;
void Try(Job c[], int i,int n){
	for(int j = x[i-1]+1; j<=n-5+i;j++){
		x[i]=j;
		if(i==5){
			show(c,n);
			dem++;
		}else{
			Try(c,i+1,n);
		}
		}
	}

int main(){
	int n=6;
	Job c[MAX]{
	{"CV001","7H","6H"},
	{"CV002","8H","5H"},
	{"CV003","9H","4H"},
	{"CV004","10H","3H"},
	{"CV005","11H","2H"},
	{"CV006","12H","1H"}
	};
	Out(c,n);
	cout<<"\nDanh sach nguoc lai !!!!"<<endl;
	DQ(c,n,n-1);
	
	cout<<"\n Lay ra 5 job!!!"<<endl;
	
	Try(c,1,n);
	cout<<"\nSo cach:"<<dem<<endl;
	
}
