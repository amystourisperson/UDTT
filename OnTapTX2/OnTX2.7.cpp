#include<bits/stdc++.h>
using namespace std;

struct HT{
	char ten[30];
	int bd;
	int kt;
};

void Sort(HT d[], int n){
	for(int i=0;i<n-1;i++){
		for(int j=n-1;j>i;j--){
			if(d[j-1].kt>d[j].kt){
				HT temp=d[j-1];
				d[j-1]=d[j];
				d[j]=temp;
			}
		}
	}
}
int G(HT d[],int n,int s[]){
	Sort(d,n);
	for(int i=0;i<n;i++){
		s[i]=0;
	}
	int dem=1;
	s[0]=1;
	int start=d[0].kt;
	int i=1;
	while(i<n){
		if(start <=d[i].bd){
			s[i]++;
			start=d[i].kt;
			dem++;
		}
		i++;
	}
	return dem;
}
int main(){
	int n=5;
	HT d[]={{"Job",1,4},{"AI",0,6},{"soft skill",3,5},{"start up",5,7},{"safe inter",8,9}};
	Sort(d,n);
	for(int i=0;i<n;i++){
		cout<<d[i].ten<<" "<<d[i].bd<<" "<<d[i].kt<<endl;
	}
	int s[100];
	int dem=G(d,n,s);
	cout<<"\nHoi nghi tham gia!!"<<endl;
	for(int i=0;i<n;i++){
		if(s[i]){
			cout<<d[i].ten<<" "<<d[i].bd<<" "<<d[i].kt<<endl;
		}
	}
	cout<<"\nToi da tham gia duoc: "<<dem<<" hoi nghi!!"<<endl;
	
}
