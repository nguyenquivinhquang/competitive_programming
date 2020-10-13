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
bool isPrime[1000005];
vector<int> snt;
void eratos()
{
    reset(isPrime, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i <= int(1e6 + 1); ++i)
    {
        if (isPrime[i] == true)
        {
            for (int j = i * i; j <= int(1e6 + 1); j += i)
                isPrime[j] = false;
        }
    }
    for (int i = 1; i <= int(1e6 + 1); i++)
        if (isPrime[i] == true)
        {
            snt.push_back(i);
        }
}
int find_M(int x)
{
    for (auto v : snt)
    {
        if (v > x)
            return x;
        if (x % v == 0)
            return x / v;
    }
    return x;
}
ll find_step(int x)
{
    if (x == 1)
        return 1;
    int t = find_M(x);
    if (t == x)
        return x + x / t - 1;
    return find_step(t) + x / t - 1;
}
void solve()
{
    int step = 0, a = 1, x = 0, n, res = n;
    cin >> n;
    res = find_step(n);
    cout << res << endl;
}
int main()
{
    fastio;
    eratos();
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        solve();
    }
}