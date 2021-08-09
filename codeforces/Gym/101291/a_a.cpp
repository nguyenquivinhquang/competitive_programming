#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
using namespace std;
string root;
int res = 26, cur = 0, n;
int main()
{
    int a[1000], b[1000];
    reset(b, 0);
    string x;
    cin >> x;
    for (int i = 0; i < x.length(); i++)
        a[i + 1] = x[i];
    n = x.length();
    b[0] = 0;
    a[0] = 0;
    for (int j = 1; j <= n; j++)
    {
        int cur = a[j];
        b[j] = 1;
        for (int i = j - 1; i >= 0; i--)
        {
            if (a[i] < a[j])
            {
                b[j] = max(b[j], b[i] + 1);
            }
        }
    }
    for (int i = 1; i <= n; i++)
        res = min(res, 26 - b[i]);
    cout << res;
}