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
	char *P1="abc";
	
	if(BMH(T,P1)){
		cout<<"P1:Yes"<<endl;
	}else{
		cout<<"P1:NO";
	}
	
}



//Caitui
#include<bits/stdc++.h>
using namespace std;

struct Hang{
	int STT;
	int w;
	int v;
};

void QHD(Hang a[],int n,int m, int F[][100]){
	for(int i=0;i<=n;i++){
		F[i][0]=0;
	}
	for(int j=0;j<=m;j++){
		F[0][j]=0;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			F[i][j]=F[i-1][j];
			
			if(a[i-1].w<=j){
				F[i][j]=max(F[i][j],F[i-1][j-a[i-1].w]+a[i-1].v);
			}
		}
	}
}

int Truyvet(Hang a[], int n, int m,int F[][100],int x[]){
	int dem=0;
	int i=n,j=m;
	while(i>0 && j>0){
		if(F[i][j]!=F[i-1][j]){
			x[dem++]=i-1;
			j-=a[i-1].w;
		}
		i--;
	}
	return dem;
}

void Xuat(Hang a[], int x[], int dem, int gtmax){
	cout<<"\nCac goi hang duoc chon:";
	
	for(int i=dem-1;i>=0;i--){
		cout<<"\nSTT:"<<a[x[i]].STT<<"Khoi luong:"<<a[x[i]].w<<"Gia tri:"<<a[x[i]].v<<endl;
	}
	cout<<"\nTong so hang lay duoc:"<<dem<<endl;
	cout<<"\nGia tri lon nhat duoc:"<<gtmax<<endl;
}
const int MAX=12;
int main(){
	int n=6;
	Hang a[n]={
		{1,5,13},
		{2,6,14},
		{3,7,15},
		{4,2,11},
		{5,3,17},
		{6,5,14}
	};
	int m=12;
	int F[100][100];
	QHD(a,n,m,F);
	int x[100];
	int dem=Truyvet(a,n,m,F,x);
	Xuat(a,x,dem,F[n][m]);
}



//Doitien
#include<bits/stdc++.h>
using namespace std;

void coin_changing(int c[], int n, int m, int f[], int s[]){
    f[0] = 0;

    for(int i=1;i<=m;i++){
        int Min = INT_MAX;

        for(int j=0;j<n;j++){
            if(c[j] <= i && f[i-c[j]] + 1 < Min){
                Min = f[i-c[j]] + 1;
                s[i] = j;
            
			}
			
        }
		  f[i] = Min;
    }
}

void truyvet(int c[], int s[], int m, int dem[]){
    while(m > 0){
        dem[s[m]]++;
        m -= c[s[m]];
    }
}

void xuat(int c[], int dem[], int n, int f[], int m){
    cout << "\nSo to tien it nhat: " << f[m] << endl;

    cout << "\nPhuong an doi tien:\n";

    for(int i=0;i<n;i++){
        if(dem[i] > 0){
            cout << c[i] << " : " << dem[i] << " to" << endl;
        }
    }
}

int main(){
    int c[]= {1, 2, 5, 10, 20};
//int c[100];
    int n = 5;
//    for (int i=0;i<n;i++){
//    	cout<<"\nNhap c["<<i<<"]=:";
//    	cin>>c[i];
//	}

    int m;
    cout << "Nhap so tien can doi: ";
    cin >> m;

    int f[1000];
    int s[1000];
    int dem[100];

    for(int i=0;i<100;i++)
        dem[i] = 0;

    coin_changing(c, n, m, f, s);

    truyvet(c, s, m, dem);

    xuat(c, dem, n, f, m);

    return 0;
}



//Day con tang
#include<bits/stdc++.h>
using namespace std;

void QHD(int a[],int L[], int T[],int n){
	a[0]=-10000000;
	a[n+1]=1000000;
	L[n+1]=1;
	for(int i=n;i>=0;i--){
		int jmax=n+1;
		for(int j=i+1;j<=n+1;j++){
			if(a[j]>a[i]&& L[j]>L[jmax]){
				jmax=j;
			}
		}
		L[i]=L[jmax]+1;
		T[i]=jmax;
		
	}
}

void Truyvet(int a[],int T[],int n){
	int k=T[0];
	cout<<"\nDay con:";
	while(k!=n+1){
		cout<<"a["<<k<<"]:"<<a[k]<<" ";
		k=T[k];
	}
}

int main(){
	int n=6;
	int a[]={0,1,2,5,3,6,7,0};
	int L[100];
	int T[100];
	
	QHD(a,L,T,n);
	
	Truyvet(a,T,n);
	
}



//phan tich tong
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



//xau con chung dai nhat
#include <bits/stdc++.h>
using namespace std;

#define MAX 100

// Quy hoach dong
int LCS(char X[], char Y[], int dp[][MAX])
{
    int n = strlen(X);
    int m = strlen(Y);

    // Khoi tao
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;

    // Lap bang quy hoach dong
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j],
                               dp[i][j - 1]);
        }
    }

    return dp[n][m];
}

// Dao xau
void DaoXau(char s[])
{
    int n = strlen(s);

    for (int i = 0; i < n / 2; i++)
    {
        char temp = s[i];
        s[i] = s[n - 1 - i];
        s[n - 1 - i] = temp;
    }
}

// Truy vet
void TruyVet(char X[], char Y[], int dp[][MAX], char xC[])
{
    int i = strlen(X);
    int j = strlen(Y);
    int k = 0;

    while (dp[i][j] != 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            xC[k] = X[i - 1];
            k++;

            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }
    }

    xC[k] = '\0';

    // Dao lai vi truy vet tu cuoi ve dau
    DaoXau(xC);
}

// Xuat bang
void XuatBang(char dp[][MAX], int n, int m)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
            cout << setw(4) << dp[i][j];

        cout << endl;
    }
}

int main()
{
    char X[MAX], Y[MAX];
    int dp[MAX][MAX];
    char xC[MAX];

    cout << "Nhap xau X: ";
    cin.getline(X, MAX);

    cout << "Nhap xau Y: ";
    cin.getline(Y, MAX);

    int kq = LCS(X, Y, dp);

    cout << "\nDo dai xau con chung dai nhat: " << kq << endl;

    TruyVet(X, Y, dp, xC);

    cout << "Xau con chung dai nhat: " << xC << endl;

    return 0;
}


