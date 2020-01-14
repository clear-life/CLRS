#include <iostream>
#include <stdio.h>

using namespace std;

void InsertSort(int A[],int n);

int main()
{
    int A[1000],n;
    //输入
    cin>>n;
    for(int i = 0; i < n; i++)
        cin >> A[i];
    //插入排序
    InsertSort(A,n);
    //输出
    for(int i = 0; i < n; i++)
    {
        if(i != 0)
            printf(" ");
        printf("%d",A[i]);
    }

    return 0;
}

void InsertSort(int A[],int n)
{
    for(int j = 1; j < n; j++)  //循环不变式:A[1..j]由原来的前j个元素组成，且排好序
    {
        int key = A[j];         //为A[j]找到合适的位置
        int i = j - 1;
        while(i >= 0 && A[i] > key)
        {
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
}
