/*

*/
//CÂU I. Sinh hoán vi ke tiep
#include <bits/stdc++.h>
using namespace std;

// Ham doi cho hai phan tu
void swap(int &a, int &b)
{
    int tg = a;
    a = b;
    b = tg;
}

// Ham sinh hoan vi tiep theo
void next_config(int x[], int n, int i)
{
    // Tim phan tu x[k] dau tien tu ben phai
    // lon hon x[i]
    int k = n;

    while (x[k] < x[i])
    {
        k--;
    }

    // Doi cho x[i] va x[k]
    swap(x[i], x[k]);

    // Dao nguoc day con phia sau vi tri i
    int j = n;
    i++;

    while (i < j)
    {
        swap(x[i], x[j]);
        i++;
        j--;
    }
}

int main()
{
    int n, x[1005];

    cout << "Nhap N: ";
    cin >> n;

    cout << "Nhap hoan vi X: ";
    for (int i = 1; i <= n; i++)
        cin >> x[i];

    // Tim vi tri i dau tien tu phai sang trai
    // thoa man x[i] < x[i+1]
    int i = n - 1;

    while (i > 0 && x[i] > x[i + 1])
    {
        i--;
    }

    // Neu i = 0 thi X la hoan vi cuoi cung
    if (i == 0)
    {
        cout << "Khong co hoan vi tiep theo.";
    }
    else
    {
        // Sinh hoan vi tiep theo
        next_config(x, n, i);

        cout << "Hoan vi tiep theo: ";
        for (int i = 1; i <= n; i++)
            cout << x[i] << " ";
    }

    return 0;
}

/*
//CÂU II. De quy va chia de tri

#include <bits/stdc++.h>
using namespace std;



*/
