#include<bits/stdc++.h>
using namespace std;

struct Laptop{
    char hang[20];
    char cauhinh[100];
    int gia;
};
const int MAX=10;

int char_in_string(char a,const char *s){
	int x=0;
	while(s[x]!='\0'){
		if(s[x]==a){
			return x;
		}
		x++;
	}
	return -1;
}

int BMH(const char*T,const char*P){
	int v=strlen(P),i=v-1;
	while(i<strlen(T)){
		int k=v-1;
		int vt=i;
		while(k>-1 && T[i]==P[k]){
			i--;
			k--;
		}
		if(k<0){
			return vt+1;
		}else{
			int x=char_in_string(T[i],P);
			if(x<0){
				i=i+v;
			}else{
				i=i+v-x-1;
			}
		}
	}
	return -1;
}
int main(){
	 int n=5;

    Laptop d[]={
        {"HP","CPU 2.5GHz-RAM 16GB-SSD 512GB",15000000},
        {"ACER","CPU 2.5GHz-RAM 8GB-HDD 2TB",12000000},
        {"DELL","CPU 3.0GHz-RAM 16GB-SSD 1TB",20000000},
        {"ASUS","CPU 2.8GHz-RAM 8GB-SSD 512GB",14000000},
        {"LENOVO","CPU 2.4GHz-RAM 16GB-HDD 1TB",13000000}
    };
    char *P="RAM";
    int dem=0;
    for(int i=0;i<n;i++){
    	int vt=BMH(d[i].cauhinh,P);
    	if(vt!=-1){
    		cout<<d[i].hang<<" "<<d[i].cauhinh<<" "<<d[i].gia<<" "<<vt<<endl;
    		dem++;
		}
	}
	cout<<"\nso luong:"<<dem<<endl;
	
	char *p="RAM 16GB";
	int a=0;
	for(int i=0;i<n;i++){
    	int j=BMH(d[i].cauhinh,p);
    	if(j!=-1){
    		cout<<d[i].hang<<" "<<d[i].cauhinh<<" "<<d[i].gia<<" "<<j<<endl;
    		a++;
		}
	}
	cout<<"\nso laptop co "<<p<<":"<<a;

}
