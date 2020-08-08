#include <bits/stdc++.h>
#define ll long long
#define maxn 100001
using namespace std;
ll a[maxn], id[maxn], n;
map<ll, ll> trace, b;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (b[a[i]] == 0)
            b[a[i]] = i;
        trace[a[i]]++;
    }
    trace[0] = 0;

    ll pos = n + 1, x = 0, y = 0;
    for (auto i = trace.end(); i != trace.begin(); i--)
    {

        if (i != trace.end())
        {

            id[pos] += (x - i->first) * y;
            x = i->first;
            pos = min(b[x], pos);
            y += i->second;
        }
    }
    id[pos] += (x - 0) * y;
    for (int i = 1; i <= n; i++)
        cout << id[i] << endl;
}
/*
10
1 2 1 3 2 4 2 5 8 1
*/