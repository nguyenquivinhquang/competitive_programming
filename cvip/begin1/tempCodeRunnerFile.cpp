#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;
int fibo[1000];
int l[966][31]; //46366
void Hoai_Thuong()
{
    memset(l, 0, sizeof(l));
    
    fibo[1] = fibo[2] = 1;
    l[fibo[2]][2]=1;
    for (int i = 3; i <= 23; i++)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
        l[fibo[i]][i]=1;
    }
}
void pre()
{
    
    for (int i = 1; i <= 966; i++)
    {
        
        for (int j = 2; j <= 10; j++)
            if ((i - fibo[j] >= 0) && (l[fibo[i]][j - 1] != 0))
            {
                l[i][j] = max(l[i][j], l[i-fibo[i]][j - 1]+1);
            }
    }
    
}
void write(int x)
{
    int kq[30];
    int n = 0;
    int i;
    for (i = 1; i <= 30; i++)
    {
        if (fibo[i] >= x)
            break;
    }
    kq[1] = x;
}
int main()
{
    Hoai_Thuong();
    fibo[1] = 0;
    pre();
    for (int i=1;i<=23;i++)
        cout<<fibo[i]<<" ";
}