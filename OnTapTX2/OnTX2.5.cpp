#include<bits/stdc++.h>
using namespace std;
void Sort(string d[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=n-1;j>0;j--){
			if(d[j-1].length()<d[j].length()){
				string temp=d[j-1];
				d[j-1]=d[j];
				d[j]=temp;
			}
		}
	}
}


bool G(string d[], int n, int k,int s[]){
	for(int i=0;i<n;i++){
		s[i]=0;
	}
	
	int i=0;
	string xau_new;
	int tong=0;
	while(i<n && tong+d[i].length()<=k){
		xau_new+=d[i];
		s[i]++;
		i++;
		tong=xau_new.length();
		if(tong==k){
			return true;
		}
	}
		return false;
}

int char_in_string(char a, const char*s){
	int x=0;
	while(s[x]!='\0'){
		if(s[x]==a){
			return x;
		}
		x++;
	}
	return -1;
}

bool BMH(const char *T, const char*P){
	int v=strlen(P),i=v-1;
	while(i<strlen(T)){
		int k=v-1;
		while(k>-1 && T[i]==P[k]){
			i--;
			k--;
		}
		if(k<0){
			return true;
		}else{
			int x=char_in_string(T[i],P);
			if(x<0){
				i=i+v;
			}else{
				i=i+v-x-1;
			}
		}
	}
	return false;
}
int main(){
	int n=7;
	string d[]={"hi","hello","nice","yeah","yes","no","childl"};
	Sort(d,n);
	for(int i=0;i<n;i++){
		cout<<d[i]<<" ";
	}
	int s[100];
	int k=11;
	if(G(d,n,k,s)){
		cout<<"\nXau ki tu lay!!!"<<endl;
		for(int i=0;i<n;i++){
			if(s[i]>0)
				cout<<d[i]<<" co do dai: "<<d[i].length()<<endl;
		}
	}else{
		cout<<"\nKhong tim duoc bang tham lam!!!"<<endl;
	}
	
	char *P="child";
	int dem=0;
	cout<<"\nSo xau lay!!"<<endl;
	for(int i=0;i<n;i++){
		if(BMH(d[i].c_str(),P)){
			cout<<d[i]<<endl;
			dem++;
		}
	}
	cout<<"\nTong so xau chua "<<P<<":"<<dem<<endl;

}#include<bits/stdc++.h>
using namespace std;
void Sort(string d[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=n-1;j>0;j--){
			if(d[j-1].length()<d[j].length()){
				string temp=d[j-1];
				d[j-1]=d[j];
				d[j]=temp;
			}
		}
	}
}


bool G(string d[], int n, int k,int s[]){
	for(int i=0;i<n;i++){
		s[i]=0;
	}
	
	int i=0;
	string xau_new;
	int tong=0;
	while(i<n && tong+d[i].length()<=k){
		xau_new+=d[i];
		s[i]++;
		i++;
		tong=xau_new.length();
		if(tong==k){
			return true;
		}
	}
		return false;
}

int char_in_string(char a, const char*s){
	int x=0;
	while(s[x]!='\0'){
		if(s[x]==a){
			return x;
		}
		x++;
	}
	return -1;
}

bool BMH(const char *T, const char*P){
	int v=strlen(P),i=v-1;
	while(i<strlen(T)){
		int k=v-1;
		while(k>-1 && T[i]==P[k]){
			i--;
			k--;
		}
		if(k<0){
			return true;
		}else{
			int x=char_in_string(T[i],P);
			if(x<0){
				i=i+v;
			}else{
				i=i+v-x-1;
			}
		}
	}
	return false;
}
int main(){
	int n=7;
	string d[]={"hi","hello","nice","yeah","yes","no","childl"};
	Sort(d,n);
	for(int i=0;i<n;i++){
		cout<<d[i]<<" ";
	}
	int s[100];
	int k=11;
	if(G(d,n,k,s)){
		cout<<"\nXau ki tu lay!!!"<<endl;
		for(int i=0;i<n;i++){
			if(s[i]>0)
				cout<<d[i]<<" co do dai: "<<d[i].length()<<endl;
		}
	}else{
		cout<<"\nKhong tim duoc bang tham lam!!!"<<endl;
	}
	
	char *P="child";
	int dem=0;
	cout<<"\nSo xau lay!!"<<endl;
	for(int i=0;i<n;i++){
		if(BMH(d[i].c_str(),P)){
			cout<<d[i]<<endl;
			dem++;
		}
	}
	cout<<"\nTong so xau chua "<<P<<":"<<dem<<endl;

}
