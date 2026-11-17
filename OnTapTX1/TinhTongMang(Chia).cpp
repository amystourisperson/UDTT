#include<bits/stdc++.h>
using namespace std;

int Sum(float a[], int n, int l, int r){
	if(l==r){
		return a[l];
	}
	
	int mid=(l+r)/2;
	int left=Sum(a,n,l,mid);
	int right=Sum(a,n,mid+1,r);
	
	return left+right;
	
}
int main(){
	int n=10;
//	do{
//		cout<<"\nNhap n(n>0):";
//		cin>>n;
//	}while(n<10);
	
	float a[n]={1,2,3,4,5,6,7,8,9,10};
	
//	for(int i=0;i<n;i++){
//		cout<<"\na["<<i<<"]:";
//		cin>>a[i];
//	}
	
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	
	cout<<"\nTong:"<<Sum(a,n,0,n-1);
}
