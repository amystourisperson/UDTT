
#include<bits/stdc++.h>
using namespace std;

int Sum(int a[], int n, int l, int r){
	if(l==r){
		if(a[l]%2!=0){
			return a[l];
		}
		return 0;
	}
	int mid=(l+r)/2;
	int left=Sum(a,n,l,mid);
	int right=Sum(a,n,mid+1,r);
	
	return left+right;
}


int DQ(int a[], int n, int i){
	if(i==n)	return 0;
	
	if(a[i]%2!=0){
		return a[i]+DQ(a,n,i+1);
	}
	return DQ(a,n,i+1);
}
int main(){
	int n=10;
//	do{
//		cout<<"\nNhap n(n>0):";
//		cin>>n;
//	}while(n<10);
	
	int a[n]={1,2,3,4,5,6,7,8,9,10};
	
//	for(int i=0;i<n;i++){
//		cout<<"\na["<<i<<"]:";
//		cin>>a[i];
//	}
	
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	
//	cout<<"\nTong:"<<Sum(a,n,0,n-1);
	cout<<"\nTong:"<<DQ(a,n,0);
}
