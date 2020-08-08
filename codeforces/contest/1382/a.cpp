#include <bits/stdc++.h>
#define maxn 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define inputfile freopen(input.txt, r, stdin)
#define outputfile freopen(out.txt, w, stdout)
using namespace std;
void solve()
{
    int n, m, temp;
    vector<int> a(3000, 0), b(3000, 0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        a[temp] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> temp;
        b[temp] = 1;
    }
    for (int i = 1; i <= 1000; i++)
        if (a[i] * b[i] > 0)
        {
            cout << "YES" << endl;
            cout << 1 << " " << i << endl;

            return;
        }
    cout << "NO" << endl;
}
int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
        solve();
}