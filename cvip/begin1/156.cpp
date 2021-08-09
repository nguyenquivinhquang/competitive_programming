#include <iostream>
#include <cmath>
using namespace std;

bool Hoai_Thuong(int x)
{
    int temp = 0;
    for (int i = 1; i <= sqrt(x); i++)
    {
        if (i == x)
            break;
        if (x % i == 0)
        {
            temp += i;
            if ((x / i > sqrt(x))&&(x/i<x))
                temp += x / i;
        }
        if (temp > x)
            return false;
    }
    if (temp == x)
        return true;
    else
        return false;
}
int main()
{
    int n,m=0;
    int a[10];
    Hoai_Thuong(6);
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        if (Hoai_Thuong(i) == true)
            {
                m++;
                a[m]=i;
            }
    }
    cout<<m<<endl;
    for (int i=1;i<=m;i++)
        cout<<a[i]<<endl;
}