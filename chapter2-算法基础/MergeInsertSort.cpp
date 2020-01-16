#include <iostream>
#include <stdio.h>

using namespace std;

int k = 5;

void InsertSort(int A[], int l, int r);
void MergeInsertSort(int A[],int l, int r);
void Merge(int A[], int l, int mid, int r);

int main()
{
    long n;
    //输入
    cin>>n;
    int A[n];
    for(long i = 0; i < n; i++)
        cin >> A[i];
    //插入排序
    MergeInsertSort(A, 0, n - 1);
    //输出
    for(int i = 0; i < n; i++)
    {
        if(i != 0)
            printf(" ");
        printf("%d",A[i]);
    }

    return 0;
}

void InsertSort(int A[], int l, int r)
{
    if(l <= r)
    {
        for(int j = l + 1; j <= r; j++)
        {
            int key = A[j];
            int i = j - 1;
            while(i >= l && A[i] > key)
            {
                A[i + 1] = A[i];
                i--;
            }
            A[i + 1] = key;
        }
    }
}

void MergeInsertSort(int A[],int l, int r)
{
    if(l <= r)
    {
        if(r - l + 1 > k)
        {
            int mid = (l + r) / 2;
            MergeInsertSort(A, l, mid);
            MergeInsertSort(A, mid + 1, r);
            Merge(A, l, mid, r);
        }
        else
            InsertSort(A, l, r);
    }
}

void Merge(int A[],int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int B[n1],C[n2];

    for(int i = 0; i < n1; i++)
        B[i] = A[l + i];
    for(int i = 0; i < n2; i++)
        C[i] = A[mid + i + 1];

    int i = 0, j = 0;
    for(int k = l; k <= r; k++)
    {
        if(i >= n1)
            A[k] = C[j++];
        else if(j >= n2)
            A[k] = B[i++];
        else if(B[i] <= C[j])
            A[k] = B[i++];
        else
            A[k] = C[j++];
    }
}






