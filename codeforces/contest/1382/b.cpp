#include <bits/stdc++.h>
#define maxn 100001
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define inputfile freopen(input.txt, r, stdin)
#define outputfile freopen(out.txt, w, stdout)
using namespace std;
void solve()
{
    int a[maxn], b[maxn], n, p = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        p += a[i] == 1 ? 1 : 2;
    }
    if (n == 2)
    {
        if (a[1] == 1)
            p = 1;
        else
            p = 3;
    }
    if (p % 3 == 0 || n == 1)
        cout << "First";
    else
        cout << "Second";
    cout << endl;
}
int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
        solve();
}