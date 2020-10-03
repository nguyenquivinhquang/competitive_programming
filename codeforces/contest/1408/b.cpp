#include <bits/stdc++.h>
#define N 150
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
ll n, k, count_snt = 0, a[N];
ll gcd(ll x, ll y)
{
    ll r, i;
    while (y != 0)
    {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}
ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}
void solve2()
{
    //int size = n + 5;
    bool fee[1000009];
    reset(fee, true);
    for (int i = 1; i <= k; i++)
    {
        cin >> a[i];
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (fee[i] == false)
            continue;
        for (int j = 1; j <= k; j++)
            if (i % a[j] == 0)
            {
                fee[i] = false;
                break;
            }
    }
    for (int i = 0; i < n; i++)
        if (fee[i] == true)
            res++;
    cout << res << endl;
}
int solve1()
{
    ll trace[30];
    reset(trace, 0);
    ll limit = 1;
    for (int i = 1; i <= k; i++)
        limit *= 2;
    for (int i = 1; i <= k; i++)
        cin >> a[i];
	//cout << limit << endl;
    for (int i = 0; i < limit; i++)
    {
        // cout << i << ' ' << limit << endl;
        ll Lcm = 1;
        int countBit = 0;
        for (int j = 0; j < k; j++)
            if (i & (1 << j))
            {
                Lcm = lcm(Lcm, (a[j + 1])), countBit++;
                if (Lcm > 100000000000000)
                {
                    Lcm = -1;
                    break;
                }
            }
        if (Lcm <= 100000000000000 && Lcm != -1)
        {
            trace[countBit] += (n - 1) / Lcm;
        }
 
    }
    ll res1 = 0, res2 = 0;
    for (int i = 0; i < k; i++)
    {
        if (i % 2 == 0)
            res1 += trace[i];
        else
            res1 -= trace[i];
    }
    cout << res1;
    return 0;
}
int main()
{
    //fastio;
    cin >> n >> k;
    if (k <= 20)
        solve1();
    else
        solve2();
}