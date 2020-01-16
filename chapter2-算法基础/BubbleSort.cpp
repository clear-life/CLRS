#include <iostream>
#include <stdio.h>

using namespace std;

void BubbleSort(int A[], int l, int r);

int main()
{
    long n;
    //输入
    cin>>n;
    int A[n];
    for(long i = 0; i < n; i++)
        cin >> A[i];
    //插入排序
    BubbleSort(A, 0, n - 1);
    //输出
    for(int i = 0; i < n; i++)
    {
        if(i != 0)
            printf(" ");
        printf("%d",A[i]);
    }

    return 0;
}

void BubbleSort(int A[], int l, int r)
{
    if(l <= r)
    {
        for(int i = l; i < r; i++)//循环不变式：A[l..i-1]包含A中最小的i-l个数，且排好序
        {
            for(int j = r; j >= i + 1; j--)//循环不变式：A[j..n]是原来的一个排列，且A[j]是最小的
            {
                if(A[j - 1] > A[j])
                {
                    int tem = A[j - 1];
                    A[j - 1] = A[j];
                    A[j] = tem;
                }
            }
        }
    }
}




