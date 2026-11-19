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
