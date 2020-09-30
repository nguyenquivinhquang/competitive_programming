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
int n, k, snt[664589], count_snt = 0, a[N];
ll gcd(ll a, ll b)
{
    ll r, i;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
ll lcm(__int128 a, __int128 b)
{
    return a * b / gcd(a, b);
}
void solve2()
{
    vector<int> vt;
    ll res = 0;
    for (int i = 1; i <= k; i++)
        cin >> a[i];
    for (int i = 1; i <= k; i++)
    {
        bool check = true;
        for (auto v : vt)
            if (a[i] % v == 0)
            {
                check = false;
                break;
            }
        if (check)
            vt.push_back(a[i]);
    }
    sort(vt.begin(), vt.end());
    for (int i = 0; i < vt.size(); i++)
    {
        set<ll> temp;
        res += n / vt[i];
        for (int j = i - 1; j >= 0; j--)
        {
            bool check = true;
            ll u = lcm(vt[i], vt[j]);
            for (auto v : temp)
                if (u % v == 0)
                {
                    check = false;
                    break;
                }
            if (check == false)
                continue;
            res -= n / u;
            temp.insert(u);
        }
    }   
    cout << n - res << endl;
}
int main()
{
    int testcase;
    cin >> n >> k;
    solve2();
}