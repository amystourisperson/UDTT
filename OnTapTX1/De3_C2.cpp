/* Chia de tri va De quy
Bai: Dem so cap phan tu nghich dao cua mang A
- Khoi tao danh sach a gom toi thieu 20 so gom ca am va duong
- Dem so cap phan tu nghich dao theo chien luoc de quy
- Dem so cap phan tu nghich dao theo chien luoc chia de tri (giong cau truc file BTTH3.2.cpp)
- Hien thi ket qua
*/
#include <iostream>
using namespace std;

// Mang phu toan cuc giong file BTTH3.2.cpp
int b[100];

// 1. Thuat toan dem cap nghich dao theo chien luoc de quy
int DeQuy(int a[], int i, int n)
{
    if (i >= n)
        return 0;

    int count = 0;
    for (int j = i + 1; j <= n; j++)
    {
        if (a[i] > a[j])
            count++;
    }

    return count + DeQuy(a, i + 1, n);
}

// 2. Thuat toan dem cap nghich dao theo chien luoc chia de tri (dung mang b toan cuc giong BTTH3.2.cpp)
long long MergeSortAndCount(int a[], int l, int r)
{
    long long invCount = 0;
    if (r > l)
    {
        int m = (l + r) / 2;

        // Sap xep va dem nua dau
        invCount += MergeSortAndCount(a, l, m);

        // Sap xep va dem nua sau
        invCount += MergeSortAndCount(a, m + 1, r);

        // Sao chep nua dau cua a sang b (giong BTTH3.2.cpp)
        for (int i = l; i <= m; i++)
            b[i] = a[i];

        // Sao chep nua con lai cua a sang b theo thu tu nguoc lai (giong BTTH3.2.cpp)
        for (int j = m + 1; j <= r; j++)
            b[r + m + 1 - j] = a[j];

        // i chay tu dau, j chay tu cuoi va tron (giong BTTH3.2.cpp)
        int i = l;
        int j = r;

        for (int k = l; k <= r; k++)
        {
            if (b[i] <= b[j])
            {
                a[k] = b[i];
                i++;
            }
            else
            {
                a[k] = b[j];
                j--;
                // Phan mo rong de dem so cap nghich dao:
                // Khi b[j] duoc chon vi nho hon b[i], tat ca cac phan tu tu i den m 
                // o nua dau deu lon hon b[j], tao thanh (m - i + 1) cap nghich dao.
                invCount += (m - i + 1);
            }
        }
    }
    return invCount;
}

int main()
{
    int n = 20;

    // Khoi tao mang a gom 20 so gom ca am va duong (chi so tu 1 den n, bo qua a[0])
    int a1[100] = {
        0,
        5, -2, 8, 3, -1,
        9, 0, -4, 6, 2,
        -5, 7, 1, -3, 4,
        -6, 10, 2, -7, 6
    };

    // Tao ban sao mang a de phuong phap chia de tri khong lam thay doi thu tu a1 cua de quy
    int a2[100];
    for (int i = 0; i <= n; i++)
    {
        a2[i] = a1[i];
    }

    cout << "Danh sach ban dau:\n";
    for (int i = 1; i <= n; i++)
        cout << a1[i] << " ";
    cout << endl;

    // Thuc hien dem theo chien luoc de quy
    int kqDeQuy = DeQuy(a1, 1, n);
    cout << "\nSo cap phan tu nghich dao (theo chien luoc de quy): " << kqDeQuy << endl;

    // Thuc hien dem theo chien luoc chia de tri
    long long kqChiaDeTri = MergeSortAndCount(a2, 1, n);
    cout << "So cap phan tu nghich dao (theo chien luoc chia de tri): " << kqChiaDeTri << endl;

    return 0;
}
