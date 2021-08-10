#include <bits/stdc++.h>
#define maxn 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define inputfile freopen(input.txt, r, stdin)
#define outputfile freopen(out.txt, w, stdout)
using namespace std;
int main()
{
    ll res = 0, val = 0;
    map<ll, ll> trace;
    int a, b, c;
    cin >> a >> b >> c;
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
            for (int k = 1; k <= c; k++)
                trace[i + j + k]++;
    for (auto v : trace)
        if (v.second > res)
        {
            res = v.second;
            val = v.first;
        }
    cout << val;
}