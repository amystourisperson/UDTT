#include<bits/stdc++.h>
using namespace std;
void sort(int c[], int n){
	for(int i=0;i<n-1;i++){
		for(int j=n-1;j>i;j--){
			if(c[j-1]<c[j]){
				int tmp=c[j-1];
				c[j-1]=c[j];
				c[j]=tmp;
			}
		}
	}
}
bool greedy(int n, int m, int s[], int c[]){
	for(int i=0;i<m;i++){
		s[i]=0;
	}
	int i=0;
	while(i<m && n>0){
		s[i]=n/c[i];
		n=n%c[i];
		i++;	
	}
	if(n==0){
		return true;
	}
	return false;
}

int main(){
	int n=30;
	int m=8;
	int c[m]={8,7,6,5,4,3,2,1};
	int s[100];
	sort(c,m);
	if(greedy(n,m,s,c)){
		cout<<"\nDOI Thanh cong!!"<<endl;	
		for(int i=0;i<m;i++){
			if(s[i]>0)
				cout<<c[i]<<":"<<s[i]<<endl;	
		}
	}else{
		cout<<"\nKHong doi duoc!!"<<endl;
	}
}

