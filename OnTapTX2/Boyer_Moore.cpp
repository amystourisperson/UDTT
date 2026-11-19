#include<bits/stdc++.h>
using namespace std;
int char_in_string(char a,const char*s){
	int x=0;
	while(s[x]!='\0'){
		if(s[x]==a){
			return x;
		}
		x++;
	}
	return -1;
}
bool BMH(const char*T, const char*P){
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
	char *T="abcdefgh";
	char *P1="fgh";
	
	if(BMH(T,P1)){
		cout<<"P1:Yes"<<endl;
	}else{
		cout<<"P1:NO";
	}
	
}
