#include<bits/stdc++.h>
using namespace std;

int QHD(int F[], int n, int S,int a[]){
	for(int i=0;i<=S;i++){
		F[i]=0;
	}
	
	F[0]=1;
	for(int i=0;i<n;i++){
	
		for(int j=S;j>=a[i];j--){
			F[j]=F[j]+F[j-a[i]];
		}
	}
	return F[S];
}

int main() {
   int S;

//    cout << "Nhap n: ";
//    cin >> n;
int n=5;
int a[]={2,5,7,8,9};
int F[100];   

    cout << "Nhap S: ";
    cin >> S;

    cout << "So cach tao tong " << S << " la: ";
    cout << QHD(F, n, S,a);

    return 0;
}
