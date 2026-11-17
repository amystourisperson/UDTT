//Bai 2
#include <bits/stdc++.h>
//PPS

#include <bits/stdc++.h>
using namespace std;

char S[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

// Ham hien thi mot cau hinh gom k ky tu
void view_config(int x[], int k)
{
    for (int i = 1; i <= k; i++)
        cout << S[x[i] - 1] << " ";

    cout << endl;
}

// Ham sinh cau hinh tiep theo
void next_config(int x[], int k, int i)
{
    // Tang phan tu tai vi tri i len 1
    x[i] +=1;

    // Cap nhat cac phan tu phia sau
    // moi phan tu sau bang phan tu truoc cong 1
    i++;
    while (i <= k)
    {
        x[i] = x[i - 1] + 1;
        i++;
    }
}

// Ham liet ke cac tap con k phan tu cua tap n phan tu
void listing_configs(int k, int n)
{
    int i, x[7] = {0};

    // Khoi tao cau hinh dau tien: 1, 2, ..., k
    for (int i = 1; i <= k; i++)
        x[i] = i;

    int dem = 0;

    do
    {
        // Hien thi tap con hien tai
        view_config(x, k);
        dem++;

        // Tim vi tri i co the tang them
        i = k;
        while (i > 0 && x[i] == n - k + i)
            i--;

        // Neu tim duoc vi tri i thi sinh cau hinh tiep theo
        if (i > 0)
            next_config(x, k, i);

    } while (i > 0);

    cout << "Tong so cach lay: " << dem << endl;
}

int main()
{
    // Lay 6 ky tu tu tap gom 7 ky tu
    listing_configs(6, 7);

    return 0;
}

/* 

#include <bits/stdc++.h>
using namespace std;

char S[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
int x[7];
int dem = 0;

// Ham hien thi mot tap con gom 6 ky tu
void show()
{
    for (int i = 1; i <= 6; i++)
        cout << S[x[i] - 1] << " ";

    cout << endl;
}

// Ham quay lui chon ky tu thu i
void Try(int i)
{
    // Thu cac ky tu co chi so lon hon ky tu truoc
    for (int j = x[i - 1] + 1; j <= 7 - 6 + i; j++)
    {
        x[i] = j;

        // Neu da chon du 6 ky tu thi hien thi
        if (i == 6)
        {
            show();
            dem++;
        }
        else
        {
            // Neu chua du thi chon ky tu tiep theo
            Try(i + 1);
        }
    }
}

int main()
{
    // Gia tri khoi tao de ky tu dau tien co the la A
    x[0] = 0;

    Try(1);

    cout << "Tong so cach lay: " << dem << endl;

    return 0;
}

*/
