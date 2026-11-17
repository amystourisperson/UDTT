//Bai4
#include<bits/stdc++.h>
using namespace std;

struct Chuyenbay{
	char sohieu[30];
	int giave;
	int seat;
};

const int MAX=10;

void out(Chuyenbay ds[],int n){
	cout<<"SO hieu"<<setw(10)<<"Gia ve"<<setw(10)<<"So ghe"<<endl;
	for(int i=0;i<n;i++){
		cout<<ds[i].sohieu<<setw(10)<<ds[i].giave<<setw(10)<<ds[i].seat<<endl;
	}
}

int Dem(Chuyenbay ds[],int n,int i){
	if(i==n)	return 0 ;
	if(ds[i].giave>700000){
		cout << ds[i].sohieu
             << setw(10) << ds[i].giave
             << setw(10) << ds[i].seat << endl;
             return 1+Dem(ds,n,i+1);
	}
	return Dem(ds,n,i+1);
}

int find_min(Chuyenbay ds[],int l, int r){
	if(l==r)	return l;
	int mid=(l+r)/2;
	int left=find_min(ds,l,mid);
	int right=find_min(ds,mid+1,r);
	
	if(ds[left].giave<ds[right].giave){
		return left;
	}
	return right;
}
int x[MAX];
void inPA(Chuyenbay ds[]){
    for(int i = 1; i <= 4; i++)
        cout << ds[x[i]-1].sohieu << " ";
    cout << endl;
}
int y=0;
void find_chuyen(Chuyenbay ds[], int i,int n){
	for(int j=x[i-1]+1; j<=n-4+i;j++){
		x[i]=j;
	if(i==4){
		inPA(ds);
		y++;
	}else{
		find_chuyen(ds,i+1,n);
	}
}
}
int main(){
	 Chuyenbay ds[MAX] = {
        {"VN001", 650000, 180},
        {"VN002", 720000, 200},
        {"VN003", 850000, 160},
        {"VN004", 950000, 220},
        {"VN005",1100000, 190},
        {"VN006",1300000, 250},
        {"VN007",1500000, 170}
    };

    int n=7;
    cout<<"\nDanh sach chuyen bay!!!"<<endl;
    out(ds,n);
//    cout<<"\nDanh sach so chuyen hop le!!!"<<endl;
//	int tong=Dem(ds,n,0);
//	cout<<"\nSo chuyen:"<<tong<<endl;
//	
//	cout<<"\nVe Min!!"<<endl;
//	int vt=find_min(ds,0,n-1);
//		cout << ds[vt].sohieu
//             << setw(10) << ds[vt].giave
//             << setw(10) << ds[vt].seat << endl;


find_chuyen(ds,1,n);
cout<<y;
}
	

