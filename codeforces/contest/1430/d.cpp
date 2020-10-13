#include <bits/stdc++.h>
#define N 200005
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
int n;
string x;
void solve()
{
    cin >> n >> x;
    int prefix[N];
    reset(prefix, 0);
    prefix[0] = 1;
    for (int i = 1; i < n; i++)
        if (x[i] == x[i - 1])
        {
            prefix[i] = prefix[i - 1] + 1;
            prefix[i - 1] = -1;
        }
        else
            prefix[i] = 1;
    int a[N], ss = 1, ee = 1, res = 0;
    for (int i = 0; i < n; i++)
        if (prefix[i] != -1)
            a[ee++] = prefix[i];
    ee--;
    //cout << ss <<" " << ee << endl;
    //     for (int i = ss; i <= ee; i++)
    //        cout << a[i] << " ";
    //     cout << endl;
    int m = ee;
    while (ss <= ee)
    {
        if (a[ss] == 1)
            ss++, ee--;
        else
            ss++;
        res++;
    }
    cout << res << endl;
}
int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        solve();
    }
}