#include <bits/stdc++.h>
#define el '\n'
#define mod %
#define ll long long
using namespace std;
ll gcd(ll A, ll B)
{
    if (B == 0)
        return A;
    else
        return gcd(B, A % B);
}
ll lcd(ll a, ll b )
{
    return a*b/gcd(a,b);
}
int main()
{
    ll n,res=10000000000000000;
    cin>>n;
    ll a,b,x,y;
    for (int i=1;i<=sqrt(n)+1;i++)
    {
        if (n mod i==0)
        {
            a=i;
            b=n/a;
            if (lcd(a,b)==n)
            if (max(a,b)<res)
            {
                res=max(a,b);
                x=a,y=b;
            }
        }
    }
    cout<<x<<" "<<y;
}