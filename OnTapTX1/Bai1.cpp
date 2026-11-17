//Bai1 Cach1: Phuong Phap Sinh 

#include <bits/stdc++.h>
using namespace std;

// Danh sach 4 nguoi, danh cho vi tri 0 de dung chi so tu 1
string S[] = {"", "tung", "cuc", "truc", "mai"};

// Danh sach 4 ghe: A, B, C, D
char G[] = {'A', 'B', 'C', 'D'};

// Ham doi cho hai phan tu
void swap(int &a, int &b)
{
    int tg = a;
    a = b;
    b = tg;
}

// Ham hien thi mot cach xep
void view_config(int x[], int n)
{
    // Nguoi thu i ngoi ghe duoc danh dau boi x[i]
    for (int i = 1; i <= n; i++)
    {
        cout << S[i] << " ngoi ghe " << G[x[i] - 1] << "; ";
    }
    cout << endl;
}

// Ham sinh cau hinh tiep theo
void next_config(int x[], int n, int i)
{
    // Tim phan tu x[k] dau tien tu ben phai
    // lon hon x[i] hoac bang x[i]
    int k = n;
    while (x[k] < x[i])
    {
        k--;
    }

    // Doi cho x[i] va x[k]
    swap(x[i], x[k]);

    // Dao nguoc phan day tu i+1 den n
    int j = n;
    i++;

    while (i < j)
    {
        swap(x[i], x[j]);
        i++;
        j--;
    }
}

// Ham liet ke tat ca cac hoan vi
void listing_configs(int n)
{
    int i, x[5] = {0};

    // Khoi tao hoan vi dau tien: 1, 2, 3, 4
    for (int i = 1; i <= n; i++)
    {
        x[i] = i;
    }

    // Bien dem so cach xep
    int dem = 0;

    do
    {
        // Hien thi cau hinh hien tai
        view_config(x, n);
        dem++;

        // Tim vi tri i dau tien tu phai sang trai
        // sao cho x[i] < x[i+1]
        i = n - 1;
        while (i > 0 && x[i] > x[i + 1])
        {
            i--;
        }

        // Neu i > 0 thi van con hoan vi tiep theo
        if (i > 0)
        {
            next_config(x, n, i);
        }

    } while (i > 0); // Dung khi da den hoan vi cuoi cung

    // Hien thi tong so cach xep
    cout << "Tong so cach xep: " << dem << endl;
}

int main()
{
    // Co 4 nguoi va 4 ghe
    listing_configs(4);

    return 0;
}


//Cach 2: Thuat toan quay lui
/*

#include <bits/stdc++.h>
using namespace std;

char S[] = {'A', 'B', 'C', 'D'};
string N[] = {"tung", "cuc", "truc", "mai"};
int x[5];
bool dd[5];
int dem = 0;

void show()
{
    for (int i = 1; i <= 4; i++)
    {
        cout << N[i - 1] << " ngoi ghe " << S[x[i]] << "; ";
    }
    cout << endl;
}

void Try(int i)
{
    for (int j = 0; j < 4; j++)
    {
        if (dd[j] == false)
        {
            x[i] = j;

            if (i == 4)
            {
                show();
                dem++;
            }
            else
            {
                dd[j] = true;
                Try(i + 1);
                dd[j] = false;
            }
        }
    }
}

int main()
{
    Try(1);

    cout << "Tong so cach xep: " << dem << endl;

    return 0;
}
*/

