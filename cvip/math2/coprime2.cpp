#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n = 610000, m = 0;
vector<bool> mark(n + 1, true);
vector<ll> snt(10000001), a(10001), c(5101);
int count_snt = 0;
bool check_prime(ll x)
{
    for (int i=2;i<=sqrt(x);i++)
        if (x % i==0) return false;
    return true;
}
void eratos()
{
    for (ll i = 2; i <= n; i++)
    {
        if (mark[i])
        {
            count_snt++;
            snt[count_snt] = i;
            for (ll j = i * 2; j <= n; j += i)
            {
                mark[j] = false;
                //cout<<i<<" "<<j<<endl;
            }
        }
    }
    //cout<<snt[count_snt]<<endl;
    int i = 1;
    ll temp = 0,x=1;
    while (i < count_snt)
    {
        //x=1;
        while (x<=snt[i+1])
        {
            x=x*10;
        }
        //x=x/10;
        
        temp = snt[i] *x + snt[i + 1];
        i = i + 2;
        if (check_prime(temp) == true)
        {
            m++;
            c[m] = temp;
            if (m>500) break;
        }
    }
    /*for (int i=1;i<=500;i++)
        cout<<c[i]<<endl;
    */
}
int main()
{
    eratos();
    int n;
    cin>>n;
    cout<<c[n];
}