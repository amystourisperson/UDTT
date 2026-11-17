#include<bits/stdc++.h>
using namespace std;

double total_DQ(double A[],int i, int n){
	//i: vi tri hien tai dang xet
	if(i>=n || i<0)	return 0 ;  //dkien dung
	if((int)A[i]%2 != 0){
		return A[i]+total_DQ(A,i+1,n);
	}
	return total_DQ(A,i+1,n);
}


int main(){
	int n =8;
	double A[] ={-2,-5,6,-2,-3,1,5,-6};
	
	cout<<"Tong cac so le theo de quy:"<<total_DQ(A,0,n);
}

