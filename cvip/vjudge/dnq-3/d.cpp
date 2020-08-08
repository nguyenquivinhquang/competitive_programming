#include <bits/stdc++.h>
#define maxn 5001
using namespace std;
int a[maxn], n;
int Gb(int l, int r)
{
    if (l==r) return 1;
    if (l>r) return 0;
    int f_min = 1000000001, res = 0, pos, c = 0;
    for (int i = l; i <= r; i++)
    {
        if (a[i] < f_min)
            f_min = a[i], pos = i;
        if (a[i] != 0)
            c++;
    }
    for (int i = l; i <= r; i++)
    {
        a[i] -= f_min;
        if (a[i] < 0)
            a[i] = 0;
    }
    int bd=l,kt=r;
    for (int i=l;i<=r+1;i++)
    if (a[i]==0)
    {
        res+=Gb(bd,i-1);
        bd=i+1;
    }
    return min(res+f_min,c);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[n+1]=0;
    cout<<Gb(1,n);
}