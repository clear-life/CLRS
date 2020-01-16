#include <iostream>
#include <stdio.h>

using namespace std;

long  MergesortInversion(int A[],long l, long r);//归并排序并计数逆序对
long Combine(int A[],long l, long mid, long r);//合并两个有序子数组的逆序对个数

int main()
{
    long n;
    //输入
    cin>>n;
    int A[n];
    for(long i = 0; i < n; i++)
        cin >> A[i];
    //插入排序
    long count = MergesortInversion(A, 0, n - 1);
    //输出
    cout << count << endl;
    /*for(int i = 0; i < n; i++)
    {
        if(i != 0)
            printf(" ");
        printf("%d",A[i]);
    }*/

    return 0;
}

long MergesortInversion(int A[],long l, long r)
{
    if(l < r)
    {
        long mid = (l + r) / 2;
        long c1 = MergesortInversion(A, l, mid);
        long c2 = MergesortInversion(A, mid + 1, r);
        long c3 = Combine(A, l, mid, r);
        return c1 + c2 + c3;
    }
    return 0;
}

long Combine(int A[],long l, long mid, long r)
{
    long n1 = mid - l + 1;
    long n2 = r - mid;
    int B[n1],C[n2];

    for(long i = 0; i < n1; i++)
    {
        B[i] = A[l + i];
    }
    for(long i = 0; i < n2; i++)
    {
        C[i] = A[mid + i + 1];
    }

    long i = 0, j = 0, count = 0;
    for(long k = l; k <= r; k++)//循环不变式：count的值为从<*,0>到<*,j-1>的所有逆序对的个数
    {
        if(i >= n1)
            A[k] = C[j++];
        else if(j >= n2)
            A[k] = B[i++];
        else if(B[i] <= C[j])
            A[k] = B[i++];
        else
        {
            A[k] = C[j++];
            count += n1 - i;
        }
    }
    return count;
}










