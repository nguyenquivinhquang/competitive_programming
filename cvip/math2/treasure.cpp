#include <bits/stdc++.h>
#define mod %
#define ll long long
using namespace std;
ll trace[101];
ll top; //=))
int check(ll x)
{
    for (int i = 1; i <= top; i++)
        if (x == trace[i])
            return i;
    top++;
    trace[top] = x;
    return 0;
}
ll c1(ll x, int k)
{
    ll t, pos, bot, i;
    ll ahihi = x;
    for (i = 1; i <= k; i++)
    {
        t = x mod 100, pos = check(t);
        if (pos != 0)
            break;
        x = x + x mod 100;
    }
    bot = i - 1;
    if (pos == 0)
        pos = 1;
    top = pos;
    ll res = 0;
    for (i = top; i <= bot; i++)
        res += trace[i];
    t = (k - top + 1) / (bot - top + 1);
    res = res * t;
    for (int i = top; i < top + (k - top + 1) % (bot - top + 1); i++)
        res += trace[i];
    for (int i = 1; i < top; i++)
        res += trace[i];
    res=res+ahihi;    
    return res;
}
int backup(int x, int k)
{

    for (int i = 1; i <= k; i++)
    {
        x = x + x mod 100;
    }
    return x;
}
int main()
{
    int x, k, t;
    cin>>t;
    for (int i = 1; i <= t; i++)
    {
        memset(trace, 0, sizeof(trace));
        top = 0;
        cin >> x >> k;
        cout << c1(x, k)<<endl;
    }
}