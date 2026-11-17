#include <bits/stdc++.h>
using namespace std;
/*
Ham	                       Nhiem vu
swap(a, b)	            Ðoi cho hai phan tu
view_config(x, n)   	In hoan vi hien tai
next_config(x, n, i)	Sinh hoan vi ke tiep
listing_configs(n)    	Khoi tao và liet ke toan bo hoan vi
*/
// =====================================================
// BAI 1: LIET KE DAY NHI PHAN
// =====================================================

// Ham sinh cau hinh nhi phan tiep theo
// x[i] = 1: tang vi tri i len 1
// Cac vi tri phia sau i duoc gan bang 0
// void next_config(int x[], int n, int i){
//     x[i] = 1;
//     i++;
//     while(i <= n){
//         x[i] = 0;
//         i++;
//     }
// }

// Ham in cau hinh nhi phan hien tai
// void view_config(int x[], int n){
//     for(int i = 1; i <= n; i++)
//         cout << x[i];
//     cout << endl;
// }

// Ham liet ke tat ca day nhi phan co do dai n
// void listing_configs(int n){
//     int i;  //Bien dung de tim vi tri bit can doi 
//     int x[n+1] = {0};  // Khoi tao day dau tien: 00...0
//
//     do{
//         view_config(x, n);  // In cau hinh hien tai
//
//         i = n;              // Bat dau tim tu vi tri cuoi (duyet tu phai sang trai)
//
//         // Bo qua cac bit 1 lien tiep o cuoi day
//         while(i > 0 && x[i] == 1){  //neu bit hien tai == 1 tiep tuc lui sang trai
//             i--;  //bo qua cac bit 1 de tim bit 0
//         }
//
//         // Neu i > 0 thi van con cau hinh tiep theo
//         if(i > 0){
//             next_config(x, n, i);  //doi bit 0 thanh 1 va dua cac bit ben phai thanh 0
//         }
//
//     }while(i > 0); // Dung khi tat ca cac bit deu bang 1
// }

// int main(){
//     int n;
//     cout << "Nhap do dai day nhi phan: ";
//     cin >> n;
//
//     listing_configs(n);
//     return 0;
// }


// =====================================================
// BAI 2: LIET KE CAC TAP CON K PHAN TU
// =====================================================

// Ham sinh tap con tiep theo
// x[] luu cac phan tu duoc chon, theo thu tu tang dan
// Vi du: x = {1, 2, 4}, k = 3 (k: so ptu can chon)
// Neu i = 2 thi tang x[2], sau do cap nhat cac vi tri sau
// void next_config(int x[], int k, int i){
//   //i: vi tri tang len de tao tap con tiep theo 
//     x[i] += 1;  // Tang phan tu tai vi tri i len 1
//     i++; //chuyen sang vtri ke tiep
//
//     // Cac phan tu phia sau phai tang dan
//     // Moi phan tu bang phan tu truoc no cong 1
//     while(i <= k){ 
//         x[i] = x[i-1] + 1;
//         i++;
//     }
// }

// Ham in tap con hien tai
// void view_config(int x[], int k){
//     for(int i = 1; i <= k; i++)
//         cout << x[i] << " ";
//     cout << endl;
// }

// Ham liet ke tat ca tap con k phan tu cua tap co n phan tu
// void listing_configs(int k, int n){
//     int i, x[k+1] = {0}; //i: Bien xd vtri can doi
//
//     // Khoi tao tap con dau tien: 1, 2, ..., k
//     for(int i = 1; i <= k; i++){
//         x[i] = i;
//     }
//
//     do{
//         view_config(x, k);  // In tap con hien tai
//
//         i = k;  // Bat dau xet tu phan tu cuoi cung
//         //Chi khi phan tu o cuoi lon nhat thi moi phai lui ve ptu dung trc
//         // Neu x[i] da dat gia tri lon nhat n-k+i
//         // thi lui ve vi tri truoc de tim vi tri co the tang
//         while(i > 0 && x[i] == n-k+i){
			//x[i] == n-k+i : Dam bao phan tu thu i dat gia tri lon nhat 
			//vd: x[1] = 3 vi x[2] se la 4, x[3] = 5
//             i--;
//         }  //xet tu thang x[3] no ch phai la lon nhat
//
//         // Neu tim duoc vi tri i thi sinh tap con tiep theo
//         if(i > 0){
//             next_config(x, k, i);
//         }
//
//     }while(i > 0); // Dung khi khong con tap con tiep theo
// }

// int main(){
//     int n;
//     cout << "\nNhap do dai tap S: ";
//     cin >> n;
//
//     int k;
//     cout << "\nNhap so phan tu cua tap con: ";
//     cin >> k;
//
//     listing_configs(k, n);
//     return 0;
// }


// =====================================================
// BAI 3: LIET KE HOAN VI
// =====================================================

// Ham doi cho hai gia tri a va b
void swap(int &a, int &b){
    int tg = a;  // Luu gia tri a vao bien tam
    a = b;       // Gan b cho a
    b = tg;      // Gan gia tri ban dau cua a cho b
}

// Ham in hoan vi hien tai
void view_config(int x[], int n){
    // Mang x su dung cac vi tri tu 1 den n
    for(int i = 1; i <= n; i++)
        cout << x[i];
    cout << endl;
}

// Ham sinh hoan vi tiep theo
// x[]: hoan vi hien tai
// n: so phan tu
// i: vi tri can doi cho
void next_config(int x[], int n, int i){

    int k = n;  // Bat dau tim tu vi tri cuoi cung de tim ptu co gtri > x[i]

    // Tim tu ben phai phan tu dau tien lon hon x[i]
    // Doan phia sau i dang co thu tu giam dan
    while(x[k] < x[i]){
        k--;
    } //khi vong lap dung ta tim dc ptu > x[i]

    // Doi x[i] voi phan tu tim duoc x[k]
    // Muc dich: tang hoan vi len nho nhat co the
    swap(x[i], x[k]);

//doan phia sau vtri i chua chac da tang dan, nen ta can them buoc dao nguoc
    int j = n; //bat dau tu ptu cuoi
    i++;  // chuyen sang vtri ngay sau vi tri chot ban dau
//Muc dich la xd vi tri can dao nguoc tu i+1 -> n
    // Dao nguoc doan x[i] den x[n]
    // Vi doan nay dang giam dan nen dao nguoc se tang dan
    while(i < j){
        swap(x[i], x[j]);
        i++;
        j--;
    } //dung khi thang i va j gap nhau hoac vuot qua nhau
}

// Ham liet ke tat ca hoan vi cua day 1, 2, ..., n
void listing_configs(int n){

    int i, x[n+1] = {0};

    // Khoi tao hoan vi dau tien: 1, 2, ..., n
    for(int i = 1; i <= n; i++){
        x[i] = i;
    }

    do{
        view_config(x, n);  // In hoan vi hien tai

        i = n - 1;  // Bat dau tim tu vi tri gan cuoi

        // Tim vi tri i dau tien tu phai sang trai
        // thoa man x[i] < x[i+1]
        // Cac phan tu sau i dang sap xep giam dan
        while(i > 0 && x[i] > x[i+1]){
            i--;
        }

        // Neu i > 0 thi van con hoan vi tiep theo
        if(i > 0){
            next_config(x, n, i);
        }

    }while(i > 0); // Dung khi khong tim duoc vi tri i
                   // Khi do hoan vi hien tai la n, n-1, ..., 1
}

int main(){
    int n;

    cout << "\nNhap do dai tap S: ";
    cin >> n;

    listing_configs(n);  // Goi ham liet ke hoan vi

    return 0;
}
