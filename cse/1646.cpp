#include <bits/stdc++.h>
#define maxn 200001
#define ll long long
using namespace std;
int n, q, x, y;
vector<ll> a(maxn, 0), prefix(maxn, 0);

int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
    }
    while (q--)
    {
        cin >> x >> y;
        cout << prefix[y] - prefix[x] + a[x] << "\n";
    }
}