#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x) memset(x, 0, sizeof(x))
#define quyen_sort(x, size) sort(x + 1, x + 1 + size);
using namespace std;
void solve()
{
    int n, a[N];
    bool check = true;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 2; i <= n; i++)
        if (abs(a[i] - a[i - 1]) > 1)
            check = false;
    if (check == false)
        cout << "NO";
    else
        cout << "YES";
    cout << endl;
}

int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
        solve();
}