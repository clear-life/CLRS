#include <iostream>
#include <stdio.h>

using namespace std;

void MergeSort(int A[],int l,int r);
void Merge(int A[],int l,int mid,int r);

int main()
{
    int n;
    //输入
    cin>>n;
    int A[n];
    for(int i = 0; i < n; i++)
        cin >> A[i];
    //插入排序
    MergeSort(A,0,n-1);
    //输出
    for(int i = 0; i < n; i++)
    {
        if(i != 0)
            printf(" ");
        printf("%d",A[i]);
    }

    return 0;
}

void MergeSort(int A[],int l,int r)
{
    if(l < r)
    {
        int mid = (l + r) / 2;

        MergeSort(A,l,mid);
        MergeSort(A,mid + 1,r);
        Merge(A, l, mid, r);
    }
}

void Merge(int A[],int l,int mid,int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int B[n1],C[n2];

    //转移数组
    for(int i = 0; i < n1; i++)
    {
        B[i] = A[l + i];
    }
    for(int i = 0; i < n2; i++)
    {
        C[i] = A[mid + i + 1];
    }
    //开始合并，从l到r的转移
    int i = 0, j = 0;

    for(int k = l; k <= r; k++)//循环不变式：A[l..k-1]为合并好的部分
    {
        //判断是否把其中一个数组转移完毕
        /*if(i >= n1)
        {
            A[k] = C[j++];
            continue;
        }
        if(j >= n2)
        {
            A[k] = B[i++];
            continue;
        }
        //比较两个数组中的小值，转移到目标数组
        if(B[i] <= C[j])
        {
            A[k] = B[i++];
        }
        else
        {
            A[k] = C[j++];
        }*/
        if(i >= n1)
            A[k] = C[j++];
        else if(j >= n2)
            A[k] = B[i++];
        else if(B[i] < C[j])
            A[k] = B[i++];
        else
            A[k] = C[j++];
    }
}













