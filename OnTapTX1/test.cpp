#include <bits/stdc++.h>
using namespace std;
string tv[] = {"", "Tung", "Cuc", "Truc", "Mai"};
string dl[] = {"", "Da Nang", "Phu Quoc", "Ha Long"};

int x[5];
int dem = 0;

void view(int x[], int n){
	dem++;
	cout<<"Cach: "<<dem<<endl;
	for(int i = 1;i<=n;i++){
		cout<<tv[i]<<" : "<<dl[x[i]]<<" ";
	}
	cout<<endl;
}

void next_config(int x[], int n, int i){
	x[i] += 1;
	i++;
	while(i <= n){
		x[i] = 1;
		i++;
	}
}

void list_config(int n){
	int i;
	for(int i=1;i<=n;i++){
		x[i] = 1;
	}
	
	do{
		view(x, n);
		i = n;
		while(i>0 && x[i] == 3){
			i--;
		}
		
		if(i > 0){
			next_config(x, n, i);
		}	
	}while(i > 0);
}

void Try(int k, int n){
	for(int j = 1;j<=3;j++){
		x[k] = j;
		if(k == n){
			view(x, n);
		}else{
			Try(k+1, n);
		}
	}
}

int main(){
	int n = 4; //4 thanh vien
	dem = 0;
	list_config(n);
	cout<<"Tong so cach la: "<<dem<<endl;
	dem = 0;
	Try(1, n);
	cout<<"Tong so cach la: "<<dem<<endl;
	
	return 0;

}
