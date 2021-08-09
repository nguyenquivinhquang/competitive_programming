#include <bits/stdc++.h>
#define ll long long
#define maxn 200001
using namespace std;
ll n, u, v, x, p[maxn];
set<ll> pos;
multiset<ll> len;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    cin >> x >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    len.insert(x);
    pos.insert(0), pos.insert(x);
    for (int i = 1; i <= n; i++)
    {
        auto find = pos.lower_bound(p[i]);
        v = *find, find--, u = *find;
        auto it = len.find(v - u);
        len.erase(it);
        pos.insert(p[i]);
        len.insert(p[i] - u), len.insert(v - p[i]);
        it = len.end(), it--;
        cout << *it << " ";
    }
}