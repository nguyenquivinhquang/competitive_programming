#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("d.inp", "r", stdin);
    freopen("d.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    int a[1000];
    cin >> n>>q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        cout << a[i] << endl;
}