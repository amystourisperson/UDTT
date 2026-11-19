#include<bits/stdc++.h>
using namespace std;

void QHD(int a[],int L[], int T[],int n){
	a[0]=-10000000;
	a[n+1]=1000000;
	L[n+1]=1;
	for(int i=n;i>=0;i--){
		int jmax=n+1;
		for(int j=i+1;j<=n+1;j++){
			if(a[j]>a[i]&& L[j]>L[jmax]){
				jmax=j;
			}
		}
		L[i]=L[jmax]+1;
		T[i]=jmax;
		
	}
}

void Truyvet(int a[],int T[],int n){
	int k=T[0];
	cout<<"\nDay con:";
	while(k!=n+1){
		cout<<"a["<<k<<"]:"<<a[k]<<" ";
		k=T[k];
	}
}

int main(){
	int n=6;
	int a[]={0,1,2,5,3,6,7,0};
	int L[100];
	int T[100];
	
	QHD(a,L,T,n);
	
	Truyvet(a,T,n);
	
}
