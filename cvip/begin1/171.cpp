#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;
int fibo[1000];
int l[50000][31]; //46366
int m = 23;
void Hoai_Thuong()
{
    memset(l, 0, sizeof(l));
    long long sum=0;
    fibo[1] = fibo[2] = 1;
    l[fibo[2]][2] = 1;
    for (int i = 3; i <= m; i++)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
        sum+=fibo[i];
        l[fibo[i]][i] = 1;
          
    }
}
void pre()
{

    for (int i = 1; i <= 46367; i++)
    {

        for (int j = 2; j <= m; j++)
            if (i - fibo[j] >= 0&&l[i - fibo[j]][j - 1]!=0)
            {
                l[i][j] = max(l[i][j - 1], l[i - fibo[j]][j - 1] + 1);
            }
            else
                l[i][j] = max(l[i][j - 1],l[i][j]);
    }
}
void write(int x)
{
    int kq[30];
    int n = 1;
    int temp = l[x][m]; int t=m;
    while ("Quang"!="cute")
    {
        if (x==0) break;
        for (int i = t; i >= 1; i--)
        {
            if (x-fibo[i]>=0)
            if (l[x - fibo[i]][i - 1] == temp - 1)
            {
                kq[n]=fibo[i];
                n++;
                x=x-fibo[i];
                t=i-1;
                temp--;
                break;
            }   
        }
    }
    n--;
    
    for (int i=n;i>=1;i--)
        cout<<kq[i]<<" ";
    cout<<endl;
    
}
int main()
{
    Hoai_Thuong();
    fibo[1] = 0;
    pre();
    int n,a;
   
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a;
        write(a);
    }/*
    for (int i=1;i<=100;i++)
    {
        cout<<i<<": ";
        for (int j=2;j<=m;j++)
            cout<<l[i][j]<<" ";
        cout<<endl;
    }*/
}