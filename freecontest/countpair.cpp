#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x) memset(x, 0, sizeof(x))
#define quyen_sort(x, size) sort(x + 1, x + 1 + size);
using namespace std;
int main()
{
    string x;
    map<int, ll> trace;
    ll res = 0;
    cin >> x;
    for (int i = 0; i < x.length(); i++)
    {
        int t = x[i] - '0';
        if (t == 1)
            trace[t]++;
        if (t == 2)
            res += trace[1];
    }
    cout << res;
}