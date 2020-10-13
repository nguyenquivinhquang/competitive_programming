#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
#define endl '\n'
#define input_file freopen("input.txt", "r", stdin);
#define output_file freopen("output.txt", "w", stdout);
using namespace std;
int n, a, b, c;
void solve()
{

    cin >> n;
    a = b = c = -1;
    for (int i = 0; i * 7 <= n; i++)
        for (int j = 0; j * 5 <= n; j++)
        {
            int t = n - 7 * i - 5 * j;
            if (t < 0)
                break;
            if (t % 3 == 0)
            {
                c = i;
                b = j;
                a = t / 3;
                return;
            }
        }
}
int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        solve();
        if (a != -1)
        {
            cout << a << " " << b << " " << c << endl;
        }
        else
            cout << -1 << endl;
    }
}