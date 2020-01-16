#include <iostream>
#include <stdio.h>

using namespace std;

int Horner(int A[], int x, int n);

int main()
{
    long n;
    //输入
    cin>>n;
    int A[n + 1];
    for(long i = 0; i <= n; i++)
        cin >> A[i];
    int x;
    cin >> x;
    //插入排序
    cout << Horner(A, x, n) << endl;
    //输出
    /*for(int i = 0; i < n; i++)
    {
        if(i != 0)
            printf(" ");
        printf("%d",A[i]);
    }*/

    return 0;
}

int Horner(int A[], int x, int n)
{
    int y = 0;
    for(int i = n; i >= 0; i--)//循环不变式：y = (k = 0 to n-(i+1))a(k+i+1)x^k;
        y = A[i] + x * y;
    return y;
}




