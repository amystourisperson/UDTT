#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int DemNghichDao_DeQuy(int A[], int index, int n) {
    if (index == n - 1) {
        return 0;
    }
    
    int count = 0;
    for (int j = index + 1; j < n; j++) {
        if (A[index] > A[j]) {
            count++;
        }
    }
    
    return count + DemNghichDao_DeQuy(A, index + 1, n);
}



long long MergeAndCount(int A[], int temp[], int left, int mid, int right) {
    int i = left;     
    int j = mid + 1;   
    int k = left;    
    long long count = 0;

    while (i <= mid && j <= right) {
        if (A[i] <= A[j]) {
            temp[k++] = A[i++];
        } else {
            temp[k++] = A[j++];
            count += (mid - i + 1); 
        }
    }

    while (i <= mid) {
        temp[k++] = A[i++];
    }

    while (j <= right) {
        temp[k++] = A[j++];
    }

    for (i = left; i <= right; i++) {
        A[i] = temp[i];
    }

    return count;
}

long long DemNghichDao_ChiaDeTri(int A[], int temp[], int left, int right) {
    long long count = 0;
    if (left < right) {
        int mid = (left + right) / 2;

        count += DemNghichDao_ChiaDeTri(A, temp, left, mid);
        
        count += DemNghichDao_ChiaDeTri(A, temp, mid + 1, right);
        
        count += MergeAndCount(A, temp, left, mid, right);
    }
    return count;
}

int main() {
    srand(time(0));
    
    int n = 20; 
    int A[100];
    int B[100]; 
    int temp[100];
    cout << "Mang A gom " << n << " phan tu ngau nhien (am va duong):\n";
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 100 - 50; 
        B[i] = A[i]; 
        cout << A[i] << " ";
    }
    cout << "\n\n";

    long long kq_DeQuy = DemNghichDao_DeQuy(A, 0, n);
    cout << "So cap nghich dao (Phuong phap De quy): " << kq_DeQuy << "\n";

    long long kq_ChiaDeTri = DemNghichDao_ChiaDeTri(B, temp, 0, n - 1);
    cout << "So cap nghich dao (Phuong phap Chia de tri): " << kq_ChiaDeTri << "\n";

    return 0;
}
